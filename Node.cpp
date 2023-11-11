//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

#include <iostream>
#include <format>
#define TEXT_SIZE 15

void Node::draw(QPainter *pPainter) const {
    pPainter->drawEllipse(location.x, location.y, radius, radius);
    pPainter->drawPoint(location.x, location.y);
    pPainter->setFont(QFont("Arial", TEXT_SIZE));
    pPainter->drawText(location.x - radius, location.y - radius, QString::fromStdString(title));
}

Location Node::getMiddle() const{
    return Location{location.x + radius/2, location.y + radius/2};
}
std::string Node::toString() {
    return std::format("{}({}, {})", title, location.x, location.y);
}

int Node::getRadius() const {
    return radius;
}
