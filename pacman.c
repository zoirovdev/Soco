#include <stdio.h>
#include <stdlib.h>

#include "pacman.h"


char board[HEIGHT][WIDTH];
int isgameover = 0;
int score = 0;

void put_walls(){
	//putting outer walls
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1){
				board[i][j] = OUTER_WALL;
			} else {
				board[i][j] = EMPTY;
			}
		}
	}

	//putting inner walls
	int count = 50;
	while(count--){
		int y = rand() % HEIGHT + 1;
		int x = rand() % WIDTH + 1;

		int rand_nums[] = {-1, 0, 1};
		int idx = 0;

		int rand_lengths[] = {1,3,5,7,9};
		int length_idx = rand() % 5;
		int length = rand_lengths[length_idx];

		while(length--){
			idx = rand() % 3;
			if(idx==1){
				x += rand_nums[idx];
				y += rand_nums[idx];
			} else if(idx==0){
				y += rand_nums[idx];
			} else if(idx==2){
				x += rand_nums[idx];
			}

			if(board[y][x]!=OUTER_WALL){
				board[y][x]=INNER_WALL;
			}	
		}
	}
}


void put_demons(){
	int count = 15;
	while(count--){
		int i = rand() % HEIGHT;
	       	int j = rand() % WIDTH;

		if(board[i][j]!=OUTER_WALL && board[i][j]!=INNER_WALL){
			board[i][j] = DEMON;
		}
	}
}	


void put_foods(){
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(board[i][j]!=OUTER_WALL && board[i][j]!=INNER_WALL && board[i][j]!=DEMON){
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

		if(board[i][j]!=OUTER_WALL && board[i][j]!=DEMON && board[i][j]!=INNER_WALL){
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
	
	if(board[dest_y][dest_x] == DEMON){
		printf("\nYou reached <%d scores>\n", score);
		isgameover = 0;
	} else if(board[dest_y][dest_x] == FOOD){
		board[pacman_y][pacman_x] = EMPTY;
		board[dest_y][dest_x] = PACMAN;
		score++;
	} else if(board[dest_y][dest_x] == EMPTY){
		board[pacman_y][pacman_x] = EMPTY;
		board[dest_y][dest_x] = PACMAN;
	}
}

