/*
** list_x.c for list_x in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban/srcs
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Dec 16 03:48:52 2016 Samuel
** Last update Fri Dec 16 18:11:47 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

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
