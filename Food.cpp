//
// Created by Caden Wells on 11/24/2021.
//

#include "Food.h"

//Default Constructor
Food::Food() {
    _size = 30;
    _xPos = 320;
    _yPos = 320;
}

//Getters
int Food::getSize() {
    return _size;
}

int Food::getXPos() {
    return _xPos;
}

int Food::getYPos() {
    return _yPos;
}

//Sets random food position
void Food::setFoodPos() {
    _xPos = rand() % 400;
    _yPos = rand() % 400;
}

//Draws food
CircleShape Food::drawFood(int xPos, int yPos) {
    CircleShape food(_size, 4);
    food.setFillColor(Color::Black);
    food.rotate(45);
    food.setPosition(xPos, yPos);
    return food;
}