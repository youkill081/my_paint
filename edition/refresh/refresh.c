/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to refresh the edition window
*/

#include <SFML/Graphics.h>

#include "paint_manager.h"
#include "paint_slider.h"
#include "my.h"

/*
void update_zoom(edition_t *edition, manager_t *m)
{
    float z = m -> slider_manager -> slider_list[SLIDER_ZOOM] -> actual_value;

    z = (z + 10) / 10;
    edition -> zoom.x = z;
    edition -> zoom.y = z;
    sfSprite_setScale(edition -> image_display, edition -> zoom);
}
*/

void make_position_valid(sfIntRect *rect, sfSprite *sprite, sfVector2f zoom);
void refresh_drawing(manager_t *manager, sfColor *color, int s);
void refresh_eraser(manager_t *manager, int s);

void update_zoom(edition_t *edition, manager_t *m)
{
    float z = m -> slider_manager -> slider_list[SLIDER_ZOOM] -> actual_value;

    z = (z + 10) / 10;
    edition -> zoom.x = z;
    edition -> zoom.y = z;
    sfSprite_setScale(edition -> image_display, edition -> zoom);
}

void refresh_and_display(sfRenderWindow *fen, edition_t *edition, manager_t *m)
{
    sfIntRect new_rect = sfSprite_getTextureRect(edition -> image_display);

    update_zoom(edition, m);
    sfTexture_updateFromImage(edition -> texture, edition -> image, 0, 0);
    make_position_valid(&new_rect, edition -> image_display, edition -> zoom);
    if (edition -> background != NULL)
        sfRenderWindow_drawSprite(fen, edition -> background, NULL);

    sfSprite_setTextureRect(edition -> image_display, new_rect);
    sfRenderWindow_drawSprite(fen, edition -> image_display, NULL);
    sfRenderWindow_drawRectangleShape(fen, m -> back -> hide_d, NULL);
    sfRenderWindow_drawRectangleShape(fen, m -> back -> hide_r, NULL);
}

void refresh_good_tools(manager_t *manager, sfColor *color, int s)
{
    selection_t *menu = manager -> button_manager -> selection[0];
    int tool_selected = menu -> get_selected(menu, manager -> button_manager);

    switch (tool_selected) {
    case B_PENCIL_TOOL:
        return refresh_drawing(manager, color, s);
    case B_ERASER_TOOL:
        return refresh_eraser(manager, s);
    case B_HAND_TOOL:
        return refresh_hand(manager -> edition, manager -> event);
    }
}

void refresh_edition(sfRenderWindow *fen, manager_t *manager)
{
    sfColor actu = sfRectangleShape_getFillColor(manager -> back -> color_rect);
    int s;

    s = manager -> slider_manager -> slider_list[SLIDER_SIZE] -> actual_value;
    refresh_good_tools(manager, &actu, s);
    refresh_and_display(fen, manager -> edition, manager);
}
