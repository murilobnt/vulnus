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

CPPS = $(wildcard $(SRC)/*.cpp)

## Os objetos utilizados pelo main
OBJS = $(addprefix $(OBJS-DIR)/,$(notdir $(CPPS:.cpp=.o)))

#Sintaxe de compilação

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) ./$^ $(SFML) -o ./bin/$@

$(OBJS-DIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o ./$@

clean:
	$(RM) $(OBJS-DIR)/*.o $(OBJS-DIR)/$(TARGET)