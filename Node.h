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
    Node(std::string title, const Location& location) : title(title), location(location) {};

    void draw() const;
    std::string getTitle();
    Location& getLocation();

private:
    std::string title;
    Location location;

};

#endif //NODE_H
