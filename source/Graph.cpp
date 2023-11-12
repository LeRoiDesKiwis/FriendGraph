//
// Created by leroideskiwis on 10/11/23.
//

#include <nlohmann/json.hpp>
#include <fstream>
#include <random>
#include "../headers/Graph.h"

int Graph::degree(const Node& node, const std::function<bool(const Edge*)>&shouldCount, const std::function<int(const Edge*)>&nodeFunc) const {
    int degree = 0;
    for (const auto edge : edges) {
        if(shouldCount(edge)) degree += nodeFunc(edge);
    }
    return degree;
}

int Graph::degreeIn(const Node& node) const {
    return degree(node,
        [&node](const Edge* edge){return edge->getTo() == node;},
        [](const Edge*){return 1;}
        );
}

int Graph::degreeOut(const Node& node) const{
    return degree(node,
        [&node](const Edge* edge){return edge->getFrom() == node;},
        [](const Edge*){return 1;}
        );
}

int Graph::weightedDegreeOut(const Node& node) const {
    return degree(node,
    [&node](const Edge* edge){return edge->getFrom() == node;},
    [](const Edge* edge){return edge->getWeight();}
    );
}

int Graph::weightedDegreeIn(const Node& node) const {
    return degree(node,
    [&node](const Edge* edge){return edge->getTo() == node;},
    [](const Edge* edge){return edge->getWeight();}
    );
}

void Graph::draw(QPainter* painter) {
    for(auto node : nodes) {
        node->draw(painter);
        node->setNodeSize(this);
    }
    for(auto edge : edges) {
        edge->draw(painter, this);
    }
}

void Graph::addEdge(Edge* edge) {
    Edge* existingEdge = findEdge(edge->getFrom(), edge->getTo());
    if(existingEdge != nullptr) existingEdge->changeWeight(edge->getWeight());
    else edges.push_back(edge);
    edge->getFrom().setNodeSize(this);
    edge->getTo().setNodeSize(this);

}

void Graph::addNode(Node *pNode) {
    nodes.push_back(pNode);
    pNode->setNodeSize(this);
}

Edge* Graph::findEdge(const Node& from, const Node& to) const {
    for(auto edge : edges) {
        if(edge->getFrom() == from && edge->getTo() == to) return edge;
    }
    return nullptr;
}

Graph::Graph(const std::vector<Node *> &nodes, const std::vector<Edge *> &edges) : nodes(nodes), edges(edges){
    for(auto node : nodes) {
        node->setNodeSize(this);
    }
}

Graph::Graph(std::string fileName) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 1000); // Adjust range as needed;

    std::ifstream file(fileName);
    nlohmann::json j;
    file >> j;
    auto nodesJson = j["nodes"];
    auto edgesJson = j["edges"];
    for(auto& nodeJson : nodesJson) {
        auto node = new Node(nodeJson, {dis(gen), dis(gen)});
        nodes.push_back(node);
    }

    for(auto& edgeJson : edgesJson) {
        auto edge = new Edge(edgeJson, nodes);
        edges.push_back(edge);
    }

}

void Graph::save(std::string fileName) {
    nlohmann::json j = nlohmann::json::object();
    for(auto& node : nodes) {
        j["nodes"].push_back(node->toJson());
    }
    for(auto& edge : edges) {
        j["edges"].push_back(edge->toJson());
    }
    std::ofstream file(fileName);
    file << j;
}