//
// Created by leroideskiwis on 10/11/23.
//

#include "../headers/Edge.h"
#include "../headers/Graph.h"

std::string Edge::toString(){
    return std::format("{} --[{}]--> {}", from.toString(), weight, to.toString());
}

void Edge::draw(QPainter *pPainter, Graph *graph) {
    pPainter->setPen(QPen(Qt::black, weight, Qt::SolidLine, Qt::RoundCap));
    Location middleFrom = from.getMiddle();
    Location middleTo = to.getMiddle();
    pPainter->drawLine(middleFrom.x, middleFrom.y, middleTo.x, middleTo.y);
}

void Edge::changeWeight(int weight) {
    this->weight = weight;
};
