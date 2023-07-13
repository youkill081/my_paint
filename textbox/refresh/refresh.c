/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** main file to refresh textbox
*/

#include <SFML/Graphics.h>

#include "paint_manager.h"
#include "paint_textbox.h"
#include "my.h"

void refresh_selection_textbox(textbox_t *box, event_t *event, manager_t *man);
/*
  typedef struct textbox_t {
    sfText *text;
    sfRectangleShape *background;

    sfVector2f position;
    sfVector2f size;

    sfColor background_color;
    sfColor background_ext_color;
    int background_thickness;

    sfColor text_color;
    int window;
    int id;
} textbox_t;

 */

void display_textbox(sfRenderWindow **fen, textbox_t *text_box)
{
    sfRenderWindow *t_fen = fen[text_box -> window];

    sfRenderWindow_drawRectangleShape(t_fen, text_box -> background, NULL);
    sfRenderWindow_drawText(t_fen, text_box -> text, NULL);
}

void true_refresh_textbox(sfRenderWindow **fen, textbox_t *box, manager_t *man)
{
    refresh_selection_textbox(box, man -> event, man);
    refresh_text_textbox(box, man -> event);
    display_textbox(fen, box);
}

void refresh_textbox(sfRenderWindow **fen, manager_t *man)
{
    for (int i = 0; man -> textbox_manager -> box_list[i] != NULL; i++) {
        true_refresh_textbox(fen, man -> textbox_manager -> box_list[i], man);
    }
}
