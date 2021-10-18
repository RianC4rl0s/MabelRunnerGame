#include "Bird.h"

Bird::Bird(float posX, float posY, Color tint) : color(tint) {
	bird = new TileSet("Resources/bird.png",96,96,4,4);
	anim = new Animation(bird, 0.1f, true);


	BBox(new Rect(
		-1.0f * bird->TileWidth() / 2.0f + 5.0f,
		-1.0f * bird->TileHeight() / 2.0f +20.0f,
		bird->TileWidth() / 2.0f - 5.0f,
		bird->TileHeight() / 2.0f - 20.0f) );

	MoveTo(posX, posY, Layer::MIDDLE);

	type = NORMAL_BIRD;

}
Bird::~Bird() {
	delete bird;
	delete anim;
}

void Bird::Update() {
	anim->NextFrame();
	Translate(-500 * gameTime, 0);
}
void Bird::Draw() {
	anim->Draw(x, y, z);
}