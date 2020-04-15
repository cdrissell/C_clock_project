/*

int main(void){

	//int max_x, max_y;

	system("clear");

	get_cal();

	printf("\n");
	printf("\n");
	

	for(int i = 0; i <= 15; i++){
		for (int j = 0; j <=13; j++){
			printf("%c", calendar[i][j]);
		}	
	}

	printf("\n");
	printf("\n");

	timeout(0);

	*/

	/*
	while(1){
		get_time();
		printf("\r%s", ti);	
		fflush(stdout);
	}
	*/

	//printf("\n");	
	
	/*
	initscr();
	if (has_colors() == TRUE) start_color();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr, max_y, max_x);
		
	while(TRUE){
		get_time();
		get_cal();
		int key;
		if((key = getch()) != ERR){
			switch(key){
				case 0x1B: case 127: case KEY_BACKSPACE:
					endwin();
					exit(1);
			}		
		}	
		clear();
		mvprintw(5, 5, "Current Time: %s", ti);
		for(int i = 0; i <= 21; i++){
			mvprintw(max_y/2+i, max_x/2, calendar[i]);
		}
		
		refresh();
		//usleep(500000);
	}
	endwin();
	exit(1);

}

*/


	/*
		for (int i = 0; i <= 11; i++){
			printf("\n");
			for (int j = 0; j <= col_num/6; j++){
				printf(" ");
			}
			printf("%s  ", five[i]);
			printf("%s  ", six[i]);
			printf("%s  ", dots[i]);
			printf("%s  ", seven[i]);
			printf("%s  ", nine[i]);
			printf("%s  ", dots[i]);
			printf("%s  ", eight[i]);
			printf("%s  ", seven[i]);
		}
	*/