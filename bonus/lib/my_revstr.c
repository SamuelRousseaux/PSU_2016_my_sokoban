/*
** my_revstr.c for my_revstr.c in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Tue Nov 15 00:46:39 2016 Samuel Rousseaux
** Last update Tue Nov 15 00:47:02 2016 Samuel Rousseaux
*/

char    *my_revstr(char *str)
{
  int i;
  int c;
  int t;

  i = 0;
  c = 0;
  t = 0;
  while (str[c] != '\0')
    c++;
  c--;
  while (i < c)
    {
      t = str[i];
      str[i] = str[c];
      str[c] = t;
      i++;
      c--;
    }
  return(str);
}
