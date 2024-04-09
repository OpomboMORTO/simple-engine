//TextureManager

#include "../include/textures_manager.h"
#include <iostream>

// Implementacao do metodo
TextureManager& TextureManager::getInstance(){

  static TextureManager instance;
  return instance;
}

//chamando textura e verificando se ja esta carregada
sf::Texture& TextureManager::loadTexture(const std::string& filename){

  auto it = m_textures.find(filename);
  if(it != m_textures.end()){
    //verificando se a textura ja esta carregada, se sim aumentando o contador
    it->second.refCount++;
    return it->second.texture;
  }

  //se nao estiver , carregue a textura
  sf::Texture texture;
  if(texture.loadFromFile(filename)){
    m_textures.emplace(filename, TextureData{texture, 1, {}});//criando mapa
    return m_textures.at(filename).texture;
  }
  else{
    throw std::runtime_error("Failed to load texture: " + filename);
  }
}

//descarregando texturas
void TextureManager::unloadTexture(const std::string& filename){
  auto it = m_textures.find(filename);
  if(it != m_textures.end()){
    it -> second.refCount--;
    if(it -> second.refCount <= 0){
      m_textures.erase(it);
    }
  }
}

//obtendo tamanho da lista de texturas
void TextureManager::getTextureCount(){
  std::cout << "texturas carregadas: " << m_textures.size() << std::endl;
}

//lista de objetos usando texturas
void TextureManager::getLoadedTextures(){
  std::vector<std::string> textures;
  for(const auto& pair : m_textures){
    textures.push_back(pair.first);
  }
  for(const auto& texture : textures) {
    std::cout << "caminho das texturas: : " << texture << std::endl;
  }
}

// numeros de objetos usando texturas

int TextureManager::getObjectCountForTexture(const std::string& filename) const {
  auto it = m_textures.find(filename);
  if(it != m_textures.end()){
    return it->second.objectNames.size();
  }
  return 0;
}
