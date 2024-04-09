cmake_minimum_required(VERSION 3.10)
project(MeuProjetoSFML)

# Definindo a versão do C++ usada
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Adicionando o diretório de inclusão dos headers
include_directories(include)

# Definindo a lista de arquivos de origem
set(SRCS
    src/main.cpp
    src/TextureManager.cpp
    src/PhysicsManager.cpp
    src/GameObject.cpp
)

# Adicionando o executável
add_executable(main ${SRCS})

# Localização das bibliotecas SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Linkando as bibliotecas SFML
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)