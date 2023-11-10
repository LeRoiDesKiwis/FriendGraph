//
// Created by leroideskiwis on 10/11/23.
//
#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>

typedef struct {
    int x;
    int y;
} Location;

class Node {
    public:
        Node(std::string& title, int id, Location& location);

        void draw();
        std::string& getTitle();
        int getId();
        Location& getLocation;

    private:
        std::string title;
        int id;
        Location location;

};

#endif //NODE_H
