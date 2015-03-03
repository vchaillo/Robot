#ifndef MAIN_H
# define MAIN_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

# define EXEC 1
# define END 0
# define TRUE 1
# define FALSE 0

void		display_menu(SDL_Surface *screen);
void		display_pause(SDL_Surface *screen);
void		game(SDL_Surface *screen);
SDL_Rect	move(SDL_Rect *position_bender);

#endif
