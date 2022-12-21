#pragma once 
#include <vector>

class Grid{

    private:
        int size;
        std::vector<std::vector<int>> board = {};
    public:
        Grid(int size);
        std::vector<std::vector<int>> getBoard();
        int getSize();
        int idLastFreeCell(int idColumnOrLane, int idInLane, std::string direction);
        bool gameIsLost();
        void pressedUp();
        void pressedDown();
        void pressedLeft();
        void pressedRight();
        void asciiOutput();
};