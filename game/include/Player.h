#pragma once

#include <raylib/raylib.h>

#include "core/Animation.h"
#include "core/Transform.h"

enum class PlayerAnimationState {
	IDLE,
	RUNNING,
	ATTACKING,
};

class Player {
   private:
	Transform2D
		transform;	// TODO: Later change playerSize into scale value instead
					// and multiply this inside Animation with sizePerSlice

	Animation idleAnimation;
	Animation runAnimation;
	Animation* currentAnimation;
	PlayerAnimationState currentAnimationState = PlayerAnimationState::IDLE;
	bool flipped = false;

   public:
	Player(Vector2 initPosition, Vector2 pSize);
	inline Transform2D& GetTransform2D() { return transform; }
	void Init();
	void Update();
	void Draw();

   private:
	void UpdateAnimationState(PlayerAnimationState newState);
};