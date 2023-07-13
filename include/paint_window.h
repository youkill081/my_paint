/*
** EPITECH PROJECT, 2023
** my_pain
** File description:
** contain include for window
*/

#ifndef PAINT_WINDOW_H_
    #define PAINT_WINDOW_H_
    #include <SFML/Graphics.h>
    #include "paint_manager.h"
enum WINDOW_NAME {
    MAIN_WINDOW,
    SAVE_WINDOW,
    WINDOW_NUMBER
};

static const sfVector2u FEN_SIZE[] = {
    {1024, 1024},
    {400, 100}
};

void run_paint(sfRenderWindow **fen_list, manager_t *manager);
sfRenderWindow *create_window(int i);
#endif
