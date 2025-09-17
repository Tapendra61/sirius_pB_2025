#include"Player.h"

Player::Player() : idleAnimation("player_idle", 48, 0.1f, ONESHOT) { }

void Player::Init() {
	idleAnimation.Init();
}

void Player::Draw() {
	idleAnimation.Play();
}