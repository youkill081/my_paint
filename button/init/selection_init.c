/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to init the selection button list
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_button.h"
#include "my.h"

/*
typedef struct selection_t {
    int nbr_button;
    int selected;
    int *button_list;
} selection_t;
static const int NBR_SELECTION = 1;
static const selection_t SELECTION_LIST[] = {
    {2, 0, (int[]) {11, 12}}
};
*/

int get_button_selection(selection_t *menu, button_manager_t *manager);

selection_t *create_selection_menu(int i)
{
    selection_t *end = malloc(sizeof(selection_t));

    end -> nbr_button = SELECTION_LIST[i].nbr_button;
    end -> selected = SELECTION_LIST[i].selected;
    end -> button_list = SELECTION_LIST[i].button_list;
    end -> get_selected = &get_button_selection;
    return end;
}

void init_all_selection(button_manager_t *manager)
{
    int i = 0;

    while (i < NBR_SELECTION) {
        manager -> selection[i] = create_selection_menu(i);
        i++;
    }
    manager -> selection[i] = NULL;
}
