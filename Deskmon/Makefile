# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -IC:/SFML/SFML-2.6.2/include

# Directorios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = bin
BIN = main.exe

# Archivos fuente y objetos
SRCS := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJNAMES := $(notdir $(SRCS:.cpp=.o))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJNAMES))

# Regla principal
all: $(BIN)

# Linkeo final
$(BIN): $(OBJS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $@ $^ -LC:/SFML/SFML-2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system -lgdi32 -luser32

# Compila cada .cpp a .o en bin/ sin subcarpetas
$(OBJ_DIR)/%.o:
	@echo "Compiling $*..."
	$(CXX) $(CXXFLAGS) -c $(filter %/$*.cpp,$(SRCS)) -o $@

# Ejecutar
run: $(BIN)
	@echo "Hello, Digital World!"
	@./$(BIN)

# Limpiar
clean:
	del /Q $(OBJ_DIR)\*.o 2>nul
	del /Q $(BIN) 2>nul
