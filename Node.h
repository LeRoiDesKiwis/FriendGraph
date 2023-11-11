//
// Created by leroideskiwis on 10/11/23.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <utility>
#include <QPainter>
#include "Graph.h"
class Graph;

struct Location{
    int x;
    int y;
};

class Node {
public:
    Node(const std::string title, const Location& location, const Qt::GlobalColor color = Qt::black) : title(title), location(location), color(color){};

    void draw(QPainter *pPainter) const;
    [[nodiscard]] std::string getTitle() const {return title;};
    Location& getLocation(){return location;};
    bool operator==(const Node& other) const {
        return title == other.title;
    }
    [[nodiscard]] Location getMiddle() const;
    std::string toString();

    [[nodiscard]] bool isClicked(Location location) const;

    void setColor(Qt::GlobalColor color);

    void setSize(int size) {this->size = size;};

    [[nodiscard]] int getSize() const;

    void setNodeSize(Graph *graph);

private:
    const std::string title;
    Location location;
    Qt::GlobalColor color;
    int size = 10;
};

#endif //NODE_H
