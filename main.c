#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a = 1;
    int y = 5;

    struct tm
    {
        int tm_sec;       /* secondes (0,59) */
        int tm_min;       /* minutes (0,59) */
        int tm_hour;      /* heures depuis minuit (0,23) */
        int tm_mday;      /* jour du mois (0,31) */
        int tm_mon;       /* mois depuis janvier (0,11) */
        int tm_year;      /* années écoulées depuis 1900 */
        int tm_wday;      /* jour depuis dimanche (0,6) */
        int tm_tm_yday;   /* jour depuis le 1er janvier (0,365) */
        int tm_isdst;
    };

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


    time_t actTime;
    struct tm *timeComp;

    time(&actTime);
    timeComp = localtime(&actTime);
    /*creating string yyyy-MM-dd hh:mm:ss*/
    printf("%d-%02d-%02d %02d:%02d:%02d \n", timeComp->tm_year + 1900,
                                                       timeComp->tm_mon + 1,
                                                       timeComp->tm_mday,
                                                       timeComp->tm_hour,
                                                       timeComp->tm_min,
                                                       timeComp->tm_sec);


    }

    return 0;
}
