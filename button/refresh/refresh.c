/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to refresh the button
*/

#include <SFML/Graphics.h>

#include "paint_button.h"
#include "paint_event.h"
#include "my.h"

button_t *get_button(button_manager_t *manager, int id)
{
    for (int i = 0; manager -> button_list[i] != NULL; i++) {
        if (manager -> button_list[i] -> id == id)
            return manager -> button_list[i];
    }
    return NULL;
}

int mouse_hover(button_t *button, event_t *event)
{
    if (event->mouse_position.x >= button->position.x &&
        event->mouse_position.x <= button->position.x + button->size.x) {
        if (event->mouse_position.y >= button->position.y &&
            event->mouse_position.y <= button->position.y + button->size.y) {
            return 1;
        }
    }
    return 0;
}

void check_click(button_t *button, event_t *event)
{
    if (mouse_hover(button, event) && event -> mouse_state == RELEASED) {
        if (button -> executor != NULL)
            button -> executor(button, event);
    }
}

void set_hover(button_t *button, event_t *event)
{
    if (mouse_hover(button, event) || button -> state == SELECTED) {
        sfRectangleShape_setFillColor(button->rectangle, button->hover_color);
        return;
    }
    sfRectangleShape_setFillColor(button->rectangle, button->base_color);
}

void refresh_button_t(sfRenderWindow **fen, button_t *button, event_t *event)
{
    sfRenderWindow *b_fen = fen[button -> window];

    if (button -> state == SHOW || button -> state == SELECTED) {
        set_hover(button, event);
        check_click(button, event);
        sfRenderWindow_drawRectangleShape(b_fen, button -> rectangle, NULL);
        if (button -> type == BUTTON_TEXT) {
            sfRenderWindow_drawText(b_fen, button -> text, NULL);
            return;
        }
        if (button -> type == BUTTON_IMAGE && button -> image != NULL) {
            sfRenderWindow_drawSprite(b_fen, button -> image, NULL);
        }
    }
}
