#include <SFML/Graphics.hpp>
#include <iostream>

//#include "LevelSystem.h"
#include "player.h"

using namespace sf;
using namespace std;

//CircleShape shape(100.f);

unique_ptr<Player> player = make_unique<Player>();


void Reset() {
    
}


void load() {
    //shape.setFillColor(Color::Blue);

    //ls::loadLevelFile("res/levels/maze.txt");

    //// Print the level to the console
    //for (size_t y = 0; y < ls::getHeight(); ++y) {
    //    for (size_t x = 0; x < ls::getWidth(); ++x) {
    //        cout << ls::getTile({ x, y });
    //    }
    //    cout << endl;
    //}

    Reset();
}


void Update(RenderWindow& window) {
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    Event event;

    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }
    

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    

    player->Update(dt);
}

void Render(RenderWindow& window) {
    //window.draw(shape);
    player->Render(window);
}


int main(){
  RenderWindow window(VideoMode({gameWidth, gameHeight}), "Tile Game");
  
  
  load();

  while (window.isOpen()){

      window.clear();
      Update(window);
      Render(window);
      window.display();
    
  }

  return 0;
}