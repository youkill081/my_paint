/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to refresh text in textbox
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "paint_textbox.h"
#include "my.h"

int is_char_allow(textbox_t *textbox, char c)
{
    for (int i = 0; textbox -> allow_char[i] != '\0'; i++) {
        if (textbox -> allow_char[i] == c)
            return 1;
    }
    return 0;
}

void remove_last(textbox_t *textbox)
{
    char *new_text = my_strdup(sfText_getString(textbox -> text));
    new_text[my_strlen(new_text) - 1] = '\0';
    sfText_setString(textbox -> text, new_text);
}

void append_text(textbox_t *textbox, char c)
{
    const char *text = sfText_getString(textbox -> text);
    char *new_string = NULL;
    int i = 0;

    if (c == 8)
        return remove_last(textbox);
    if (!is_char_allow(textbox, c))
        return;
    new_string = malloc(sizeof(char) * (my_strlen(text) + 2));
    if (new_string == NULL)
        return;
    while (text[i] != '\0') {
        new_string[i] = text[i];
        i++;
    }
    new_string[i] = c;
    new_string[i + 1] = '\0';
    sfText_setString(textbox -> text, new_string);
}

void refresh_text_textbox(textbox_t *textbox, event_t *event)
{
    if (textbox -> is_selected) {
        if (event -> key_pressed != -1) {
            append_text(textbox, event -> key_pressed);
        }
    }
}
