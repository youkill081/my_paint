/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** fen manager
*/

#include <SFML/Graphics.h>

#include "my.h"
#include "paint_file.h"
#include "paint_color.h"
#include "paint_event.h"
#include "paint_background.h"
#include "paint_button.h"
#include "paint_slider.h"

#include "paint_manager.h"

void refresh_edition(sfRenderWindow *fen, manager_t *manager);
void refresh_textbox(sfRenderWindow **fen, manager_t *man);
void open_image(sfRenderWindow **fen, manager_t *manager);

void reset_window(sfRenderWindow *fen)
{
    sfRenderWindow_clear(fen, BACKGROUND_COLOR);
}

void run_complicated_button(sfRenderWindow **fen, manager_t *manager)
{
    if (manager -> event -> button_execution == B_SAVE_FILE)
        save_image(fen, manager);
    if (manager -> event -> button_execution == B_OPEN_FILE)
        open_image(fen, manager);
    if (manager -> event -> button_execution == B_NEW_FILE)
        new_image(fen, manager);
    manager -> event -> button_execution = -1;
}

void run_paint(sfRenderWindow **fen_list, manager_t *manager)
{
    sfRenderWindow *main_fen = fen_list[0];

    while (sfRenderWindow_isOpen(main_fen)) {
        reset_window(main_fen);
        manadge_event(main_fen, manager -> event, 1);
        show_background(main_fen,  manager -> back, manager -> slider_manager);
        refresh_button(fen_list, manager -> button_manager, manager -> event);
        refresh_edition(main_fen, manager);
        refresh_slider(fen_list, manager -> slider_manager, manager -> event);
        run_complicated_button(fen_list, manager);
        refresh_textbox(fen_list, manager);
        sfRenderWindow_display(main_fen);
    }
}
