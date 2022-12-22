#include <iostream>
#include <vector>
#include <random>
#include "Grid.h"

Grid::Grid(int initSize){
    size = initSize;

    for(int i = 0; i < size; i++){
        std::vector<int> vec = {};
        for(int j = 0; j < size; j++){
            vec.push_back(0);
        }
        board.push_back(vec);
    }

    /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,size-1);

    int randX = distr(gen);
    int randY = distr(gen);

    board[randX][randY] = 2;

    int newRandX = distr(gen);
    int newRandY = distr(gen);

    while(newRandX == randX && newRandY == randY){
        newRandX = distr(gen);
        newRandY = distr(gen);
    }

    board[newRandX][newRandY] = 2;
    */

    //test board
    
    board[0][0] = 2;
    board[1][0] = 2;
    board[2][0] = 2;
    board[3][0] = 2;


    board[2][2] = 2;
    board[3][2] = 2;

    board[2][1] = 2;
    board[2][3] = 2;
    
    board[3][1] = 2;

}

    
void Grid::pressedUp(){

    //first we delete every free cells
    for(int i = 0; i < size; i++){  // i are columns, j are rows 
        for(int j = 0; j < size; j++){
            int value  = board[j][i];
            if(value != 0){
                if(j > 0){
                    if(board[j-1][i] == 0){     // cell above is free
                        int finalIdInLane = j;
                        for(int jj = finalIdInLane; jj >= 0; jj--){
                            if(board[jj][i] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n", j, i, finalIdInLane, i);
                        board[j][i] = 0;
                        board[finalIdInLane][i] = value;
                    }
                }
            }
        }
    }

    // now we check is some merge are available
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(j < size - 1){
                int currentValue = board[j][i];
                if(board[j+1][i] == currentValue && currentValue > 0)
                {
                    board[j+1][i] = 0;
                    board[j][i] = 2*currentValue;
                }
            }
            
        }
    }

    // due do merge some space can appear, so one more time
    for(int i = 0; i < size; i++){  // i are columns, j are rows 
        for(int j = 0; j < size; j++){
            int value  = board[j][i];
            if(value != 0){
                if(j > 0){
                    if(board[j-1][i] == 0){     // cell above is free
                        int finalIdInLane = j;
                        for(int jj = finalIdInLane; jj >= 0; jj--){
                            if(board[jj][i] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n", j, i, finalIdInLane, i);
                        board[j][i] = 0;
                        board[finalIdInLane][i] = value;
                    }
                }
            }
        }
    }

}

void Grid::pressedDown(){

    for(int i = 0; i < size; i++){      // i are columns, j are rows
        for(int j = size - 1; j >= 0; j--){
            int value = board[j][i];
            if(value != 0){
                if(j < size - 1){
                    if(board[j+1][i] == 0){     //cell down is free
                        int finalIdInLane = j;
                        for(int jj = finalIdInLane; jj < size; jj++){
                            if(board[jj][i] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n",j,i,finalIdInLane,i);
                        board[j][i] = 0;
                        board[finalIdInLane][i] = value;

                    
                    }
                }
            }
        }
    }

    // now we check is some merge are available
    for(int i = 0; i < size; i++){
        for(int j = size - 1; j > 0; j--){
            int value = board[j][i];
            if(value > 0 && board[j-1][i] == value){
                board[j-1][i] = 0;
                board[j][i] = 2*value;
            }
        }
    }

    // due do merge some space can appear, so one more time
    for(int i = 0; i < size; i++){      // i are columns, j are rows
        for(int j = size - 1; j >= 0; j--){
            int value = board[j][i];
            if(value != 0){
                if(j < size - 1){
                    if(board[j+1][i] == 0){     //cell down is free
                        int finalIdInLane = j;
                        for(int jj = finalIdInLane; jj < size; jj++){
                            if(board[jj][i] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n",j,i,finalIdInLane,i);
                        board[j][i] = 0;
                        board[finalIdInLane][i] = value;

                    
                    }
                }
            }
        }
    }

}

void Grid::pressedLeft(){

    for(int i = 0; i < size; i++){      // i are rows, j are columns
        for(int j = 0; j < size; j++){
            int value = board[i][j];
            if(value != 0){
                if(j > 0){
                    if(board[i][j-1] == 0){
                        int finalIdInLane = j; 
                        for(int jj = finalIdInLane; jj >= 0; jj--){
                            if(board[i][jj] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n",i,j,i,finalIdInLane);
                        board[i][j] = 0;
                        board[i][finalIdInLane] = value;
                    }
                }
            }
        }
    }

    // now we check is some merge are available
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            int value = board[i][j];
            if(value > 0 && board[i][j+1] == value)
            {
                board[i][j+1] = 0;
                board[i][j] = 2*value;
            }    
        }
    }

    // due do merge some space can appear, so one more time
    for(int i = 0; i < size; i++){      // i are rows, j are columns
        for(int j = 0; j < size; j++){
            int value = board[i][j];
            if(value != 0){
                if(j > 0){
                    if(board[i][j-1] == 0){
                        int finalIdInLane = j; 
                        for(int jj = finalIdInLane; jj >= 0; jj--){
                            if(board[i][jj] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n",i,j,i,finalIdInLane);
                        board[i][j] = 0;
                        board[i][finalIdInLane] = value;
                    }
                }
            }
        }
    }

}

void Grid::pressedRight(){

    for(int i = 0; i < size; i++){      // i are rows, j are columns
        for(int j = size - 1; j >= 0; j--){
            int value = board[i][j];
            if(value != 0){
                if(j < size - 1){
                    if(board[i][j+1] == 0){
                        int finalIdInLane = j;
                        for(int jj = finalIdInLane; jj < size; jj++){
                            if(board[i][jj] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n",i,j,i,finalIdInLane);
                        board[i][j] = 0;
                        board[i][finalIdInLane] = value;
                    }
                }
            }
        }
    }

    // now we check is some merge are available
    for(int i = 0; i < size; i++){
        for(int j = size - 1; j >= 0; j--){
            int value = board[i][j];
            if(j > 0 && board[i][j-1] == value){
                board[i][j-1] = 0;
                board[i][j] = 2*value;
            }
            
        }
    }


    for(int i = 0; i < size; i++){      // i are rows, j are columns
        for(int j = size - 1; j >= 0; j--){
            int value = board[i][j];
            if(value != 0){
                if(j < size - 1){
                    if(board[i][j+1] == 0){
                        int finalIdInLane = j;
                        for(int jj = finalIdInLane; jj < size; jj++){
                            if(board[i][jj] == 0){
                                finalIdInLane = jj;
                            }
                        }
                        //printf("(%d,%d) -> (%d,%d)\n",i,j,i,finalIdInLane);
                        board[i][j] = 0;
                        board[i][finalIdInLane] = value;
                    }
                }
            }
        }
    }

}

bool Grid::gameIsLost(){
    return false;
}

std::vector<std::vector<int>> Grid::getBoard(){return board;}

int Grid::getSize(){return size;}

void Grid::asciiOutput(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}