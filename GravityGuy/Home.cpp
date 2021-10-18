/**********************************************************************************
// Home (Código Fonte) 
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Mabel.h"
#include "Home.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    //backg = new Sprite("Resources/TitleScreen.png");
    pressEnter = new TileSet("Resources/enter.png", 480, 62, 1, 5);
    anim = new Animation(pressEnter, 0.180f, true);
    pressEsc = new TileSet("Resources/esc.png", 480, 62, 1, 5);
    anim2 = new Animation(pressEsc, 0.180f, true);
    background = new Background(Color(1, 1, 1, 1));
    Mabel::audio->Play(MENU, true);

    title = new Sprite("Resources/MabelTitulo.png");


    gameFont = new Font("Resources/ink-free32.png");
    gameFont->Spacing("Resources/ink-free32.dat");

}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();
    
    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
        Mabel::audio->Stop(MENU);
        Mabel::NextLevel<Level1>();
    }
    else
    {
        anim->NextFrame();
        anim2->NextFrame();
        background->Update();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    background->Draw();
    //backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    anim->Draw(window->CenterX(), 275);
    anim2->Draw(window->CenterX(), 325);

    title->Draw(window->CenterX(), 200.0f, Layer::FRONT);

    text.str("");
    //text << "1000";
    text << "High Score: " << Mabel::highScore;

    int length = int(text.tellp());
    gameFont->Draw(window->CenterX() - (length * 16.0f) / 2, 600.0f, text.str(), Color(1, 1, 1, .65f));

}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete anim;
    delete anim2;
    delete pressEnter;
    delete pressEsc;
    delete backg;
    delete background;
    delete playerSprite;
    delete title;
    delete gameFont;
}

// ------------------------------------------------------------------------------