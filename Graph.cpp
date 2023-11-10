//
// Created by leroideskiwis on 10/11/23.
//

#include "Graph.h"

#include <iostream>

void Graph::draw() {
    std::cout << "Il y a " << nodes.size() << " noeuds" << std::endl;
    for (auto node: nodes) {
        std::cout << "- " << node->getTitle() <<
            " Degré out : " << degreeOut(*node) <<
                " ; Degré in : " << degreeIn(*node) << std::endl
        ;
    }

    std::cout << std::endl;

    for(auto edge : edges) {
        std::cout << "- " << edge->toString() << std::endl;
    }
}

int Graph::degreeIn(const Node& node) const {
    int degree = 0;
    for (const auto edge : edges) {
        if(edge->getTo() == node) degree++;
    }
    return degree;
}

int Graph::degreeOut(const Node& node) const{
    int degree = 0;
    for (const auto edge : edges) {
        if(edge->getFrom() == node) degree++;
    }
    return degree;
}
