NAME = asteriod

all: $(NAME)

$(NAME): 
	gcc src/* -o asteriod -g -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0 -l ft `sdl2-config --cflags --libs`

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
