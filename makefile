# Compilador a ser utilizado
CC = g++

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c++17

# Diretório para os arquivos de origem (.cpp)
SRCDIR = src

# Diretório para o executável
BINDIR = bin

# Nome do executável
TARGET = main

# Lista de arquivos de origem (.cpp)
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Bibliotecas necessárias da SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Inclusão dos diretórios de cabeçalho
INC = -I include

# Comando de compilação e ligação
$(BINDIR)/$(TARGET): $(SRCS)
    $(CC) $(CFLAGS) $(INC) $^ -o $@ $(SFML_LIBS)

# Comando para limpar o executável
clean:
    rm -f $(BINDIR)/$(TARGET)