#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a = 1;
    int y = 5;
    FILE* fichier = NULL;
    fichier = fopen("essai.txt", "w+");
    if (fichier !=0)
    {
        if (a=1)
            {
            fprintf(fichier, "Player 1 wins in y strikes!", y);
            }
        else
            {
            fprintf(fichier, "Player 2 wins in y strikes", y);
            }
    }

    return 0;
}
