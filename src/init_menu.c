/*
** EPITECH PROJECT, 2023
** init_game
** File description:
** File where the menu is initialized
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../include/my.h"

static void init_window(struct my_hunter *all)
{
    all->win.mode.width = 1200;
    all->win.mode.height = 1000;
    all->win.mode.bitsPerPixel = 32;
    all->win.window = sfRenderWindow_create(all->win.mode, "MyHunter",
    sfClose, NULL);
}

static void init_menu_bg(struct my_hunter *all)
{
    all->menu[0].texture = sfTexture_createFromFile(
    "./resources/duck_hunt_background.png", NULL);
    all->menu[0].sprite = sfSprite_create();
    all->menu[0].scale.x = 1;
    all->menu[0].scale.y = 1.3;
    sfSprite_setTexture(all->menu[0].sprite, all->menu[0].texture, sfTrue);
    sfSprite_setScale(all->menu[0].sprite, all->menu[0].scale);
}

static void init_start_button(struct my_hunter *all)
{
    all->menu[1].texture = sfTexture_createFromFile(
    "./resources/start_button.png", NULL);
    all->menu[1].sprite = sfSprite_create();
    all->menu[1].scale.x = 2;
    all->menu[1].scale.y = 2;
    all->menu[1].pos.x = 275;
    all->menu[1].pos.y = 750;
    sfSprite_setTexture(all->menu[1].sprite, all->menu[1].texture, sfTrue);
    sfSprite_setScale(all->menu[1].sprite, all->menu[1].scale);
    sfSprite_setPosition(all->menu[1].sprite, all->menu[1].pos);
}

static void init_title(struct my_hunter *all)
{
    all->menu[2].font = sfFont_createFromFile(
    "./resources/Kindapix-Ke0A.ttf");
    all->menu[2].text = sfText_create();
    all->menu[2].pos.x = 300;
    all->menu[2].pos.y = 1;
    sfText_setString(all->menu[2].text, "My\n  Hunter");
    sfText_setFont(all->menu[2].text, all->menu[2].font);
    sfText_setCharacterSize(all->menu[2].text, 200);
    sfText_setPosition(all->menu[2].text, all->menu[2].pos);
}

void init_menu(struct my_hunter *all)
{
    init_window(all);
    all->menu = malloc(sizeof(*all->menu) * 3);
    init_menu_bg(all);
    init_start_button(all);
    init_title(all);
    init_game(all);
}
