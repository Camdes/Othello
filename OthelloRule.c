#include <stdio.h>
#include "OthelloRule.h"

int revSide(int board[side_max][length_max], int player_side, int player_length, int turn)
{
	int ret;

	ret = sideLineFunction(board, player_side, player_length, 0, turn);
	ret = sideLineFunction(board, player_side, player_length, 1, turn);
	ret = lengthLineFunction(board, player_side, player_length, 0, turn);
	ret = lengthLineFunction(board, player_side, player_length, 1, turn);
	return 0;
}
int lengthLineFunction(int board[side_max][length_max],int player_side,int player_length,int UDflag ,int turn)
{
	int revSideTmp = player_side; /* 後で、どこまで反転させたか分かるように置いておく。 */
	int piece = 0;
	if( turn == 0 ) {
		piece = 1;
	} else {
		piece = 2;
	}

	if((player_side < 0) || (player_side > 8)) {
		printf("ERROR player_side:%d \n", player_side);
		return -1;
	}

	while( (player_side >= 0) && (player_side <= 8) ) {
		if( UDflag == 0 ) {
			player_side--;
		} else {
			player_side++;
		}
		if ( board[player_side][player_length] == piece ) {
			while ( player_side != revSideTmp ) {
				printf("player_side:%d\n", player_side);
				board[player_side][player_length] = piece;
				if( UDflag == 0 ) {
					player_side++;
				} else {
					player_side--;
				}
			}
			break;
		} else {
			return 2;
		}
	}
	return 0;
}

int sideLineFunction(int board[side_max][length_max],int player_side,int player_length,int LRflag ,int turn)
{
	int revLengthTmp = player_length; /* 後で、どこまで反転させたか分かるように置いておく。 */
	int piece = 0;
	if( turn == 0 ) {
		piece = 1;
	} else {
		piece = 2;
	}

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
		if ( board[player_side][player_length] == piece ) {
			while ( player_length != revLengthTmp ) {
				board[player_side][player_length] = piece;
				if( LRflag == 0 ) {
					player_length++;
				} else {
					player_length--;
				}
				break;
			}
		} else {
			return 2;
		}
	}
	return 0;
}
