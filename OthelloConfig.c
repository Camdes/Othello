#include <stdio.h>
#include "OthelloConfig.h"

/* この関数は、displayの代わりになる。 				*/
/* displayと違い●と◯ではなく、1,2などで表示される。*/
void checkBoard( int board[side_max][length_max] )
{
	int side_i;
	int length_i;

	printf("\n0 1 2 3 4 5 6 7");
	for ( side_i = 0; side_i < 8; side_i++) {
		if( side_i != 0 ) {
			printf("%d ", side_i-1);
		}
		printf("\n");
		for( length_i = 0; length_i < 8; length_i++ ) {
			printf("%d ", board[side_i][length_i]);
		}
	}
	printf("7\n");
	return;
}