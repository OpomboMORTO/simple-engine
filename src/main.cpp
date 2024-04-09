#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../include/TextureManager.h"
#include "../include/PhysicsManager.h"

using namespace std;

class Player : public Colider, public enable_shared_from_this<Player>
{
  
public:
  
  Player() {

    player.setSize(sf::Vector2f(30.f, 30.f));
    player.setFillColor(sf::Color::Black);
    player.setPosition(sf::Vector2f(400.f, 700.f));
    player.setScale(sf::Vector2f(1.f, 1.f));
    player.setOrigin(sf::Vector2f(15.f, 15.f));
    player.setOutlineThickness(2.f);
    player.setOutlineColor(sf::Color::White);
    
    }

  void Update()
  {
    DeltaTime();

    Move(0.f,velocity);
  }
  //
  void EventUpdate()
  {
  }
  //
  void Move(float x , float y)
  {
    player.move(x,y);
  }
  //
  float DeltaTime()
  {
    time+=clock.restart();
    return time.asSeconds();
  }
  //
  void setWindow(sf::RenderWindow* window)
  {
    this->window = window;
  }
  void setTexture(string path)
  {

    sf::Texture texture;
    if(!texture.loadFromFile(path))
    {
       cout << "erro" << endl;
    }

    player.setTexture(&texture);
  }
  //
  void renderDraw()
  {
    window->draw(player);
  }
  //
  void setPosition(sf::Vector2f position)
  {
    player.setPosition(position);
  }
  //contrato com a interface
  virtual sf::FloatRect getBounds() const override
  {
    return player.getGlobalBounds();
  }
  //
  virtual void onColider(){}
  //
  virtual void onTriggerEnter() override {
    onTrigger = true;
    std::cout << "Trigger ativado!" << std::endl;
    player.setFillColor(sf::Color::Red);

    velocity*=-1.1;

    cout<<velocity<<endl;
    
  }
  //
  virtual void onTriggerExit() override {
    onTrigger = false;
    std::cout << "Trigger desativado!" << std::endl;
    player.setFillColor(sf::Color::Black);
  }
  void setColider(ColiderManager* coliderManager, std::shared_ptr<Player> player)
  {
    coliderManager->addColider(player);
  }
  //
  shared_ptr<Player> getSharedPtr() {
        return shared_from_this();
  }

private:

  ColiderManager* coliderManager;

  sf::RectangleShape player;
  
  sf::RenderWindow* window;

  sf::Clock clock;
  
  sf::Time time;

  float velocity = 2;
};

void Render()
{

  ColiderManager coliderManager;
  
  sf::RenderWindow window(sf::VideoMode(800,1000),"name");

  window.setFramerateLimit(144);

  auto cube0 = std::make_shared<Player>();
  cube0->setWindow(&window);
  cube0->setPosition(sf::Vector2f(400, 100));
  cube0->setColider(&coliderManager,cube0);

  auto cube1 = std::make_shared<Player>();
  cube1->setWindow(&window);
  cube1->setPosition(sf::Vector2f(400, 700));
  cube1->setColider(&coliderManager,cube1);

  auto cube2 = std::make_shared<Player>();
  cube2->setWindow(&window);
  cube2->setPosition(sf::Vector2f(400, 400));
  cube2->setColider(&coliderManager,cube2);
  cube2->setTexture("assets/mob001.png");


  while(window.isOpen())
    {
      cube2->Update();

      sf::Event event;

      while(window.pollEvent(event))
	{     	  
	  if(event.type == sf::Event::Closed)
	    {
	      window.close();
	    }
	}


      coliderManager.checkColider();

      window.clear(sf::Color::Black);
      cube0->renderDraw();
      cube1->renderDraw();
      cube2->renderDraw();
      window.display();
    }
}

int main()
{
  Render();

  return 0;
}
