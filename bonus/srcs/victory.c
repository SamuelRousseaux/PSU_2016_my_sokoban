/*
** victory.c for victory in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 19:29:09 2016 Samuel
** Last update Mon Dec 19 17:52:29 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

void	firework()
{
  clear();
  mvprintw(1, 0, "           OOO0");
  mvprintw(2, 0, "         OOO OO");
  mvprintw(3, 0, "         OO   O");
  mvprintw(4, 0, "         OO   OO");
  mvprintw(5, 0, "          OO   OOO");
  mvprintw(6, 0, "           OO    OO");
  mvprintw(7, 0, "           OO     OOO");
  mvprintw(8, 0, "            OO      OO");
  mvprintw(9, 0, "       OOOOOOO       OO");
  mvprintw(10, 0, "    OOOOO              OOO OO");
  mvprintw(11, 0, "   OO     OOOO          OOOOOO");
  mvprintw(12, 0, "   OO  OOOO  OOO             OO");
  mvprintw(13, 0, "   OO        OOO             OO");
  mvprintw(14, 0, "    OOOOOOOOOO OOO           OO");
  mvprintw(15, 0, "    OO        OOOO           OO");
  mvprintw(16, 0, "    OOOOOOOOOOO  OO          OO");
  mvprintw(17, 0, "      OO       OOOO     OOOOOO");
  mvprintw(18, 0, "      OOOOOOOOOO OO    OOO OO");
  mvprintw(19, 0, "         OO     OOOO OOO");
  mvprintw(20, 0, "         OOOOOOOOOOOOO");
  mvprintw(22, 0, "YOU WON! Your time: Too long error");
  refresh();
  usleep(4000000);
}

char	*victory(t_list *lo)
{
  while (lo->next != NULL)
    {
      if (mvinch(lo->y, lo->x) != 'X')
	return (NULL);
      lo = lo->next;
    }
  if (mvinch(lo->y, lo->x) != 'X')
    return (NULL);
  firework();
  endwin();
  exit(0);
}
