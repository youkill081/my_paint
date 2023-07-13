/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** for background
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_background.h"
#include "paint_window.h"
#include "paint_macro.h"
#include "paint_slider.h"
#include "paint_macro.h"
#include "paint_color.h"
#include "my.h"

/*
  typedef struct background_t {
    sfRectangleShape *top_rect;
    sfRectangleShape *color_rect;
    sfRectangleShape *hide_d;
    sfRectangleShape *hide_r;
} background_t;
FEN_SIZE[i].x, FEN_SIZE[i].y,
 */

void create_hider(background_t *back)
{
    back -> hide_d = sfRectangleShape_create();
    back -> hide_r = sfRectangleShape_create();
    sfRectangleShape_setSize(back -> hide_d, (sfVector2f) {FEN_SIZE[0].x, 300});
    sfRectangleShape_setSize(back -> hide_r, (sfVector2f) {300, FEN_SIZE[0].y});
    sfRectangleShape_setFillColor(back -> hide_d, BACKGROUND_COLOR);
    sfRectangleShape_setFillColor(back -> hide_r, BACKGROUND_COLOR);
    sfRectangleShape_setPosition(back -> hide_d, (sfVector2f) {0, 780});
    sfRectangleShape_setPosition(back -> hide_r, (sfVector2f) {980, 200});
}

background_t *create_back(sfRenderWindow *window)
{
    background_t *back = malloc(sizeof(background_t));
    sfVector2u size = sfRenderWindow_getSize(window);

    back -> top_rect = sfRectangleShape_create();
    back -> color_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(back -> top_rect, (sfVector2f) {size.x, 150});
    sfRectangleShape_setFillColor(back -> top_rect, BACKGROUND_COLOR_H);
    sfRectangleShape_setSize(back -> color_rect, (sfVector2f) {100, 100});
    sfRectangleShape_setFillColor(back -> color_rect, (sfColor) {0, 0, 0, 255});
    sfRectangleShape_setPosition(back -> color_rect, (sfVector2f) {880, 30});
    create_hider(back);
    return back;
}

void update_color(slider_manager_t *sl_man, background_t *back)
{
    sfColor newcolor = {0, 0, 0, 255};
    newcolor.r = sl_man -> slider_list[SLIDER_RED] -> actual_value;
    newcolor.g = sl_man	-> slider_list[SLIDER_GREEN] -> actual_value;
    newcolor.b = sl_man	-> slider_list[SLIDER_BLUE] -> actual_value;
    sfRectangleShape_setFillColor(back -> color_rect, newcolor);
}

void show_background(sfRenderWindow *f, background_t *back, slider_manager_t *s)
{
    update_color(s, back);
    sfRenderWindow_drawRectangleShape(f, back -> top_rect, NULL);
    sfRenderWindow_drawRectangleShape(f, back -> color_rect, NULL);
}
