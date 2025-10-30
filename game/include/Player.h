#pragma once

#include <raylib/raylib.h>

#include "Core.h"

enum class PlayerAnimationState {
	IDLE,
	RUNNING,
	ATTACKING,
};

class Player : Sirius::Entity {
   private:
	Sirius::Transform2D
		transform;	// TODO: Later change playerSize into scale value instead
					// and multiply this inside Animation with sizePerSlice

	Sirius::Animation idleAnimation;
	Sirius::Animation runAnimation;
	Sirius::Animation* currentAnimation;
	PlayerAnimationState currentAnimationState = PlayerAnimationState::IDLE;
	bool flipped = false;

   public:
	Player(Vector2 initPosition, Vector2 pSize);
	inline Sirius::Transform2D& GetTransform2D() { return transform; }
	void Init();
	void Update();
	void Draw();

   private:
	void UpdateAnimationState(PlayerAnimationState newState);
};