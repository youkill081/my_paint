/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** drop_down menu initialisation
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "paint_button.h"
#include "my.h"

/*
  typedef struct drop_down_t {
     int nbr_button;
     int state;
     int *button_list;
  } drop_down_t;

  typedef struct button_manager_t {
     button_t **button_list;
     drop_down_t **drom_down;
  } button_manager_t;

  static const int NBR_DROP = 1;
  static const drop_down_t DROP_LIST[] = {
     {3, 0, (int[]) {1, 2, 3}}
  };

 */

drop_down_t *create_drop_menu(int i)
{
    drop_down_t *end = malloc(sizeof(drop_down_t));

    end -> nbr_button = DROP_LIST[i].nbr_button;
    end -> state = DROP_LIST[i].state;
    end -> button_list = DROP_LIST[i].button_list;

    return end;
}

void init_all_drop(button_manager_t *manager)
{
    int i = 0;

    while (i < NBR_DROP) {
        manager -> drop_down[i] = create_drop_menu(i);
        i++;
    }
    manager -> drop_down[i] = NULL;
}
