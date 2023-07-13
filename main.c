/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** main file of my_paint
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_window.h"
#include "paint_event.h"
#include "paint_background.h"
#include "paint_button.h"
#include "paint_edition.h"
#include "paint_slider.h"
#include "paint_textbox.h"

#include "paint_manager.h"

manager_t *init_manager(void)
{
    manager_t *end = malloc(sizeof(manager_t));

    end -> event = init_event();
    end -> back = NULL;
    end -> button_manager = NULL;
    end -> slider_manager = NULL;
    end -> edition = init_edition();
    return end;
}

sfRenderWindow **create_window_list(void)
{
    sfRenderWindow **w = malloc(sizeof(sfRenderWindow*) * (WINDOW_NUMBER + 1));

    w[WINDOW_NUMBER] = NULL;
    for (int i = 0; i < WINDOW_NUMBER; i++) {
        w[i] = create_window(i);
        if (i != 0)
            sfRenderWindow_setVisible(w[i], sfFalse);
    }
    return w;
}

int main(int ac, char **av)
{
    sfRenderWindow **fen_list;
    manager_t *manager = init_manager();

    fen_list = create_window_list();
    if (fen_list == NULL)
        return 84;
    manager -> back = create_back(fen_list[0]);
    manager -> button_manager = init_button_manager(fen_list[0]);
    manager -> slider_manager = init_slider_manager();
    manager -> textbox_manager = init_textbox_manager();
    run_paint(fen_list, manager);
}
