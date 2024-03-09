//
// Created by leroideskiwis on 10/11/23.
//

#include "../headers/Edge.h"
#include "../headers/Graph.h"

std::string Edge::toString(){
    return std::format("{} --[{}]--> {}", from->toString(), weight, to->toString());
}

void Edge::draw(QPainter *pPainter) {
    pPainter->setPen(QPen(Qt::black, weight, Qt::SolidLine, Qt::RoundCap));
    Location middleFrom = from->getMiddle();
    Location middleTo = to->getMiddle();
    pPainter->drawLine(middleFrom.x, middleFrom.y, middleTo.x, middleTo.y);
}

void Edge::changeWeight(int weight) {
    this->weight = weight;
}

Edge::Edge(nlohmann::basic_json<> json, std::vector<Node *> nodes) {
    Node* from = nullptr;
    Node* to = nullptr;
    for(auto& node : nodes) {
        if(node->getTitle() == json["from"].get<std::string>()) from = node;
        if(node->getTitle() == json["to"].get<std::string>()) to = node;
    }
    auto weight = json["weight"].get<int>();

    if(from == nullptr || to == nullptr) throw std::runtime_error("Node not found");
    this->from = from;
    this->to = to;
    this->weight = weight;
};

nlohmann::basic_json<> Edge::toJson(){
    auto json = nlohmann::json::object();
    json["from"] = from->getTitle();
    json["to"] = to->getTitle();
    json["weight"] = weight;
    return json;
}