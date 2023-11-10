#include <iostream>

#include "Node.h"
#include <string>

int main() {
    Location location = {0, 0};
    const auto node = new Node("LeRoiDesKiwis", location);
    node->draw();
    return 0;
}
