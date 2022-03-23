#include "board_read.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* chessviz_origin;
    chessviz_origin = fopen("chess-board.txt", "a+");
    FILE* chessviz_change;
    chessviz_change = fopen("chess-board_change.txt", "w+");
    FILE* chessviz_read;
    chessviz_read = fopen("chess-board_read.txt", "w+");
    check_open(chessviz_origin);
    check_open(chessviz_read);
    check_open(chessviz_change);
    repeat_board(chessviz_origin, chessviz_change);
    close_open(chessviz_origin, chessviz_change);
    repeat_board(chessviz_origin, chessviz_read);
    close_open(chessviz_origin, chessviz_read);
    char str[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int position_symbol = 0;
    int position = 0;
    int position_1 = 0;
    int position_2 = 0;
    int mas_position[6];
    char Word[100];
    char board_position[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    //
    while (1) {
        scanf("%s", Word);
            if (check_size(Word) == 1) {
                for (position_symbol = 0; position_symbol < 5;
                     position_symbol++) {
                    position = 0;
                    if (Symbol_and_Number(Word, str, position_symbol, &position)
                        == 1) {
                        mas_position[position_symbol] = position;
                    }
                    if (Symbol_and_Number(
                                Word,
                                board_position,
                                position_symbol,
                                &position)
                        == 1) {
                        mas_position[position_symbol] = position;
                    }
                }
                position_1 = (mas_position[0] * 2 + 1) + mas_position[1] * 18;
                position_2 = (mas_position[3] * 2 + 1) + mas_position[4] * 18;
                close_open(chessviz_read, chessviz_change);
                the_most_important(
                        chessviz_read, chessviz_change, position_1, position_2);
                print_board(chessviz_read);
            }
    }
    //
    fclose(chessviz_origin);
    fclose(chessviz_read);
    fclose(chessviz_change);
    return 0;
}