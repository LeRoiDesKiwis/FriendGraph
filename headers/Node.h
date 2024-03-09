//
// Created by leroideskiwis on 10/11/23.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <utility>
#include <QPainter>
#include <nlohmann/json.hpp>
#include "Graph.h"
class Graph;

/**
 * @brief Structure representing a location
 * @details A location is a point in a 2D space
 */
struct Location{
    int x;
    int y;
};

class Node {
public:

    /**
     * @brief Construct a new Node object
     * @param title The title of the node
     * @param location The location of the node
     * @param color The color of the node
     */
    Node(const std::string title, const Location& location, const Qt::GlobalColor color = Qt::black) : title(title), location(location), color(color){};

    /**
     * @brief Construct a new Node object from a json object
     * @param json The json object
     * @param defaultLocation The default location
     */
    Node(nlohmann::json_abi_v3_11_3::basic_json<> json, Location defaultLocation);

    /**
     * @brief Draw the node
     * @param pPainter
     */
    void draw(QPainter *pPainter) const;

    /**
     * @brief Get the title of the node
     * @return The title
     * @deprecated Getters and setters will be removed in the future
     */
    [[nodiscard]] std::string getTitle() const {return title;};

    /**
     * @brief Get the location of the node
     * @return The location
     * @deprecated Getters and setters will be removed in the future
     */
    Location& getLocation(){return location;};
    bool operator==(const Node& other) const {
        return title == other.title;
    }

    /**
     * @brief Get the middle of the node
     * @return The middle
     */
    [[nodiscard]] Location getMiddle() const;
    std::string toString();

    /**
     * @brief Check if the node is clicked
     * @param location The location of the click
     * @return true if the node is clicked
     */
    [[nodiscard]] bool isClicked(Location location) const;

    /**
     * @brief Set the color of the node
     * @param color The color
     */
    void setColor(Qt::GlobalColor color);

    /**
     * @brief Set the size of the node
     * @param size The size
     */
    void setSize(int size) {this->size = size;};

    /**
     * @brief Get the size of the node
     * @return The size
     * @deprecated Getters and setters will be removed in the future
     */
    [[nodiscard]] int getSize() const;

    /**
     * @brief Set the size of the node based on the weighted in degree
     * @param graph The graph
     */
    void setNodeSize(Graph *graph);

    /**
     * @brief Get the json representation of the node
     * @return The json object
     */
    nlohmann::basic_json<> toJson();

    /**
     * @brief Adapt the middle of the node
     * @details The middle of the node is the top left corner of the node. This function adapts the middle to the center of the node
     * @param location The location
     * @return The adapted location
     */
    [[nodiscard]] Location adaptMiddle(Location location) const {
        return Location{location.x - getSize()/2, location.y - getSize()/2};
    }
private:
    std::string title;
    Location location;
    Qt::GlobalColor color = Qt::black;
    int size = 10;
};

#endif //NODE_H
