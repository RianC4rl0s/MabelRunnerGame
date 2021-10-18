/**********************************************************************************
// Background (Código Fonte)
// 
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background(Color tint) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = xB =xM =xM2 = x;

    // carrega imagens
    //imgF = new Image("Resources/BackgFront.png");
    imgF = new Image("Resources/bk2.png");
    //imgB = new Image("Resources/BackgBack.png");
    imgB = new Image("Resources/bk1.png");
    imgC = new Image("Resources/montain_test_2.png");
    imgD = new Image("Resources/montain_test_2.png");
    
    // cria sprites do plano de fundo
    sky     = new Sprite("Resources/sky_d.png");    
    backgF1 = new Sprite(imgF);
    backgF2 = new Sprite(imgF);
    backgB1 = new Sprite(imgB);
    backgB2 = new Sprite(imgB);
    
    backgM1 = new Sprite(imgC);
    backgM2 = new Sprite(imgC);
    backgM3 = new Sprite(imgD);
    backgM4 = new Sprite(imgD);
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete imgF;
    delete imgB;    
    delete imgC;    
    delete imgD;    
    delete backgF1;
    delete backgF2;
    delete backgB1;
    delete backgB2;
    delete backgM1;
    delete backgM2;
    delete backgM3;
    delete backgM4;
    delete sky;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes

   
    xF -= 200 * gameTime;
    xM -= 100 * gameTime;
    xB -= 150 * gameTime;
    xM2 -= 210 * gameTime;
  
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    // desenha pano de fundo
    sky->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 1.0f, 0.0f, color);

    // desenha nuvens mais distantes
    backgB1->Draw(xB, y, 0.86f, 1.0f, 0.0f, color);
    backgB2->Draw(xB + imgB->Width(), y, 0.86f, 1.0f, 0.0f, color);
    
    // traz pano de fundo de volta para dentro da tela
    if (xB + imgB->Width()/2.0f < 0)
        xB += imgB->Width();

    // desenha nuvens mais próximos
    backgF1->Draw(xF, y, 0.6f, 1.0f, 0.0f, color);
    backgF2->Draw(xF + imgF->Width(), window->Height()/2.0f, 0.6f, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF->Width()/2.0f < 0)
        xF += imgF->Width();


    // desenha montanhas mais distantes
    backgM1->Draw(xM, y, 0.76f, 1.0f, 0.0f, color);
    backgM2->Draw(xM + imgC->Width(), y, 0.76f, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xM + imgC->Width() / 2.0f < 0)
        xM += imgC->Width();
    
    // desenha montanhas mais proximas
    backgM3->Draw(xM2, y, 0.59f, 1.0f, 0.0f, Color(0.2,0.7,0.5,1));
    backgM4->Draw(xM2 + imgD->Width(), y, 0.59f, 1.0f, 0.0f, Color(0.2, 0.7, 0.5, 1));

    // traz pano de fundo de volta para dentro da tela
    if (xM2 + imgD->Width() / 2.0f < 0)
        xM2 += imgD->Width();
    

  


}

// -------------------------------------------------------------------------------
