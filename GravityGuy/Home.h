/**********************************************************************************
// Home (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_HOME_H_
#define _GRAVITYGUY_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

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
    TileSet * pressEnter = nullptr;    // tileset da animação
    TileSet * pressEsc = nullptr;    // tileset da animação
    Animation * anim = nullptr;     // animação do menu
    Animation * anim2 = nullptr;     // animação do menu


    Sprite* title = nullptr;
    TileSet* playerSprite = nullptr;
    Background* background = nullptr;
public:
    void Init();                    // inicia nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nível
};

// -----------------------------------------------------------------------------

#endif