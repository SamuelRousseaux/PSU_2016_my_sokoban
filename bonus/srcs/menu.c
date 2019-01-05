/*
** menu.c for menu in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban/bonus/srcs
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Tue Dec 20 03:38:24 2016 Samuel
** Last update Tue Dec 20 21:29:45 2016 Samuel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

void	launch(int a)
{
  if (a == 1)
    {
      pid_t x;
      x = fork();
      if (x < 0)
	{
	  puts("fork failure");
	  exit(-1);
	}
      else if (x == 0)
	execlp("mpg123", "mpg123", "-q", "./music/LIFE.mp3", NULL);
    }
  clear();
}

void	menu_sub(int key, int *a)
{
  if (key == 'y')
    {
      mvprintw(4, 0, "                ");
      mvprintw(4, 0, "MUSIC ENABLED");
      *a = 1;
    }
  if (key == 'n')
    {
      mvprintw(4, 0, "MUSIC DISABLED");
      *a = 0;
    }
}

void    menu()
{
  int	a;
  int	key;

  a = 0;
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  key = 0;
  while (key != ' ')
    {
      mvprintw(1, 0, "SOKOBAN THE GAME GOTY EDITION FULL UNLOCKED OF DOOM");
      mvprintw(3, 0, "ENABLE MUSIC? (LIFE.MP3)   y/n");
      mvprintw(4, 0, "MUSIC DISABLED");
      menu_sub(key, &a);
      mvprintw(6, 0, "PRESS SPACE TO PLAY");
      key = getch();
    }
  launch(a);
  endwin();
}
