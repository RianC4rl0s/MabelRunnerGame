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

	gameFont = new Font("Resources/ink-free32.png");
	gameFont->Spacing("Resources/ink-free32.dat");


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



	text.str("");
	//text << "1000";
	text << "Total Score: " << Mabel::totalScore;

	int length = int(text.tellp());
	gameFont->Draw(window->CenterX() - (length*16.0f)/2, 600.0f, text.str(), Color(0, 0, 0, .65f));

}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
	Mabel::totalScore = 0;
	delete title;
	delete anim2;
	delete pressEsc;
	delete dead;
	
	delete gameFont;
	
}

// ----------------------------------------------------------------------

