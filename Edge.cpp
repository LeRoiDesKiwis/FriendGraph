//
// Created by leroideskiwis on 10/11/23.
//

#include "Edge.h"

std::string Edge::toString(){
    return std::format("{} --[{}]--> {}", from.toString(), weight, to.toString());
};
