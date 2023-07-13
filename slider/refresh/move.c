/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** small file, contain function to move slider
*/

#include <SFML/Graphics.h>

#include "paint_slider.h"
#include "paint_event.h"

float recalc_pos(slider_t *slider, float x)
{
    float pos_rect_x = sfRectangleShape_getPosition(slider -> slider_back).x;
    float lenght;

    pos_rect_x -= sfCircleShape_getRadius(slider -> slider);
    if (x >= pos_rect_x + slider -> lenght) {
        lenght = slider -> position.x + slider -> lenght;
        return lenght - sfCircleShape_getRadius(slider -> slider);
    }
    if (x <= pos_rect_x)
        return slider -> position.x - sfCircleShape_getRadius(slider -> slider);
    return x;
}

void move_slider(slider_t *slider, event_t *event)
{
    int radius;
    sfVector2f circle_pos;
    if (event -> mouse_state == HOLD) {
        circle_pos = sfCircleShape_getPosition(slider -> slider);
        radius = sfCircleShape_getRadius(slider -> slider);
        circle_pos.x = event -> mouse_position.x - radius;
        circle_pos.x = recalc_pos(slider, circle_pos.x);
        sfCircleShape_setPosition(slider -> slider, circle_pos);
    }
}
