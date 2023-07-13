/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to refresh button selection
*/

#include <SFML/Graphics.h>

#include "paint_button.h"
#include "paint_event.h"
#include "my.h"

/*
  typedef struct selection_t {
    int nbr_button;
    int selected;
    int *button_list;
} selection_t;
typedef struct button_manager_t {
    button_t **button_list;
    drop_down_t **drop_down;
    selection_t **selection;
    button_t *(*get_button) (struct button_manager_t *manager, int id);
} button_manager_t;

 */

int get_button_selection(selection_t *menu, button_manager_t *manager)
{
    button_t *temp_button = NULL;

    for (int i = 0; i < menu -> nbr_button; i++) {
        temp_button = manager -> get_button(manager, menu -> button_list[i]);
        if (temp_button == NULL) {
            my_putstr("Selection menu : button not found (get selection)\n");
            return -1;
        }
        if (temp_button -> state == SELECTED)
            return temp_button -> id;
    }
    return -1;
}

int is_clicked(button_t *button, event_t *event)
{
    if (button -> is_hover(button, event)) {
        if (event -> mouse_state == RELEASED) {
            return 1;
        }
    }
    return 0;
}

void deselect_all(selection_t *menu, button_manager_t *manager)
{
    button_t *temp_button = NULL;

    for (int i = 0; i < menu -> nbr_button; i++) {
        temp_button = manager -> get_button(manager, menu -> button_list[i]);
        if (temp_button == NULL) {
            my_putstr("Selection menu : button not found (déselection)\n");
            return;
        }
        temp_button -> state = SHOW;
    }
}

void refresh_selection(selection_t *menu, event_t *event, button_manager_t *man)
{
    button_t *temp_button = NULL;

    for (int i = 0; i < menu -> nbr_button; i++) {
        temp_button = man -> get_button(man, menu -> button_list[i]);
        if (temp_button == NULL) {
            my_putstr("Selection menu : button not found !\n");
            return;
        }
        if (is_clicked(temp_button, event)) {
            deselect_all(menu, man);
            temp_button -> state = SELECTED;
            return;
        }
    }
}

void *refresh_selection_menu(button_manager_t *manager, event_t *event)
{
    for (int i = 0; manager -> selection[i] != NULL; i++) {
        refresh_selection(manager -> selection[i], event, manager);
    }
}
