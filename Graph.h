//
// Created by leroideskiwis on 10/11/23.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <functional>
#include <memory>
#include <vector>
#include <QPainter>

#include "Edge.h"
#include "Node.h"


class Graph {

public:
    Graph(const std::vector<Node*>& nodes, const std::vector<Edge*>& edges) : nodes(nodes), edges(edges) {};
    void draw(QPainter *qpainter);
    [[nodiscard]] int degree(const Node& node, const std::function<bool(const Edge*)>&shouldCount, const std::function<int(const Edge*)>&nodeFunc) const;
    [[nodiscard]] int degreeIn(const Node& node) const;
    [[nodiscard]] int degreeOut(const Node& node) const;
    [[nodiscard]] int weightedDegreeIn(const Node& node) const;
    [[nodiscard]] int weightedDegreeOut(const Node& node) const;

    [[nodiscard]] std::vector<Node*> getNodes() {return nodes;};

    void addEdge(Node &node, Node &node1);

private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
};



#endif //GRAPH_H
