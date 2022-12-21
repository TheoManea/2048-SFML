#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.cpp"
#include "Gui.cpp"

#define width 1000
#define height 500

int main()
{
    Grid grid(4);
    grid.asciiOutput();

    sf::RenderWindow window(sf::VideoMode(width, height), "2048");

    while (window.isOpen())
    {
       

        sf::Event event;
        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        grid.pressedUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        grid.pressedDown();
                    }
                    else if (event.key.code == sf::Keyboard::Right)
                    {
                        grid.pressedRight();
                    }
                    else if (event.key.code == sf::Keyboard::Left)
                    {
                        grid.pressedLeft();
                    }
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }

        window.clear();

        // here everything will be drawn
        drawBoard(window,grid);

        window.display();
    }

    return 0;
}