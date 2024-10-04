#include <iostream>
#include "Themodel.h"
#include "View.h"
#include "raylib.h"
#include <string>

using namespace std;

int main() {
    Themodel* m = new Themodel();
    View view(*m);
    bool gameOver = false;
    int moves = 0;

    int squareSize = 100;
    vector<vector<color>> grid = m->getGrid();
    int rows = grid.size();
    int cols = grid[0].size();

    InitWindow(cols * squareSize, rows * squareSize, "Game");
    SetTargetFPS(60);

    string scoreMessage;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        string scoreMessage = "Score: " + to_string(moves);



        if (!gameOver) {
            view.display();
            DrawText(scoreMessage.c_str(), 10, 10, 20, BLACK);


            //wait for click
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();

                //find click loc
                int x = static_cast<int>(mousePos.y / squareSize);  // Row
                int y = static_cast<int>(mousePos.x / squareSize);  // Column

                //bounds checking
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    m->select(x, y);
                    m->drop(); 
                    moves++;
                }
            }

            gameOver = m->gameOver();
        }

        if (gameOver) {
            scoreMessage = "     Game Over!\n\nFinal Score: " + to_string(moves) + ", GG!";//game over
            float startTime = GetTime();
            while (GetTime() - startTime < 5.0 && !WindowShouldClose()) { //time to see
                BeginDrawing();
                ClearBackground(RAYWHITE);
                view.display();
                DrawText(scoreMessage.c_str(), 150, 220, 20, BLACK);
                EndDrawing();
            }

            break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
