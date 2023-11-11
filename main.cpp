#include <fstream>
#include <iostream>

#include "Node.h"
#include <string>

#include "Edge.h"
#include <nlohmann/json.hpp>
#include <random>

#include "Graph.h"
#include "GraphWidget.h"

#include <QApplication>

Graph* parseFromJson(std::string fileName);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto graph = parseFromJson("example.json");
    auto graphWidget = new GraphWidget(graph, nullptr);
    graphWidget->show();

    return QApplication::exec();
}

Graph* parseFromJson(std::string fileName) {
    std::vector<Node*> nodes = {};
    std::vector<Edge*> edges = {};

    std::ifstream file(fileName);
    nlohmann::json j;
    file >> j;
    auto nodesJson = j["nodes"];
    auto edgesJson = j["edges"];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 1000); // Adjust range as needed;

    for(auto& nodeJson : nodesJson) {
        Location location{};
        if(nodeJson["location"] == nullptr) location = {dis(gen), dis(gen)};
        else location = {nodeJson["location"]["x"].get<int>(), nodeJson["location"]["y"].get<int>()};
        auto node = new Node(nodeJson["title"].get<std::string>(), location);
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
