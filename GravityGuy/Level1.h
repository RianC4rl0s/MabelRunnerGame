/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
// 
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_LEVEL1_H_
#define _GRAVITYGUY_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"


#include "Font.h"
#include <sstream>
// ------------------------------------------------------------------------------


using std::stringstream;
class Level1 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado

    Font* sysFont = nullptr;               // fonte do sistema
    Font* gameFont = nullptr;              // fonte do jogo

    stringstream text;


public:
    static Scene* scene;           // cena do nível

    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif