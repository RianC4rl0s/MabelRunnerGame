#include "Thorn.h"


Thorn::Thorn(float posX, float posY, Color tint) : color(tint) {
	thorn = new Sprite("Resources/thorn.png");


	BBox(new Rect(-thorn->Width() / 2, -thorn->Height() / 2, thorn->Width() / 2, thorn->Height() / 2));
	
	MoveTo(posX, posY, Layer::MIDDLE);

	type = NORMAL_THORN;

}	
Thorn::~Thorn() {
	delete thorn;
	
}

void Thorn::Update() {
	Translate(-300 * gameTime, 0);
}