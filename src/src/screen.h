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
			loading,
			gameplay,
			result,
			credits
		};

		States states;

		Screens();
		~Screens();

		void updateMenu();
		void drawMenu();

		void updateLoading();
		void drawLoading();

		void updateGameplay();
		void drawGameplay();

		void updateResult();
		void drawResult();

		void updateCredits();
		void drawCredits();

	};
}
#endif // !SCREEN_H

