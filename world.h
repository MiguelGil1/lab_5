#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <fstream>
using namespace std;
class world{
public:
    world();
    ~world();

    int * readWorld(string file);
private:
    int worldMatrix[13][31];
};

#endif // WORLD_H
