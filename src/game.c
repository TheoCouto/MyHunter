/*
** EPITECH PROJECT, 2023
** my hunter game view
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../include/my.h"

static int exit_game(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 23 && mouse.x <= 78 && mouse.y >= 27 && mouse.y <= 77) {
        if (event.type == sfEvtMouseButtonPressed) {
            return (1);
        }
    }
    return (0);
}

static void int_to_str(int num, char *str)
{
    int i = 8;
    char temp;

    while (num != 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        i++;
    }
    str[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

static void game_score(struct my_hunter *all)
{
    char score_str[100];

    all->game->score += 1;
    int_to_str(all->game->score, score_str);
    sfText_setString(all->game[4].text, score_str);
}

static void duck_death(struct my_hunter *all, sfRenderWindow *window,
                        sfEvent event)
{
    sfSprite **sprite = &all->game[1].sprite;
    sfVector2i mouse;
    sfFloatRect coords;

    mouse = sfMouse_getPositionRenderWindow(window);
    coords = sfSprite_getGlobalBounds(*sprite);
    if (sfFloatRect_contains(&coords, mouse.x, mouse.y)) {
        sfSprite_destroy(*sprite);
        *sprite = NULL;
        game_score(all);
    }
}

static void duck_animation(sfRenderWindow *window, sfSprite *duck_sprite,
                            sfIntRect *duck_hitbox, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.3f) {
        duck_hitbox->left += 110;
        if (duck_hitbox->left > 220) {
            duck_hitbox->left = 0;
                }
        sfSprite_setTextureRect(duck_sprite, *duck_hitbox);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(window, duck_sprite, NULL);
}

static void render_game_event(struct my_hunter *all, sfRenderWindow *window,
sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) {
        duck_death(all, window, event);
    }
}

static void isduck_alive(struct my_hunter *all, sfRenderWindow *window,
                        sfClock *clock)
{
    if (all->game[1].sprite) {
            sfSprite_setPosition(all->game[1].sprite, all->game[1].pos);
            duck_animation(window, all->game[1].sprite,
            &all->game[1].rect, clock);
            all->game[1].pos.x += 0.2;
            if (all->game[1].pos.x > 1200) {
                all->game[1].pos.x = -100;
            }
    } else if (!all->game[1].sprite) {
        init_duck(all);
    }
}

void start_game(struct my_hunter *all, sfRenderWindow *window, sfEvent event)
{
    sfClock *clock = sfClock_create();

    all->game->score = 0;
    sfText_setString(all->game[4].text, "0");
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            render_game_event(all, window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, all->game[0].sprite, NULL);
        sfRenderWindow_drawSprite(window, all->game[2].sprite, NULL);
        sfRenderWindow_drawText(window, all->game[3].text, NULL);
        sfRenderWindow_drawText(window, all->game[4].text, NULL);
        isduck_alive(all, window, clock);
        sfRenderWindow_display(window);
        if (exit_game(window, event) == 1) {
            break;
        }
    }
}
