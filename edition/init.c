/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** for the init of edition
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_edition.h"
#include "my.h"

/*
typedef struct edition_t {
    sfImage *image;
    sfTexture *texture;
    sfSprite *image_display;
    sfSprite *background
} edition_t;
static const sfVector2f EDITOR_POSITION = {100, 300};
static const sfVector2d EDITOR_SIZE = {1000, 500};
*/

sfSprite *init_background(sfIntRect *rect)
{
    sfTexture *b_tex = sfTexture_createFromFile("src/img/alpha0.png", rect);
    sfSprite *end;

    if (b_tex == NULL) {
        my_putstr("Background texture not found (alpha0)\n");
        return NULL;
    }
    end = sfSprite_create();
    sfTexture_setRepeated(b_tex, sfTrue);
    sfSprite_setTexture(end, b_tex, sfFalse);
    sfSprite_setPosition(end, EDITOR_POSITION);
    sfSprite_setTextureRect(end, EDITOR_SIZE);
    return end;
}

edition_t *init_edition(void)
{
    edition_t *end = malloc(sizeof(edition_t));
    sfColor fill_color = {255, 255, 255, 255};
    sfIntRect rect = (sfIntRect) {0, 0, EDITOR_SIZE.width, EDITOR_SIZE.height};

    end -> image = sfImage_createFromColor(rect.width, rect.height, fill_color);
    end -> texture = sfTexture_createFromImage(end -> image, &rect);
    end -> image_display = sfSprite_create();
    end -> background = init_background(&rect);
    end -> hand_backup = (sfVector2i) {0, 0};
    end -> mouse_backup = (sfVector2i) {0, 0};
    end -> zoom = (sfVector2f) {1, 1};
    sfSprite_setTexture(end -> image_display, end -> texture, sfFalse);
    sfSprite_setPosition(end -> image_display, EDITOR_POSITION);
    sfSprite_setTextureRect(end -> image_display, EDITOR_SIZE);
    return end;
}
