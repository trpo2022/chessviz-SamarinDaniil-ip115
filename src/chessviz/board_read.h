#include <stdio.h>

void close_open(FILE* chessviz_read, FILE* chessviz_change);
void chess_piece_movement(
        FILE* chessviz_read,
        FILE* chessviz_change,
        int position_1,
        int position_2);
void check_open(FILE* chessviz);
void rewrite_change(FILE* chessviz_change, FILE* chessviz_read);
void repeat_board(FILE* chessviz_origin, FILE* chessviz_change);
int check_symbol_peshka(FILE* chessviz, int position);
int check_symbol_pusto(FILE* chessviz, int position);
void print_board(FILE* chessviz_read);
void the_most_important(
        FILE* chessviz_read,
        FILE* chessviz_change,
        int position_1,
        int position_2);
int check_size(char* Word);
int Symbol_and_Number(
        char* Word, char* str, int position_symbol, int* position);