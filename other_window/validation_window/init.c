/*
** EPITECH PROJECT, 2023
** my_pain
** File description:
** extra function for validation window
*/

#include <SFML/Graphics.h>

sfText *create_text_validation(char *text)
{
    sfText *end = sfText_create();
    sfFont *font = sfFont_createFromFile("src/font/arial.ttf");

    if (font == NULL) {
        return NULL;
    }
    sfText_setFont(end, font);
    sfText_setString(end, text);
    sfText_setCharacterSize(end, 20);
    sfText_setColor(end, (sfColor) {255, 255, 255, 255});
    sfText_setPosition(end, (sfVector2f) {10, 10});
    return end;
}
