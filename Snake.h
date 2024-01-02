//
// Created by Caden Wells on 11/23/2021.
//
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Food.h"
using namespace std;
using namespace sf;

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

class Snake {
private:
    string _name;
    static const int _size = 30;
    int _xPos;
    int _yPos;
    int _score;

public:
    //Default Constructor
    Snake();

    //Getters
    string getName() const;
    int getSize() const;
    int getXPos() const;
    int getYPos() const;
    int getScore() const;

    //Setters
    void setName(string name);
    void setX(int xPos);
    void setY(int yPos);

    //Updates snake's position in each direction
    void updateSnakePosUp();
    void updateSnakePosDown();
    void updateSnakePosLeft();
    void updateSnakePosRight();

    //Draws Snake
    CircleShape drawSnake(int xPos, int yPos);

    //Increment numGames and numScore
    void addOneScore();

    //Method to check whether the position of the food and the position of the snake are the same
    //if the method returns true, then the food disappears, the snake grows my one, and the
    //food appears in a new position on the board
    bool checkSnakeAndFoodPos(Food& food);

};

#endif //SNAKE_SNAKE_H
