#ifndef SCREEN_H
#define SCREEN_H

namespace screen
{
	class Screens
	{
	public:

		enum States
		{
			menu,
			instructions,
			gameplay,
			result,
			credits
		};

		States states;

		Screens();
		~Screens();

		void initData();

		void updateMenu();
		void drawMenu();

		void updateInstructions();
		void drawInstructions();

		void updateGameplay();
		void drawGameplay();

		void updateResult();
		void drawResult();

		void updateCredits();
		void drawCredits();

	};
}
#endif // !SCREEN_H

