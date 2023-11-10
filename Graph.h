//
// Created by leroideskiwis on 10/11/23.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <memory>
#include <vector>

#include "Edge.h"
#include "Node.h"


class Graph {

public:
    Graph(const std::vector<Node*>& nodes, const std::vector<Edge*>& edges) : nodes(nodes), edges(edges) {};
    void draw();
    [[nodiscard]] int degreeIn(const Node& node) const;
    [[nodiscard]] int degreeOut(const Node& node) const;

private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
};



#endif //GRAPH_H
