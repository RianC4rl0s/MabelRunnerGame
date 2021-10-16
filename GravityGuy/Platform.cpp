/**********************************************************************************
// Platform (Código Fonte)
//
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"
#include "Mabel.h"
// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType, Color tint) : color(tint)
{
	
	switch (platType)
	{
	case SMALL:  platform = new Sprite("Resources/grassPlatformSmall.png"); type = SMALL; break;
	case MEDIUM: platform = new Sprite("Resources/GrassPlatformMedium.png"); type = MEDIUM; break;
	case LARGE:  platform = new Sprite("Resources/grasPlatformLarge.png"); type = LARGE; break;
	case FINISH: platform = new Sprite("Resources/grasPlatformLarge.png"); type = FINISH; break;
	}

	BBox(new Rect(-platform->Width() / 2.0f,
		-platform->Height() / 2.0f +5,
		platform->Width() / 2.0f,
		platform->Height() / 2.0f));

	MoveTo(posX, posY, Layer::MIDDLE);
	width = (float) platform->Width();
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
	delete platform;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
	// move plataforma apenas no eixo x

	
		Translate(-300*gameTime, 0);
	
		if (x < -1000)
			Mabel::scene->Delete();
}

// -------------------------------------------------------------------------------
float Platform::Width() {
	return width;
}