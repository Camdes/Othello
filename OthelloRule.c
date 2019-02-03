#include <stdio.h>
#include "OthelloRule.h"

int revSide(int board[side_max][length_max], int player_side, int player_length, int turn)
{
	int revLengthTmp = player_length; /* 後で、どこまで反転させたか分かるように置いておく。 */
	int ret;

	ret = sideLineFunction(board, player_side, player_length, 0);
	ret = sideLineFunction(board, player_side, player_length, 1);
	return 0;
}


int sideLineFunction(int board[side_max][length_max],int player_side,int player_length,int LRflag )
{
	int revLengthTmp = player_length; /* 後で、どこまで反転させたか分かるように置いておく。 */
	
	if((player_length < 0) || (player_length > 8)) {
		printf("ERROR player_length:%d \n", player_length);
		return -1;
	}
	
	while( (player_length >= 0) && (player_length <= 8) ) {
		if( LRflag == 0 ) {
			player_length--;
		} else {
			player_length++;
		}
		if ( board[player_side][player_length] == 1 ) {
			while ( player_length != revLengthTmp ) {
				board[player_side][player_length] = 1;
				if( LRflag == 0 ) {
					player_length++;
				} else {
					player_length--;
				}
			}
			break;
		}
	}
	return 0;
}