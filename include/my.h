/*
** EPITECH PROJECT, 2023
** MyHunter Header
** File description:
** MyHunter Header
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>

struct window {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
};

struct menu {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f size;
};

struct game {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    int score;
};

struct my_hunter{
    struct window win;
    struct menu *menu;
    struct game *game;
};

int my_putstr(char const *str);

void init_menu(struct my_hunter *all);

void init_game(struct my_hunter *all);

void start_game(struct my_hunter *all, sfRenderWindow *window, sfEvent event);

void init_duck(struct my_hunter *all);

#endif /* MY_H_ */
