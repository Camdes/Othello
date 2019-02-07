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
	/* player turn:player1 1(��):player2 */
	/* turn:0 ��, turn:1 ��)*/
	int turn = 0;
	/*retrun value check*/
	int ret = 0;

	init(board);
	display(board);
	//checkBoard(board);
	while( length != 3 || side != 3) {
		if ( turn == 0 ) {
			printf("���̃^�[��\n");
		} else {
			printf("���̃^�[��\n");
		}

		printf("�����ɋ��u���ꏊ���w�肵�Ă�������\n");
		printf("�c:");
		scanf("%d",&length);
		printf("\n��:");
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
		/* display���AcheckBoard�Ɏg�������� */
		display(board);
		//checkBoard(board);
	}
	return 0;
}

int player(int length,int side,int turn)
{
	//todo:will read itlater
	/* -1�̗��R�́A�\����́A1���炾���A�����I�ɂ�0����ł���B */
	/* ����Ă��̒�������킵�Ă���B */
	int player_length = length - 1;
	int player_side = side - 1;
	int ret = 0;
	int revCheck = 0;
	if ( (length == 0 || side == 0) || (board[player_side][player_length] >= 1) ) {
		printf("�����ɋ�͂����܂���B\n");
		printf("������x�����Ă�������\n");
		return -1;
	}
	if( turn == 0 ) {
		revCheck = revSide(board,player_side,player_length, turn);
		if(revCheck == 2) {
			printf("�����ɋ�͂����܂���B\n");
			printf("������x�����Ă�������\n");
			return -1;
		} else {
		board[player_side][player_length] = 1;
		}
	} else {
		revCheck = revSide(board,player_side,player_length, turn);
		if(revCheck == 2) {
			printf("�����ɋ�͂����܂���B\n");
			printf("������x�����Ă�������\n");
			return -1;
		} else {
			board[player_side][player_length] = 2;
		}
	}
	return 0;
}
