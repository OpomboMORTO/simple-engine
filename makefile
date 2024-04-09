# Compilador a ser utilizado
CC = g++

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c++17

# Diretório para os arquivos de origem (.cpp)
SRCDIR = src

# Diretório para os arquivos de objeto (.o)
OBJDIR = obj

# Diretório para os arquivos de inclusão (.h)
INCLUDEDIR = include

# Diretório para os arquivos de assets (.png)
ASSETSDIR = assets

# Nome do executável
TARGET = meu_programa

# Lista de arquivos de origem (.cpp)
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Lista de arquivos de objetos (.o)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Bibliotecas necessárias da SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Inclusão dos diretórios de cabeçalho
INC = -I $(INCLUDEDIR)

# Comando de compilação
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
    $(CC) $(CFLAGS) $(INC) -c $< -o $@

# Comando de ligação (linkagem)
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $^ -o $@ $(SFML_LIBS)

# Comando para limpar os arquivos de objeto e o executável
clean:
    rm -f $(OBJDIR)/*.o $(TARGET)
