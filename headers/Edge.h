//
// Created by leroideskiwis on 10/11/23.
//

#ifndef EDGE_H
#define EDGE_H
#include <format>

#include "Node.h"
class Graph;
class Node;

class Edge {

public:
    Edge(Node& node1, Node& node2, const int weight) : from(&node1), to(&node2), weight(weight) {};
    Edge(Node& node1, Node& node2) : from(&node1), to(&node2), weight(1) {};

    Edge(nlohmann::basic_json<> json, std::vector<Node *> nodes);

    [[nodiscard]] Node& getFrom() const {return *from;}
    [[nodiscard]] Node& getTo() const {return *to;}
    [[nodiscard]] int getWeight() const {return weight;};
    std::string toString();
    [[nodiscard]] bool operator==(const Edge& other) const {
        return from == other.from && to == other.to;
    }

    void draw(QPainter *pPainter, Graph *graph);

    void changeWeight(int weight);

private:
    Node* from = nullptr;
    Node* to = nullptr;
    int weight;

};



#endif //EDGE_H
