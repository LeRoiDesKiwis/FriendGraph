//
// Created by leroideskiwis on 10/11/23.
//

#include "../headers/Node.h"

#include <iostream>
#include <format>
#define TEXT_SIZE 15
#define OFFSET_RADIUS 10

void Node::draw(QPainter *pPainter) const {
    pPainter->setPen(QPen(color, 2, Qt::SolidLine, Qt::RoundCap));
    pPainter->drawEllipse(location.x, location.y, getSize(), getSize());
    pPainter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    pPainter->setFont(QFont("Arial", TEXT_SIZE));
    pPainter->drawText(location.x - getSize(), location.y - getSize(), QString::fromStdString(title));
}

Location Node::getMiddle() const{
    return Location{location.x + getSize()/2, location.y + getSize()/2};
}
std::string Node::toString() {
    return std::format("{}({}, {})", title, location.x, location.y);
}

bool Node::isClicked(Location location) const {
    //TODO make the hitbox a circle
    return (location.x >= getMiddle().x-getSize()/2 && location.x <= getMiddle().x + getSize()/2) &&
           (location.y >= getMiddle().y-getSize()/2 && location.y <= getMiddle().y + getSize()/2);
}

void Node::setColor(Qt::GlobalColor color) {
    this->color = color;
}

int Node::getSize() const {
    return size+OFFSET_RADIUS;
}

void Node::setNodeSize(Graph *graph) {
    size = graph->weightedDegreeIn(*this);
}

Node::Node(nlohmann::json_abi_v3_11_2::basic_json<> json, Location defaultLocation) {
    Location location{};
    if(json["location"] == nullptr) location = defaultLocation;
    else location = {json["location"]["x"].get<int>(), json["location"]["y"].get<int>()};
    this->title = json["title"].get<std::string>();
    this->location = location;
}

nlohmann::basic_json<> Node::toJson(){
    auto json = nlohmann::json::object();
    json["title"] = title;
    json["location"]["x"] = location.x;
    json["location"]["y"] = location.y;
    return json;
}
