/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to init the front of the button
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "paint_button.h"
#include "my.h"

void set_text_position(button_t *b)
{
    sfFloatRect text_rect = sfText_getLocalBounds(b -> text);
    sfFloatRect rect_rect = sfRectangleShape_getLocalBounds(b -> rectangle);
    sfVector2f f_pos = {0, 0};
    float c = 1.22;

    if (b -> text_align == CENTER) {
        f_pos.x = b->position.x + rect_rect.width / 2 - text_rect.width / 2;
        f_pos.y = b->position.y + rect_rect.height / 2 - text_rect.height / c;
    }
    if (b -> text_align == LEFT) {
        f_pos.x = b->position.x + 10;
        f_pos.y = b->position.y + rect_rect.height / 2 - text_rect.height / c;
    }
    sfText_setPosition(b -> text, f_pos);
}

void init_text(button_t *button, int i)
{
    sfFont *font = sfFont_createFromFile("src/font/arial.ttf");

    button -> text = sfText_create();
    if (font == NULL) {
        my_putstr("PERDU");
        return;
    }
    sfText_setFont(button -> text, font);
    sfText_setString(button -> text, button -> button_text);
    sfText_setCharacterSize(button -> text, 20);
    sfText_setColor(button -> text, button -> text_color);
    set_text_position(button);
}

void place_image(button_t *button)
{
    sfVector2f new_scale = {1, 1};
    sfFloatRect  image_scale = sfSprite_getLocalBounds(button -> image);

    new_scale.x = button -> size.x / image_scale.width;
    new_scale.y = button -> size.y / image_scale.height;
    sfSprite_setScale(button -> image, new_scale);
    sfSprite_setPosition(button -> image, button -> position);
}

void init_image(button_t *button, int i)
{
    sfTexture *t_button = sfTexture_createFromFile(button -> button_text, NULL);

    if (t_button == NULL) {
        my_putstr("ERROR: texture for button not found\n");
        return;
    }
    button -> image = sfSprite_create();
    sfSprite_setTexture(button -> image, t_button, sfFalse);
    place_image(button);
}

void init_front(button_t *button, int i)
{
    if (button -> type == BUTTON_TEXT) {
        init_text(button, i);
        return;
    } else if (button -> type == BUTTON_IMAGE) {
        init_image(button, i);
        return;
    }
    my_putstr("ERROR: button type not found\n");
}
