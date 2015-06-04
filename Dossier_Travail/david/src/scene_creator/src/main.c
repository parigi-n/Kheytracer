/*
** main.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david/src/scene_creator
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon Jun  1 17:08:28 2015 david sebaoun
** Last update Wed Jun  3 16:01:13 2015 david sebaoun
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <ncurses/panel.h>
#include "scene_creator.h"

#define N_LEFT_LINES 40
#define N_LEFT_COLS 30
#define N_MID_LINES 40
#define N_MID_COLS 100

void	win_show(WINDOW *win, char *label, int label_color);
void	init_wins(WINDOW **wins);
void	print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

int		main()
{
  WINDOW	*my_wins[2];
  PANEL		*my_panels[2];
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
  init_wins(my_wins);
  /* Attach a panel to each window */ /* Order is bottom up */
  my_panels[0] = new_panel(my_wins[0]); /* Push 0, order: stdscr-0 */
  my_panels[1] = new_panel(my_wins[1]); /* Push 1, order: stdscr-0-1 */
  /* Set up the user pointers to the next panel */
  set_panel_userptr(my_panels[0], my_panels[1]);
  set_panel_userptr(my_panels[1], my_panels[0]);
  /* Update the stacking order. 2nd panel will be on top */
  update_panels();
  /* Show it on the screen */
  attron(COLOR_PAIR(4));
  mvprintw(LINES - 2, 0, "Use tab to browse through the windows (ESC to Exit)");
  attroff(COLOR_PAIR(4));
  doupdate();
  top = my_panels[1];
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
void	init_wins(WINDOW **wins)
{
  int		i;
  char		label[80];

  i = 0;
  /* Left panel*/
  wins[i] = newwin(N_LEFT_LINES, N_LEFT_COLS, 2, 2);
  sprintf(label, "Objects");
  win_show(wins[i], label, i + 1);
  ++i;
  /* Mid panel*/
  wins[i] = newwin(N_MID_LINES, N_MID_COLS, 2, N_LEFT_COLS + 1);
  sprintf(label, "Objects' informations");
  win_show(wins[i], label, i + 1);
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
