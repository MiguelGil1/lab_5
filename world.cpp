#include "world.h"

array <array<int,31>,13> world::readWorld(string file){
    string line = "";
    string valor = "";
    int contRow = 0;
    ifstream infile;
    infile.open(file);
    while(!infile.eof()){
        infile >> line;
        for(int  i = 0; i < int(line.length()); i++){
            valor[0] = line[i];
            worldMatrix[contRow][i] = (stoi(valor));
        }
        contRow++;
    }
    return worldMatrix;
    //investigar SetSceneRect(4parametros);
}

/*void world::readWorld(string file){
    string line = "";
    string valor = "";
    int contRow = 0;
    ifstream infile;
    infile.open(file);
    while(!infile.eof()){
        infile >> line;
        cout << line << endl;
        for(int  i = 0; i < int(line.length()); i++){
            valor[0] = line[i];
            worldMatrix[contRow][i] = stoi(valor);
        }
        contRow++;
    }
    //return worldMatrix;
    //investigar SetSceneRect(4parametros);
}*/

/*world::~world(){
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 31; j++){
            worldMatrix[i][j] = 0;
        }
    }
}*/
