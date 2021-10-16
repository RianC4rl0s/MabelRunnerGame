/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "GameOver.h"
#include "Mabel.h"
#include "Home.h"

// ----------------------------------------------------------------------

void GameOver::Init()
{
	title = new Sprite("Resources/sky_d.png");
	pressEsc = new TileSet("Resources/esc.png", 480, 62, 1, 5);
	anim2 = new Animation(pressEsc, 0.180f, true);

	dead = new Sprite("Resources/hamsterDead.png");
}

// ----------------------------------------------------------------------

void GameOver::Update()
{
	if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN))
		Mabel::NextLevel<Home>();
	else
	{

		anim2->NextFrame();

	}
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
	title->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	anim2->Draw(window->CenterX(), window->CenterY() - pressEsc->TileHeight() / 2, Layer::FRONT);
	dead->Draw(window->CenterX(), 200, Layer::FRONT);
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
	delete title;
	delete anim2;
	delete pressEsc;
	delete dead;

}

// ----------------------------------------------------------------------

