#include "game.h"
#include <iostream> 

// This struct is used to detect and handle events
struct events
{
  
  private:
    sf::RenderWindow *window;

  public:
    events(sf::RenderWindow& w)
      : window(&w)
    {}

    void eventPoll()
    {
      sf::Event e;
      while (window->pollEvent(e))
      {
        eventType(e);
      }

    }

    void eventType(Event const& e)
    {
      switch (e.type)
      {
        case Event::Closed:
          return window->close();
      }
    }
};

// This is the play game function
void Game::playGame()
{
  // This is for generating random numbers
  // A different way of seeding should be added eventually.
  srand(time(0));

  //Create boolean for the game loop for game over
  bool gameOver = false;

  // Create the window for the game
  RenderWindow app(VideoMode(400, 533), "Doodle Game!");
  app.setFramerateLimit(60);

  // Create the textures
  Texture t1, t2, t3, t4;
  // Load the textures in 
  loadTextures(t1,t2,t3, t4);

  // Create sprites
  Sprite sBackground(t1), sPlat(t2), sPers(t3), sRedPlat(t4);

  // Create an array of platforms (points)
  point plat[20];

  // Create the location of the bad platform (red)
  point redPlat;
  redPlat.x = rand() % 400;
  redPlat.y = rand() % 533;

  // Call function to generate platforms
  generatePlatforms(plat);

  // Create variables for keeping track of objects
  int x = 100, y = 100, h = 200;
  float dx = 0, dy = 0;

  // Game loop
  while (app.isOpen() && gameOver == false) {
    
    // Create event listener and handler
    events events(app);

    // Detect Events
    events.eventPoll();

    // This will move the character left and right
    moveCharacter(x);

    dy += 0.2; // This seems to act like "gravity"
    y += dy;
    if (y > 500)
      dy = -10;

    // Move platforms and add new ones
    if (y < h)
    {
      for (int i = 0; i < 10; i++) {
        y = h;
        plat[i].y = plat[i].y - dy;
        if (plat[i].y > 533) {
          plat[i].y = 0;
          plat[i].x = rand() % 400;
        }
      }

      // This is for the red platform (fall through the plat if
      // the doodle steps on it)
        redPlat.y = redPlat.y - dy;
        if (redPlat.y > 533)
        {
          redPlat.y = 0;
          redPlat.x = rand() % 400;
        }
    }

    // This will make the character jump if they hit a platform
    for (int i = 0; i < 10; i++)
      if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) &&
          (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
        dy = -10; // This changes the jump height

    // Set position of sPers
    sPers.setPosition(x, y);

    // If the character falls to the bottom game over
    if (sPers.getPosition().y > 500)
    {
      gameOver = true;
      std::cout << "GAME OVER" << std::endl;
    }

    // This will draw the sprites
    app.draw(sBackground);
    app.draw(sPers);

    // Draw the red platform and set position
    app.draw(sRedPlat);
    sRedPlat.setPosition(redPlat.x, redPlat.y);

    for (int i = 0; i < 10; i++) {
      sPlat.setPosition(plat[i].x, plat[i].y);
      app.draw(sPlat);
    }

    // Display the app
    app.display();
  }
}

// Function for generating platforms
void Game::generatePlatforms(point plat[20])
{
  for (int i = 0; i < 10; i++) {
    plat[i].x = rand() % 400;
    plat[i].y = rand() % 533;
  }
}

// Loads the textures in
void Game::loadTextures(Texture &t1, Texture &t2, Texture &t3, Texture &t4)
{
  t1.loadFromFile("../../images/background.png");
  t2.loadFromFile("../../images/platform.png");
  t3.loadFromFile("../../images/doodle.png");
  t4.loadFromFile("../../images/redPlat1.png");
}

// Move the character left and right
void Game::moveCharacter(int &x)
{
  if (Keyboard::isKeyPressed(Keyboard::Right))
    x += 3;
  if (Keyboard::isKeyPressed(Keyboard::Left))
    x -= 3;
}

