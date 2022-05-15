NAME = asteriod

all: $(NAME)

$(NAME):
	@echo "Installing..."
	@gcc src/* -o asteriod -O3 -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0 -l ft `sdl2-config --cflags --libs`
	@echo "Install complete."

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	@echo "Starting Asteriod."
	@./$(NAME)
