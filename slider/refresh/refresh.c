/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to refresh slider
*/

#include <SFML/Graphics.h>
#include <math.h>

#include "paint_slider.h"
#include "paint_event.h"
#include "my.h"

int is_hover(slider_t *slider, event_t *event)
{
    sfVector2f circlePosition = sfCircleShape_getPosition(slider->slider);
    int radius = sfCircleShape_getRadius(slider->slider);
    float distance;
    float dx;
    float dy;

    circlePosition.x += radius;
    circlePosition.y += radius;
    dx = pow(event->mouse_position.x - circlePosition.x, 2);
    dy = pow(event->mouse_position.y - circlePosition.y, 2);
    distance = sqrt(dx + dy);
    if (distance <= radius)
        return 1;
    return 0;
}

void set_moving(slider_t *slider, event_t *event)
{
    if (event -> mouse_state == HOLD)
        slider -> was_moving = 1;
    else
        slider -> was_moving = 0;
}

void refresh_slider_s(sfRenderWindow *fen, slider_t *slider, event_t *event)
{
    sfColor hoverColor;

    sfRenderWindow_drawRectangleShape(fen, slider -> slider_back, NULL);
    sfRenderWindow_drawCircleShape(fen, slider -> slider, NULL);
    if (is_hover(slider, event) || slider -> was_moving) {
        move_slider(slider, event);
        hoverColor = slider -> slider_hover_color;
        sfCircleShape_setFillColor(slider -> slider, hoverColor);
        set_moving(slider, event);
    } else {
        sfCircleShape_setFillColor(slider -> slider, slider -> slider_color);
    }
    calcul_new_value(slider);
}

void refresh_slider(sfRenderWindow **fen, slider_manager_t *slide_m, event_t *e)
{
    if (slide_m == NULL)
        return;
    for (int i = 0; slide_m -> slider_list[i] != NULL; i++) {
        refresh_slider_s(fen[0], slide_m -> slider_list[i], e);
    }
}
