#pragma once

#include <raylib/raylib.h>
#include"Animation.h"

class Player
{
private:
	Animation idleAnimation;
	Animation runAnimation;
	Vector2 position;

public:
	Player();
	inline void SetPosition(Vector2 pos) { position = pos; }
	void Draw();
	void Init();
};