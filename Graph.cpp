//
// Created by leroideskiwis on 10/11/23.
//

#include "Graph.h"

#include <iostream>

void Graph::draw() {
    std::cout << "Il y a " << nodes.size() << " noeuds" << std::endl;
    for (auto node: nodes) {
        std::cout << "- " << node->getTitle() << std::endl;
    }

    std::cout << std::endl;

    for(auto edge : edges) {
        std::cout << "- " << edge->toString() << std::endl;
    }
}
