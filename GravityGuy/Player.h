/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _GRAVITYGUY_PLAYER_H_
#define _GRAVITYGUY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Vector2.h"    //vetor de direção
// ------------------------------------------------------------------------------

#include "Timer.h"
enum Gravity {NORMAL,STOPPED,BACK};         // tipo da gravidade

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // animação do personagem
    int         level;                  // nível finalizado

    float gravity =9.81f;
    float heavy ;
    float gravitySpeed;
    float airTime;

    float initialJumpForce;
    float jumpForce;

    bool isOnGround;
  
    Vector2* direction;
    
    Timer timer;

public:
    int score;

    bool die;

    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo
    float Left();
    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline int Player::Level()
{ return level; }

inline float Player::Bottom()
{ return y + tileset->Height()/2; }

inline float Player::Top()
{ return y - tileset->Height()/2; }
inline float Player::Left()
{ return y - tileset->Width()/2; }


inline void Player::Draw()
{ anim->Draw(x, y, z); }



// ---------------------------------------------------------------------------------

#endif