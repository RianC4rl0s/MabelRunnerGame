#include "Decoration.h"

Decoration::Decoration(float posX, float PosY, uint treeType, Color tint,float layer) : color(tint) {

	switch (treeType)
	{
	case SMALL_TREE:  decoration = new Sprite("Resources/sm_t.png"); type = SMALL_TREE; break;
	case MEDIUM_TREE_1: decoration = new Sprite("Resources/medium_t_1.png"); type = MEDIUM_TREE_1; break;
	case MEDIUM_TREE_2: decoration = new Sprite("Resources/medium_t_2.png"); type = MEDIUM_TREE_2; break;
	case PINE:  decoration = new Sprite("Resources/pine.png"); type = PINE; break;
	case DEAD_TREE: decoration = new Sprite("Resources/dead_t.png"); type = DEAD_TREE; break;
	case FINISH_LINE: decoration = new Sprite("Resources/end.png"); type = FINISH_LINE; break;

	}


	MoveTo(posX, PosY, layer);
	width = (float)decoration->Width();
}

Decoration::~Decoration() {
	delete decoration;
}

void Decoration::Update() {
	Translate(-300 * gameTime, 0);
}


float Decoration::Width() {
	return width;
}