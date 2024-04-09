#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include <cstdlib>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

//interface que vain retorna colisao

class Colider{
public:

  bool onTrigger = false;
  bool isTrigger = true;

  virtual sf::FloatRect getBounds() const = 0;
  virtual bool isActive() const { return true; }
  virtual void onColider() = 0;
  virtual void onTriggerEnter() {}
  virtual void onTriggerExit() {}
};

//Classe para armazenar e calcular colisao

class ColiderManager{
private:

  std::vector<std::shared_ptr<Colider>> coliders;
  
public:

  void addColider(const std::shared_ptr<Colider>& colider);
  
  void checkColider();

};

#endif //PHYSICS_MANAGER
