##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_makefile
##

SRC     =	main.c \
		init/window.c \
		paint/manager.c \
		event/event.c \
		event/mouse.c \
		event/init.c \
		background/background.c \
		button/init/button_init.c \
		button/init/drop_init.c \
		button/init/selection_init.c \
		button/init/front_button.c \
		button/manager.c \
		button/refresh/selection.c \
		button/refresh/refresh.c \
		button/refresh/drop.c \
		button/action/test.c \
		button/action/tools.c \
		slider/init.c \
		slider/refresh/refresh.c \
		slider/refresh/move.c \
		slider/refresh/calcul.c \
		textbox/init.c \
		textbox/refresh/refresh.c \
		textbox/refresh/selection.c \
		textbox/refresh/text.c \
		edition/refresh/refresh.c \
		edition/refresh/draw.c \
		edition/refresh/eraser.c \
		edition/refresh/hand.c \
		edition/init.c \
		file/save/save.c \
		file/open.c \
		file/new.c \
		other_window/validation_window/window.c \
		other_window/validation_window/init.c

OBJ     =	$(SRC:.c=.o)

NAME    =	my_paint

LINE	=	\n

TEST	=	lib/libmy.a

FLAGS   =       -lcsfml-system \
		-lcsfml-graphics \
		-lcsfml-window \
		-lcsfml-audio

all:    $(NAME)

.c.o:
	gcc -c $< -I include/ -L lib/ -lmy -lm -o $@ $(FLAGS)

$(NAME):        $(OBJ)
ifeq (,$(wildcard lib/libmy.a))
	cd lib/ && make && cd ../
endif
	gcc -o $(NAME) $(OBJ) -I include/ -L lib/ -lmy -lm $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
