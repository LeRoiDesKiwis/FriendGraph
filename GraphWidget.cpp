//
// Created by leroideskiwis on 11/11/23.
//

#include "GraphWidget.h"

void GraphWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    graph->draw(&painter);
}
