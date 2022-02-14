#include <stdio.h>

void check_open (FILE *chessviz)
{
    if( !chessviz)
    {
        fputs( "Error opening chess-board.txt for reading", stderr );
    }
}

int main()
{
    FILE *chessviz;
    chessviz = fopen("chess-board.txt", "r");
    check_open(chessviz);
    while (!feof(chessviz))
    {
        char ch=getc(chessviz);
        putchar(ch);
    }
    printf("\n");
    fclose(chessviz);
    return 0;
}
