//
// Created by leroideskiwis on 10/11/23.
//

#include "Edge.h"

std::string Edge::toString(){
    return std::format("{} --[{}]--> {}", from.toString(), weight, to.toString());
}

void Edge::draw(QPainter *pPainter) {
    pPainter->setPen(QPen(Qt::black, weight, Qt::SolidLine, Qt::RoundCap));
    Location middleFrom = from.getMiddle();
    Location middleTo = to.getMiddle();
    pPainter->drawLine(middleFrom.x, middleFrom.y, middleTo.x, middleTo.y);
};
