
#ifndef GAMEOVER_H_
#define GAMEOVER_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Animation.h"
#include "TileSet.h"
#include "Font.h"
#include <sstream>
// ------------------------------------------------------------------------------

using std::stringstream;
class GameOver : public Game
{
private:
    Sprite * title = nullptr;       // tela de fim

    Sprite* dead = nullptr;
    Sprite* cat = nullptr;

    TileSet* pressEsc = nullptr;    // tileset da anima��o
    
    Animation* anim2 = nullptr;     // anima��o do menu

    Font* gameFont = nullptr;              // fonte do jogo

    stringstream text;


public:
    //uint totalScore = 0;
    void Init();                    // inicializa��o do n�vel
    void Update();                  // l�gica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif