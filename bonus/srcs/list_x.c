/*
** list_x.c for list_x in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban/srcs
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Dec 16 03:48:52 2016 Samuel
** Last update Tue Dec 20 21:21:44 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

void    waterwork()
{
  clear();
  mvprintw(1, 0, "           OOOOOOOOOOOOO");
  mvprintw(2, 0, "         OOO OOO      OO");
  mvprintw(3, 0, "OOO     OO    OO OOOOOOOOOO");
  mvprintw(4, 0, "OOOOOOOO      OOOO       OO");
  mvprintw(5, 0, "OOOO          OO  OOOOOOOOOO");
  mvprintw(6, 0, "OOOO           OOO         OO");
  mvprintw(7, 0, "OOOO           OO  OOOOOOOOOO");
  mvprintw(8, 0, "OOOO            OOOO        O");
  mvprintw(9, 0, "OOOO             OOO  OOOO  O");
  mvprintw(10, 0, "OOOOOOOOO          OOOO     O");
  mvprintw(11, 0, "OOO     OO             OOOOO");
  mvprintw(12, 0, "         OOO       OOOOOO");
  mvprintw(13, 0, "           OO      OO");
  mvprintw(14, 0, "            OOO     OO");
  mvprintw(15, 0, "              OO    OO");
  mvprintw(16, 0, "               OOO   OO");
  mvprintw(17, 0, "                 OO   O");
  mvprintw(18, 0, "                  O   O");
  mvprintw(19, 0, "                  OO OO");
  mvprintw(20, 0, "                   OOO");
  mvprintw(22, 0, "YOU LOOSE, KYS !");
  refresh();
  usleep(4000000);
}

char	*ya_plus_de_place_lel(int x, int y, t_list *lo)
{
  while (lo->next != NULL)
    {
      if (lo->x == x && lo->y == y)
	return (NULL);
      lo = lo->next;
    }
  if (lo->x == x && lo->y == y)
    return (NULL);
  waterwork();
  endwin();
  exit(1);
}

char	*defeat(t_list *l, t_list *lo)
{
  while (l->next != NULL)
    {
      if (((mvinch(l->y - 1, l->x) == '#') && (mvinch(l->y, l->x - 1) == '#'))
	  ||
	  ((mvinch(l->y - 1, l->x) == '#') && (mvinch(l->y, l->x + 1) == '#'))
	  ||
	  ((mvinch(l->y + 1, l->x) == '#') && (mvinch(l->y, l->x - 1) == '#'))
	  ||
	  ((mvinch(l->y + 1, l->x) == '#') && (mvinch(l->y, l->x + 1) == '#')))
	ya_plus_de_place_lel(l->x, l->y, lo);
      l = l->next;
    }
  if (((mvinch(l->y - 1, l->x) == '#') && (mvinch(l->y, l->x - 1) == '#'))
      ||
      ((mvinch(l->y - 1, l->x) == '#') && (mvinch(l->y, l->x + 1) == '#'))
      ||
      ((mvinch(l->y + 1, l->x) == '#') && (mvinch(l->y, l->x - 1) == '#'))
      ||
      ((mvinch(l->y + 1, l->x) == '#') && (mvinch(l->y, l->x + 1) == '#')))
    ya_plus_de_place_lel(l->x, l->y, lo);
  return (NULL);
}

t_list	*get_X(int column, int row)
{
  t_list	*lx;
  int		y;
  int		x;
  int		a;

  a = 0;
  y = -1;
  lx = malloc(sizeof(t_list));
  if (lx == NULL)
    exit(84);
  while (++y != row)
    {
      x = -1;
      while (++x != column)
	{
	  if (mvinch(y, x) == 'X')
	    {
	      if (a == 0)
		lx = get_O_sub(x, y, lx, &a);
	      else
		add_node(lx, x, y);
	    }
	}
    }
  return (lx);
}
