#ifndef PLAYER_H
#define PLAYER_H
namespace player {

	class player {
		int _hp;
		float _score;
		float _multiplier;
	public:
		void setHP(int hp);
		int getHP();
		void setScore(float score);
		float getScore();
		void setMultiplier(float multiplier);
		float getMultiplier();
	};

}

#endif // !PLAYER_H

