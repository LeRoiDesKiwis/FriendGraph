//
// Created by leroideskiwis on 10/11/23.
//

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