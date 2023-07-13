/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** contain evry pointed needed
*/

#ifndef MANAGER_H_
    #define MANAGER_H_
    #include "paint_event.h"
    #include "paint_background.h"
    #include "paint_button.h"
    #include "paint_edition.h"
    #include "paint_slider.h"
    #include "paint_textbox.h"
typedef struct manager_t {
    event_t *event;
    background_t *back;
    button_manager_t *button_manager;
    slider_manager_t *slider_manager;
    textbox_manager_t *textbox_manager;
    edition_t *edition;
} manager_t;
#endif
