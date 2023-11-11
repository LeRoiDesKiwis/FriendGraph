//
// Created by leroideskiwis on 10/11/23.
//

#include "Edge.h"

std::string Edge::toString(){
    return std::format("{} --[{}]--> {}", from.toString(), weight, to.toString());
}

void Edge::draw(QPainter *pPainter) {
    pPainter->setPen(QPen(Qt::black, weight, Qt::SolidLine, Qt::RoundCap));
    pPainter->drawLine(from.getLocation().x, from.getLocation().y, to.getLocation().x, to.getLocation().y);
};
