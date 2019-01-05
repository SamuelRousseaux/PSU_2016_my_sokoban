/*
** my_swap.c for my_swap in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Wed Nov 16 00:18:30 2016 Samuel Rousseaux
** Last update Wed Nov 16 00:18:46 2016 Samuel Rousseaux
*/

int     my_swap(int *a, int *b)
{
  int   toto;

  toto = *a;
  *a = *b;
  *b = toto;
}
