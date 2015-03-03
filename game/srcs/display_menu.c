#include "main.h"

void	display_menu(SDL_Surface *screen)
{
	SDL_Surface	*menu;
	SDL_Surface	*button_new_game;
	SDL_Surface	*button_quit;
	SDL_Rect	position_menu;
	SDL_Rect	position_button_new_game;
	SDL_Rect	position_button_quit;
	SDL_Event	event;
	int		i;

	i = EXEC;
	position_menu.x = 0;
	position_menu.y = 0;
	position_button_new_game.x = 800;
	position_button_new_game.y = 200;
	position_button_quit.x = 800;
	position_button_quit.y = 400;
	menu = IMG_Load("../sprites/menu.jpg");
	button_new_game = IMG_Load("../sprites/button_new_game.jpg");
	button_quit = IMG_Load("../sprites/button_quit.jpg");
	SDL_BlitSurface(menu, NULL, screen, &position_menu);
	SDL_BlitSurface(button_new_game, NULL, screen, &position_button_new_game);
	SDL_BlitSurface(button_quit, NULL, screen, &position_button_quit);
	SDL_Flip(screen);
	while (i != END)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			i = END;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit(EXIT_SUCCESS);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (event.motion.x >= 800 && event.motion.x <= 1000 && event.motion.y >= 200 && event.motion.y <= 300)
						game(screen);
					if (event.motion.x >= 800 && event.motion.x <= 1000 && event.motion.y >= 400 && event.motion.y <= 500)
						exit(EXIT_SUCCESS);
				}
		}
		SDL_BlitSurface(menu, NULL, screen, &position_menu);
		SDL_BlitSurface(button_new_game, NULL, screen, &position_button_new_game);
		SDL_BlitSurface(button_quit, NULL, screen, &position_button_quit);
		SDL_Flip(screen);
	}
	SDL_FreeSurface(menu);
}
