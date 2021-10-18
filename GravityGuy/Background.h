/**********************************************************************************
// Background (Arquivo de Cabe�alho)
//

//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_BACKGROUND_H_
#define _GRAVITYGUY_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
	float xF, xB, xM, xM2;                       // posi��o horizontal dos sprites
	Image* imgF;                       // imagem de fundo frontal
	Image* imgB;                       // imagem de fundo traseira    
	Image* imgC;                       // imagem de fundo traseira    
	Image* imgD;                       // imagem de fundo traseira    

	Sprite* sky;                       // fundo est�tico
	Sprite* backgF1;                   // pano de fundo din�mico 
	Sprite* backgF2;                   // pano de fundo din�mico 
	Sprite* backgB1;                   // pano de fundo din�mico 
	Sprite* backgB2;                   // pano de fundo din�mico 
	Sprite* backgM1;                   // pano de fundo din�mico 
	Sprite* backgM2;                   // pano de fundo din�mico 
	Sprite* backgM3;                   // pano de fundo din�mico 
	Sprite* backgM4;                   // pano de fundo din�mico 

	Color color;                        // cor do pano de fundo

public:
	Background(Color tint);             // construtor
	~Background();                      // destrutor

	void Update();                      // atualiza��o do objeto
	void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif