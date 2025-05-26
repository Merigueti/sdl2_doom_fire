# Nome do executável
TARGET = fire

# Arquivos-fonte
SRC = main.cpp FireTable.cpp

# Compilador
CXX = g++

# Flags de compilação (pegando diretórios e libs da SDL2 automaticamente)
CXXFLAGS = -std=c++11 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_gfx

# Regra principal
all: $(TARGET)

# Como compilar
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)
