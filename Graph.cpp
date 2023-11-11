//
// Created by leroideskiwis on 10/11/23.
//

#include "Graph.h"

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
        node->draw(painter, weightedDegreeIn(*node)*5);
    }
    for(auto edge : edges) {
        edge->draw(painter, this);
    }
}


