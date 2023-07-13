/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** header for file
*/

#ifndef FILE_H_
    #define FILE_H_
    #include <SFML/Graphics.h>
    #include "paint_manager.h"
void new_image(sfRenderWindow **fen, manager_t *manager);
void save_image(sfRenderWindow **fen, manager_t *manager);
char *select_file(sfRenderWindow **fen,event_t *event, button_manager_t *man);
#endif
