#include "FireTable.hpp"
#include "colors.hpp"
#include <iostream>

FireTable::FireTable(int largura, int altura, int pixel)
    : resolucaoLargura(largura), resolucaoAltura(altura), tamanhoPixel(pixel), gen(rd()), distrib(0, 1) {
    criateTable();
}

void FireTable::criateTable() {
    colunas = resolucaoLargura / tamanhoPixel;
    linhas = resolucaoAltura / tamanhoPixel;
    tabela.resize(linhas, std::vector<int>(colunas, 0));
    for (int i = 0; i<colunas; i++){
        tabela[linhas - 1][i] = 36;
    }
}

int FireTable::getNumRows() const {
    return linhas;
}

int FireTable::getNumColuns() const {
    return colunas;
}

void FireTable::printTable() const {
    for (const auto& linha : tabela) {
        for (int valor : linha) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }
}

void FireTable::update() {
    int ultimaLinha = linhas - 2;
    int ultimaColuna = colunas - 1;
    int colorSelect;
    int vento;
    for (int i = ultimaLinha; i >= 0; i--) {
        for(int j = ultimaColuna; j >= 0; j--){
            colorSelect = tabela[i+1][j] - distrib(gen);
            if (colorSelect < 0)
                colorSelect = 0;
            vento = j - distrib(gen);
            if (vento < 0)
                break;
            tabela[i][vento] = colorSelect;
        }
    }
}

void FireTable::render_pixel(SDL_Renderer *renderer, int intensidade, int linha, int coluna) {
    SDL_Color cor;
    cor = colors[intensidade]; 
    SDL_SetRenderDrawColor(renderer, cor.r, cor.g, cor.b, cor.a);
    SDL_Rect rect;
    rect.x = coluna * tamanhoPixel;
    rect.y = linha * tamanhoPixel;
    rect.w = tamanhoPixel;
    rect.h = tamanhoPixel;
    SDL_RenderFillRect(renderer, &rect); 
}

void FireTable::render(SDL_Renderer *renderer) {
    int ultimaLinha = linhas - 1;
    int ultimaColuna = colunas - 1;
    for (int i = ultimaLinha; i >= 0; i--) {
        for(int j = ultimaColuna; j >= 0; j--){
            render_pixel(renderer, tabela[i][j], i, j);
        }
    }
}
