#include "Themodel.h"
#include "algorithm"
#include <iostream>
using namespace std;

Themodel::Themodel() : grid(5, vector<color>(5, blank)) {
    srand(time(NULL));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j] = color((rand() % 3)+1);
        }
    }
}

bool Themodel::gameOver(){
    bool status = true;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] != blank)
                status = false;
        }
    }
    return status;
}

vector<vector<color>> Themodel::getGrid() {
    return grid;
}



void Themodel::drop(){
    for(int j = 0; j < grid[0].size(); ++j){
        int width = grid.size();
        int height = grid[0].size();

        for (int col = 0; col < width; ++col) {
            int emptyRow = height - 1;
            for (int row = height - 1; row >= 0; --row) {
                if (grid[row][col] != blank) {
                    swap(grid[row][col], grid[emptyRow][col]);
                    --emptyRow;
                }
            }
        }
    }
}

void Themodel::select(int x, int y) {
    // Check if (x, y) is out of bounds or already blank
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == blank) {
        return;
    }

    color target = grid[x][y]; 
    grid[x][y] = blank;         

    // getting cardinals
    if (x > 0 && grid[x - 1][y] == target) {
        select(x - 1, y);  // north
    }
    if (x < grid.size() - 1 && grid[x + 1][y] == target) {
        select(x + 1, y);  // south
    }
    if (y > 0 && grid[x][y - 1] == target) {
        select(x, y - 1);  // west
    }
    if (y < grid[0].size() - 1 && grid[x][y + 1] == target) {
        select(x, y + 1);  // east
    }
}
