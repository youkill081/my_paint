/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to init window
*/

#include <SFML/Graphics.h>

#include "paint_window.h"

sfRenderWindow *create_window(int i)
{
    sfVideoMode screen = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {FEN_SIZE[i].x, FEN_SIZE[i].y, screen.bitsPerPixel};
    sfRenderWindow* window;
    sfVector2i position = {screen.width / 2 - 512, screen.height / 2 - 512};

    window = sfRenderWindow_create(mode, "my_paint", sfResize | sfClose, NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, position);
    sfRenderWindow_setTitle(window, "my_paint");
    return window;
}
