#include <string.h>
#include <ncurses.h>

#define ENTER 10

char *tank_forward[] = {
                "# @ #",
                "|   |",
                "#___#"};

char *tank_backward[] = {
				"#___#",
				"|   |",
                "# @ #",
                };

char *tank_right[] = {
				"#___#",
				"|   @",
                "#___#",
                };

char *tank_left[] = {
				"#___#",
				"@   |",
                "#___#",
                };

short start_x = 0, start_y = 0;


void draw_tank(char type, WINDOW *tank_window){

	char **tank;
	switch (type)
	{
	case 'w':
		tank = tank_forward;
		start_y--;
		break;
	case 's':
		tank = tank_backward;
		start_y++;
		break;
	case 'd':
		tank = tank_right;
		start_x++;
		break;
	case 'a':
		tank = tank_left;
		start_x--;
		break;
	default:
		return;
	}
	for (short i = 0; i < 3; i++){
		mvprintw(start_y + i, start_x, "%s", tank[i]);
	}
}

int main(){

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
	
	short Height, Width;

	getmaxyx(stdscr, Height, Width);

	WINDOW *tank_window = newwin(3, 3, Height / 2, Width / 2);

	char current_input;
	while ((current_input = getch()) != ENTER)
	{
		clear();
		draw_tank(current_input, tank_window);
		refresh();
	}
	

	getch();
	clear();
	endwin();
}