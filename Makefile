# Variaveis:
## O Compilador
CC = g++

## Flags adicionais
FLAGS = 

## Modificador da linguagem
LANGUAGE = c++11

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
OBJS = $(OBJS-DIR)/$(TARGET).o $(OBJS-DIR)/aliveentity.o $(OBJS-DIR)/bullet.o $(OBJS-DIR)/bulletset.o $(OBJS-DIR)/camera.o $(OBJS-DIR)/cutscene.o $(OBJS-DIR)/cutscenedatabase.o $(OBJS-DIR)/enemy.o $(OBJS-DIR)/eventhandler.o $(OBJS-DIR)/game.o $(OBJS-DIR)/grid.o $(OBJS-DIR)/inputhandler.o $(OBJS-DIR)/level.o $(OBJS-DIR)/player.o $(OBJS-DIR)/textureset.o $(OBJS-DIR)/tile.o $(OBJS-DIR)/tilemap.o $(OBJS-DIR)/tileset.o

#Sintaxe de compilação

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) $(OBJS) $(SFML) -o $(OBJS-DIR)/$(TARGET)

$(OBJS-DIR)/$(TARGET).o : $(SRC)/$(TARGET).cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/$(TARGET).cpp -o $(OBJS-DIR)/$(TARGET).o

$(OBJS-DIR)/aliveentity.o : $(SRC)/aliveentity.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/aliveentity.cpp -o $(OBJS-DIR)/aliveentity.o

$(OBJS-DIR)/bullet.o : $(SRC)/bullet.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/bullet.cpp -o $(OBJS-DIR)/bullet.o

$(OBJS-DIR)/bulletset.o : $(SRC)/bulletset.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/bulletset.cpp -o $(OBJS-DIR)/bulletset.o

$(OBJS-DIR)/camera.o : $(SRC)/camera.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/camera.cpp -o $(OBJS-DIR)/camera.o

$(OBJS-DIR)/cutscene.o : $(SRC)/cutscene.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/cutscene.cpp -o $(OBJS-DIR)/cutscene.o

$(OBJS-DIR)/cutscenedatabase.o : $(SRC)/cutscenedatabase.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/cutscenedatabase.cpp -o $(OBJS-DIR)/cutscenedatabase.o

$(OBJS-DIR)/enemy.o : $(SRC)/enemy.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/enemy.cpp -o $(OBJS-DIR)/enemy.o

$(OBJS-DIR)/eventhandler.o : $(SRC)/eventhandler.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/eventhandler.cpp -o $(OBJS-DIR)/eventhandler.o

$(OBJS-DIR)/game.o : $(SRC)/game.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/game.cpp -o $(OBJS-DIR)/game.o

$(OBJS-DIR)/grid.o : $(SRC)/grid.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/grid.cpp -o $(OBJS-DIR)/grid.o

$(OBJS-DIR)/inputhandler.o : $(SRC)/inputhandler.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/inputhandler.cpp -o $(OBJS-DIR)/inputhandler.o

$(OBJS-DIR)/level.o : $(SRC)/level.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/level.cpp -o $(OBJS-DIR)/level.o

$(OBJS-DIR)/player.o : $(SRC)/player.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/player.cpp -o $(OBJS-DIR)/player.o

$(OBJS-DIR)/textureset.o : $(SRC)/textureset.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/textureset.cpp -o $(OBJS-DIR)/textureset.o

$(OBJS-DIR)/tile.o : $(SRC)/tile.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/tile.cpp -o $(OBJS-DIR)/tile.o

$(OBJS-DIR)/tilemap.o : $(SRC)/tilemap.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/tilemap.cpp -o $(OBJS-DIR)/tilemap.o

$(OBJS-DIR)/tileset.o : $(SRC)/tileset.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRC)/tileset.cpp -o $(OBJS-DIR)/tileset.o

clean:
	$(RM) $(OBJS-DIR)/*.o $(OBJS-DIR)/$(TARGET)