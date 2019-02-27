#include "game.h"

//this is the play game function
void Game::playGame()
{
  //this is for generating random numbers
  //a different way of seeding should be added eventually.
  srand(time(0));

  //create the window for the game
  RenderWindow app(VideoMode(400, 533), "Doodle Game!");
  app.setFramerateLimit(60);

  //create the textures
  Texture t1, t2, t3;
  //load the textures in 
  loadTextures(t1,t2,t3);

  //creat sprites
  Sprite sBackground(t1), sPlat(t2), sPers(t3);

  //create an array of platforms (points)
  point plat[20];

  //call function to generate platforms
  generatePlatforms(plat);

  //create variables for keeping track of objects
  int x = 100, y = 100, h = 200;
  float dx = 0, dy = 0;

  //game loop
  while (app.isOpen()) {
    Event e;
    while (app.pollEvent(e)) {
      if (e.type == Event::Closed)
        app.close();
    }

    //this will move the character left and right
    moveCharacter(x);

    dy += 0.2; //this seems to act like "gravity"
    y += dy;
    if (y > 500)
      dy = -10;

    //move platforms and add new ones
    addAndMovePlats(y, h, dy, plat);

    //this will make the character jump if they hit a platform
    jump(dy, x, y, plat);

    //set position of sPers
    sPers.setPosition(x, y);

    //this will draw the sprites
    drawSprites(sBackground, sPlat, sPers, app, plat);

    //display the app
    app.display();
  }
}

//function for generating platforms
void Game::generatePlatforms(point plat[20])
{
  for (int i = 0; i < 10; i++) {
    plat[i].x = rand() % 400;
    plat[i].y = rand() % 533;
  }
}

//loads the textures in
void Game::loadTextures(Texture &t1, Texture &t2, Texture &t3)
{
  t1.loadFromFile("../../images/background.png");
  t2.loadFromFile("../../images/platform.png");
  t3.loadFromFile("../../images/doodle.png");
}

//move the character left and right
void Game::moveCharacter(int &x)
{
  if (Keyboard::isKeyPressed(Keyboard::Right))
    x += 3;
  if (Keyboard::isKeyPressed(Keyboard::Left))
    x -= 3;
}

//move platforms and add "new" ones
//if one of them goes offscreen
void Game::addAndMovePlats(int &y, int &h, float &dy, point plat[20])
{
  if (y < h)
      for (int i = 0; i < 10; i++) {
        y = h;
        plat[i].y = plat[i].y - dy;
        if (plat[i].y > 533) {
          plat[i].y = 0;
          plat[i].x = rand() % 400;
        }
      }
}

//this will draw the sprites on the app
void Game::drawSprites(Sprite &sBackground, Sprite &sPlat, Sprite &sPers, RenderWindow &app, point plat[20])
{

  app.draw(sBackground);
  app.draw(sPers);
  for (int i = 0; i < 10; i++) {
    sPlat.setPosition(plat[i].x, plat[i].y);
    app.draw(sPlat);
  }
}

//this will make the character jump if they hit a platform
void Game::jump(float &dy, int &x, int &y, point plat[20])
{
  for (int i = 0; i < 10; i++)
      if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) &&
          (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
        dy = -10; //this changes the jump height
}