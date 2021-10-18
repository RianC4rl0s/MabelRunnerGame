/**********************************************************************************
// Mabel (Arquivo de Cabe�alho)

//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef MABEL_H_
#define MABEL_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Player.h"
#include "Resources.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

enum Sounds {MENU, MUSIC, TRANSITION, SCORE_POINT};

// ------------------------------------------------------------------------------

using std::stringstream;
class Mabel : public Game
{
private:
    static Game * level;            // n�vel atual do jogo

public:
    static Player * player;         // jogador 
    static Audio * audio;           // sistema de �udio
    static bool viewBBox;           // estado da bounding box

    static Scene* scene;
    
    static uint totalScore;
    static uint highScore;


    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif