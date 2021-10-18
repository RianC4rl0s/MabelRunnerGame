/**********************************************************************************
// Mabel (Arquivo de Cabeçalho)

//
// Descrição:   Jogo estilo plataforma usando a engine do curso
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
    static Game * level;            // nível atual do jogo

public:
    static Player * player;         // jogador 
    static Audio * audio;           // sistema de áudio
    static bool viewBBox;           // estado da bounding box

    static Scene* scene;
    
    static uint totalScore;
    static uint highScore;


    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
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