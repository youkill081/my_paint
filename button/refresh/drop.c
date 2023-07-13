/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to make drop_down menu working
*/

#include <SFML/Graphics.h>

#include "my.h"
#include "paint_button.h"

/*typedef struct drop_down_t {
    int nbr_button;
    int state;
    int *button_list;
*/

void show_all(button_manager_t *man, drop_down_t *menu)
{
    button_t *temp;

    for (int i = 1; i < menu -> nbr_button; i++) {
        temp = get_button(man, menu -> button_list[i]);
        if (temp == NULL) {
            return;
        }
        temp -> state = SHOW;
    }
}

void hide_all(button_manager_t *man, drop_down_t *menu)
{
    button_t *temp;

    for (int i = 1; i < menu -> nbr_button; i++) {
        temp = get_button(man, menu -> button_list[i]);
        if (temp == NULL) {
            return;
        }
        temp -> state = HIDE;
    }
}

void make_up(button_manager_t *man, drop_down_t *menu, event_t *e)
{
    button_t *main_button = get_button(man, menu -> button_list[0]);

    if (main_button == NULL) {
        my_putstr("ERROR: Drop_down, button not find\n");
    }
    if (main_button -> is_hover(main_button, e)) {
        menu -> state = DOWN;
        show_all(man, menu);
    }
}

void make_down(button_manager_t *man, drop_down_t *menu, event_t *e)
{
    button_t *temp;

    for (int i = 0; i < menu -> nbr_button; i++) {
        temp = get_button(man, menu -> button_list[i]);
        if (temp == NULL) {
            my_putstr("ERROR: Drop_down, button not find\n");
            return;
        }
        if (temp -> is_hover(temp, e))
            return;
    }
    menu -> state = UP;
    hide_all(man, menu);
}

drop_down_t *refresh_drop_menu(button_manager_t *manager, event_t *event)
{
    for (int i = 0; manager -> drop_down[i] != NULL; i++) {
        if (manager -> drop_down[i] -> state == UP) {
            make_up(manager, manager -> drop_down[i], event);
            continue;
        }
        if (manager -> drop_down[i] -> state == DOWN) {
            make_down(manager, manager -> drop_down[i], event);
        }
    }
}
