/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** header for background
*/

#ifndef BACKGROUND_H_
    #define BACKGROUND_H_
    #include <SFML/Graphics.h>
    #include "paint_slider.h"
typedef struct background_t {
    sfRectangleShape *top_rect;
    sfRectangleShape *color_rect;
    sfRectangleShape *hide_d;
    sfRectangleShape *hide_r;
} background_t;

background_t *create_back(sfRenderWindow *fen);
void show_background(sfRenderWindow *f, background_t *b, slider_manager_t *s);
#endif
