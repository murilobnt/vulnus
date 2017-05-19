# Variaveis:
## O Compilador
CC = g++

## Flags adicionais
FLAGS = -Wall

## Modificador da linguagem
LANGUAGE = c++0x

## O executável
TARGET = vulnus

## A inclusão dos headers
INCLUDES = -I ./include

## SFML
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## O diretório dos objetos
OBJS-DIR = ./bin

## O diretório dos .cpp
SRC = ./src

## Os objetos utilizados pelo main
OBJS = $(OBJS-DIR)/$(TARGET).o $(OBJS-DIR)/AliveEntity.o $(OBJS-DIR)/Bullet.o $(OBJS-DIR)/BulletSet.o $(OBJS-DIR)/Camera.o $(OBJS-DIR)/Cutscene.o $(OBJS-DIR)/CutsceneDatabase.o $(OBJS-DIR)/Enemy.o $(OBJS-DIR)/Game.o $(OBJS-DIR)/Grid.o $(OBJS-DIR)/Level.o $(OBJS-DIR)/Player.o $(OBJS-DIR)/TextureSet.o $(OBJS-DIR)/Tile.o $(OBJS-DIR)/TileMap.o $(OBJS-DIR)/TileSet.o

#Sintaxe de compilação

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) $(OBJS) $(SFML) -o $(OBJS-DIR)/$(TARGET)

$(OBJS-DIR)/$(TARGET).o : $(SRC)/$(TARGET).cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/$(TARGET).cpp -o $(OBJS-DIR)/$(TARGET).o

$(OBJS-DIR)/AliveEntity.o : $(SRC)/AliveEntity.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/AliveEntity.cpp -o $(OBJS-DIR)/AliveEntity.o

$(OBJS-DIR)/Bullet.o : $(SRC)/Bullet.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Bullet.cpp -o $(OBJS-DIR)/Bullet.o

$(OBJS-DIR)/BulletSet.o : $(SRC)/BulletSet.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/BulletSet.cpp -o $(OBJS-DIR)/BulletSet.o

$(OBJS-DIR)/Camera.o : $(SRC)/Camera.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Camera.cpp -o $(OBJS-DIR)/Camera.o

$(OBJS-DIR)/Cutscene.o : $(SRC)/Cutscene.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Cutscene.cpp -o $(OBJS-DIR)/Cutscene.o

$(OBJS-DIR)/CutsceneDatabase.o : $(SRC)/CutsceneDatabase.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/CutsceneDatabase.cpp -o $(OBJS-DIR)/CutsceneDatabase.o

$(OBJS-DIR)/Enemy.o : $(SRC)/Enemy.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Enemy.cpp -o $(OBJS-DIR)/Enemy.o

$(OBJS-DIR)/Game.o : $(SRC)/Game.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Game.cpp -o $(OBJS-DIR)/Game.o

$(OBJS-DIR)/Grid.o : $(SRC)/Grid.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Grid.cpp -o $(OBJS-DIR)/Grid.o

$(OBJS-DIR)/Level.o : $(SRC)/Level.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Level.cpp -o $(OBJS-DIR)/Level.o

$(OBJS-DIR)/Player.o : $(SRC)/Player.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Player.cpp -o $(OBJS-DIR)/Player.o

$(OBJS-DIR)/TextureSet.o : $(SRC)/TextureSet.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/TextureSet.cpp -o $(OBJS-DIR)/TextureSet.o

$(OBJS-DIR)/Tile.o : $(SRC)/Tile.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/Tile.cpp -o $(OBJS-DIR)/Tile.o

$(OBJS-DIR)/TileMap.o : $(SRC)/TileMap.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/TileMap.cpp -o $(OBJS-DIR)/TileMap.o

$(OBJS-DIR)/TileSet.o : $(SRC)/TileSet.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/TileSet.cpp -o $(OBJS-DIR)/TileSet.o

clean:
	$(RM) $(OBJS-DIR)/*.o $(OBJS-DIR)/$(TARGET)
