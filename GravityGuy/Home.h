/**********************************************************************************
// Home (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_HOME_H_
#define _GRAVITYGUY_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"

#include "Background.h"
// ------------------------------------------------------------------------------

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
public:
    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif