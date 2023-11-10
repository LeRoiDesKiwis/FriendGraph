#include <iostream>

#include "Node.h"
#include <string>

#include "Edge.h"
#include <nlohmann/json.hpp>

#include "Graph.h"

int main() {
    Location location = {0, 0};
    auto node1 = new Node("LeRoiDesKiwis", location);
    auto node2 = new Node("user2", location);
    auto node3 = new Node("user3", location);
    auto node4 = new Node("user4", location);
    auto edges = {new Edge(*node1, *node2), new Edge(*node1, *node4), new Edge(*node2, *node4), new Edge(*node1, *node3), new Edge(*node2, *node3), new Edge(*node3, *node4, 5)};

    auto graph = new Graph({node1, node2, node3, node4}, edges);
    graph->draw();

    return 0;
}
