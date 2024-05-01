/*
** EPITECH PROJECT, 2023
** init_game
** File description:
** File where the game is initialized
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../include/my.h"

static void init_game_bg(struct my_hunter *all)
{
    all->game[0].texture = sfTexture_createFromFile(
    "./resources/duck_hunt_background.png", NULL);
    all->game[0].sprite = sfSprite_create();
    all->game[0].scale.x = 1;
    all->game[0].scale.y = 1.3;
    sfSprite_setTexture(all->game[0].sprite, all->game[0].texture, sfTrue);
    sfSprite_setScale(all->game[0].sprite, all->game[0].scale);
}

static int get_random_number(int min, int max)
{
    srand(time(NULL));
    return min + (rand() % (max - min + 1));
}

void init_duck(struct my_hunter *all)
{
    all->game[1].texture = sfTexture_createFromFile(
    "./resources/MyDuck.png", NULL);
    all->game[1].sprite = sfSprite_create();
    all->game[1].rect.left = 0;
    all->game[1].rect.top = 0;
    all->game[1].rect.width = 110;
    all->game[1].rect.height = 110;
    all->game[1].pos.x = -100;
    all->game[1].pos.y = get_random_number(100, 600);
    sfSprite_setTexture(all->game[1].sprite, all->game[1].texture, sfTrue);
    sfSprite_setTextureRect(all->game[1].sprite, all->game[1].rect);
}

static void init_exit_button(struct my_hunter *all)
{
    all->game[2].texture = sfTexture_createFromFile(
    "./resources/cross_icon.png", NULL);
    all->game[2].sprite = sfSprite_create();
    all->game[2].scale.x = 0.5;
    all->game[2].scale.y = 0.5;
    sfSprite_setTexture(all->game[2].sprite, all->game[2].texture, sfTrue);
    sfSprite_setScale(all->game[2].sprite, all->game[2].scale);
}

static void init_score_text(struct my_hunter *all)
{
    all->game[3].font = sfFont_createFromFile(
    "./resources/Kindapix-Ke0A.ttf");
    all->game[3].text = sfText_create();
    all->game[3].pos.x = 975;
    all->game[3].pos.y = 25;
    sfText_setString(all->game[3].text, "SCORE:");
    sfText_setFont(all->game[3].text, all->game[3].font);
    sfText_setCharacterSize(all->game[3].text, 35);
    sfText_setPosition(all->game[3].text, all->game[3].pos);
}

static void init_score_points(struct my_hunter *all)
{
    all->game[4].font = sfFont_createFromFile(
    "./resources/Kindapix-Ke0A.ttf");
    all->game[4].text = sfText_create();
    all->game[4].pos.x = 1125;
    all->game[4].pos.y = 25;
    sfText_setFont(all->game[4].text, all->game[4].font);
    sfText_setCharacterSize(all->game[4].text, 35);
    sfText_setPosition(all->game[4].text, all->game[4].pos);
}

void init_game(struct my_hunter *all)
{
    all->game = malloc(sizeof(*all->game) * 5);
    init_game_bg(all);
    init_duck(all);
    init_exit_button(all);
    init_score_text(all);
    init_score_points(all);
}
