/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** file for hand tool
*/

#include <SFML/Graphics.h>

#include "paint_edition.h"
#include "paint_event.h"
#include "my.h"

/*
  typedef struct edition_t {
    sfImage *image;
    sfTexture *texture;
    sfSprite *image_display;
    sfSprite *background;

    sfVector2f hand_backup;
} edition_t;
 */

void make_position_valid(sfIntRect *new_rect, sfSprite *sprite, sfVector2f zoom)
{
    sfVector2u size = sfTexture_getSize(sfSprite_getTexture(sprite));

    if (new_rect -> left < 0)
        new_rect ->  left = 0;
    if (new_rect -> top < 0)
        new_rect -> top = 0;
    if (new_rect -> left + new_rect -> width / zoom.x > size.x)
        new_rect -> left = size.x - new_rect -> width / zoom.x;
    if (new_rect -> top + new_rect -> height / zoom.y > size.y)
        new_rect -> top = size.y - new_rect -> height / zoom.y;
}

void refresh_hand(edition_t *edition, event_t *event)
{
    sfVector2i actu_pos;
    sfIntRect new_pos = sfSprite_getTextureRect(edition -> image_display);

    if (event -> mouse_state == NOTHING || event -> mouse_state == RELEASED)
        return;
    if (event -> mouse_state == PRESSED) {
        edition -> hand_backup = event -> mouse_position;
        return;
    }
    new_pos = sfSprite_getTextureRect(edition -> image_display);
    actu_pos = event -> mouse_position;
    new_pos.left += (edition -> hand_backup.x - actu_pos.x);
    new_pos.top += (edition -> hand_backup.y - actu_pos.y);
    make_position_valid(&new_pos, edition -> image_display, edition -> zoom);
    sfSprite_setTextureRect(edition -> image_display, new_pos);
    edition -> hand_backup = actu_pos;
}
