#pragma once
#include "point.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

//game class that will play the doodle jump game
//this includes all of the logic involved with the game
struct Game
{
    void playGame();
    void generatePlatforms(point plat[20]);
    void loadTextures(Texture &t1, Texture &t2, Texture &t3);
    void moveCharacter(int &x);
    void addAndMovePlats(int &y, int &h, float &dy, point plat[20]);
    void drawSprites(Sprite &sBackground, Sprite &sPlat, Sprite &sPers, RenderWindow &app, point plat[20]);
    void jump(float &dy, int &x, int &y, point plat[20]);
};