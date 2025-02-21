#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define DEMON 'X'
#define PACMAN 'C'
#define FOOD '.'
#define WALL '#'
#define EMPTY ' '
#define HEIGHT 20
#define WIDTH 40


char board[HEIGHT][WIDTH];
bool isnotover;

void put_walls(){
	//putting outer walls
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1){
				board[i][j] = WALL;
			} else {
				board[i][j] = EMPTY;
			}
		}
		printf("\n");
	}

	//putting inner walls
	int count = 50;
	while(count--){
		int i = (rand() % (HEIGHT + 1));
		int j = (rand() % (WIDTH + 1));

		if(board[i][j] != WALL && board[i][j] != PACMAN){
			board[i][j] = WALL;
		}
	}

	int val=5;
	while(val--){
		int row = (rand() % (HEIGHT + 1));
		for(int j=3; j<WIDTH-3; j++){
			if(board[row][j] != WALL && board[row][j] != PACMAN){
				board[row][j] = WALL;
			}
		}
	}
}


void put_demons(){
	int count = 15;
	while(count--){
		int i = rand() % HEIGHT;
	       	int j = rand() % WIDTH;

		if(board[i][j]!=WALL && board[i][j]!=PACMAN){
			board[i][j] = DEMON;
		}
	}
}	


void put_foods(){
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(board[i][j]!=WALL && board[i][j]!=PACMAN && board[i][j]!=DEMON){
				board[i][j] = FOOD;
			}
		}
	}
}


void put_pacman(){
	int count = 10;
	while(count--){
		int i = rand() % HEIGHT;
		int j = rand() % WIDTH;

		if(board[i][j] != WALL && board[i][j] != DEMON){
			board[i][j] = PACMAN;
			break;
		}
	}
}


void draw(){
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}


void move(int x, int y){
	int pacman_x = 0;
	int pacman_y = 0;
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(board[i][j] == PACMAN){
				pacman_y = i;
				pacman_x = j;
				break;
			}
		}
	}

	int dest_x = pacman_x + x;
	int dest_y = pacman_y + y;
	
	if(board[dest_y][dest_x]==DEMON){
		isnotover = false;
	} else if(board[dest_y][dest_x]==FOOD || board[dest_y][dest_x]==EMPTY){
		board[pacman_y][pacman_x] = EMPTY;
		board[dest_y][dest_x] = PACMAN;
	}
}
					
int main(){
	put_walls();
	put_demons();
	put_foods();
	put_pacman();
	
	isnotover = true;
	while(isnotover){

		system("clear");
		draw();	
		
		char c = getchar();
		switch(c){
			case 'a':
				move(-1, 0);
				break;
			case 's':
				move(0, 1);
				break;
			case 'd':
				move(1, 0);
				break;
			case 'w':
				move(0, -1);
				break;
			case 'q':
				printf("Quit\n");
				isnotover = false;
				break;
			}
	}
			

	return 0;
}
