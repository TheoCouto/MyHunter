/*
** EPITECH PROJECT, 2023
** MyHunter Main file
** File description:
** main file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"

int window_error(sfRenderWindow *window, sfTexture *texture, sfFont *font)
{
    if (!window) {
        return EXIT_FAILURE;
    }
    if (!texture) {
        return EXIT_FAILURE;
    }
    if (!font) {
        return EXIT_FAILURE;
    }
    return (0);
}

void start_click(struct my_hunter *all, sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 297 && mouse.x <= 897 && mouse.y >= 896 && mouse.y <= 948) {
        if (event.type == sfEvtMouseButtonPressed) {
            start_game(all, window, event);
        }
    }
}

void render_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void game_menu(struct my_hunter *all)
{
    while (sfRenderWindow_isOpen(all->win.window)) {
        while (sfRenderWindow_pollEvent(all->win.window, &all->win.event)) {
            render_event(all->win.window, all->win.event);
        }
        sfRenderWindow_clear(all->win.window, sfBlack);
        sfRenderWindow_drawSprite(all->win.window, all->menu[0].sprite, NULL);
        sfRenderWindow_drawSprite(all->win.window, all->menu[1].sprite, NULL);
        sfRenderWindow_drawText(all->win.window, all->menu[2].text, NULL);
        sfRenderWindow_display(all->win.window);
        start_click(all, all->win.window, all->win.event);
    }
    sfText_destroy(all->menu[2].text);
    sfFont_destroy(all->menu[2].font);
    sfTexture_destroy(all->menu[1].texture);
    sfSprite_destroy(all->menu[1].sprite);
    sfTexture_destroy(all->menu[0].texture);
    sfSprite_destroy(all->menu[0].sprite);
    sfRenderWindow_destroy(all->win.window);
}

int main(int argc, char **argv)
{
    struct my_hunter all;

    if (argc == 1) {
        init_menu(&all);
        game_menu(&all);
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] != 'h') {
        my_putstr("Flag not found.\n");
        return EXIT_FAILURE;
    } else {
        my_putstr("    ------ My Hunter ------\n");
        my_putstr("An EPITECH Project from the ");
        my_putstr("'C Graphical Programming' Module.\n");
        my_putstr("based on the famous 'Duck Hunt' game.\n");
        my_putstr("\nYou can kill the ducks by click on them and\n");
        my_putstr("your score will be increased.\n");
        my_putstr("\nHave fun!!!\n");
    }
    return EXIT_SUCCESS;
}
