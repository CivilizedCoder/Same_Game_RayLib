#include "raylib.h"
#include "View.h"
#include <vector>

using namespace std;

View::View(Themodel& b) {
    board = &b;
}

void View::display() {
    vector<vector<color>> grid = board->getGrid();

    int rows = grid.size();
    int cols = grid[0].size();
    int squareSize = 100;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int posX = col * squareSize;
            int posY = row * squareSize;

            //this would be simpler if i used all caps i geues...
            Color raylibColor = (grid[row][col] == red) ? RED : (grid[row][col] == blue) ? BLUE : (grid[row][col] == green) ? GREEN : GRAY;
            DrawRectangle(posX, posY, squareSize, squareSize, raylibColor);
        }
    }
}
