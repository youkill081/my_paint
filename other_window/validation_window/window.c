/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** contain window for save
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "paint_manager.h"
#include "paint_textbox.h"
#include "paint_window.h"
#include "paint_button.h"
#include "paint_event.h"
#include "paint_macro.h"
#include "paint_color.h"
#include "my.h"

void refresh_textbox(sfRenderWindow **fen, manager_t *man);
sfText *create_text_validation(char *text);

void action_save_ok(button_t *button, event_t *event)
{
    event -> button_execution = B_OK;
}

void action_save_cancel(button_t *button, event_t *event)
{
    event -> button_execution = B_CANCEL;
}

void reset_fen(sfRenderWindow *fen)
{
    sfRenderWindow_setSize(fen, (sfVector2u) {400, 100});
    sfRenderWindow_setVisible(fen, sfTrue);
    sfRenderWindow_setTitle(fen, "Enter text");
}

char *check_click_button(sfRenderWindow *fen, manager_t *man)
{
    char *return_value = ".";
    textbox_t *text = man -> textbox_manager -> box_list[BOX_WINDOW];
    switch (man -> event -> button_execution) {
    case B_OK:
        return_value = my_strdup(sfText_getString(text-> text));
        break;
    case B_CANCEL:
        return_value = NULL;
        break;
    }
    if (return_value == NULL || my_strcmp(return_value, ".") != 0)
        sfRenderWindow_setVisible(fen, sfFalse);
    man -> event -> button_execution = -1;
    return return_value;
}

char *validation_window(sfRenderWindow **fen, manager_t *man)
{
    char *click = ".";
    reset_fen(fen[SAVE_WINDOW]);
    while (sfRenderWindow_isOpen(fen[SAVE_WINDOW])) {
        sfRenderWindow_clear(fen[SAVE_WINDOW], BACKGROUND_COLOR);
        sfRenderWindow_requestFocus(fen[SAVE_WINDOW]);
        if (manadge_event(fen[SAVE_WINDOW], man -> event, 2))
            break;
        refresh_button(fen, man -> button_manager, man -> event);
        refresh_textbox(fen, man);
        click = check_click_button(fen[SAVE_WINDOW], man);
        if (click == NULL || my_strcmp(click, ".") != 0)
            return click;
        sfRenderWindow_display(fen[SAVE_WINDOW]);
    }
    return NULL;
}
