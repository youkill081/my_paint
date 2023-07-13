/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to open image
*/

#include <SFML/Graphics.h>

#include "paint_validation_window.h"
#include "paint_manager.h"
#include "my.h"

/*
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
    end -> zoom = (sfVector2f) {1, 1};
    sfSprite_setTexture(end -> image_display, end -> texture, sfFalse);
    sfSprite_setPosition(end -> image_display, EDITOR_POSITION);
    sfSprite_setTextureRect(end -> image_display, EDITOR_SIZE);
    return end;
}


 */

sfImage *create_image(char *path)
{
    if (path == NULL)
        return NULL;
    return sfImage_createFromFile(path);
}

void open_image(sfRenderWindow **fen, manager_t *manager)
{
    sfImage *new = create_image(validation_window(fen, manager));
    sfIntRect rect = (sfIntRect) {0, 0, EDITOR_SIZE.width, EDITOR_SIZE.height};
    edition_t *edition = manager -> edition;

    if (new == NULL) {
        return;
    }
    manager -> edition -> image = new;
    manager -> edition -> texture = sfTexture_createFromImage(new, NULL);
    sfSprite_setTexture(edition -> image_display, edition -> texture, sfFalse);
}
