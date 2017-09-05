#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>

#include "p4.h"


static struct player_s *players = NULL;

int h = DEFAULT_H;
int w = DEFAULT_W;

///////////////////////////// player ////////////////////////////


struct player_s * create_player(int nb_player)
{
        return nb_player >= 2 ? 
        calloc (2, sizeof (struct player_s)) : calloc (nb_player, sizeof (struct player_s)) ;
}

void config_player(struct player_s * player)
{
    scanf ("%s", player->name);
    player->tokens = h * w / 2;
}



int turn(int player, uc* grid)
{
    int column = 0;
    int played = 0;
    fprintf (stdout, "%s \n", PLAY_MSG);
    while (!played)
    {
        if (!player % 2)
        {
            fprintf (stdout, "%s \n", players[0].name);
            scanf("%d", &column);
            // get the '\n'
            getc(stdin);
            if (!is_filled(grid, column))
            {
                insert (grid, column,  P1_JETON);
                players[0].tokens--;
                played = 1;
            }
            else
                fprintf (stderr, "err : %s ", COLUMN_FILLED); 
        }
        else
        {
            fprintf (stdout, "%s \n", players[1].name);
            scanf("%d", &column);
            // get the '\n'
            if (is_filled(grid, column))
            {
                insert (grid, column,  P2_JETON);
                players[1].tokens--;
                played = 1;
            }
            else
                fprintf (stderr, "err : %s", COLUMN_FILLED);
        }
    }
    return EXIT_SUCCESS; 
}


////////////////////////////// tools ///////

// read function with the fgets here 


//////////////////////////////////// grid //////////////////////////////
int is_empty(uc case_value)
{
    return case_value == ' ';
}


int insert(uc* grid, int column, uc token)
{
    int i = 0;
    for (i = column * DEFAULT_H - 1; i >= (column - 1) * h; i--)
    {
        if (is_empty(grid[i]))
            grid[i] = token;
    }
    return i;
}


uc* create_tab(int w, int h)
{
    return calloc (w * h, sizeof (uint8_t));
}


int is_filled(uc* grid, int column)
{
    return grid[(column - 1) * h] != ' ';
}

int p4_game()
{
    int finished = 0;
    int player = 0;
    uc * grid = create_tab(w, h);
    if (grid)
    {
        while (!finished)
        {
            turn(player, grid);
            player++;
            if (player == 42)
                fprintf (stdout, "msg : %s ", MATCH_NULL);
        }
    }
    else
        fprintf(stderr, "mssg : %s ", ALLOCATION_ERROR);
   return 1;
}

