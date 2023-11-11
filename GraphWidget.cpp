//
// Created by leroideskiwis on 11/11/23.
//

#include <iostream>
#include "GraphWidget.h"
#include <QMouseEvent>
#include <QInputDialog>
#include <QLineEdit>
#include <QMenu>

bool isNumber(const std::string& s)
{
    return std::all_of(s.begin(), s.end(), ::isdigit);
}

void GraphWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    graph->draw(&painter);
}

void GraphWidget::mousePressEvent(QMouseEvent *event) {

    if(event->button() == Qt::LeftButton){
        mousePressed = true;
        bool found = false;
        for(auto node : graph->getNodes()) {
            std::cout << node->toString() << std::endl;
            if(node->isClicked({event->pos().x(), event->pos().y()})) {
                std::cout << " [SELECTED] " << std::flush;
                if(selectedNode != nullptr) selectedNode->setColor(Qt::black);
                selectedNode = node;
                node->setColor(Qt::red);
                found = true;
                break;
            }

        }
        if(!found){
            if(selectedNode != nullptr) {
                selectedNode->setColor(Qt::black);
                selectedNode = nullptr;
            }
            bool ok;
            QString text = QInputDialog::getText(this, tr("Add Node"),
                                                 tr("Node name:"), QLineEdit::Normal,
                                                 "", &ok);
            if (ok && !text.isEmpty()) {
                // Add your node here using the text as the name
                Node *node = new Node(text.toStdString(), {event->pos().x(), event->pos().y()});
                graph->addNode(node);
            }
        }
    }
    else if(event->button() == Qt::RightButton) {
        if(selectedNode != nullptr) {
            std::cout << "not null" << std::endl;
            for(auto node : graph->getNodes()) {
                std::cout << node->toString() << std::endl;
                if(node->isClicked({event->pos().x(), event->pos().y()})) {
                    std::cout << "new edge" << " from " << selectedNode->toString() << " to " << node->toString() << std::endl;
                    bool ok;
                    QString text = QInputDialog::getText(this, tr("Link two nodes"),
                                                         tr("Edge size: "), QLineEdit::Normal,
                                                         "", &ok);
                    if (ok && !text.isEmpty()) {
                        // Add your node here using the text as the name
                        int size = 1;
                        if(isNumber(text.toStdString())) size = std::stoi(text.toStdString());
                        Edge* edge = new Edge(*selectedNode, *node, size);
                        graph->addEdge(edge);
                    }
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
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
}