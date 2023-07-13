/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** contain event structure
*/

#ifndef PAINT_EVENT_H_
    #define PAINT_EVENT_H_
    #include <SFML/Graphics.h>
enum {
    NOTHING,
    PRESSED,
    RELEASED,
    HOLD
};

typedef struct event_t {
    int mouse_state;
    int button_execution;
    int key_pressed;
    sfVector2i mouse_position;
} event_t;

int manadge_event(sfRenderWindow *fen, event_t *ev, int c_type);
void set_mouse_state(
    sfEvent event,
    event_t *list,
    int has_e,
    sfRenderWindow *fen);
void say_mouse_state(event_t *list);
void show_mouse_pos(event_t *list);
event_t *init_event(void);
#endif
