#include "player.h"

namespace player 
{

	void player::setHP(int hp)
	{
		_hp = hp;
	}
	int player::getHP()
	{
		return _hp;
	}

	void player::setScore(float score)
	{
		_score = score;
	}
	float player::getScore()
	{
		return _score;
	}

	void player::setMultiplier(float multiplier)
	{
		_multiplier = multiplier;
	}
	float player::getMultiplier()
	{
		return _multiplier;
	}

}