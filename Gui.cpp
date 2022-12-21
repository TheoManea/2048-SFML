#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>
#include "Grid.h"
#include "Gui.h"

using namespace std;

void drawBoard(sf::RenderWindow& window, Grid grid){

    //this draw the grey background
    sf::Color bgColor(187,173,160);
    sf::RectangleShape back(sf::Vector2f(400,400));
    back.setPosition(300,50);
    back.setFillColor(bgColor);
    window.draw(back);

    //now let's draw cells

    //first define a set of gradient color 
    map<string,sf::Color> colorPalette;
    sf::Color myColor2(255, 186, 8);
    sf::Color myColor4(250, 163, 7);
    sf::Color myColor8(244, 140, 6);
    sf::Color myColor16(232, 93, 4);
    sf::Color myColor32(220, 47, 2);
    sf::Color myColor64(208, 0, 0);
    sf::Color myColor128(157, 2, 8);
    sf::Color myColor256(157, 2, 8);
    sf::Color myColor512(55, 6, 23);
    sf::Color myColor1024(55, 6, 23);
    sf::Color myColor2048(3, 7, 30);

    colorPalette["2"] = myColor2;
    colorPalette["4"] = myColor4;
    colorPalette["8"] = myColor8;
    colorPalette["16"] = myColor16;
    colorPalette["32"] = myColor32;
    colorPalette["64"] = myColor64;
    colorPalette["128"] = myColor128;
    colorPalette["256"] = myColor256;
    colorPalette["512"] = myColor512;
    colorPalette["1024"] = myColor1024;
    colorPalette["2048"] = myColor2048;

    int paddingCells = 10;
    int sizeGrid = grid.getSize() ;
    int sizeCell = (380 - (sizeGrid - 1)*paddingCells ) / sizeGrid;
    sf::Color cellColor(122, 118, 114);

    
    for(int i = 0; i < sizeGrid; i++){
        for(int j = 0; j < sizeGrid; j++){
            std::vector<std::vector<int>> board = grid.getBoard();
            int value = board[i][j];
            auto s = std::to_string(value);
            sf::RectangleShape cell(sf::Vector2f(sizeCell,sizeCell));
            cell.setFillColor(colorPalette[s]);
            cell.setPosition(300 + paddingCells + paddingCells*j + sizeCell*j, 50 + paddingCells + paddingCells*i + sizeCell*i);
            window.draw(cell);
        }
    }
    

    //draw scores of each cells 
    
    sf::Font font;
    if (!font.loadFromFile("Roboto.ttf"))
    {
        printf("Error while loading font...");
    }

    for(int foo = 0; foo < sizeGrid; foo++){
        for(int bar = 0; bar < sizeGrid; bar++){
            int value = grid.getBoard()[foo][bar];
            if(value > -1){
                auto s = std::to_string(value);
                sf::Text text;
                text.setFont(font); 
                text.setString(s);
                text.setCharacterSize(40);
                text.setFillColor(sf::Color::White);
                text.setPosition( 300 + paddingCells + paddingCells*bar + sizeCell*bar,50 + paddingCells + paddingCells*foo + sizeCell*foo);
                window.draw(text);
            }
            
        }
    }

    



}