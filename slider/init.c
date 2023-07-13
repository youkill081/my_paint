/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to init sliders
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_slider.h"

/*
  float pos_rect_x = sfRectangleShape_getPosition(slider -> slider_back).x;

    pos_rect_x -= sfCircleShape_getRadius(slider -> slider);
 */

void init_circle_slider(slider_t *slider)
{
    sfVector2f pos = {slider -> position.x - 13, slider -> position.y - 5.5};

    slider -> slider = sfCircleShape_create();
    sfCircleShape_setPosition(slider -> slider, pos);
    sfCircleShape_setRadius(slider -> slider, 13);
    sfCircleShape_setFillColor(slider -> slider, slider -> slider_color);
}

void init_rect_slider(slider_t *slider)
{
    sfVector2f size = {slider -> lenght, 15};

    slider -> slider_back = sfRectangleShape_create();
    sfRectangleShape_setSize(slider -> slider_back, size);
    sfRectangleShape_setFillColor(slider -> slider_back, slider -> rect_color);
    sfRectangleShape_setPosition(slider -> slider_back, slider -> position);
}

slider_t *init_slider(int i)
{
    slider_t *end = malloc(sizeof(slider_t));

    if (end == NULL)
        return NULL;
    end -> lenght = SLIDER_LIST[i].lenght;
    end -> max_value = SLIDER_LIST[i].max_value;
    end -> actual_value = SLIDER_LIST[i].actual_value;
    end -> id = SLIDER_LIST[i].id;
    end -> slider_color = SLIDER_LIST[i].slider_color;
    end -> slider_hover_color = SLIDER_LIST[i].slider_hover_color;
    end -> rect_color = SLIDER_LIST[i].rect_color;
    end -> position = SLIDER_LIST[i].position;
    end -> was_moving = 0;
    init_rect_slider(end);
    init_circle_slider(end);
    return end;
}

slider_manager_t *init_slider_manager(void)
{
    slider_manager_t *manager = malloc(sizeof(slider_manager_t));

    if (manager == NULL)
        return NULL;
    manager -> slider_list = malloc(sizeof(slider_t) * (NBR_SLIDER + 1));
    if (manager -> slider_list == NULL)
        return NULL;
    manager -> slider_list[NBR_SLIDER] = NULL;
    for (int i = 0; i < NBR_SLIDER; i++) {
        manager -> slider_list[i] = init_slider(i);
    }
    return manager;
}
