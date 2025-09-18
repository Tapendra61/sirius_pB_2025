#include "Player.h"

Player::Player()
	: idleAnimation("player_idle", 48, 0.1f, REPEATING),
	  runAnimation("player_run", 48, 0.08f, REPEATING),
	  currentAnimation{&idleAnimation} {}

void Player::Init() {
	idleAnimation.Init();
	runAnimation.Init();
}

void Player::Update() {
	if(IsKeyDown(KEY_D)) {
		UpdateAnimationState(PlayerAnimationState::RUNNING);
	}else {
		UpdateAnimationState(PlayerAnimationState::IDLE);
	}
}

void Player::UpdateAnimationState(PlayerAnimationState newState) {
	if (currentAnimationState == newState) return;

	currentAnimationState = newState;

	switch (currentAnimationState) {
		case PlayerAnimationState::RUNNING:
			currentAnimation = &runAnimation;
			break;
		default:
			currentAnimation = &idleAnimation;
			break;
	}
}

void Player::Draw() { currentAnimation->Play(); }