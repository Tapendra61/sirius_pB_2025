#include"Player.h"

Player::Player() : idleAnimation("player_idle", 48) { }

void Player::Init() {
	idleAnimation.Init();
}

void Player::Draw() {
	idleAnimation.Play();
}