//
// Created by Daria Aleksandrova on 2/20/18.
//

#include "include/vm.h"

void	cycles_to_die_refresh(int cycle_to_die)
{
	int y;

	y = 45;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 215, "          ");
	mvprintw(y, 215, "%d", cycle_to_die);
	refresh();
}

void 	pause_vm()
{
	while (1)
	{
		if (getch() == 32)
			break ;
	}

}

void	cycle_refresh(int cycle)
{
	int y;

	y = 8;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 208, "%d", cycle);
	refresh();
	usleep(100000);
	if (getch() == 32)
		pause_vm();

}

char *initiate_color(void)
{
	char *clr;
	int i;

	start_color();
	init_color(COLOR_MAGENTA, 230, 230, 230);
	init_pair(10, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(7, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(8, COLOR_RED, COLOR_MAGENTA);
	init_pair(9, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	clr = malloc(4096);
	i = 0;
	while (i < 4096)
		clr[i++] = 11;
	return (clr);
}

int		create_borders()
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < COL + 8)					//горизонтальные линии
	{
		mvaddch(0, x, ' ' | COLOR_PAIR(10));
		mvaddch(ROW - 1, x++, ' ' | COLOR_PAIR(10));
	}
	while (y < ROW)				// вертикальные линии
	{
		mvaddch(y, 0, ' ' | COLOR_PAIR(10));
		mvaddch(y, COL - 45, ' ' | COLOR_PAIR(10));
		mvaddch(y++, COL + 8, ' ' | COLOR_PAIR(10));
	}
	refresh();
	return (0);
}

int 	choose_players_color(t_player *players, char *clr, int players_num)
{
	int 	pl;
	int 	size;
	int 	i;
	int 	j;

	pl = 1;
	i = 0;
	size = 4096 / players_num;
	while (players)
	{
		j = i;
		while (j - i < (int)players->header->prog_size)
			clr[j++] = pl;
		players = players->next;
		i += size;
		pl++;
	}
	return (0);
}

int		fullfill_map(t_core *core, char *clr, int players)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 2;
	i = 0;
	attron(COLOR_PAIR(10));
	mvprintw(0, 3, "COREWAR is inda hause");
	choose_players_color(core->players, clr, players);
	attrset(A_NORMAL);
	while (i < 4096)
	{
		x += 3;
		attron(COLOR_PAIR(clr[i]));
		mvprintw(y, x, "%02x", core->map[i]);
		attrset(A_NORMAL);
		if (x > COL - 50 && !(x = 0))
			y++;
		i++;
	}
	refresh();
	return (0);
}

void	print_const_part(t_core *core)
{
	int y;

	y = 45;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 200, "CYCLE_TO_DIE : %d", core->cycle_to_die);
	mvprintw(y + 2, 200, "CYCLE_DELTA : 50");
	mvprintw(y + 4, 200, "NBR_LIVES : 21");
	mvprintw(y + 6, 200, "MAX_CHECKS : %d", core->max_checks);
	refresh();
}

int     fullfill_players_on_map(int players_num, t_player *players, t_core *core)
{
	int y;
	int pl;

	pl = 1;
	y = 8;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 200, "Cycle : %d", 0);
	mvprintw(y + 3, 200, "Processes : %d", 0);
	while (pl < players_num + 1 && pl < 5)
	{
		mvprintw(y + 7, 200, "Player %d :", players->number);
		attron(COLOR_PAIR(players->number));
		mvprintw(y + 7, 211, "%s", players->header->prog_name);
		attroff(COLOR_PAIR(players->number));
		mvprintw(y + 8, 202, "Last live : ");
		mvprintw(y + 8, 230, "%d", core->process->last_live);
		mvprintw(y + 9, 202, "Lives in current period : ");
		mvprintw(y + 9, 230, "%d", players->lives);
		y += 5;
		pl++;
		players = players->next;
	}
	print_const_part(core);
	refresh();
	return (0);
}

void	draw_map(char *clr, int	players, t_core *core)
{
	curs_set(0);
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, true);
	create_borders();
	fullfill_map(core, clr, players);
	fullfill_players_on_map(players, core->players, core);
}

int		ncurses_version(t_core *core)
{
	char *color;
	int num;

	initscr();
	color = initiate_color();
    num = get_players_size(core->players);
	draw_map(color, num, core);
	return (0);
}