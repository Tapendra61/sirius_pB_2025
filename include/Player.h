#pragma once

#include <raylib/raylib.h>

#include "Animation.h"

enum class PlayerAnimationState {
	IDLE,
	RUNNING,
	ATTACKING,
};

class Player {
   private:
	Animation idleAnimation;
	Animation runAnimation;
	Animation* currentAnimation;
	PlayerAnimationState currentAnimationState = PlayerAnimationState::IDLE;

	Vector2 position;

   public:
	Player();
	inline void SetPosition(Vector2 pos) { position = pos; }
	void Update();
	void Draw();
	void Init();

   private:
	void UpdateAnimationState(PlayerAnimationState newState);
};