#include "main.h"

void	display_pause(SDL_Surface *screen)
{
	SDL_Surface	*menu_pause;
	SDL_Surface	*button_resume;
	SDL_Surface	*button_menu;
	SDL_Surface	*button_quit;
	SDL_Rect	position_menu_pause;
	SDL_Rect	position_button_resume;
	SDL_Rect	position_button_menu;
	SDL_Rect	position_button_quit;
	SDL_Event	event;
	int		i;

	i = EXEC;
	position_menu_pause.x = 0;
	position_menu_pause.y = 0;
	position_button_resume.x = 540;
	position_button_resume.y = 100;
	position_button_menu.x = 540;
	position_button_menu.y = 300;
	position_button_quit.x = 540;
	position_button_quit.y = 500;
	menu_pause = IMG_Load("../sprites/menu_pause.jpg");
	button_resume = IMG_Load("../sprites/button_resume.jpg");
	button_menu = IMG_Load("../sprites/button_menu.jpg");
	button_quit = IMG_Load("../sprites/button_quit.jpg");
	SDL_SetAlpha(menu_pause, SDL_SRCALPHA, 128);
	SDL_BlitSurface(menu_pause, NULL, screen, &position_menu_pause);
	SDL_BlitSurface(button_resume, NULL, screen, &position_button_resume);
	SDL_BlitSurface(button_menu, NULL, screen, &position_button_menu);
	SDL_BlitSurface(button_quit, NULL, screen, &position_button_quit);
	SDL_Flip(screen);
	while (i != END)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			exit(EXIT_SUCCESS);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				i = END;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (event.motion.x >= 540 && event.motion.x <= 740 && event.motion.y >= 100 && event.motion.y <= 200)
					i = END;
				if (event.motion.x >= 540 && event.motion.x <= 740 && event.motion.y >= 300 && event.motion.y <= 400)
					display_menu(screen);
				if (event.motion.x >= 540 && event.motion.x <= 740 && event.motion.y >= 500 && event.motion.y <= 600)
					exit(EXIT_SUCCESS);
			}
		}
		SDL_Flip(screen);
	}
	SDL_FreeSurface(menu_pause);
	SDL_FreeSurface(button_resume);
	SDL_FreeSurface(button_menu);
	SDL_FreeSurface(button_quit);
}
