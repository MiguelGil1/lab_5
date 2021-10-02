#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>
#include <array>

using namespace std;
class world{
public:
    //~world();

    array <array<int,31>,13> readWorld(string file);
    //void readWorld(string file);
private:
    array <array<int,31>,13> worldMatrix;
};

#endif // WORLD_H
