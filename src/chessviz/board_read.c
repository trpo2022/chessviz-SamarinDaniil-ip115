#include "board_read.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void close_open(FILE* chessviz_read, FILE* chessviz_change)
{
    fclose(chessviz_read);
    fclose(chessviz_change);
    chessviz_change = fopen("chess-board_change.txt", "a+");
    chessviz_read = fopen("chess-board_read.txt", "a+");
}

void chess_piece_movement(
        FILE* chessviz_read,
        FILE* chessviz_change,
        int position_1,
        int position_2)
{
    fclose(chessviz_read);
    chessviz_read = fopen("chess-board_read.txt", "r+");
    fclose(chessviz_change);
    chessviz_change = fopen("chess-board_change.txt", "w+");
    int point = 0;
    char tmp = 'P';
    while (!feof(chessviz_read)) {
        point++;
        char ch = getc(chessviz_read);
        if (point == position_1) {
            tmp = ch;
            ch = '#';
            putc(ch, chessviz_change);
        }
        if (point == position_2) {
            ch = tmp;
            putc(ch, chessviz_change);
        }
        if (point != position_1 && point != position_2) {
            putc(ch, chessviz_change);
        }
        if (point == 169)
            break;
    }
}

void rewrite_change(FILE* chessviz_change, FILE* chessviz_read)
{
    fclose(chessviz_read);
    fclose(chessviz_change);
    chessviz_change = fopen("chess-board_change.txt", "a+");
    chessviz_read = fopen("chess-board_read.txt", "w+");
    repeat_board(chessviz_change, chessviz_read);
}

void check_open(FILE* chessviz)
{
    if (!chessviz) {
        fputs("Error opening .txt for reading", stderr);
    }
}

void repeat_board(FILE* chessviz_origin, FILE* chessviz_change)
{
    int p = 0;
    while (!feof(chessviz_origin)) {
        p++;
        char ch = getc(chessviz_origin);
        putc(ch, chessviz_change);
        if (p == 169)
            break;
    }
}

int check_symbol_peshka(FILE* chessviz, int position)
{
    int check = 0;
    int z = 0;
    while (!feof(chessviz)) {
        z++;
        char ch = getc(chessviz);
        if (z == position) {
            if (ch == 'p') {
                printf("\n BB %d BB \n", z);
                check++;
            }
            if (ch == 'P') {
                check++;
            }
        }
        if (ch == 'p')
        {
            printf("\n AA %d AA \n", z);
        }
    }
    if (check != 0) {
        return 1;
    } else {
        return 0;
    }
}

int check_symbol_pusto(FILE* chessviz, int position)
{
    int check = 0;
    int z = 0;
    while (!feof(chessviz)) {
        z++;
        char ch = getc(chessviz);
        if (z == position) {
            if (ch == '#') {
                check++;
            }
        }
    }
    if (check != 0) {
        return 1;
    } else {
        return 0;
    }
}

void the_most_important(
        FILE* chessviz_read,
        FILE* chessviz_change,
        int position_1,
        int position_2)
{
    if (check_symbol_peshka(chessviz_read, position_1) == 1) {
        close_open(chessviz_read, chessviz_change);
        if (check_symbol_pusto(chessviz_read, position_2) == 1) {
            printf("\n AAAA \n");
            chess_piece_movement(
                    chessviz_read, chessviz_change, position_1, position_2);
        }
    }
    rewrite_change(chessviz_change, chessviz_read);
}

void print_board(FILE* chessviz_read)
{
    int p;
    fclose(chessviz_read);
    chessviz_read = fopen("chess-board_read.txt", "a+");
    while (!feof(chessviz_read)) {
        p++;
        char ch = getc(chessviz_read);
        if (ch == '#') {
            ch = ' ';
        }
        if (p == 169)
            break;
        putc(ch, stderr);
    }
}

int check_size(char* Word)
{
    if (strlen(Word) == 5) {
        return 1;
    } else {
        return 0;
    }
}

int Symbol_and_Number(char* Word, char* str, int position_symbol, int* position)
{
    int check = 0;
    int const Symbol_size = 8;
    //
    for (int j = 0; j < Symbol_size; j++) {
        if (Word[position_symbol] == str[j]) {
            *position = 1 + j;
            check = 1;
            return check;
            break;
        }
    }
    //
    if (check == 0) {
        return 0;
    }
    return 0;
}
