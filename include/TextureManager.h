#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <vector>

class TextureManager{

 public:

  // Metodo estatico para obter a instancia unica do TextureManager
  static TextureManager& getInstance();

  // Carrega uma textura para o arquivo
  sf::Texture& loadTexture(const std::string& filename);

  //descarregando textura
  void unloadTexture(const std::string& filename);

  // Retorna o numero de texturas carregadas
  void getTextureCount();

  // Lista de texturas carregadas
  void getLoadedTextures();

  // Objetos que estao usando as texturas
  int getObjectCountForTexture(const std::string& filename) const;
  
 private:

  struct TextureData {

    sf::Texture texture;
    int refCount;; //contador de texturas
    std::vector<std::string> objectNames; //nomes do objetos usando as texturas
  };

  //mapa de nomes dos arquivos de textura
  std::unordered_map<std::string, TextureData> m_textures;

  //contrutor 
  TextureManager() {}

  //desabilitar copias do contrutor
  TextureManager(const TextureManager&)=delete;
  TextureManager& operator=(const TextureManager&)=delete;

    

};

#endif // TEXTURE_MANAGER_H
