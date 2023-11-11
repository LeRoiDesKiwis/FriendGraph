//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

#include <iostream>
#include <format>
#define SIZE 10

void Node::draw(QPainter *pPainter) const {
    pPainter->drawEllipse(location.x, location.y, SIZE, SIZE);
}

std::string Node::toString() {
    return std::format("{}({}, {})", title, location.x, location.y);
}
