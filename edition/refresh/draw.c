/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** file for draw
*/

#include <SFML/Graphics.h>
#include <math.h>

#include "paint_edition.h"
#include "paint_manager.h"
#include "paint_event.h"
#include "my.h"

int mouse_in_rect(event_t *event)
{
    if (event->mouse_position.x >= EDITOR_POSITION.x &&
        event->mouse_position.x <= EDITOR_POSITION.x + EDITOR_SIZE.width) {
        if (event->mouse_position.y >= EDITOR_POSITION.y &&
            event->mouse_position.y <= EDITOR_POSITION.y + EDITOR_SIZE.height) {
            return 1;
        }
    }
    return 0;
}

sfVector2i get_coordinate_in_area(manager_t *m, sfVector2i m_pos)
{
    edition_t *edition = m -> edition;
    sfVector2i end = {0, 0};
    sfIntRect view = sfSprite_getTextureRect(edition -> image_display);
    float z = m -> slider_manager -> slider_list[SLIDER_ZOOM] -> actual_value;

    z = (z + 10) / 10;
    end.x = ((m_pos.x - EDITOR_POSITION.x) / z) + view.left;
    end.y = ((m_pos.y - EDITOR_POSITION.y) / z) + view.top;
    return end;
}

void draw_pixel(sfImage *image, int x, int y, sfColor *color)
{
    sfVector2u size = sfImage_getSize(image);

    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;
    sfImage_setPixel(image, x, y, *color);
}

// methode du tracé de cercle de Bresenham
void draw_circle(edition_t * ed, sfVector2i co, int r, sfColor *color)
{
    int x = co.x;
    int y = co.y;
    int d = 3 - 2 * r;
    int i = 0;
    int j = r;
    while (i <= j) {
        for (int k = -j; k <= j; k++) {
            draw_pixel(ed->image, x + i, y + k, color);
            draw_pixel(ed->image, x - i, y + k, color);
            draw_pixel(ed->image, x + k, y + i, color);
            draw_pixel(ed->image, x + k, y - i, color);
        }
        if (d < 0) {
            d = d + 4 * i + 6;
        } else {
            d = d + 4 * (i - j) + 10;
            j--;
        }
        i++;
    }
}

void refresh_drawing(manager_t *manager, sfColor *color, int s)
{
    sfVector2i co_in;
    edition_t *edition = manager -> edition;
    event_t *event = manager -> event;

    if (mouse_in_rect(event)) {
        co_in = get_coordinate_in_area(manager, event -> mouse_position);
        if (event -> mouse_state == HOLD) {
            draw_circle(edition, (sfVector2i) {co_in.x, co_in.y}, s, color);
        }
        manager -> edition -> mouse_backup = co_in;
    }
}
