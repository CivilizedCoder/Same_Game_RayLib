#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "color.h"
using namespace std;
class Themodel{
private:
    vector<vector<color>> grid;
public:
    Themodel();
    void select(int x, int y);
    vector<vector<color>> getGrid();
    bool gameOver();
    void drop();

};

#endif