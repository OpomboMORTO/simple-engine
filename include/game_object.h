#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../include/textures_manager.h"
#include "../include/physics_manager.h"

class GameObject : public Colider, public std::enable_shared_from_this<GameObject>
{
  
public:
  
  GameObject();

  //TRANSFORM

  void setPosition(sf::Vector2f position);
  void setRotation(float rotation);
  void setOrigin(sf::Vector2f origin);
  void setScale(sf::Vector2f scale);
  
  void setRotate(float rotate);
  void setMove(sf::Vector2f move);

  //TEXTURE

  void setTexture(std::string path);

  //ANIMATION

  void Animation( sf::Vector2i ract, sf::Vector2i spr,sf::Vector2i sprlc, int sprst, float spd);

  void setSpriteSheet(std::string path);

  void Flip();

  void Draw();

  //RENDERER

  void setRender(sf::RenderWindow* window);

  //RIGDBODY

  void colider(bool colision);

  void setColider(ColiderManager* coliderManager, std::shared_ptr<GameObject> gameObject);

  void setBoxPosition(sf::Vector2f position, sf::Vector2f boxPosition);
  void setBoxRotation(float boxRotation);
  void setBoxOrigin(sf::Vector2f origin, sf::Vector2f boxOrigin);
  void setBoxScale(sf::Vector2f scale, sf::Vector2f boxScale);

  void setBoxColor(sf::Color boxColor);
  void setBoxSize(sf::Vector2f boxSize);

  std::shared_ptr<GameObject> getSharedPtr();

  virtual sf::FloatRect getBounds() const override;
  virtual void onTriggerEnter() override;
  virtual void onTriggerExit() override;
  virtual void onColider();

  //CLOCK

  float deltaTime();

  private:

  //TRANSFORM

  sf::Vector2f position;
  float rotation;
  sf::Vector2f origin;
  sf::Vector2f scale;

  //ANIMATION

  int animations;

  int currentLine;
  int currentColun;
  int currentSprite;

  //TEXTURE

  std::string path;
  
  sf::Sprite object;

  //RENDERER

  sf::RenderWindow* window;

  //RIGIDBORDY
  
  ColiderManager* coliderManager;

  sf::RectangleShape coliderShape;
 
  bool coliderOn;

  //CLOCK

  sf::Clock clock;
  sf::Time time;

};

#endif //GAME_OBJECT_H
