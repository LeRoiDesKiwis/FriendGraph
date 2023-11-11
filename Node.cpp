//
// Created by leroideskiwis on 10/11/23.
//

#include "Node.h"

#include <iostream>
#include <format>
#define TEXT_SIZE 15
#define OFFSET_RADIUS 10

void Node::draw(QPainter *pPainter, int radius) const {
    pPainter->setPen(QPen(color, 2, Qt::SolidLine, Qt::RoundCap));
    pPainter->drawEllipse(location.x, location.y, radius+OFFSET_RADIUS, radius+OFFSET_RADIUS);
    pPainter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    pPainter->setFont(QFont("Arial", TEXT_SIZE));
    pPainter->drawText(location.x - radius, location.y - radius, QString::fromStdString(title));
}

Location Node::getMiddle(int radius) const{
    return Location{location.x + radius/2, location.y + radius/2};
}
std::string Node::toString() {
    return std::format("{}({}, {})", title, location.x, location.y);
}

bool Node::isClicked(Location location, int radius) const {
    return location.x >= this->location.x && location.x <= this->location.x + radius && location.y >= this->location.y && location.y <= this->location.y + radius;
}

void Node::setColor(Qt::GlobalColor color) {
    this->color = color;
}
