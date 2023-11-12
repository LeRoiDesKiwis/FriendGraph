#include <fstream>

#include "../headers/Node.h"
#include <string>

#include "../headers/GraphWidget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto graph = new Graph("example.json");
    auto graphWidget = new GraphWidget(graph, nullptr);
    graphWidget->show();

    return QApplication::exec();
}
