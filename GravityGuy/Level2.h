/**********************************************************************************
// Level2 (Arquivo de Cabe�alho)

// Descri��o:   N�vel 2 do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_LEVEL2_H_
#define _GRAVITYGUY_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"
#include "Font.h"
#include <sstream>


// ------------------------------------------------------------------------------
using std::stringstream;
class Level2 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado

    Font* sysFont = nullptr;               // fonte do sistema
    Font* gameFont = nullptr;              // fonte do jogo

    stringstream text;


public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif