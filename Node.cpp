//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

#include <iostream>
#include <format>

void Node::draw() const {
    std::cout << "[ " << title << " ] ";
}

std::string Node::toString() {
    return std::format("{}({}, {})", title, location.x, location.y);
}
