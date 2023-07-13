/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** for the edition of image
*/

#ifndef EDITION_H_
    #define EDITION_H_
    #include <SFML/Graphics.h>
    #include "paint_event.h"
typedef struct edition_t {
    sfImage *image;
    sfTexture *texture;
    sfSprite *image_display;
    sfSprite *background;

    sfVector2f zoom;
    sfVector2i hand_backup;
    sfVector2i mouse_backup;
    int move_start;
} edition_t;

static const sfVector2f EDITOR_POSITION = {50, 250};
static const sfIntRect EDITOR_SIZE = {0, 0, 930, 530};

edition_t *init_edition(void);
int mouse_in_rect(event_t *event);
void refresh_hand(edition_t *edition, event_t *event);
void draw_circle(edition_t * ed, sfVector2i co, int r, sfColor *color);
#endif
