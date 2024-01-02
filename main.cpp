/*
 * /* CSCI 261: Final Project: Snake
 * Author: Caden Wells
 * Skip Days Used: 4
 * Skip Days Remaining: 1
 * Resources Used: Instructions on Canvas, UML Diagram
 *
 * Description: This final project recreates a simple version of the classic computer game, snake.
 * The program uses either the WASD or arrow keys to control a snake around a board in order to eat
 * pieces of good to grow longer. The food is generated at random positions and the game ends
 * when the snake hits one of the walls.
 */

#include <fstream>
#include <vector>
#include "Snake.h"
using namespace std;

int main() {
    //Creates Snake Object
    Snake player;
    //Creates Food Object
    Food food;

    //Creates and opens a file to write out player data such as name and score
    ofstream outputFile;

    //Opens text file for writing
    outputFile.open("snakeData.txt");

    //Checks for errors
    if(outputFile.fail()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    //Asks user to enter their name and then sets the name of the snake to their name
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    player.setName(playerName);

    //Creates a vector of snakes to control the length of the snake as it eats food
    vector<Snake> totalSnake;

    //Adds initial snake object to vector
    totalSnake.push_back(player);

    //Counter to control the loop speed for the snake's movement
    int counter = 0;

    //Boolean values for loops that continually update snake's position
    bool moveUp = false;
    bool moveDown = false;
    bool moveRight = false;
    bool moveLeft = false;

    //Boolean to determine whether the game has ended
    bool gameOver = false;

    //Sets initial position of food
    food.setFoodPos();

    RenderWindow window( VideoMode(640, 640), "Snake" );

    while( window.isOpen() ) {
        window.clear( Color{0, 153, 0});

        if(!gameOver) {
            //Draws food
            window.draw(food.drawFood(food.getXPos(), food.getYPos()));

            //Draws Snake
            for(int i = 0; i < totalSnake.size(); i++) {
                window.draw(totalSnake.at(i).drawSnake(totalSnake.at(i).getXPos(), totalSnake.at(i).getYPos()));
            }

            if(moveUp) {
                if(counter % 30 == 0) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        totalSnake.at(i).updateSnakePosUp();
                    }
                }
            }
            if(moveDown) {
                if(counter % 30 == 0) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        totalSnake.at(i).updateSnakePosDown();
                    }
                }
            }
            if(moveLeft) {
                if(counter % 30 == 0) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        totalSnake.at(i).updateSnakePosLeft();
                    }
                }
            }
            if(moveRight) {
                if(counter % 30 == 0) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        totalSnake.at(i).updateSnakePosRight();
                    }
                }
            }

            //Checks the position of the food relative to the snake to determine if the snake has eaten the food
            if(totalSnake.at(0).checkSnakeAndFoodPos(food)) {
                food.setFoodPos();
                Snake snakeAddition;
                if(moveUp) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        snakeAddition.setX(totalSnake.at(i).getXPos());
                        snakeAddition.setY(totalSnake.at(i).getYPos() + player.getSize() + 15);
                    }
                }
                else if(moveDown) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        snakeAddition.setX(totalSnake.at(i).getXPos());
                        snakeAddition.setY(totalSnake.at(i).getYPos() - player.getSize() - 15);
                    }
                }
                else if (moveLeft) {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        snakeAddition.setX(totalSnake.at(i).getXPos() + player.getSize() + 15);
                        snakeAddition.setY(totalSnake.at(i).getYPos());
                    }
                }
                else {
                    for(int i = 0; i < totalSnake.size(); i++) {
                        snakeAddition.setX(totalSnake.at(i).getXPos() - player.getSize() - 15);
                        snakeAddition.setY(totalSnake.at(i).getYPos());
                    }
                }
                player.addOneScore();
                totalSnake.push_back(snakeAddition);
            }
        }

        //Checks the position of the snake to see if it's at any of the edges and displays game over text
        if((totalSnake.at(0).getXPos() == 15) || (totalSnake.at(0).getXPos() == 620) || (totalSnake.at(0).getYPos() == -25) || (totalSnake.at(0).getYPos() == 585)) {
            gameOver = true;
            Font font;
            font.loadFromFile("data/arial.ttf");
            Text gameOver("Game Over", font);
            gameOver.setCharacterSize(48);
            gameOver.setStyle(Text::Bold);
            gameOver.setFillColor(Color::Black);
            gameOver.setPosition(200, 250);
            window.draw(gameOver);
        }


        window.display();

        Event event;
        while( window.pollEvent(event) ) {
            if( event.type == Event::Closed ) {
                window.close();
            }
            if(event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::W:
                        moveUp = true;
                        moveDown = false;
                        moveLeft = false;
                        moveRight = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at( i - 1).getXPos() + 15);
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos() + totalSnake.at(i - 1).getSize() + 15);
                        }
                        break;
                    case Keyboard::Up:
                        moveUp = true;
                        moveDown = false;
                        moveLeft = false;
                        moveRight = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos());
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos() + totalSnake.at(i - 1).getSize() + 15);
                        }
                        break;
                    case Keyboard::S:
                        moveDown = true;
                        moveUp = false;
                        moveLeft = false;
                        moveRight = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos());
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos() - totalSnake.at(i - 1).getSize() - 15);
                        }
                        break;
                    case Keyboard::Down:
                        moveDown = true;
                        moveUp = false;
                        moveLeft = false;
                        moveRight = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos());
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos() - totalSnake.at(i - 1).getSize() - 15);
                        }
                        break;
                    case Keyboard::A:
                        moveLeft = true;
                        moveUp = false;
                        moveDown = false;
                        moveRight = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos() + totalSnake.at(i - 1).getSize() + 15);
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos());
                        }
                        break;
                    case Keyboard::Left:
                        moveLeft = true;
                        moveUp = false;
                        moveDown = false;
                        moveRight = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos() + totalSnake.at(i - 1).getSize() + 15);
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos());
                        }
                        break;
                    case Keyboard::D:
                        moveRight = true;
                        moveUp = false;
                        moveDown = false;
                        moveLeft = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos() - totalSnake.at(i - 1).getSize() - 15);
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos());
                        }
                        break;
                    case Keyboard::Right:
                        moveRight = true;
                        moveUp = false;
                        moveDown = false;
                        moveLeft = false;
                        for(int i = 1; i < totalSnake.size(); i++) {
                            totalSnake.at(i).setX(totalSnake.at(i - 1).getXPos() - totalSnake.at(i - 1).getSize() - 15);
                            totalSnake.at(i).setY(totalSnake.at(i - 1).getYPos());
                        }
                        break;
                }
            }
        }
        counter++;
    }

    //After the game has been played, writes out the player's data
    outputFile << "Player: " << player.getName() << endl;
    outputFile << "Score: " << player.getScore() << endl;

    //Closes file
    outputFile.close();

    return EXIT_SUCCESS;
}
