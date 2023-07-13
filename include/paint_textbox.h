/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** header for text box
*/

#ifndef TEXTBOX_T_
    #define TEXTBOX_T_
    #include <SFML/Graphics.h>
    #include "paint_event.h"
enum TEXT_BOX_NAME {
    BOX_WINDOW
};

typedef struct textbox_t {
    sfText *text;
    sfRectangleShape *background;

    sfVector2f position;
    sfVector2f size;

    sfColor background_color;
    sfColor background_ext_color;
    sfColor hover_color;
    sfColor selected_color;
    int background_thickness;

    sfColor text_color;
    char *allow_char;
    int window;
    int is_selected;
    int id;
} textbox_t;

typedef struct textbox_manager_t {
    textbox_t ** box_list;
} textbox_manager_t;

static const int BOX_NUMBER = 1;
static const textbox_t BOX_LIST[] = {
    {NULL, NULL,
    (sfVector2f) {20, 10}, (sfVector2f) {350, 40},
    (sfColor) {156, 51, 54, 255},
    (sfColor) {1, 210, 90, 255},
    (sfColor) {0, 50, 190, 255},
    (sfColor) {200, 210, 90, 255},
    5,
    (sfColor) {255, 255, 255, 255},
    "abcdefghijklmnopqrstuvwxyz._\\",
    1,
    0,
    0}
};

textbox_manager_t *init_textbox_manager(void);
void refresh_text_textbox(textbox_t *textbox, event_t *event);
#endif
