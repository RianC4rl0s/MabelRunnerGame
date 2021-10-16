#include "Food.h"

Food::Food(float posX, float posY, Color tint): color(tint) {
	food = new Sprite("Resources/berry.png");
	
	BBox(new Rect(-food->Width() / 2, -food->Height() / 2, food->Width() / 2, food->Height() / 2));

	MoveTo(posX, posY, Layer::MIDDLE);

	type = NORMAL_FOOD;
}	
Food::~Food() {
	delete food;
}
void Food::OnCollision(Object* obj) {
	
}
void Food::Update() {
	
	Translate(-300 * gameTime, 0);
}
