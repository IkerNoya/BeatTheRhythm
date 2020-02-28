#include "player.h"

namespace player 
{
	Player::Player()
	{
		_hp = 5;
		_score = 0;
		_multiplier = 1;
	}

	Player::Player(int hp, float score, float multiplier)
	{
		_hp = hp;
		_score = score;
		_multiplier = multiplier;
	}

	Player::~Player()
	{

	}

	void Player::setHP(int hp)
	{
		_hp = hp;
	}
	int Player::getHP()
	{
		return _hp;
	}

	void Player::setScore(float score)
	{
		_score = score;
	}
	float Player::getScore()
	{
		return _score;
	}

	void Player::setMultiplier(float multiplier)
	{
		_multiplier = multiplier;
	}
	float Player::getMultiplier()
	{
		return _multiplier;
	}

}