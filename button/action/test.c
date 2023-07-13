/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** button test
*/

#include "paint_button.h"
#include "paint_event.h"
#include "my.h"

void action_open(button_t *button, event_t *event)
{
    event -> button_execution = button -> id;
}

void action_about(button_t *button, event_t *event)
{
    event -> button_execution = B_ABOUT;
}

void action_newfile(button_t *button, event_t *event)
{
    event -> button_execution = B_NEW_FILE;
}
