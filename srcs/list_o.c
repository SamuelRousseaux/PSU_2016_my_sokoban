/*
** list_o.c for list_o in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 16:10:54 2016 Samuel
** Last update Fri Dec 16 03:48:34 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

t_list	*add_node(t_list *lo, int x, int y)
{
  t_list	*temp;

  temp = malloc(sizeof(t_list));
  if (temp == NULL)
    return (NULL);
  temp->x = x;
  temp->y = y;
  temp->next = NULL;
  while (lo->next != NULL)
    lo = lo->next;
  temp->prev = lo;
  lo->next = temp;
  return (NULL);
}

t_list  *get_O_sub(int x, int y, t_list *lo, int *a)
{
  lo->x = x;
  lo->y = y;
  lo->prev = NULL;
  lo->next = NULL;
  *a = 1;
  return (lo);
}

t_list	*get_O(int column, int row)
{
  t_list	*lo;
  int		y;
  int		x;
  int		a;

  a = 0;
  y = -1;
  lo = malloc(sizeof(t_list));
  if (lo == NULL)
    exit(84);
  while (++y != row)
    {
      x = -1;
      while (++x != column)
	{
	  if (mvinch(y, x) == 'O')
	    {
	      if (a == 0)
		lo = get_O_sub(x, y, lo, &a);
	      else
		add_node(lo, x, y);
	    }
	}
    }
  return (lo);
}
