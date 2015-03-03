#include "main.h"

SDL_Rect	move(SDL_Rect *position_bender)
{
	SDL_Event	event;
	SDL_Rect	new_position;
	int		i;

	i = EXEC;
	while (i != END)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_LEFT)
			{
//				if (colision(screen, bender, level, event) == TRUE)
					new_position.x = position_bender->x--;
					i = END;
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
//				if (colision(screen, bender, level, event) == TRUE)
					new_position.x = position_bender->x++;
					i = END;
			}
		}
	}
	return (new_position);
}
