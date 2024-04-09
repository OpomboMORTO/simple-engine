#include "../include/game_object.h"
#include <iostream>
#include <string>

using namespace std;

GameObject::GameObject()

    //TRANSFORM:
  : position(sf::Vector2f(0.f,0.f)),
    origin(sf::Vector2f(0.f,0.f)),
    scale(sf::Vector2f(0.f,0.f)),
    rotation(0.f),
    
    //RIGIDBODY:
    coliderOn(false),
    coliderManager(nullptr),
    
    //RENDERER
    object(),
    window(nullptr),

    //CLOCK

    time(sf::Time::Zero),
    clock(),

    //ANIMATION
    currentLine(1),
    currentColun(1),
    currentSprite(1)

{
  //TRANSFORM

  object.setPosition(position);
  object.setRotation(rotation);
  object.setOrigin(origin);
  object.setScale(scale);

  //BOXCOLIDER

  coliderShape.setPosition(position);
  coliderShape.setRotation(rotation);
  coliderShape.setOrigin(origin);
  coliderShape.setScale(scale);
  coliderShape.setOutlineThickness(1.f);
  coliderShape.setOutlineColor(sf::Color::White);
}

void GameObject::setPosition(sf::Vector2f position){object.setPosition(position);}
void GameObject::setRotation(float rotation){object.setRotation(rotation);}
void GameObject::setOrigin(sf::Vector2f origin){object.setOrigin(origin);}
void GameObject::setScale(sf::Vector2f scale){object.setScale(scale);}

void GameObject::setRotate(float rotate){}
void GameObject::setMove(sf::Vector2f move){}

void GameObject::setTexture(std::string path){}

void GameObject::Animation( sf::Vector2i ract, sf::Vector2i spr,sf::Vector2i sprlc, int sprst, float spd){}
void GameObject::setSpriteSheet(std::string path){}
void GameObject::Flip(){}
void GameObject::Draw(){}

void GameObject::setRender(sf::RenderWindow* window){this->window = window;}

void GameObject::colider(bool colision){}
void GameObject::setColider(ColiderManager* coliderManager, std::shared_ptr<GameObject> gameObject){}
void GameObject::setBoxPosition(sf::Vector2f position, sf::Vector2f boxPosition){}
void GameObject::setBoxRotation(float boxRotation){}
void GameObject::setBoxOrigin(sf::Vector2f origin, sf::Vector2f boxOrigin){}
void GameObject::setBoxScale(sf::Vector2f scale, sf::Vector2f boxScale){}
void GameObject::setBoxColor(sf::Color boxColor){}
void GameObject::setBoxSize(sf::Vector2f boxSize){}
std::shared_ptr<GameObject> GameObject::getSharedPtr(){}

virtual sf::FloatRect GameObject::getBounds() const override{}
virtual void GameObject::onTriggerEnter() override{}
virtual void GameObject::onTriggerExit() override{}
virtual void GameObject::onColider() override{}

float GameObject::deltaTime(){}
