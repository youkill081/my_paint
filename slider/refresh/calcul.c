/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** small file for slider calcul
*/

#include <SFML/Graphics.h>

#include "paint_slider.h"
#include "my.h"

/*
  int can_go_slider(slider_t *slider, float x)
{
    float pos_rect_x = sfRectangleShape_getPosition(slider -> slider_back).x;

    pos_rect_x -= sfCircleShape_getRadius(slider -> slider);
    if (x >= pos_rect_x && x <= pos_rect_x + slider -> lenght)
        return 1;
    return 0;
}

typedef struct slider_t {
    sfRectangleShape *slider_back;
    sfCircleShape  *slider;
    sfColor rect_color;
    sfColor slider_color;
    sfColor slider_hover_color;
    int lenght;
    int max_value;
    int actual_value;
    int id;
    int was_moving;
    sfVector2f position;
} slider_t;

 */

void calcul_new_value(slider_t *slider)
{
    float circle_x = sfCircleShape_getPosition(slider -> slider).x;

    circle_x += sfCircleShape_getRadius(slider -> slider);
    circle_x -= slider -> position.x;
    slider -> actual_value = circle_x / slider -> lenght * slider -> max_value;
}
