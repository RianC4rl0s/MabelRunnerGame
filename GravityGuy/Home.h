

#ifndef HOME_H_
#define HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

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
    TileSet * pressEnter = nullptr;    // tileset da animação
    TileSet * pressEsc = nullptr;    // tileset da animação
    Animation * anim = nullptr;     // animação do menu
    Animation * anim2 = nullptr;     // animação do menu


    Sprite* title = nullptr;
    TileSet* playerSprite = nullptr;
    Background* background = nullptr;

    Font* gameFont = nullptr;              // fonte do jogo

    stringstream text;

public:
    void Init();                    // inicia nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nível
};

// -----------------------------------------------------------------------------

#endif