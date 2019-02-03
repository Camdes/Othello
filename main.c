#include<stdio.h>

#include "board.h"
#include "common.h"
#include "OthelloRule.h"
#include "OthelloConfig.h"

int player(int a,int b,int turn);

int main(void)
{
	int i,j;
	int length = 0;
	int side = 0;
	/* player turn:player1 1(白):player2 */
	/* turn:0 白, turn:1 黒)*/
	int turn = 0;
	/*retrun value check*/
	int ret = 0;

	init(board);
	display(board);
	//checkBoard(board);
	while( length != 3 || side != 3) {
		if ( turn == 0 ) {
			printf("白のターン\n");
		} else {
			printf("黒のターン\n");
		}

		printf("ここに駒を置く場所を指定してください\n");
		printf("縦:");
		scanf("%d",&length);
		printf("\n横:");
		scanf("%d",&side);
		if( turn == 0 ) {
			ret = player(length, side, turn);
			if( ret < 0 ) {
				continue;
			}
			turn = 1;
		} else {
			player(length, side, turn);
			if( ret < 0 ) {
				continue;
			}
			turn = 0;
		}
		/* displayか、checkBoardに使い分けて */
		display(board);
		//checkBoard(board);
	}
	return 0;
}

int player(int length,int side,int turn)
{
	//todo:will read itlater
	/* -1の理由は、表示状は、1からだが、内部的には0からである。 */
	/* よってその辻褄をあわしている。 */
	int player_length = length - 1;
	int player_side = side - 1;
	int ret = 0;
	int revCheck = 0;
	if ( (length == 0 || side == 0) || (board[player_side][player_length] >= 1) ) {
		printf("ここに駒はおけません。\n");
		printf("もう一度試してください\n");
		return -1;
	}
	if( turn == 0 ) {
		revCheck = revSide(board,player_side,player_length, turn);
		board[player_side][player_length] = 1;
	} else {
		board[player_side][player_length] = 2;
	}
	return 0;
}
