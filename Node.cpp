//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

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
