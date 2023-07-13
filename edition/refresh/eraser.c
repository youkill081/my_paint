/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** for eraser
*/

#include <SFML/Graphics.h>

#include "paint_edition.h"
#include "paint_manager.h"
#include "paint_event.h"

sfVector2i get_coordinate_in_area(manager_t *man, sfVector2i m_pos);

void erase(manager_t *man, int s)
{
    edition_t *edition = man -> edition;
    event_t *event = man -> event;
    sfVector2i co_in = get_coordinate_in_area(man, event -> mouse_position);
    sfColor color = {255, 255, 255, 0};

    if (event -> mouse_state == HOLD) {
        draw_circle(edition, (sfVector2i) {co_in.x, co_in.y}, s, &color);
    }
}

void refresh_eraser(manager_t *manager, int s)
{
    if (mouse_in_rect(manager -> event)) {
        erase(manager, s);
    }
}
