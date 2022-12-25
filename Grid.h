#pragma once 
#include <vector>

class Grid{

    private:
        int size;
        int score = 0;
        std::vector<std::vector<int>> board = {};
    public:
        Grid(int size);
        std::vector<std::vector<int>> getBoard();
        int getSize();
        int idLastFreeCell(int idColumnOrLane, int idInLane, std::string direction);
        int getScore();
        void setScore(int value);
        bool gameIsLost();
        void pressedUp();
        void pressedDown();
        void pressedLeft();
        void pressedRight();
        void asciiOutput();
        void generateNewCell(std::string direction);
};