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
    //fix référence indéfinie vers « vtable for GraphWidget »
    explicit GraphWidget(Graph* graph, QWidget* parent = nullptr) : QWidget(parent), graph(graph) {};
    void paintEvent(QPaintEvent* event) override;
    virtual ~GraphWidget() {};

private:
    Graph* graph;
};


#endif //FRIEND_GRAPH_GRAPHWIDGET_H
