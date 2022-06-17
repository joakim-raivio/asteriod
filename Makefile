NAME = asteriod
CFLAGS = $(shell sdl2-config --cflags)
LIB = $(shell sdl2-config --libs)

all: $(NAME)

$(NAME):
	@echo "Installing..."
	gcc src/* -o asteriod -O3 -I include -L lib -l ft $(CFLAGS) $(LIB) -l SDL2_image-2.0.0
	@echo "Install complete."

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	@echo "Starting Asteriod."
	@./$(NAME)
