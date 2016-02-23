### Programs
CXX = g++
RM_CMD = /bin/rm

### Variables
#DEBUG =-ggdb
WALL = -Wall
#PROFILE = -pg
#OPT = -02
LANGUAGE_STANDARD = c++0x
LIBS = $(LIBS_SFML)
LIBS_SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

### Diretories
LIB_DIR = -L/usr/local/lib
BIN_DIR = ./bin
SOURCE_DIR = ./src
INCLUDE_DIR = ./include
INCLUD_PATHS = -I $(INCLUDE_DIR)

### Compilation flags
CFLAGS = $(WARN) $(DEBUG)$ $(PROFILE) $(OPT) -std=$(LANGUAGE_STANDARD)

### Linkation flags
LFLAGS = $(WARN) $(LIB_DIR) $(LIBS) -std=$(LANGUAGE_STANDARD)

### Program name
PGM = gnjk

### List of objects
OBJS = $(BIN_DIR)/$(PGM).o $(BIN_DIR)/AliveEntity.o $(BIN_DIR)/Bullet.o $(BIN_DIR)/BulletSet.o $(BIN_DIR)/Camera.o $(BIN_DIR)/Cutscene.o $(BIN_DIR)/CutsceneDatabase.o $(BIN_DIR)/Game.o $(BIN_DIR)/Player.o $(BIN_DIR)/TextureSet.o $(BIN_DIR)/Tile.o $(BIN_DIR)/TileMap.o $(BIN_DIR)/TileSet.o
### List of sources
RCS = $(SOURCE_DIR)/$(PGM).cpp $(SOURCE_DIR)/AliveEntity.cpp $(SOURCE_DIR)/Bullet.cpp $(SOURCE_DIR)/BulletSet.cpp $(BIN_DIR)/Camera.o $(SOURCE_DIR)/Cutscene.cpp $(SOURCE_DIR)/CutsceneDatabase.cpp $(SOURCE_DIR)/Game.cpp $(SOURCE_DIR)/Player.cpp $(SOURCE_DIR)/TextureSet.cpp $(SOURCE_DIR)/Tile.cpp $(SOURCE_DIR)/TileMap.cpp $(SOURCE_DIR)/TileSet.cpp

### Entries
$(PGM): $(OBJS)
	$(CXX) $(OBJS) $(LFLAGS) -o $(BIN_DIR)/$(PGM)

#
$(BIN_DIR)/$(PGM).o: $(SRCS)
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/$(PGM).cpp -o $(BIN_DIR)/$(PGM).o


##### AliveEntity
#
$(BIN_DIR)/AliveEntity.o: $(SOURCE_DIR)/AliveEntity.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/AliveEntity.cpp -o $(BIN_DIR)/AliveEntity.o

#
$(SOURCE_DIR)/AliveEntity.cpp: $(INCLUDE_DIR)/AliveEntity.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/AliveEntity.cpp


##### Player
#
$(BIN_DIR)/Player.o: $(SOURCE_DIR)/Player.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/Player.cpp -o $(BIN_DIR)/Player.o

#
$(SOURCE_DIR)/Player.cpp: $(INCLUDE_DIR)/Player.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/Player.cpp

##### Load Bullet
#
$(BIN_DIR)/Bullet.o: $(SOURCE_DIR)/Bullet.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/Bullet.cpp -o $(BIN_DIR)/Bullet.o

#
$(SOURCE_DIR)/Bullet.cpp: $(INCLUDE_DIR)/Bullet.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/Bullet.cpp


##### Load Game Error
#
$(BIN_DIR)/BulletSet.o: $(SOURCE_DIR)/BulletSet.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/BulletSet.cpp -o $(BIN_DIR)/BulletSet.o

#
$(SOURCE_DIR)/BulletSet.cpp: $(INCLUDE_DIR)/BulletSet.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/BulletSet.cpp


##### Camera
#
$(BIN_DIR)/Camera.o: $(SOURCE_DIR)/Camera.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/Camera.cpp -o $(BIN_DIR)/Camera.o

#
$(SOURCE_DIR)/Camera.cpp: $(INCLUDE_DIR)/Camera.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/Camera.cpp


##### Cutscene
#
$(BIN_DIR)/Cutscene.o: $(SOURCE_DIR)/Cutscene.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/Cutscene.cpp -o $(BIN_DIR)/Cutscene.o

#
$(SOURCE_DIR)/Cutscene.cpp: $(INCLUDE_DIR)/Cutscene.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/Cutscene.cpp


##### CutsceneDatabase
#
$(BIN_DIR)/CutsceneDatabase.o: $(SOURCE_DIR)/CutsceneDatabase.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/CutsceneDatabase.cpp -o $(BIN_DIR)/CutsceneDatabase.o

#
$(SOURCE_DIR)/Cutscene.cpp: $(INCLUDE_DIR)/CutsceneDatabase.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/CutsceneDatabase.cpp

##### Game
#
$(BIN_DIR)/Game.o: $(SOURCE_DIR)/Game.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/Game.cpp -o $(BIN_DIR)/Game.o

#
$(SOURCE_DIR)/Game.cpp: $(INCLUDE_DIR)/Game.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/Game.cpp

##### TextureSet
#
$(BIN_DIR)/TextureSet.o: $(SOURCE_DIR)/TextureSet.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/TextureSet.cpp -o $(BIN_DIR)/TextureSet.o

#
$(SOURCE_DIR)/TextureSet.cpp: $(INCLUDE_DIR)/TextureSet.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/TextureSet.cpp

##### Tile
#
$(BIN_DIR)/Tile.o: $(SOURCE_DIR)/Tile.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/Tile.cpp -o $(BIN_DIR)/Tile.o

#
$(SOURCE_DIR)/Tile.cpp: $(INCLUDE_DIR)/Tile.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/Tile.cpp

##### TileMap
#
$(BIN_DIR)/TileMap.o: $(SOURCE_DIR)/TileMap.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/TileMap.cpp -o $(BIN_DIR)/TileMap.o

#
$(SOURCE_DIR)/TileMap.cpp: $(INCLUDE_DIR)/TileMap.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/TileMap.cpp


##### Game Over
#
$(BIN_DIR)/TileSet.o: $(SOURCE_DIR)/TileSet.cpp
	$(CXX) $(CFLAGS) -c $(INCLUD_PATHS) $(SOURCE_DIR)/TileSet.cpp -o $(BIN_DIR)/TileSet.o

#
$(SOURCE_DIR)/TileSet.cpp: $(INCLUDE_DIR)/TileSet.h

#
$(SOURCE_DIR)/$(PGM).cpp: $(SOURCE_DIR)/TileSet.cpp


# Eliinates junk files
clean:
	$(RM_CMD) $(BIN_DIR)/*.o $(SOURCE_DIR)/*~ $(INCLUDE_DIR)/*~ $(BIN_DIR)/$(PGM)
