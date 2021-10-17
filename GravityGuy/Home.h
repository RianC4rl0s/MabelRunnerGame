

#ifndef HOME_H_
#define HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"

#include "Background.h"
#include "Font.h"
#include <sstream>
// ------------------------------------------------------------------------------

using std::stringstream;
class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    TileSet * pressEnter = nullptr;    // tileset da anima��o
    TileSet * pressEsc = nullptr;    // tileset da anima��o
    Animation * anim = nullptr;     // anima��o do menu
    Animation * anim2 = nullptr;     // anima��o do menu


    Sprite* title = nullptr;
    TileSet* playerSprite = nullptr;
    Background* background = nullptr;

    Font* gameFont = nullptr;              // fonte do jogo

    stringstream text;

public:
    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif