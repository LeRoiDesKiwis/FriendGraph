//
// Created by leroideskiwis on 10/11/23.
//

#include "Graph.h"

#include <functional>
#include <iostream>

void Graph::draw() {
    std::cout << "Il y a " << nodes.size() << " noeuds" << std::endl;
    for (auto node: nodes) {
        std::cout << "- " << node->toString() << std::endl;
        std::cout << "\tDegré in : " << degreeIn(*node) << std::endl;
        std::cout << "\tDegré out : " << degreeOut(*node) << std::endl;
        std::cout << "\tDegré in weight : " << weightedDegreeIn(*node) << std::endl;
        std::cout << "\tDegré out weight : "<< weightedDegreeOut(*node) << std::endl;
    }

    std::cout << std::endl;

    for(auto edge : edges) {
        std::cout << "- " << edge->toString() << std::endl;
    }
}

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


