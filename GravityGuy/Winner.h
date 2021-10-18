
#ifndef WINNER_H
#define WINNER_H

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Animation.h"
#include "TileSet.h"
#include "Font.h"
#include <sstream>
// ------------------------------------------------------------------------------

using std::stringstream;
class Winner : public Game
{
private:
    Sprite* title = nullptr;       // tela de fim

    Sprite* dead = nullptr;

    TileSet* pressEsc = nullptr;    // tileset da animação

    Animation* anim2 = nullptr;     // animação do menu

    Font* gameFont = nullptr;              // fonte do jogo

    stringstream text;


public:
    //uint totalScore = 0;
    void Init();                    // inicialização do nível
    void Update();                  // lógica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finalização do nível
};

// ------------------------------------------------------------------------------

#endif