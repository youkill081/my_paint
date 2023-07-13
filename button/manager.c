/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** function for manager
*/

#include <SFML/Graphics.h>

#include "paint_button.h"
#include "paint_event.h"
#include "my.h"

void refresh_button(sfRenderWindow **fen, button_manager_t *man, event_t *ev)
{
    refresh_drop_menu(man, ev);
    refresh_selection_menu(man, ev);
    for (int i = 0; man -> button_list[i] != NULL; i++) {
        refresh_button_t(fen, man -> button_list[i], ev);
    }
}
