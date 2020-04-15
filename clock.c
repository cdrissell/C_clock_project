#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clock.h"

char* cal;

void get_time(char* x){
	FILE *t;
	t = popen("date \"+%T\"", "r");
	fgets(x, 9, t);
	pclose(t);
}

void get_cal(char* x){
	FILE *c;
	c = popen("cal", "r");
	while(feof(c) != 1){
		*x = fgetc(c);
		x++;
	}
	pclose(c);
}

int get_line(void){
	int hold;
	FILE *li;
	char line[4];
	li = popen("tput lines", "r");
	fgets(line, 4, li);  
	hold = atoi(line);
	return hold;
}

int get_col(void){
	int hold;
	FILE *col;
	char column[4];
	col = popen("tput cols", "r");
	fgets(column, 4, col);
	hold = atoi(column);
	return hold;
}

void sigint_handler(int sig){
	printf("\n");

	//shows cursor
	printf("\e[?25h");

	//resets text color
	printf("%s", RESET);

	free(cal);
	system("clear");
	system("tput reset");
	exit(1);
}

int main(int argc, char* argv[]){

	char ti[8];
	char day[2];
	cal = malloc(200);
	char **fulltime[9];
	int line_num;
	int col_num;

	int color_flag = 0;
	int timer;
	char alarmtime[8];
	int atimeint;

	signal(SIGINT, sigint_handler);

	system("clear");

	//hides console cursor
	printf("\e[?25l");

	line_num = get_line();
	col_num = get_col();

	if (argc > 1){
		if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "Help") == 0){
			for (int i = 1; i <= line_num/2-4; i++) printf("\n");
			while(1){
				for(int i = 0; i < (col_num-20)/2; i++) printf(" ");
				printf("This is the help page\n");
				printf("\r\33[A");
			}
		}
		else if (strcmp(argv[1], "-c") == 0 && argc == 3){
			if (strcmp(argv[2], "Red") == 0 || strcmp(argv[2], "red") == 0){
				printf("%s", RED);
				color_flag = 1;
			}else if (strcmp(argv[2], "Green") == 0 || strcmp(argv[2], "green") == 0){
				printf("%s", GREEN);
				color_flag = 2;
			}else if (strcmp(argv[2], "Yellow") == 0 || strcmp(argv[2], "yellow") == 0){
				printf("%s", YELLOW);
				color_flag = 3;
			}else if (strcmp(argv[2], "Blue") == 0 || strcmp(argv[2], "blue") == 0){
				printf("%s", BLUE);
				color_flag = 4;
			}else if (strcmp(argv[2], "Magenta") == 0 || strcmp(argv[2], "magenta") == 0){
				printf("%s", MAGENTA);
				color_flag = 5;
			}else if (strcmp(argv[2], "Cyan") == 0 || strcmp(argv[2], "cyan") == 0){
				printf("%s", CYAN);
				color_flag = 6;
			}else if (strcmp(argv[2], "White") == 0 || strcmp(argv[2], "white") == 0){
				printf("%s", WHITE);
				color_flag = 7;
			}
		}
		else if (strcmp(argv[1], "-t") == 0 && argc == 3){
			// NEEDS WORK
			get_time(alarmtime);
			timer = atoi(argv[2]);
			printf("%d",timer);
			atimeint = atoi(alarmtime);
			printf("%d", atimeint);
			sprintf(alarmtime, "%d", atimeint+timer);
			//*alarmtime = itoa(atimeint+timer);
			//printf("%s", alarmtime);
		}
	}

	//centers the text vertically
	for (int i = 1; i <= line_num/2-11; i++){
		printf("\n");
	}

	get_cal(cal);

	// prints the title of the calendar
	for(int i = 0; i < (col_num-20)/2; i++) printf(" ");
	for(int i = 0; i < 23; i++){
		printf("%c", cal[i]);
	}

	// prints the rest of the calendar. Catches the current day and colors it
	for(int i = 23; i < 176; i++){
		if (cal[i-1] == '\n'){
			for(int i = 0; i < (col_num-20)/2; i++) printf(" ");
		}
		if (cal[i-2] == 95 && cal[i-1] == 8){
			if(color_flag == 1 || color_flag == 5) printf("%s", CYAN);
			else printf("%s", RED);
			printf("%c", cal[i]);
		} else{
			printf("%s", RESET);
			if(color_flag == 1) printf("%s", RED);
			if(color_flag == 2) printf("%s", GREEN);
			if(color_flag == 3) printf("%s", YELLOW);
			if(color_flag == 4) printf("%s", BLUE);
			if(color_flag == 5) printf("%s", MAGENTA);
			if(color_flag == 6) printf("%s", CYAN);
			if(color_flag == 7) printf("%s", WHITE);
			printf("%c", cal[i]);
		}
	}

	printf("\n");
	printf("\n");

	//loop to update time
	while(1){

		get_time(ti);

		//sets first time digit
		if (ti[0] == '0') {
			fulltime[0] = zero;
		} else if (ti[0] == '1'){
			fulltime[0] = one;
		} else if (ti[0] == '2'){
			fulltime[0] = two;
		}

		//sets colons and second through sixth time digit
		for (int i = 1; i < 8; i++){
			if (ti[i] == '0'){
				fulltime[i] = zero;
			} else if (ti[i] == '1'){
				fulltime[i] = one;
			} else if (ti[i] == '2'){
				fulltime[i] = two;
			} else if (ti[i] == '3'){
				fulltime[i] = three;
			} else if (ti[i] == '4'){
				fulltime[i] = four;
			} else if (ti[i] == '5'){
				fulltime[i] = five;
			} else if (ti[i] == '6'){
				fulltime[i] = six;
			} else if (ti[i] == '7'){
				fulltime[i] = seven;
			} else if (ti[i] == '8'){
				fulltime[i] = eight;
			} else if (ti[i] == '9'){
				fulltime[i] = nine;
			} else if (ti[i] == ':'){
				fulltime[i] = dots;
			}
		}

		for (int j = 0; j <= 10; j++){

			//centers the text horizontally 
			for(int i = 0; i < (col_num-92)/2; i++) printf(" ");

			//prints the time
			printf("%s  %s  %s  %s  %s  %s  %s  %s\n", 
					fulltime[0][j], fulltime[1][j],
					fulltime[2][j], fulltime[3][j],
					fulltime[4][j], fulltime[5][j],
					fulltime[6][j], fulltime[7][j]);

		}

		//erases previous interation's printf()
		for (int j = 0; j <= 10; j++){
			printf("\r\33[A");
		}

	}
	return 0;
}
