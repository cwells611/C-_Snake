//
// Created by Caden Wells on 11/23/2021.
//

#include "Snake.h"



//Default Constructor
Snake::Snake() {
    _name = "Snake";
    _xPos = 320;
    _yPos = 320;
    _score = 0;
}

//Getters
string Snake::getName() const {
    return _name;
}

int Snake::getSize() const {
    return _size;
}

int Snake::getXPos() const {
    return _xPos;
}
int Snake::getYPos() const {
    return _yPos;
}

int Snake::getScore() const {
    return _score;
}

//Setters
void Snake::setName(string name) {
    if(isalpha(name.at(0))) {
        _name = name;
    }
    else {
        string name;
        cout << "Enter your name: " << endl;
        cin >> name;
        setName(name);
    }
}

void Snake::setX(int xPos) {
    _xPos = xPos;
}
void Snake::setY(int yPos) {
    _yPos = yPos;
}

//Update's snake position on the board
void Snake::updateSnakePosUp() {
    _yPos -= 1;
}

void Snake::updateSnakePosDown() {
    _yPos += 1;
}

void Snake::updateSnakePosLeft() {
    _xPos -= 1;
}

void Snake::updateSnakePosRight() {
    _xPos += 1;
}

//Draws Snake
CircleShape Snake::drawSnake(int xPos, int yPos) {
    CircleShape snake(_size, 4);
    snake.setPosition(xPos, yPos);
    snake.setFillColor(Color::Red);
    snake.rotate(45);
    return snake;
}

bool Snake::checkSnakeAndFoodPos(Food& food) {
    for(int i = 0; i < _size; i++) {
        if((getXPos() == food.getXPos() + i) && (getYPos() == food.getYPos() + i)) {
            return true;
        }
    }
    return false;
}

//Increments the score
void Snake::addOneScore() {
    _score++;
}


