### LOL, just now I realised this was written in pt-br all this commits! O:
### Since makefile isn't the easier thing to comprehend, I'll comment what
### I do below :D

# SECTION: VARIABLES

## The compiler / O compilador
CC = g++

## Additional flags / Flags adicionais
FLAGS = -g

## Language modifier / Modificador da linguagem
LANGUAGE = c++11

## The executable / O executável
TARGET = vulnus

## Headers' inclusion / A inclusão dos headers
INCLUDES = -I ./include

## SFML
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Objects directory / O diretório dos objetos
OBJS-DIR = ./bin

## Source files directory / O diretório dos arquivos fonte
SRC = ./src

## The source code files / Os arquivos do código fonte
CPPS = $(wildcard $(SRC)/*.cpp)

## Objects required by main / Os objetos requiridos pelo main
OBJS = $(addprefix $(OBJS-DIR)/,$(notdir $(CPPS:.cpp=.o)))

# SECTION: COMPILING

## Structure: ENTITY : DEPENDENCY
## Estrutura: ENTIDADE : DEPENDÊNCIA

## About variables: $@ refers to the ENTITY. $< refers to the first DEPENDENCY. $^ refers to the entire DEPENDENCY.
## Sobre variáveis: $@ refere-se à ENTIDADE. $< refere-se à primeira DEPENDÊNCIA. $^ refere-se a DEPENDÊNCIA inteira.

## For all entries, the dependency is the target file.
## Para todas as entradas, a dependência é o arquivo executável.
all : $(TARGET)

## To satisfy the target file dependency above, we need the objects.
## Para satisfazer a dependência do arquivo executável acima, nós precisamos dos objetos.
$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) ./$^ $(SFML) -o ./bin/$@

## To satisfy the objects dependency above, we need the source code files.
## Para satisfazer a dependência dos objetos acima, nós precisamos dos arquivos do código fonte.
$(OBJS-DIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o ./$@

## For entry "clean" (make clean), delete the objects and the executable.
## Para a entrada "clean" (make clean), delete os objetos e o executável.
clean :
	$(RM) $(OBJS-DIR)/*.o $(OBJS-DIR)/$(TARGET)