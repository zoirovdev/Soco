#ifndef PACMAN_H
#define PACMAN_H


#define PACMAN 'C'
#define DEMON 'X'
#define FOOD '.'
#define OUTER_WALL '#'
#define INNER_WALL '='
#define EMPTY ' '
#define HEIGHT 20
#define WIDTH 40


extern char board[HEIGHT][WIDTH];
extern int isgameover;
extern int score;


void put_walls();
void put_demons();
void put_foods();
void put_pacman();
void draw();
void move();


#endif
