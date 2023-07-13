/*
** EPITECH PROJECT, 2023
** my_pain
** File description:
** button manager
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

#include "paint_button.h"
#include "my.h"

void init_rectangle(button_t *button, int i)
{
    button->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rectangle, button->size);
    sfRectangleShape_setPosition(button->rectangle, button->position);
}

button_t *create_button_from_macro(button_manager_t *manager, int i)
{
    button_t *end = malloc(sizeof(button_t));

    end -> size = BUTTON_LIST_SIZE[i].size;
    end -> position = BUTTON_LIST_SIZE[i].position;
    end -> base_color = BUTTON_LIST_SIZE[i].base_color;
    end -> hover_color = BUTTON_LIST_SIZE[i].hover_color;
    end -> text_color = BUTTON_LIST_SIZE[i].text_color;
    end -> executor = BUTTON_LIST_SIZE[i].executor;
    end -> button_text = BUTTON_LIST_SIZE[i].button_text;
    end -> text_align = BUTTON_LIST_SIZE[i].text_align;
    end	-> window = BUTTON_LIST_SIZE[i].window;
    end -> state = BUTTON_LIST_SIZE[i].state;
    end -> type = BUTTON_LIST_SIZE[i].type;
    end -> id = BUTTON_LIST_SIZE[i].id;
    end -> is_hover = &mouse_hover;
    end -> image = NULL;
    init_rectangle(end, i);
    init_front(end, i);
    return end;
}

button_manager_t *init_button_manager(sfRenderWindow *windows)
{
    button_manager_t *manager = malloc(sizeof(button_manager_t));
    int i = 0;

    manager -> button_list = malloc(sizeof(button_t) * (NBR_BUTTON + 1));
    manager -> drop_down = malloc(sizeof(drop_down_t) * (NBR_DROP + 1));
    manager -> selection = malloc(sizeof(selection_t) * (NBR_SELECTION + 1));
    while (i < NBR_BUTTON) {
        manager -> button_list[i] = create_button_from_macro(manager, i);
        i++;
    }
    init_all_drop(manager);
    init_all_selection(manager);
    manager -> button_list[i] = NULL;
    manager -> get_button = &get_button;
    return manager;
}
