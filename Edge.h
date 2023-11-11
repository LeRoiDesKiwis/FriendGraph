//
// Created by leroideskiwis on 10/11/23.
//

#ifndef EDGE_H
#define EDGE_H
#include <format>

#include "Node.h"
class Graph;


class Edge {

public:
    Edge(Node& node1, Node& node2, const int weight) : from(node1), to(node2), weight(weight) {};
    Edge(Node& node1, Node& node2) : from(node1), to(node2), weight(1) {};
    [[nodiscard]] const Node& getFrom() const {return from;}
    [[nodiscard]] const Node& getTo() const {return to;}
    [[nodiscard]] int getWeight() const {return weight;};
    std::string toString();
    [[nodiscard]] bool operator==(const Edge& other) const {
        return from == other.from && to == other.to;
    }

    void draw(QPainter *pPainter, Graph *graph);
private:
    Node& from;
    Node& to;
    int weight;

};



#endif //EDGE_H
