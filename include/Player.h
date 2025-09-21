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
	Vector2 position;
	Vector2
		playerSize;	 // TODO: Later change playerSize into scale value instead
					 // and multiply this inside Animation with sizePerSlice

	Animation idleAnimation;
	Animation runAnimation;
	Animation* currentAnimation;
	PlayerAnimationState currentAnimationState = PlayerAnimationState::IDLE;

   public:
	Player(Vector2 initPosition, Vector2 pSize);
	inline void SetSize(Vector2 newSize) { playerSize = newSize; }
	inline void SetSize(float width, float height) {
		playerSize.x = width;
		playerSize.y = height;
	}
	inline Vector2 GetPosition() { return position; }
	inline void SetPosition(Vector2 pos) { position = pos; }
	void Init();
	void Update();
	void Draw();

   private:
	void UpdateAnimationState(PlayerAnimationState newState);
};