//
// Created by leroideskiwis on 11/11/23.
//

#ifndef FRIEND_GRAPH_GRAPHWIDGET_H
#define FRIEND_GRAPH_GRAPHWIDGET_H


#include <QWidget>
#include "Graph.h"

class GraphWidget : public QWidget{
    Q_OBJECT
public:
    explicit GraphWidget(Graph* graph, QWidget* parent = nullptr) : QWidget(parent), graph(graph) {};
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Graph* graph;
    Node* selectedNode = nullptr;
    bool mousePressed = false;
};


#endif //FRIEND_GRAPH_GRAPHWIDGET_H
