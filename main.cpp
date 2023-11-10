#include <fstream>
#include <iostream>

#include "Node.h"
#include <string>

#include "Edge.h"
#include <nlohmann/json.hpp>

#include "Graph.h"

Graph* parseFromJson(std::string fileName);

int main() {
    auto graph = parseFromJson("example.json");
    graph->draw();

    return 0;
}

Graph* parseFromJson(std::string fileName) {
    std::vector<Node*> nodes = {};
    std::vector<Edge*> edges = {};

    std::ifstream file(fileName);
    nlohmann::json j;
    file >> j;
    auto nodesJson = j["nodes"];
    auto edgesJson = j["edges"];

    auto location = new Location(0, 0);

    for(auto& nodeJson : nodesJson) {
        auto node = new Node(nodeJson["title"].get<std::string>(), *location);
        nodes.push_back(node);
    }

    for(auto& edgeJson : edgesJson) {
        Node* from = nullptr;
        Node* to = nullptr;
        for(auto& node : nodes) {
            if(node->getTitle() == edgeJson["from"].get<std::string>()) from = node;
            if(node->getTitle() == edgeJson["to"].get<std::string>()) to = node;
        }
        auto weight = edgeJson["weight"].get<int>();

        if(from != nullptr && to != nullptr) {
            auto edge = new Edge(*from, *to, weight);
            edges.push_back(edge);
        }
    }
    return new Graph(nodes, edges);
}
