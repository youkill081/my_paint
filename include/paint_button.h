/*
** EPITECH PROJECT, 2023
** my_pain
** File description:
** include for button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_
    #include <SFML/Graphics.h>
    #include "paint_event.h"

enum BUTTON_TYPE {
    BUTTON_TEXT,
    BUTTON_IMAGE
};
enum TEXT_ALIGN {
    LEFT,
    CENTER
};
enum BUTTON_STATE {
    HIDE,
    SHOW,
    SELECTED
};
enum DROP_STATE {
    UP,
    DOWN
};
enum BUTTON_NAME {
    B_FILE,
    B_NEW_FILE,
    B_OPEN_FILE,
    B_SAVE_FILE,
    B_EDITION,
    B_PENCIL,
    B_ERASER,
    B_HELP,
    B_ABOUT,
    B_HELP_DROP,
    B_PENCIL_TOOL,
    B_ERASER_TOOL,
    B_HAND_TOOL,
    B_OK,
    B_CANCEL
};

typedef struct button_manager_t button_manager_t;

typedef struct button_t {
    sfVector2f size;
    sfVector2f position;
    sfColor base_color;
    sfColor hover_color;
    sfColor text_color;
    int type;
    char *button_text;
    int window;
    int id;
    int text_align;
    int state;
    sfText *text;
    sfRectangleShape *rectangle;
    sfSprite *image;
    void (*executor) (struct button_t *button, event_t *event);
    int (*is_hover) (struct button_t *button, event_t *event);
} button_t;
typedef struct drop_down_t {
    int nbr_button;
    int state;
    int *button_list;
} drop_down_t;
typedef struct selection_t {
    int nbr_button;
    int selected;;
    int *button_list;
    int (*get_selected) (struct selection_t *menu, button_manager_t *manager);
} selection_t;
typedef struct button_manager_t {
    button_t **button_list;
    drop_down_t **drop_down;
    selection_t **selection;
    button_t *(*get_button) (struct button_manager_t *manager, int id);
} button_manager_t;

void action_newfile(button_t *button, event_t *event);
void action_about(button_t *button, event_t *event);
void action_pen(button_t *button, event_t *event);
void action_eraser(button_t *button, event_t *event);
void action_open(button_t *button, event_t *event);
void action_save(button_t *button, event_t *event);
void action_save_cancel(button_t *button, event_t *event);
void action_save_ok(button_t *button, event_t *event);

int mouse_hover(button_t *button, event_t *event);

static const int NBR_BUTTON = 15;
static const button_t BUTTON_LIST_SIZE[] = {
    {{100, 30},
    {0, 0},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "file",
    0,
    0, CENTER, SHOW, NULL, NULL, NULL, NULL},

    {{210, 30},
    {0, 30},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "new file",
    0,
    1, LEFT, HIDE, NULL, NULL, NULL, &action_newfile},

    {{210, 30},
    {0, 60},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "open file",
    0,
    2, LEFT, HIDE, NULL, NULL, NULL, &action_open},

    {{210, 30},
    {0, 90},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "save file",
    0,
    3, LEFT, HIDE, NULL, NULL, NULL, &action_save},

    {{100, 30},
    {100, 0},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "edition",
    0,
    4, CENTER, SHOW, NULL, NULL, NULL, NULL},

    {{210, 30},
    {100, 30},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "pencil",
    0,
    5, LEFT, HIDE, NULL, NULL, NULL, NULL},

    {{210, 30},
    {100, 60},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "eraser",
    0,
    6, LEFT, HIDE, NULL, NULL, NULL, NULL},

    {{100, 30},
    {200, 0},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "help",
    0,
    7, CENTER, SHOW, NULL, NULL, NULL, NULL},

    {{210, 30},
    {200, 30},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "about",
    0,
    8, LEFT, HIDE, NULL, NULL, NULL, &action_about},

    {{210, 30},
    {200, 60},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "help",
    0,
    9, LEFT, HIDE, NULL, NULL, NULL, NULL},

    {{50, 50},
    {200, 90},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_IMAGE,
    "src/img/pen.png",
    0,
    10, CENTER, SHOW, NULL, NULL, NULL, NULL},

    {{50, 50},
    {260, 90},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_IMAGE,
    "src/img/gomme.png",
    0,
    11, CENTER, SHOW, NULL, NULL, NULL, NULL},

    {{50, 50},
    {320, 90},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_IMAGE,
    "src/img/hand.png",
    0,
    12, CENTER, SHOW, NULL, NULL, NULL, NULL},

    {{100, 30},
    {85, 65},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "Cancel",
    1,
    13, CENTER, SHOW, NULL, NULL, NULL, &action_save_cancel},

    {{100, 30},
    {215, 65},
    {102, 99, 101, 255},
    {69, 65, 68, 255},
    {255, 255, 255, 255},
    BUTTON_TEXT,
    "Ok",
    1,
    14, CENTER, SHOW, NULL, NULL, NULL, &action_save_ok}
};

static const int NBR_DROP = 3;
static const drop_down_t DROP_LIST[] = {
    {4, UP, (int[]) {0, 1, 2, 3}},
    {3, UP, (int[]) {4, 5, 6}},
    {3, UP, (int[]) {7, 8, 9}}
};

static const int NBR_SELECTION = 1;
static const selection_t SELECTION_LIST[] = {
    {3, 0, (int[]) {10, 11, 12}}
};

void refresh_button(sfRenderWindow **fen, button_manager_t *man, event_t *ev);
void refresh_button_t(sfRenderWindow **fen, button_t *button, event_t *event);
drop_down_t *refresh_drop_menu(button_manager_t *manager, event_t *event);
void *refresh_selection_menu(button_manager_t *manager, event_t *event);
button_manager_t *init_button_manager(sfRenderWindow *windows);
button_t *get_button(button_manager_t *manager, int id);
void init_all_selection(button_manager_t *manager);
void init_all_drop(button_manager_t *manager);
void init_front(button_t *button, int i);
#endif
