//
// Created by leroideskiwis on 10/11/23.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <utility>
#include <QPainter>

struct Location{
    int x;
    int y;
};

class Node {
public:
    Node(const std::string title, const Location& location, int radius = 20) : title(title), location(location), radius(radius) {};

    void draw(QPainter *pPainter) const;
    [[nodiscard]] std::string getTitle() const {return title;};
    Location& getLocation(){return location;};
    bool operator==(const Node& other) const {
        return title == other.title;
    }
    [[nodiscard]] Location getMiddle() const;
    std::string toString();

    [[nodiscard]] int getRadius() const;

private:
    const std::string title;
    Location location;
    int radius;
};

#endif //NODE_H
