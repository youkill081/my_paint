/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** to save image
*/

#include <SFML/Graphics.h>

#include "paint_validation_window.h"
#include "paint_edition.h"
#include "paint_manager.h"
#include "paint_button.h"
#include "paint_event.h"
#include "paint_file.h"
#include "my.h"

void action_save(button_t *button, event_t *event)
{
    event -> button_execution = B_SAVE_FILE;
}

void save_image(sfRenderWindow **fen, manager_t *man)
{
    char *save;
    save = validation_window(fen, man);
    if (save == NULL) {
        my_putstr("The image was'nt saved\n");
        return;
    }
    if (sfImage_saveToFile(man -> edition -> image, save))
        my_putstr("The image has been saved\n");
    else
        my_putstr("can't save the image\n");
}
