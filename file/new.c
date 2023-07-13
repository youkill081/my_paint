/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to create image
*/

#include <SFML/Graphics.h>

#include "paint_manager.h"

void new_image(sfRenderWindow **fen, manager_t *manager)
{
    sfColor fill_color = {255, 255, 255, 255};
    sfIntRect rect = (sfIntRect) {0, 0, EDITOR_SIZE.width, EDITOR_SIZE.height};
    sfImage *new = sfImage_createFromColor(rect.width, rect.height, fill_color);
    edition_t *edition = manager -> edition;

    manager -> edition -> image = new;
    manager -> edition -> texture = sfTexture_createFromImage(new, NULL);
    sfSprite_setTexture(edition -> image_display, edition -> texture, sfFalse);
}
