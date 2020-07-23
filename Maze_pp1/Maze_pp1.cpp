// Maze_pp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // 2D maze # is a wall, ' ' is a movable location, X is the entrance, O is the exit.
    const char walls[15][15] = { { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { 'X', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', 'O' },
                                 { '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#' },
                                 { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };

    // Player location is defined by the x vaule of the array above.
    int playerLocationX = 0;
    int playerLocationY = 1;

   

    //Ask player to move again, until they exit the maze.
    while (walls[playerLocationY][playerLocationX] != 'O')
    {
        // Print maze array to the screen.
        // First for loop is for y axis index 
        for (int y = 0; y < 15; ++y)
        {
            // Second for loop is for X axis index
            for (int x = 0; x < 15; ++x)
            {
                // Determining player icon location by comparing XY indices with player location
                if ((playerLocationX == x) and (playerLocationY == y))
                {
                    std::cout << "P";
                }
                else
                {
                    // print maze vaule at specific location
                    std::cout << walls[y][x];
                }

            }
            // printing new line
            std::cout << std::endl;
        }

        //Request input from the player, storing the input character.
        std::cout << "Please use 'A' 'W' 'S' or 'D' to move player icon." << std::endl;
        char playerInput;
        std::cin >> playerInput;


        //Assign cardinal directs to keys 'A' 'S' 'D' 'W'
        int newPlayerLocationX = playerLocationX;
        int newPlayerLocationY = playerLocationY;
        switch (playerInput)
        {
        case 'A':
        case 'a':
            newPlayerLocationX -= 1; // -= subtracts from and sets the varible
            break;
        case 'S':
        case 's':
            newPlayerLocationY += 1;
            break;
        case 'D':
        case 'd':
            newPlayerLocationX += 1;
            break;
        case 'W':
        case 'w':
            newPlayerLocationY -= 1;
            break;
        }

        //Comparing cases with array walls for unallowable moves
        //Checking for any input that would take player out of the array
        if ((newPlayerLocationX < 0) or (newPlayerLocationX > 14) or (newPlayerLocationY < 0) or (newPlayerLocationY > 14))
        {
            std::cout << "Invalid entry, please try again." << std::endl;
        }
        //Checking for any input that would overlap the '#' or wall in the array
        else if (walls[newPlayerLocationY][newPlayerLocationX] == '#')
        {
            std::cout << "You've hit a wall! Try again!" << std::endl;
        }

        //Assuming all unallowable moves were caught, then move must be allowable.
        else
        {
            //Rewriting player location to the allowable new location. 
            playerLocationX = newPlayerLocationX;
            playerLocationY = newPlayerLocationY;
        }

    }

    //Player has exited maze - game over
    std::cout << "Game Over" << std::endl;

}