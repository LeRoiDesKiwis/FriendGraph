//
// Created by leroideskiwis on 11/11/23.
//

#include <iostream>
#include "GraphWidget.h"
#include <QMouseEvent>

void GraphWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    graph->draw(&painter);
}

void GraphWidget::mousePressEvent(QMouseEvent *e) {

    if(e->button() == Qt::LeftButton){
        mousePressed = true;
        bool found = false;
        for(auto node : graph->getNodes()) {
            std::cout << node->toString() << std::endl;
            if(node->isClicked({e->pos().x(), e->pos().y()}, 20)) {
                std::cout << " [SELECTED] " << std::flush;
                if(selectedNode != nullptr) selectedNode->setColor(Qt::black);
                selectedNode = node;
                node->setColor(Qt::red);
                found = true;
                break;
            }

        }
        if(!found && selectedNode != nullptr){
            selectedNode->setColor(Qt::black);
            selectedNode = nullptr;
        }
    }
    else if(e->button() == Qt::RightButton) {
        std ::cout << selectedNode->toString() << std::endl;
        if(selectedNode != nullptr) {
            std::cout << "not null" << std::endl;
            for(auto node : graph->getNodes()) {
                std::cout << node->toString() << std::endl;
                if(node->isClicked({e->pos().x(), e->pos().y()}, 20)) {
                    std::cout << "new edge" << " from " << selectedNode->toString() << " to " << node->toString() << std::endl;
                    graph->addEdge(*selectedNode, *node);
                    break;
                }
            }
        }
    }
    update();
}
void GraphWidget::mouseMoveEvent(QMouseEvent *event) {
    if(selectedNode != nullptr && mousePressed) {
        selectedNode->getLocation().x = event->pos().x();
        selectedNode->getLocation().y = event->pos().y();
        update();
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
}
