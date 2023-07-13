/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** all event for mouse
*/

#include <SFML/Graphics.h>

#include "my.h"
#include "paint_event.h"

void show_mouse_pos(event_t *list)
{
    my_putstr("mouse position : ");
    my_put_nbr(list -> mouse_position.x);
    my_putchar(' ');
    my_put_nbr(list -> mouse_position.y);
    my_putchar('\n');
}

void set_mouse_state_null(event_t *list)
{
    switch (list -> mouse_state) {
    case PRESSED:
        list -> mouse_state = HOLD;
        break;
    case RELEASED:
        list -> mouse_state = NOTHING;
        break;
    }
}

void set_mouse_position(sfEvent event, event_t *list, sfRenderWindow *fen)
{
    sfVector2f cp;

    if (event.type == sfEvtMouseMoved) {
        list -> mouse_position.x = event.mouseMove.x;
        list -> mouse_position.y = event.mouseMove.y;
        cp = sfRenderWindow_mapPixelToCoords(fen, list -> mouse_position, NULL);
        list -> mouse_position.x = (int) cp.x;
        list -> mouse_position.y = (int) cp.y;
    }
}

void set_mouse_state(
    sfEvent event,
    event_t *list,
    int has_e,
    sfRenderWindow *fen)
{
    set_mouse_position(event, list, fen);
    if (!has_e) {
        set_mouse_state_null(list);
        return;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        list -> mouse_state = PRESSED;
        return;
    }
    if (event.type == sfEvtMouseButtonReleased) {
        list -> mouse_state = RELEASED;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        list -> mouse_state = HOLD;
        return;
    }
    list -> mouse_state = NOTHING;
}

void say_mouse_state(event_t *list)
{
    switch (list -> mouse_state) {
    case PRESSED:
        my_putstr("mouse: PRESSED\n");
        break;
    case RELEASED:
        my_putstr("mouse: RELEASED\n");
        break;
    case NOTHING:
        my_putstr("mouse: NOTHING\n");
        break;
    case HOLD:
        my_putstr("mouse: HOLD\n");
    }
}
