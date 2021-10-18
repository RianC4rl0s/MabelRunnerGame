/**********************************************************************************
// Mabel (Código Fonte)
// 
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "Mabel.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros estáticos da classe
Game*   Mabel::level = nullptr;
Player* Mabel::player = nullptr;
Audio*  Mabel::audio = nullptr;
bool    Mabel::viewBBox = false;

Scene* Mabel::scene = nullptr;

uint Mabel::totalScore = 0;
uint Mabel::highScore = 0;
// ------------------------------------------------------------------------------

void Mabel::Init() 
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(MENU, "Resources/Bug Catching - Emily A. Sprague.wav");
   
    audio->Add(MUSIC, "Resources/Rainbow Forest - Quincas Moreira.wav");
   
    audio->Add(TRANSITION, "Resources/jump.wav");
    audio->Add(SCORE_POINT, "Resources/eat_sound.wav",3);
    // bounding box não visível
    viewBBox = false;

    // cria jogador
    player = new Player();

    totalScore = 0;
    highScore = 0;

    // inicializa nível de abertura do jogo
    level = new Home();
    level->Init();
    
}

// ------------------------------------------------------------------------------

void Mabel::Update()
{
    // habilita/desabilita visualização da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    
  
    // atualiza nível
    level->Update();

} 

// ------------------------------------------------------------------------------

void Mabel::Draw()
{
    // desenha nível
    level->Draw();
} 

// ------------------------------------------------------------------------------

void Mabel::Finalize()
{
    level->Finalize();

    delete player;
    delete audio;
    delete level;
    
    //delete scene;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 720);
    engine->window->Color(30, 50, 80);
    engine->window->Title("Mabel");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Mabel());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

