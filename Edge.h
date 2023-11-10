//
// Created by leroideskiwis on 10/11/23.
//

#ifndef EDGE_H
#define EDGE_H
#include <format>

#include "Node.h"


class Edge {

public:
    Edge(Node& node1, Node& node2, const int weight) : node1(node1), node2(node2), weight(weight) {};
    Edge(Node& node1, Node& node2) : node1(node1), node2(node2), weight(1) {};
    std::string toString() {
        return std::format("{} --[{}]--> {}", node1.getTitle(), weight, node2.getTitle());
    };

private:
    Node& node1;
    Node& node2;
    int weight;
};



#endif //EDGE_H
