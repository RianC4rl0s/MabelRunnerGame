/**********************************************************************************
// Background (Arquivo de Cabeçalho)
//

//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_BACKGROUND_H_
#define _GRAVITYGUY_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
	float xF, xB, xM, xM2;                       // posição horizontal dos sprites
	Image* imgF;                       // imagem de fundo frontal
	Image* imgB;                       // imagem de fundo traseira    
	Image* imgC;                       // imagem de fundo traseira    
	Image* imgD;                       // imagem de fundo traseira    

	Sprite* sky;                       // fundo estático
	Sprite* backgF1;                   // pano de fundo dinâmico 
	Sprite* backgF2;                   // pano de fundo dinâmico 
	Sprite* backgB1;                   // pano de fundo dinâmico 
	Sprite* backgB2;                   // pano de fundo dinâmico 
	Sprite* backgM1;                   // pano de fundo dinâmico 
	Sprite* backgM2;                   // pano de fundo dinâmico 
	Sprite* backgM3;                   // pano de fundo dinâmico 
	Sprite* backgM4;                   // pano de fundo dinâmico 

	Color color;                        // cor do pano de fundo

public:
	Background(Color tint);             // construtor
	~Background();                      // destrutor

	void Update();                      // atualização do objeto
	void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif