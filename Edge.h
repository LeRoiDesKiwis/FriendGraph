//
// Created by leroideskiwis on 10/11/23.
//

#ifndef EDGE_H
#define EDGE_H
#include "Node.h"


class Edge {

public:
    Edge(Node& node1, Node& node2) : node1(node1), node2(node2) {};
    std::string toString() {
        return node1.getTitle()+" --> "+ node2.getTitle();
    };

private:
    Node& node1;
    Node& node2;
};



#endif //EDGE_H
