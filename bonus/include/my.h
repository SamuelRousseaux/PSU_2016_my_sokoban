/*
** my.h for my include in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sun Dec 11 16:54:31 2016 Samuel
** Last update Tue Dec 20 04:02:06 2016 Samuel
*/

#ifndef MY_H_
# define MY_H_
# include <time.h>

/*
** lib
*/
int	my_strlen(char *);
void	my_putstr(char *);

/*
** readmap.c
*/
void	readmap(char *);
void	menu();

/*
** list_o.c
*/
typedef struct  s_list
{
  int           x;
  int           y;
  struct s_list *next;
  struct s_list *prev;
}               t_list;
t_list  *get_O(int, int);
t_list  *add_node(t_list *, int, int);
t_list  *get_O_sub(int, int, t_list *, int *);

/*
** list_x.c
*/
t_list	*get_X(int, int);
char    *defeat(t_list *, t_list *);

/*
** print.c
*/
typedef struct	s_coordp
{
  int		x;
  int		y;
  int		O;
  int		a;
  int		key;
  int 		cols;
  int		lines;
  clock_t	time;
}		t_coordp;
void		sokoban(char **, int, int);
t_coordp	print_map(char **, int, int);
void		reset_game(char **, int, int, t_list *);

/*
** move.c
*/
t_coordp       	move_P(t_coordp, int);
void    	check_O(t_list *);

/*
** move_right.c
*/
t_coordp	move_right(t_coordp);

/*
** move_left.c
*/
t_coordp        move_left(t_coordp);

/*
** move_up.c
*/
t_coordp        move_up(t_coordp);

/*
** move_down.c
*/
t_coordp        move_down(t_coordp);

/*
** redim.c
*/
void	redim(int, int, t_list *, char **);

/*
** victory.c
*/
char	*victory(t_list *);

#endif /* !MY_H_ */
