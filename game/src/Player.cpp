#include "Player.h"

Player::Player(Vector2 initPosition, Vector2 pSize)
	: transform(GetComponent<Sirius::Transform2D>()),
	  idleAnimation("player_idle", 48, 0.1f, Sirius::REPEATING, transform->Position(), transform->Scale()),
	  runAnimation("player_run", 48, 0.08f, Sirius::REPEATING, transform->Position(), transform->Scale()),
	  currentAnimation{&idleAnimation} {
		transform->Position() = initPosition;
		transform->Scale() = pSize;
	  }

void Player::Init() {
	idleAnimation.Init();
	runAnimation.Init();
}

void Player::Update() {
	if (IsKeyDown(KEY_D)) {
		isFlipped = false;
		transform->Position().x += 200.0f * GetFrameTime();
		UpdateAnimationState(PlayerAnimationState::RUNNING);
	} else if (IsKeyDown(KEY_A)) {
		isFlipped = true;
		transform->Position().x -= 200.0f * GetFrameTime();
		UpdateAnimationState(PlayerAnimationState::RUNNING);
	} else {
		UpdateAnimationState(PlayerAnimationState::IDLE);
	}
}

void Player::UpdateAnimationState(PlayerAnimationState newState) {
	if (currentAnimationState == newState)
		return;

	currentAnimationState = newState;

	switch (currentAnimationState) {
	case PlayerAnimationState::RUNNING:
		currentAnimation = &runAnimation;
		runAnimation.Reset();
		break;
	default:
		currentAnimation = &idleAnimation;
		idleAnimation.Reset();
		break;
	}
}

void Player::Draw() {
	currentAnimation->Play(isFlipped);
}