#pragma once

#include <raylib/raylib.h>
#include "Core.h"

enum class PlayerAnimationState {
	IDLE,
	RUNNING,
	ATTACKING,
};

class Player : sr::Entity {
  private:
	sr::Transform2D* transform = nullptr; 

	sr::Animation idleAnimation;
	sr::Animation runAnimation;
	sr::Animation* currentAnimation;
	PlayerAnimationState currentAnimationState = PlayerAnimationState::IDLE;
	bool isFlipped = false;

  public:
	Player(Vector2 initPosition, Vector2 pSize);
	void Init();
	void Update();
	void Draw();

  private:
	void UpdateAnimationState(PlayerAnimationState newState);
};