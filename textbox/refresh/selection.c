/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** refresh for the selection textbox
*/

#include <SFML/Graphics.h>

#include "paint_manager.h"
#include "my.h"

int mouse_hover_box(textbox_t *box, event_t *event)
{
    if (event->mouse_position.x >= box->position.x &&
        event->mouse_position.x <= box->position.x + box->size.x) {
        if (event->mouse_position.y >= box->position.y &&
            event->mouse_position.y <= box->position.y + box->size.y) {
            return 1;
        }
    }
    return 0;
}

void unselect_all(textbox_manager_t *box_manager)
{
    for (int i = 0; box_manager -> box_list[i] != NULL; i++) {
        box_manager -> box_list[i] -> is_selected = 0;
    }
}

void refresh_selection_textbox(textbox_t *box, event_t *event, manager_t *man)
{
    int hover = mouse_hover_box(box, event);
    sfRectangleShape *back = box -> background;

    if (box -> is_selected)
        return;
    if (hover && event -> mouse_state == PRESSED) {
        unselect_all(man -> textbox_manager);
        box -> is_selected = 1;
        sfRectangleShape_setOutlineColor(back, box -> selected_color);
        return;
    }
    if (hover) {
        sfRectangleShape_setOutlineColor(back, box -> hover_color);
        return;
    }
    sfRectangleShape_setOutlineColor(back, box -> background_ext_color);
}
