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
	Sirius::Transform2D* transform = nullptr; // TODO: Later change playerSize into scale value instead
											  // and multiply this inside Animation with sizePerSlice

	Sirius::Animation idleAnimation;
	Sirius::Animation runAnimation;
	Sirius::Animation* currentAnimation;
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