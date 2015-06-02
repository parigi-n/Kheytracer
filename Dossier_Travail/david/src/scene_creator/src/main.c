/*
** main.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david/src/scene_creator
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon Jun  1 17:08:28 2015 david sebaoun
** Last update Tue Jun  2 12:27:59 2015 david sebaoun
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <ncurses/panel.h>
#include "scene_creator.h"

#define NLINES 10
#define NCOLS 40

void	win_show(WINDOW *win, char *label, int label_color);
void	init_wins(WINDOW **wins, int n);
void	print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

/* static void	finish(int sig) */
/* { */
/*   (void)sig; */
/*   endwin(); */
/*   /\* do your non-curses wrapup here *\/ */
/*   exit(0); */
/* } */

/* int	main(int argc, char **argv) */
/* { */
/*   int	c; */
/*   int	num; */

/*   num = 0; */
/*   /\* initialize your non-curses data structures here *\/ */
/*   signal(SIGINT, finish); */
/*   initscr();      /\* initialize the curses library *\/ */
/*   keypad(stdscr, TRUE);  /\* enable keyboard mapping *\/ */
/*   nonl();         /\* tell curses not to do NL->CR/NL on output *\/ */
/*   cbreak();       /\* take input chars one at a time, no wait for \n *\/ */
/*   echo();         /\* echo input - in color *\/ */
/*   if (has_colors()) */
/*     { */
/*       start_color(); */
/*       /\* */
/*        * Simple color assignment, often all we need.  Color pair 0 cannot */
/*        * be redefined.  This example uses the same value for the color */
/*        * pair as for the foreground color, though of course that is not */
/*        * necessary: */
/*        *\/ */
/*       init_pair(1, COLOR_RED,     COLOR_BLACK); */
/*       init_pair(2, COLOR_GREEN,   COLOR_BLACK); */
/*       init_pair(3, COLOR_YELLOW,  COLOR_BLACK); */
/*       init_pair(4, COLOR_BLUE,    COLOR_BLACK); */
/*       init_pair(5, COLOR_CYAN,    COLOR_BLACK); */
/*       init_pair(6, COLOR_MAGENTA, COLOR_BLACK); */
/*       init_pair(7, COLOR_WHITE,   COLOR_BLACK); */
/*     } */
/*   while (42) */
/*     { */
/*       c = getch();     /\* refresh, accept single keystroke of input *\/ */
/*       attrset(COLOR_PAIR(num % 8)); */
/*       num++; */
/*       write(1, &c, 1);      /\* process the command keystroke *\/ */
/*     } */
/*   finish(0);               /\* we're done *\/ */
/*   (void)argc; */
/*   (void)argv; */
/* } */

int		main()
{
  WINDOW	*my_wins[3];
  PANEL		*my_panels[3];
  PANEL		*top;
  int		ch;
  
  /* Initialize curses */
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  /* Initialize all the colors */
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_wins(my_wins, 3);
  /* Attach a panel to each window */ /* Order is bottom up */
  my_panels[0] = new_panel(my_wins[0]); /* Push 0, order: stdscr-0 */
  my_panels[1] = new_panel(my_wins[1]); /* Push 1, order: stdscr-0-1 */
  my_panels[2] = new_panel(my_wins[2]); /* Push 2, order: stdscr-0-1-2 */
  /* Set up the user pointers to the next panel */
  set_panel_userptr(my_panels[0], my_panels[1]);
  set_panel_userptr(my_panels[1], my_panels[2]);
  set_panel_userptr(my_panels[2], my_panels[0]);
  /* Update the stacking order. 2nd panel will be on top */
  update_panels();
  /* Show it on the screen */
  attron(COLOR_PAIR(4));
  mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
  attroff(COLOR_PAIR(4));
  doupdate();
  top = my_panels[2];
  while ((ch = getch()) != KEY_F(1))
    {
      switch(ch)
	{
	case 9:
	  top = (PANEL *)panel_userptr(top);
	  top_panel(top);
	  break;
	}
      update_panels();
      doupdate();
    }
  endwin();
  return 0;
}

/* Put all the windows */
void	init_wins(WINDOW **wins, int n)
{
  int		x;
  int		y;
  int		i;
  char		label[80];

  y = 2;
  x = 10;
  for(i = 0; i < n; ++i)
    {
      wins[i] = newwin(NLINES, NCOLS, y, x);
      sprintf(label, "Window Number %d", i + 1);
      win_show(wins[i], label, i + 1);
      y += 3;
      x += 7;
    }
}

/* Show the window with a border and a label */
void	win_show(WINDOW *win, char *label, int label_color)
{
  int	startx;
  int	starty;
  int	height;
  int	width;

  getbegyx(win, starty, startx);
  getmaxyx(win, height, width);
  box(win, 0, 0);
  mvwaddch(win, 2, 0, ACS_LTEE); 
  mvwhline(win, 2, 1, ACS_HLINE, width - 2); 
  mvwaddch(win, 2, width - 1, ACS_RTEE); 
  print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

void	print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
  int	length;
  int	x;
  int	y;
  float	temp;

  if (win == NULL)
    win = stdscr;
  getyx(win, y, x);
  if (startx != 0)
    x = startx;
  if (starty != 0)
    y = starty;
  if (width == 0)
    width = 80;
  length = strlen(string);
  temp = (width - length)/ 2;
  x = startx + (int)temp;
  wattron(win, color);
  mvwprintw(win, y, x, "%s", string);
  wattroff(win, color);
  refresh();
}
