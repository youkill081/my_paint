/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** header for sliders
*/

#ifndef SLIDER_H_
    #define SLIDER_H_
    #include <SFML/Graphics.h>
    #include "paint_event.h"
enum SLIDER_NAME{
    SLIDER_RED,
    SLIDER_BLUE,
    SLIDER_GREEN,
    SLIDER_SIZE,
    SLIDER_ZOOM
};

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
typedef struct slider_manager_t {
    slider_t **slider_list;
} slider_manager_t;

static const int NBR_SLIDER = 5;
static const slider_t SLIDER_LIST[] = {
    {NULL, NULL,
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    200,
    255,
    0,
    1, 0, {650, 30}},

    {NULL, NULL,
    {0, 0, 255, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    200,
    255,
    0,
    2, 0, {650, 70}},

    {NULL, NULL,
    {0, 255, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    200,
    255,
    0,
    3, 0, {650, 110}},

    {NULL, NULL,
    {82, 77, 81, 255},
    {82, 77, 81, 255},
    {129, 122, 127, 255},
    150,
    100,
    0,
    4, 0, {24, 127.5}},

    {NULL, NULL,
    {82, 77, 81, 255},
    {82, 77, 81, 255},
    {129, 122, 127, 255},
    500,
    140,
    0,
    4, 0, {50, 950}}
};

void refresh_slider(sfRenderWindow **fen, slider_manager_t *slider, event_t *e);
void move_slider(slider_t *slider, event_t *event);
slider_manager_t *init_slider_manager(void);
void calcul_new_value(slider_t *slider);
#endif
