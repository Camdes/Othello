#include<stdio.h>
#include "common.h"

void init( int board[side_max][length_max] )
{
	int i;
	int j;

	board[3][3] = BRACK;
	board[3][4] = WHITE;
	board[4][3] = WHITE;
	board[4][4] = BRACK;

	return ;
}

void display( int board[side_max][length_max] )
{
	int i;
	int j;

	printf("\n 1 2 3 4 5 6 7 8");
	for( i = 0; i < 8; i++ )
	{
		if( i != 0)
		{
		printf("%d ",i);
		}
		printf("\n");
		for(j = 0; j < 8; j++ )
		{
			if( board[i][j] == 0 )
			{
				printf("[");
			}
			else if ( board[i][j] == WHITE )
			{
				printf("›");
			}
			else if ( board[i][j] == BRACK )
			{
				printf("œ");
			}
		}
	}
	printf("8\n");
	return;
}




