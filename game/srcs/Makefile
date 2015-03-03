NAME = First_Game

SRC = main.c display_menu.c game.c main.h display_pause.c move.c

SDL = `sdl-config --libs --cflags`

FLAGS = -Wall -Wextra -Werror

SDL_IMAGE = -lSDL_image

all:
	gcc -o $(NAME) $(SRC) $(FLAGS) $(SDL) $(SDL_IMAGE)

clean:
	rm -f $(NAME)

re: clean all

.PHONY = all clean re
