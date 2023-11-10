//
// Created by leroideskiwis on 10/11/23.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <utility>

typedef struct {
    int x;
    int y;
} Location;

class Node {
public:
    Node(const std::string& title, const Location& location) : title(title), location(location) {};

    void draw() const;
    [[nodiscard]] const std::string& getTitle() const;
    Location& getLocation();

private:
    const std::string& title;
    Location location;

};

#endif //NODE_H
