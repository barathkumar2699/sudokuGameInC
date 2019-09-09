#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define LT 218
#define RT 191
#define CROSS 197
#define HL 196
#define VL 179
#define TT 194
#define BT 193
#define LST 195
#define RST 180
#define LB 192
#define RB 217
#define BS 8
#define SPACE 32
#define WIDTH 5
#define HEIGHT 1
#define DIM 9
#define N 9
#define UNASSIGNED 0

/*  COORD coord={0,0}; // this is global variable
				    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }*/

int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}};

// This function finds an entry in grid that is still unassigned
int FindUnassignedLocation(int grid[N][N], int *row, int *col);

// Checks whether it will be legal to assign num to the given row, col
int isSafe(int grid[N][N], int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
//all unassigned locations in such a way to meet the requirements
//for Sudoku solution (non-duplication across rows, columns, and boxes) */
int SolveSudoku(int grid[N][N])
{
	int row, col,num;

	// If there is no unassigned location, we are done
	if (!FindUnassignedLocation(grid, &row, &col))
	return 1; // success!

	// consider digits 1 to 9
	for ( num = 1; num <= 9; num++)
	{
		// if looks promising
		if (isSafe(grid, row, col, num))
		{
			// make tentative assignment
			grid[row][col] = num;
			gotoxy(15+(6*col),4+(2*row));
			printf("%d",grid[row][col]);
		       //	c++;
		       getch();

			//getchar();
			//printGrid(grid);

			// return, if success, yay!
			if (SolveSudoku(grid))
				return 1;

			// failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}
	return 0; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
found, the reference parameters row, col will be set the location
that is unassigned, and 1 is returned. If no unassigned entries
remain, 0 is returned. */
int FindUnassignedLocation(int grid[N][N], int *row1, int *col1)
{
int row,col;
	for ( row = 0; row < N; row++){
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
	    {

	    *row1=row;
	    *col1=col;
				return 1;
	    }
	}
	return 0;
}

/* Returns a intean which indicates whether an assigned entry
in the specified row matches the given number. */
int UsedInRow(int grid[N][N], int row, int num)
{
int col;
	for (col = 0; col < N; col++)
		if (grid[row][col] == num)
			return 1;
	return 0;
}

/* Returns a intean which indicates whether an assigned entry
in the specified column matches the given number. */
int UsedInCol(int grid[N][N], int col, int num)
{
int row;
	for (row = 0; row < N; row++)
		if (grid[row][col] == num)
			return 1;
	return 0;
}

/* Returns a intean which indicates whether an assigned entry
within the specified 3x3 box matches the given number. */
int UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
int row,col;
	for (row = 0; row < 3; row++)
		for ( col = 0; col < 3; col++)
			if (grid[row+boxStartRow][col+boxStartCol] == num)
				return 1;
	return 0;
}

/* Returns a intean which indicates whether it will be legal to assign
num to the given row,col location. */
int isSafe(int grid[N][N], int row, int col, int num)
{
	/* Check if 'num' is not already placed in current row,
	current column and current 3x3 box */
	return !UsedInRow(grid, row, num) &&
		!UsedInCol(grid, col, num) &&
		!UsedInBox(grid, row - row%3 , col - col%3, num)&&
			grid[row][col]==UNASSIGNED;
}

/* A utility function to print grid */
void printGrid(int grid[N][N])
{
int row,col;
	for ( row = 0; row < N; row++)
	{
	for ( col = 0; col < N; col++)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}

/* Driver Program to test above functions */

int main()//home
{
  int bcol , brow,ctr1,ctr2,ctr3,safer,safec,i,j,rinc,cinc;
  clrscr();
 safec= bcol = (80 - ((DIM *WIDTH)+DIM+1))/2;
 safer= brow = (25 - ((DIM *HEIGHT)+DIM+1))/2;
//  printf("Am here");
  gotoxy(bcol,brow);
   printf("%c",LT);
  for(ctr2=1 ; ctr2<= DIM ; ctr2++)
  {
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",HL);
   printf("%c",TT);
  }
  printf("%c%c",BS,RT);
  //end of first line
  for(ctr3=1 ; ctr3<= DIM; ctr3++)
 {
  gotoxy(bcol,++brow);
  for(ctr2=1 ; ctr2<= DIM+1; ctr2++)
  {
   printf("%c",VL);
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",SPACE);
  }
  gotoxy(bcol,++brow);
  printf("%c",LST);
  for(ctr2 =1  ; ctr2<= DIM; ctr2++)
  {
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",HL);
  printf("%c",CROSS);
  }
  printf("%c%c",BS,RST);
 }
 //body of the box
  gotoxy(bcol,brow);
   printf("%c",LB);
  for(ctr2=1 ; ctr2<= DIM ; ctr2++)
  {
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",HL);
   printf("%c",BT);
  }
  printf("%c%c",BS,RB);
  //end of last line
  rinc=1,cinc=3;

  gotoxy(safec,safer);
 // safec=safec+cinc;
 // safer=safer+rinc;

  for(i=0;i<DIM;i++,rinc+=2)
  {
  cinc=3;
  for(j=0;j<DIM;j++)
  {
//  printf("%d",grid[i][j]);
 // getch();
  gotoxy(safec+cinc,safer+rinc);
	printf("%d",grid[i][j]);//,safec+cinc,safer+rinc);
  cinc+=6;
  }
  }




SolveSudoku(grid);
  getch();
  return 0;
}

