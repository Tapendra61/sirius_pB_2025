#include "Player.h"

Player::Player()
	: idleAnimation("player_idle", 48, 0.1f, REPEATING),
	  runAnimation("player_run", 48, 0.08f, REPEATING) {}

void Player::Init() {
	idleAnimation.Init();
	runAnimation.Init();
}

void Player::Draw() { runAnimation.Play(); }