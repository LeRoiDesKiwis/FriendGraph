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

/**
 * @brief Class representing a graph
 * @details A graph is a collection of nodes and edges
 */
class Graph {

public:
    /**
     * @brief Construct a new Graph object
     * @param nodes the list of nodes
     * @param edges the list of edges
     */
    Graph(const std::vector<Node*>& nodes, const std::vector<Edge*>& edges);
    /**
     * @brief Construct a new Graph object from a json file
     * @param fileName The name of the file
     */
    Graph(std::string fileName);
    /**
     * @brief Draw the graph
     * @param qpainter The painter
     */
    void draw(QPainter *qpainter);
    /**
     * @brief Caculate the degree of a node
     * @param node The node
     * @param shouldCount A function that returns true if the edge should be counted
     * @param nodeFunc A function that takes an edge and returns the value to add to the degree
     * @return The degree
     */
    [[nodiscard]] int degree(const Node& node, const std::function<bool(const Edge*)>&shouldCount, const std::function<int(const Edge*)>&nodeFunc) const;

    /**
     * @brief Calculate the in degree of a node
     * @param node The node
     * @return The degree only taking into account the destination of the edge
     */
    [[nodiscard]] int degreeIn(const Node& node) const;

    /**
     * @brief Calculate the out degree of a node
     * @param node The node
     * @return The degree only taking into account the source of the edge
     */
    [[nodiscard]] int degreeOut(const Node& node) const;

    /**
     * @brief Calculate the weighted in degree of a node
     * @param node The node
     * @return The degree only taking into account the destination of the edge
     */
    [[nodiscard]] int weightedDegreeIn(const Node& node) const;

    /**
     * @brief Calculate the weighted out degree of a node
     * @param node The node
     * @return The degree only taking into account the source of the edge
     */
    [[nodiscard]] int weightedDegreeOut(const Node& node) const;

    /**
     * @brief Get the list of edges
     * @return The list of edges
     */
    [[nodiscard]] std::vector<Node*> getNodes() {return nodes;};

    /**
     * @brief Add an edge to the graph
     * @param edge The edge
     */
    void addEdge(Edge* edge);

    /**
     * @brief Add a node to the graph
     * @param pNode The node
     */
    void addNode(Node *pNode);

    /**
     * @brief Save the graph to a file
     * @param fileName The name of the file
     */
    void save(std::string fileName);
    ~Graph();

private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;

    [[nodiscard]] Edge *findEdge(const Node &from, const Node &to) const;
};



#endif //GRAPH_H
