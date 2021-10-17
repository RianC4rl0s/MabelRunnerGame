/**********************************************************************************
// Level2 (Código Fonte)
//
// Criação:     27 Set 2021
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 2 do jogo
//
**********************************************************************************/

#include "Mabel.h"
#include "Home.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"

#include <string>
#include <fstream>
#include "Thorn.h"
#include"Food.h"
#include "Bird.h"
#include "Decoration.h"
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
	// cria gerenciador de cena
	scene = new Scene();

	// pano de fundo do jogo
	Color dark{ 0.4f, 0.4f, 0.4f, 1.0f };
	backg = new Background(dark);
	scene->Add(backg, STATIC);

	// adiciona jogador na cena
	scene->Add(Mabel::player, MOVING);

	// ----------------------
	// plataformas
	// ----------------------

	Platform* plat;
	float posX, posY;
	uint  platType;

	ifstream fin;
	fin.open("Level2.txt");

	fin >> posX;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha com informações da plataforma
			fin >> posY; fin >> platType;
			plat = new Platform(posX, posY, platType, dark);
			scene->Add(plat, STATIC);
		}
		else
		{
			// ignora comentários
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}

		fin >> posX;
	}
	fin.close();

	// ----------------------

	Mabel::audio->Frequency(MUSIC, 1.0f);
	Mabel::audio->Frequency(TRANSITION, 0.85f);


	sysFont = new Font("Resources/Ms Sans Serif PIXEL 44.png");
	sysFont->Spacing("Resources/Ms Sans Serif pixel 44.dat");
	gameFont = new Font("Resources/ink-free32.png");
	gameFont->Spacing("Resources/ink-free32.dat");


	Food* food;


	fin.open("Level1Food.txt");
	fin >> posX;

	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha com informações da plataforma
			fin >> posY;
			food = new Food(posX, posY, Color(1,1,1,1));
			scene->Add(food, STATIC);
		}
		else
		{
			// ignora comentários
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}

		fin >> posX;
	}
	fin.close();


	Thorn* thorn;
	Bird* bird;

	int obsType = 0;
	fin.open("Level2Obstacles.txt");
	fin >> posX;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha com informações da plataforma
			fin >> posY;
			fin >> obsType;
			if (obsType == 0) {
				thorn = new Thorn(posX, posY, Color(1, .6f, .6f, 1));
				scene->Add(thorn, STATIC);

			}
			else if (obsType == 1) {
				bird = new Bird(posX, posY, Color(1, .6f, .6f, 1));
				scene->Add(bird, STATIC);
			}

		}
		else
		{
			// ignora comentários
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}

		fin >> posX;
	}
	fin.close();


	Decoration* decoration = new Decoration(18500, 380, FINISH_LINE, dark, .56f);
	scene->Add(decoration, STATIC);


	Mabel::scene = scene;
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
	if (window->KeyPress(VK_ESCAPE) || Mabel::player->Level() == 2 || window->KeyPress('N'))
	{
		Mabel::totalScore += Mabel::player->score;
		if (Mabel::totalScore > Mabel::highScore) {
			Mabel::highScore = Mabel::totalScore;
		}
		Mabel::totalScore += Mabel::player->score;
		Mabel::audio->Stop(MUSIC);
		Mabel::NextLevel<Home>();
		Mabel::player->Reset();
	}
	/*else if (Mabel::player->Bottom() < 0 || Mabel::player->Top() > window->Height())
	{
		Mabel::audio->Stop(MUSIC);
		Mabel::NextLevel<GameOver>();
		Mabel::player->Reset();
	}*/
	else if (Mabel::player->Top() > window->Height())
	{
		Mabel::totalScore += Mabel::player->score;
		if (Mabel::totalScore > Mabel::highScore) {
			Mabel::highScore = Mabel::totalScore;
		}
		Mabel::audio->Stop(MUSIC);
		Mabel::NextLevel<GameOver>();
		Mabel::player->Reset();
	}
	else
	{
		scene->Update();
		scene->CollisionDetection();
	}
	if (Mabel::player->die) {
		Mabel::audio->Stop(MUSIC);
		Mabel::NextLevel<GameOver>();
		Mabel::player->Reset();
	}
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	backg->Draw();
	scene->Draw();

	text.str("");
	//text << "1000";
	text << "Score: " << Mabel::player->score;

	int length = int(text.tellp());
	gameFont->Draw(window->Width() - (30.0f * length), 70.0f, text.str(), Color(1, 1, 1, 1));
	gameFont->Draw(window->Width() - 200.0f, 35.0f, "Level 2/2", Color(1, 1, 1, 1));


	gameFont->Draw(200.0f, 660.0f, "Use Left and Righ to move horizontal. Space to jump", Color(1, 1, 1, 1), Layer::FRONT, 0.75f);


	if (Mabel::viewBBox)
		scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
	scene->Remove(Mabel::player, MOVING);
	delete scene;
	delete sysFont;
	delete gameFont;

}

// ------------------------------------------------------------------------------
