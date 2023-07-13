/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main file of event manadgement
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "my.h"
#include "paint_event.h"

void close_window(sfRenderWindow *window, int close_type)
{
    if (close_type == 1) {
        sfRenderWindow_close(window);
        return;
    }
    if (close_type == 2) {
        sfRenderWindow_setVisible(window, sfFalse);
        return;
    }
    my_putstr("Window close type doesn't exist\n");
}

void set_keyboard_state(event_t *ev, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        ev -> key_pressed = event.text.unicode;
    }
}

int manadge_event(sfRenderWindow *fen, event_t *ev, int c_type)
{
    sfEvent event;
    int i = 0;

    ev -> key_pressed = -1;
    while (sfRenderWindow_pollEvent(fen, &event)) {
        set_mouse_state(event, ev, 1, fen);
        set_keyboard_state(ev, event);
        if (event.type == sfEvtClosed) {
            close_window(fen, c_type);
            return 1;
        }
        i++;
    }
    if (i == 0)
        set_mouse_state(event, ev, 0, fen);
    return 0;
}
