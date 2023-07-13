/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to init event
*/

#include <stdlib.h>

#include "paint_event.h"
#include "my.h"

event_t *init_event(void)
{
    event_t *end = malloc(sizeof(event_t));

    end -> mouse_position = (sfVector2i) {-1, -1};
    end -> key_pressed = -1;
    end -> button_execution = -1;
    return end;
}
