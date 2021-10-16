/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"
#include "Mabel.h"
#include "Platform.h"
#include "Thorn.h"
#include "Food.h"
#include "GameOver.h"
// ---------------------------------------------------------------------------------

Player::Player()
{
	//tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
	tileset = new TileSet("Resources/tileseth3.png", 128, 128, 4, 12);
	//anim = new Animation(tileset, 0.120f, true);
	anim = new Animation(tileset, 0.1f, true);

	// sequências de animação do player
	uint invert[4] = { 4,5,6,7 };
	uint back[4] = { 11,10,9,8 };
	uint normal[4] = { 0,1,2,3 };

	anim->Add(INVERTED, invert, 4);
	anim->Add(NORMAL, normal, 4);
	anim->Add(BACK, back, 4);
	// cria bounding box
	BBox(new Rect(
		-1.0f * tileset->TileWidth() / 2.0f + 10.0f,
		-1.0f * tileset->TileHeight() / 2.0f,
		tileset->TileWidth() / 2.0f -10.0f ,
		tileset->TileHeight() / 2.0f));

	// inicializa estado do player

	level = 0;

	airTime = 0;
	heavy = 50;
	gravitySpeed = 0;

	direction = new Vector2(0, 0);

	initialJumpForce = -1000;
	jumpForce = 0;

	isOnGround = true;

	// posição inicial
	//MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
	MoveTo(300, 70, Layer::FRONT);

	score = 0;

	die = false;

	timer.Start();
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete anim;
	delete tileset;
	delete direction;

}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
	// volta ao estado inicial
	MoveTo(window->CenterX(), 70, Layer::FRONT);
	level = 0;
	gravity = 9;
	airTime = 0;
	heavy = 50;
	gravitySpeed = 0;
	jumpForce = 0;

	direction->setVector2(0, 0);
	score = 0;

	die = false;

	timer.Reset();
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
	isOnGround = false;
	//airTime = 0;
	//gravitySpeed = 0;
	//jumpForce = 0;
	if (obj->Type() == FINISH)
	{
		// chegou ao final do nível
		level++;
	}
	if (obj->Type() == SMALL || obj->Type() == MEDIUM || obj->Type() == LARGE) {
		direction->setVector2(0, 0);
		Platform* plat = (Platform*)obj;

		Rect* platBb = (Rect*)plat->BBox();
		Rect* playerBb = (Rect*)BBox();


		//Colide em cima
		if (platBb->Top() <= playerBb->Bottom() && platBb->Bottom() > playerBb->Bottom()) {
			if (playerBb->Right() > platBb->Left() && playerBb->Left() < platBb->Right()) {

				gravitySpeed = 0;
				jumpForce = 0;
				airTime = 0;
				MoveTo(x, obj->Y() - 90);
				isOnGround = true;

				// ----------------------------------------------------------
				// Processa teclas pressionadas
				// ----------------------------------------------------------
				// jogador só pode alterar a gravidade enquanto estiver
				// em cima de uma plataforma, não é possível a mudança no ar
				// ----------------------------------------------------------
				//speedY = 0;

				if (isOnGround && window->KeyDown(VK_SPACE))
				{

					//gravity = -gravity;
					jumpForce = initialJumpForce;

					Mabel::audio->Play(TRANSITION);

				}
			}
		}
		else if (platBb->Bottom() > playerBb->Top() && platBb->Top() < playerBb->Top()) {//colide em baixo
			if (playerBb->Right() > platBb->Left() && playerBb->Left() < platBb->Right()) {
				MoveTo(x, obj->Y() + 96);
				airTime = 0;
				gravitySpeed = 0;
				jumpForce = 0;
			}
		}
		else if (platBb->Right() > playerBb->Left() && platBb->Right() < playerBb->Right()) {
			//bateu na esquerda
			if ((platBb->Bottom() <platBb->Bottom() && platBb->Bottom() > platBb->Top()) || (playerBb->Top() > platBb->Top()&& playerBb->Top() < platBb->Bottom())|| (platBb->Bottom() > platBb->Bottom() || playerBb->Top() < platBb->Top())) {

				MoveTo(platBb->Right() + tileset->TileWidth() / 2, y);
			}

		}
		else if (platBb->Left() < playerBb->Right() && platBb->Left() > playerBb->Left()) {
			//if ((platBb->Bottom() <platBb->Bottom() && platBb->Bottom() > platBb->Top()) || (playerBb->Top() > platBb->Top()&& playerBb->Top() < platBb->Bottom())) {
			if (platBb->Bottom() > platBb->Bottom() || playerBb->Top() < platBb->Top()) {
				MoveTo(platBb->Left() - tileset->TileWidth() / 2, y);
				//colisao a direita

				
			}
		}




	}

	if (obj->Type() == NORMAL_THORN) {
		Reset();
		die = true;
		
	}

	if (obj->Type() == NORMAL_FOOD) {
		score += 10;
		Mabel::scene->Delete(obj, STATIC); 
		//GravityGuy::audio->Play(SCORE_POINT);
		
	}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// ação da gravidade sobre o personagem
	/*if (gravity == NORMAL)
		Translate(0, 300 * gameTime);
	else
		Translate(0, -300 * gameTime);
		*/

		// atualiza animação
	anim->Select(NORMAL);
	anim->NextFrame();
	airTime += gameTime;
	/*if (gravitySpeed < 500) {//velociade terminal
	}*/

	gravitySpeed = gravity * 200 * airTime;


	if (jumpForce < 0) {
		//jumpForce += gravitySpeed;
	}
	direction->setVector2(0, gravitySpeed + jumpForce);

	//jumpForce -= gravity * heavy * 10 * airTime;

	if (((X() - tileset->TileWidth() / 2) > 0) && ((X() + tileset->TileWidth() / 2) <= window->Width())) {

		if (window->KeyDown(VK_LEFT)) {
			Translate(-400 * gameTime, 0);
			anim->Select(BACK);
		}
		else if (window->KeyDown(VK_RIGHT)) {
			Translate(400 * gameTime, 0);
			anim->Select(NORMAL);
		}
		else {
			Translate(-300 * gameTime, 0);
			if((X() - tileset->TileWidth()) / 2  + 10>= 0)
			anim->Select(INVERTED);
		}

	}
	if ((X() - tileset->TileWidth()) / 2 <= 0) {
		MoveTo(1.0f + (float)tileset->TileWidth(), y);
		anim->Select(NORMAL);
	}
	if ((X() + tileset->TileWidth() / 2) >= window->Width()) {
		MoveTo(window->Width() - (float)tileset->TileWidth() / 2, y);

	}

	//score = score + 1;

	if (timer.Elapsed(0.5f))
	{
		score = score +1;
		timer.Reset();
	}

	Translate(direction->X() * gameTime, direction->Y() * gameTime);
}


// ---------------------------------------------------------------------------------