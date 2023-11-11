//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

#include <iostream>
#include <format>
#define SIZE 30

void Node::draw(QPainter *pPainter) const {
    pPainter->drawEllipse(location.x, location.y, SIZE, SIZE);
    pPainter->drawPoint(location.x, location.y);
}

Location Node::getMiddle() const{
    return Location{location.x + SIZE/2, location.y + SIZE/2};
}
std::string Node::toString() {
    return std::format("{}({}, {})", title, location.x, location.y);
}