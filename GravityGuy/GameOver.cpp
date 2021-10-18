/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
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
	cat = new Sprite("Resources/cat.png");

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
	title->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 1.0F, 0.0F,Color(0.1f,0.1f,0.1f,1));
	anim2->Draw(window->CenterX(), window->CenterY() - pressEsc->TileHeight() / 2, Layer::FRONT);
	dead->Draw(window->CenterX(), 200, Layer::FRONT);
	cat->Draw(490.0f, 170.0f, Layer::FRONT);


	text.str("");
	//text << "1000";
	text << "Total Score: " << Mabel::totalScore;

	int length = int(text.tellp());
	gameFont->Draw(window->CenterX() - (length*16.0f)/2, 600.0f, text.str(), Color(1, 1, 1, .65f));

}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
	Mabel::totalScore = 0;
	delete title;
	delete anim2;
	delete pressEsc;
	delete dead;
	delete cat;
	delete gameFont;
	
}

// ----------------------------------------------------------------------

