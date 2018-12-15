#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LATO 10

typedef enum
{
    true,
    false
} boolean;
typedef struct
{
    int griglia[LATO][LATO];
} GRIGLIA;

void stampagriglia(GRIGLIA griglia)
{
    /* stampa la griglia */
    for (int i = 0; i < LATO; ++i)
    {
        for (int j = 0; j < LATO; j++)
        {
            printf("%d", griglia.griglia[i][j]);
        }
        printf("\n");
    }
}

GRIGLIA posizionanavi(GRIGLIA griglia)
{
    /* posiziona 4 navi di dimensione 2 */
    for (int c = 1; c <= 4; c++)
    {
        int colonnacorrente = 0;
        int rigacorrente = 0;

        printf("inserisci la nave %d da 2\n", c);
        printf("inserisci le coordinate del primo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 2;

        printf("\ninserisci le coordinate del secondo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 2;
        stampagriglia(griglia);
    }

    /* posiziona 3 navi di dimensione 3 */
    for (int c = 1; c <= 3; c++)
    {
        int colonnacorrente = 0;
        int rigacorrente = 0;
        printf("inserisci la nave %d da 3\n", c);
        printf("inserisci le coordinate del primo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 3;
        printf("\ninserisci le coordinate del secondo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 3;
        printf("\ninserisci le coordinate del terzo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 3;
        stampagriglia(griglia);
    }

    /* posiziona 2 navi di dimensione 4 */
    for (int c = 1; c <= 2; c++)
    {
        int colonnacorrente = 0;
        int rigacorrente = 0;
        printf("inserisci la nave %d da 4\n", c);
        printf("inserisci le coordinate del primo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 4;
        printf("\ninserisci le coordinate del secondo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        // cosa a caso
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 4;
        printf("\ninserisci le coordinate del terzo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 4;
        printf("\ninserisci le coordinate del quarto punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 4;
        stampagriglia(griglia);
    }

    /* posiziona 1 nave di dimensione 5 */
    for (int c = 1; c <= 1; c++)
    {
        int colonnacorrente = 0;
        int rigacorrente = 0;
        printf("inserisci la nave %d da 5\n", c);
        printf("inserisci le coordinate del primo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 5;
        printf("\ninserisci le coordinate del secondo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 5;
        printf("\ninserisci le coordinate del terzo punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        printf("\ninserisci le coordinate del quarto punto");
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 5;
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 5;
        printf("\ninserisci le coordinate del quinto punto");
        printf("\nin che riga la vuoi inserire?");
        scanf("\n%d", &colonnacorrente);
        printf("\nin che colonna la vuoi mettere?");
        scanf("\n%d", &rigacorrente);
        griglia.griglia[colonnacorrente - 1][rigacorrente - 1] = 5;
        stampagriglia(griglia);
    }

    return griglia;
}

int main()
{
    printf("Hello, World!\n");
    GRIGLIA griglia;
    for (int i = 0; i < LATO; ++i)
    {
        for (int j = 0; j < LATO; j++)
        {
            // int f = 0;
            griglia.griglia[i][j] = 0;
            // printf("%d", griglia.griglia[i][j]);
        }
        // printf("\n");

    } /*ho creato la griglia*/

    stampagriglia(griglia);

    griglia = posizionanavi(griglia);
    stampagriglia(griglia);

    return 0;
}