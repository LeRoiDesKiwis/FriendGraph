//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

#include <iostream>

void Node::draw() const {
    std::cout << "[ " << title << " ] ";
}

std::string Node::getTitle() {
    return title;
}

Location& Node::getLocation() {
    return location;
}
