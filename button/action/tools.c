/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** action for tools button
*/

#include "paint_button.h"
#include "paint_event.h"
#include "my.h"

void action_pen(button_t *button, event_t *event)
{
    my_putstr("click pen\n");
}

void action_eraser(button_t *button, event_t *event)
{
    my_putstr("click eraser\n");
}
