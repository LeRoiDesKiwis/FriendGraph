//
// Created by leroideskiwis on 11/11/23.
//

#include <iostream>
#include "../headers/GraphWidget.h"
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

void GraphWidget::addEdge(QMouseEvent* event){
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
                return;
            }
            bool ok;
            QString text = QInputDialog::getText(this, tr("Add Node"),
                                                 tr("Node name:"), QLineEdit::Normal,
                                                 "", &ok);
            if (ok && !text.isEmpty()) {
                Node *node = new Node(text.toStdString(), {event->pos().x(), event->pos().y()});
                graph->addNode(node);
            }
        }
    }
    else if(event->button() == Qt::RightButton) {
        if(selectedNode != nullptr) {
            std::cout << "not null" << std::endl;
        }
        addEdge(event);
    }
    update();
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event) {
    if(selectedNode != nullptr && mousePressed) {
        Location loc = selectedNode->adaptMiddle({event->pos().x(), event->pos().y()});
        selectedNode->getLocation().x = loc.x;
        selectedNode->getLocation().y = loc.y;
        update();
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
}

void GraphWidget::keyPressEvent(QKeyEvent *event) {
    //ctrl s for save
    if(event->key() == Qt::Key_S && event->modifiers() == Qt::ControlModifier) {
        std::cout << "saving" << std::endl;
        graph->save("example.json");
    }
}