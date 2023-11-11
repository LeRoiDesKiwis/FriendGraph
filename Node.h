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
    Node(const std::string title, const Location& location) : title(title), location(location) {};

    void draw(QPainter *pPainter) const;
    [[nodiscard]] std::string getTitle() const {return title;};
    Location& getLocation(){return location;};
    bool operator==(const Node& other) const {
        return title == other.title;
    }
    std::string toString();

private:
    const std::string title;
    Location location;

};

#endif //NODE_H
