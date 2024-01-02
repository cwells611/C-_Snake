//
// Created by Caden Wells on 11/24/2021.
//
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

class Food{
private:
    int _size;
    int _xPos;
    int _yPos;

public:
    //Default constructor
    Food();

    //Getters
    int getSize();
    int getXPos();
    int getYPos();

    //Sets random position of food
    void setFoodPos();

    //Draw food
    CircleShape drawFood(int xPos, int yPos);

};

#endif //SNAKE_FOOD_H
