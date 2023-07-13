/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** initialisation of textbox
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_textbox.h"
#include "my.h"

void init_text_textbox(textbox_t *end)
{
    sfFont *font = sfFont_createFromFile("src/font/arial.ttf");
    sfVector2f textpos = end -> position;
    unsigned int c_size;
    float sy = end->size.y + end -> background_thickness * 2;
    end -> text = sfText_create();
    if (font == NULL) {
        my_putstr("can't find font (textbox)\n");
        return;
    }
    sfText_setFont(end -> text, font);
    c_size = sfText_getCharacterSize(end -> text);
    sfText_setColor(end -> text, end -> text_color);
    textpos.y = end->position.y + sy / 2 - c_size;
    sfText_setPosition(end -> text, textpos);
}

void init_background_textbox(textbox_t *end)
{
    sfRectangleShape *back = NULL;

    end -> background = sfRectangleShape_create();
    back = end -> background;
    sfRectangleShape_setSize(back, end -> size);
    sfRectangleShape_setPosition(back, end -> position);
    sfRectangleShape_setFillColor(back, end -> background_color);
    sfRectangleShape_setOutlineThickness(back, end -> background_thickness);
    sfRectangleShape_setOutlineColor(back, end -> background_ext_color);
}

textbox_t *init_textbox(int i)
{
    textbox_t *end = malloc(sizeof(textbox_t));

    if (end == NULL)
        return end;
    end -> position = BOX_LIST[i].position;
    end -> size = BOX_LIST[i].size;
    end -> background_color = BOX_LIST[i].background_color;
    end -> background_ext_color = BOX_LIST[i].background_ext_color;
    end -> hover_color = BOX_LIST[i].hover_color;
    end -> selected_color = BOX_LIST[i].selected_color;
    end -> background_thickness = BOX_LIST[i].background_thickness;
    end -> text_color = BOX_LIST[i].text_color;
    end -> allow_char = BOX_LIST[i].allow_char;
    end -> window = BOX_LIST[i].window;
    end -> id = BOX_LIST[i].id;
    end -> is_selected = 0;
    init_text_textbox(end);
    init_background_textbox(end);
    return end;
}

textbox_manager_t *init_textbox_manager(void)
{
    textbox_manager_t *end = malloc(sizeof(textbox_manager_t));

    end -> box_list = malloc(sizeof(textbox_t) * (BOX_NUMBER + 1));
    if (end == NULL || end -> box_list == NULL)
        return NULL;
    end -> box_list[BOX_NUMBER] = NULL;
    for (int i = 0; i < BOX_NUMBER; i++) {
        end -> box_list[i] = init_textbox(i);
    }
    return end;
}
