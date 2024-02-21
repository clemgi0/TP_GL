# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = .
OBJ_DIR = bin
BIN_DIR = .
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE = $(BIN_DIR)/my_program

# Compilation
all: $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Nettoyage
clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)