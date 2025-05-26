#ifndef FIRETABLE_HPP
#define FIRETABLE_HPP
#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <vector>

class FireTable {
private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;

    int resolucaoLargura;
    int resolucaoAltura;
    int tamanhoPixel;

    int colunas;
    int linhas;
    std::vector<std::vector<int>> tabela;

    void criateTable();

public:
    FireTable(int largura, int altura, int pixel);
    int getNumRows() const;
    int getNumColuns() const;
    void printTable() const;
    void render_pixel(SDL_Renderer *renderer, int intensidade, int linha, int coluna);
    void render(SDL_Renderer *renderer);
    void update();
};

#endif
