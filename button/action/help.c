/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** for help
*/

#include "paint_button.h"
#include "paint_event.h"
#include "my.h"

void action_help(button_t *button, event_t *event)
{
    my_putstr("click sur help !\n");
}

void action_open(button_t *button, event_t *event)
{
    event -> button_execution = button -> id;
}
