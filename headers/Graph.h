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

class Node;
class Edge;

class Graph {

public:
    Graph(const std::vector<Node*>& nodes, const std::vector<Edge*>& edges);
    Graph(std::string fileName);
    void draw(QPainter *qpainter);
    [[nodiscard]] int degree(const Node& node, const std::function<bool(const Edge*)>&shouldCount, const std::function<int(const Edge*)>&nodeFunc) const;
    [[nodiscard]] int degreeIn(const Node& node) const;
    [[nodiscard]] int degreeOut(const Node& node) const;
    [[nodiscard]] int weightedDegreeIn(const Node& node) const;
    [[nodiscard]] int weightedDegreeOut(const Node& node) const;

    [[nodiscard]] std::vector<Node*> getNodes() {return nodes;};

    void addEdge(Edge* edge);

    void addNode(Node *pNode);

    void save(std::string fileName);
    ~Graph();

private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;

    [[nodiscard]] Edge *findEdge(const Node &from, const Node &to) const;
};



#endif //GRAPH_H
