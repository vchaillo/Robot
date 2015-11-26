#include "main.h"

int	main(void)
{
	SDL_Surface	*screen;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetIcon(IMG_Load("../sprites/icon.bmp"), NULL);
	screen = SDL_SetVideoMode(WIN_W, WIN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		fprintf(stderr, "Impossible de charger le mode Vidéo : %s\n", SDL_GetError());
	}
	SDL_WM_SetCaption("First_Game", NULL);
	display_menu(screen);
	SDL_FreeSurface(screen);
	SDL_Quit();
	return (0);
}
