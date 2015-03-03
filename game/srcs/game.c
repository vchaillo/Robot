#include "main.h"

void	game(SDL_Surface *screen)
{
	SDL_Surface	*background;
	SDL_Surface	*ground;
	SDL_Surface	*bender;
	SDL_Surface	*monster;
	SDL_Rect	position_background;
	SDL_Rect	position_ground;
	SDL_Rect	position_bender;
	SDL_Rect	position_monster;
	SDL_Event	event;
	int		i;
	int		time;
	int		old_time;
	
	i = EXEC;
	position_background.x = 0;
	position_background.y = 0;
	position_ground.x = 0;
	position_ground.y = 563;
	background = IMG_Load("../sprites/background.jpg");
	ground = IMG_Load("../sprites/ground.png");
	bender = IMG_Load("../sprites/bender_right.png");
	monster = IMG_Load("../sprites/monster.png");
	position_bender.x = position_ground.x;
	position_bender.y = position_ground.y - bender->h + 4;
	position_monster.x = 1200;
	position_monster.y = position_ground.y - monster->h + 4;
	SDL_BlitSurface(background, NULL, screen, &position_background);
	SDL_BlitSurface(bender, NULL, screen, &position_bender);
	SDL_BlitSurface(monster, NULL, screen, &position_monster);
	SDL_BlitSurface(ground, NULL, screen, &position_ground);
	SDL_Flip(screen);	
	SDL_EnableKeyRepeat(100, 10);
	while (i != END)
	{
		time = SDL_GetTicks();
		if (time - old_time > 30)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					exit(EXIT_SUCCESS);
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
						display_pause(screen);
					if (event.key.keysym.sym == SDLK_RIGHT)
					{
						bender = IMG_Load("../sprites/bender_right.png");
						position_bender.x = position_bender.x + 5;
					}
					if (event.key.keysym.sym == SDLK_LEFT)
					{
						bender = IMG_Load("../sprites/bender_left.png");
						position_bender.x = position_bender.x - 5;
					}
				}
			}
			position_monster.x = position_monster.x - 5;
			SDL_BlitSurface(background, NULL, screen, &position_background);
			SDL_BlitSurface(bender, NULL, screen, &position_bender);
			SDL_BlitSurface(monster, NULL, screen, &position_monster);
			SDL_BlitSurface(ground, NULL, screen, &position_ground);
			SDL_Flip(screen);
			old_time = time;
		}
		else
			SDL_Delay(30 - (time - old_time));
	}
	SDL_FreeSurface(background);
	SDL_FreeSurface(ground);
	SDL_FreeSurface(bender);
	SDL_FreeSurface(monster);
}
