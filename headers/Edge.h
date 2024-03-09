//
// Created by leroideskiwis on 10/11/23.
//

#ifndef EDGE_H
#define EDGE_H
#include <format>

#include "Node.h"
class Graph;
class Node;

/**
 * @brief Class representing an edge between two nodes
 * @details An edge is a connection between two nodes, it has a weight and a direction
 */
class Edge {

public:
    /**
     * @brief Construct a new Edge object
     * @param node1 From node
     * @param node2 Destination node
     * @param weight Weight of the edge
     */
    Edge(Node& node1, Node& node2, const int weight) : from(&node1), to(&node2), weight(weight) {};

    /**
     * @brief Construct a new Edge object. The weight is set to 1
     * @param node1 From node
     * @param node2 Destination node
     */
    Edge(Node& node1, Node& node2) : from(&node1), to(&node2), weight(1) {};

    /**
     * @brief Construct a new Edge object from a json object. You have to provide the list of nodes
     * @param json The json object
     * @param nodes The list of nodes
     */
    Edge(nlohmann::basic_json<> json, std::vector<Node *> nodes);

    /**
     * @brief Get the from node
     * @return The from node
     * @deprecated Getters and setters will be removed in the future
     */
    [[nodiscard]] Node& getFrom() const {return *from;}
    /**
     * @brief Get the destination node
     * @return The destination node
     * @deprecated Getters and setters will be removed in the future
     */
    [[nodiscard]] Node& getTo() const {return *to;}
    /**
     * @brief Get the weight of the edge
     * @return The weight
     * @deprecated Getters and setters will be removed in the future
     */
    [[nodiscard]] int getWeight() const {return weight;};
    std::string toString();
    [[nodiscard]] bool operator==(const Edge& other) const {
        return from == other.from && to == other.to;
    }

    /**
     * @brief Draw the edge
     * @param pPainter
     */
    void draw(QPainter *pPainter);

    /**
     * @brief Change the weight of the edge
     * @param weight the new weight
     * @deprecated Getters and setters will be removed in the future
     */
    void changeWeight(int weight);

    /**
     * @brief Convert the edge to a json object
     * @details The json object will have the following format:
     * {"from":"node1","to":"node2","weight":1}
     * @return The json object
     */
    nlohmann::basic_json<> toJson();

private:
    Node* from = nullptr;
    Node* to = nullptr;
    int weight;
};



#endif //EDGE_H
