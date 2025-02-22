#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

#include "pacman.h"



					
int main(){
	srand(time(NULL));
	put_walls();
	put_demons();
	put_foods();
	put_pacman();

	printf("Movements: up -> w\tdown -> s\tleft -> a\tright -> d\n");
	printf("Enter y to continue => ");
	char y;
	scanf("%c", &y);
	if(y=='y') isgameover = 1;
	else  isgameover = 0; 

	score = 0;
	while(isgameover){

		system("clear");
		draw();	
		printf("\nSCORE -: %d\n", score);

		char c;
		scanf("%c", &c);
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
				printf("\nYou reached <%d scores>\n", score);
				printf("Quit\n");
				isgameover = 0;
				break;
			}
	}
			

	return 0;
}
