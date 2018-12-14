#include <stdio.h>
#define MAX 10
#define COLPITA 9
#define MANCATO 8
#define DEBUG

int converti_lettere_in_numeri(char cordinaLETT_colonna);
void stampacampo(int campo[MAX][MAX]);
void stampanavi(int num_cacciatorpediniere_da_posizionare, int num_sottomarini_da_posizionare, int num_corazzieri_da_posizionare, int num_portaerei_da_posizionare);

int main()
{
    int campo[MAX][MAX];
    int campo2[MAX][MAX];
    int campo_di_attacco[MAX][MAX];
    int campo_di_attacco2[MAX][MAX];
    int comando;

    //variabili per cordinate
    int cordinataNUM_riga;
    char cordinaLETT_colonna;
    int cordina_converita_num;
    //

    //variabili per navi
    int num_navi_da_posizionare = 9;
    int num_cacciatorpediniere_da_posizionare = 3;
    int num_sottomarini_da_posizionare = 3;
    int num_corazzieri_da_posizionare = 2;
    int num_portaerei_da_posizionare = 1;

    //

    //compilazione del campo
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            campo[r][c] = 0;
        }
    }
    //

    stampacampo(campo);

    //giocatore 1 compilazione del campo
    char a;
    printf("Ciao Giocatore1, pronto a giocare (premi invio)?");
    scanf("%c", &a);
    if (a == '\n')
    {
        printf("\n bene! posiziona le tue navi \n\n");
    }

#ifdef DEBUG
    num_navi_da_posizionare = 1; // temp
#endif

    do
    { //posizionamento delle navi per il giocatore 1
        stampanavi(num_cacciatorpediniere_da_posizionare, num_sottomarini_da_posizionare,
                   num_corazzieri_da_posizionare, num_portaerei_da_posizionare);

        printf("\nselezione la nave da posizionare:\ncacciatorpediniere: digita 2\nsottomarino: digita 3\ncorazzata: digita 4\nportaerei: digita 5\n");
        scanf("%d", &comando);

        if (comando > 5 && comando < 2)
            printf("scelta non disponibile");

        else
        {
            if (comando == 2)
            { //posizionare cacciatorpediniere
                stampacampo(campo);
                printf("|STAI PER POSIZIONARE UN CACCAITORPEDINERE|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                campo[cordinataNUM_riga][cordina_converita_num] = 2;
                stampacampo(campo);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c++) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c--) && (cordina_converita_num == d)) || ((cordina_converita_num == d++) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d--) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo);
                    }
                }

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo[cordinataNUM_riga][cordina_converita_num] = 2;
                stampacampo(campo);

                num_cacciatorpediniere_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (comando == 3)
            { //posizionare sottomarino
                stampacampo(campo);
                printf("|STAI PER POSIZIONARE UN SOTTOMARINO|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo[cordinataNUM_riga][cordina_converita_num] = 3;
                stampacampo(campo);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c + 2) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c - 2) && (cordina_converita_num == d)) || ((cordina_converita_num == d + 2) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d - 2) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo);
                    }
                }

                //per stampare il sottomarino sulla mappa
                if (cordinataNUM_riga == c + 2)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo[cordinataNUM_riga - 1][cordina_converita_num] = 3;
                }
                if (cordinataNUM_riga == c - 2)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo[cordinataNUM_riga + 1][cordina_converita_num] = 3;
                }
                if (cordina_converita_num == d + 2)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo[cordinataNUM_riga][cordina_converita_num - 1] = 3;
                }
                if (cordina_converita_num == d - 2)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo[cordinataNUM_riga][cordina_converita_num + 1] = 3;
                }
                //

                stampacampo(campo);

                num_sottomarini_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (comando == 4)
            { //posizionare corazzata
                stampacampo(campo);
                printf("|STAI PER POSIZIONARE UNA CORAZZATA|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo[cordinataNUM_riga][cordina_converita_num] = 4;
                stampacampo(campo);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c + 3) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c - 3) && (cordina_converita_num == d)) || ((cordina_converita_num == d + 3) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d - 3) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo);
                    }
                }

                //per stampare il sottomarino sulla mappa
                if (cordinataNUM_riga == c + 3)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo[cordinataNUM_riga - 1][cordina_converita_num] = 4;
                    campo[cordinataNUM_riga - 2][cordina_converita_num] = 4;
                }
                if (cordinataNUM_riga == c - 3)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo[cordinataNUM_riga + 1][cordina_converita_num] = 4;
                    campo[cordinataNUM_riga + 2][cordina_converita_num] = 4;
                }
                if (cordina_converita_num == d + 3)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo[cordinataNUM_riga][cordina_converita_num - 1] = 4;
                    campo[cordinataNUM_riga][cordina_converita_num - 2] = 4;
                }
                if (cordina_converita_num == d - 3)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo[cordinataNUM_riga][cordina_converita_num + 1] = 4;
                    campo[cordinataNUM_riga][cordina_converita_num + 2] = 4;
                }
                //

                stampacampo(campo);

                num_corazzieri_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (comando == 5)
            { //posizionare portaerei
                stampacampo(campo);
                printf("|STAI PER POSIZIONARE UNA PORTAEREI|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo[cordinataNUM_riga][cordina_converita_num] = 5;
                stampacampo(campo);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c + 4) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c - 4) && (cordina_converita_num == d)) || ((cordina_converita_num == d + 4) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d - 4) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo);
                    }
                }

                //per stampare la portaerei sulla mappa
                if (cordinataNUM_riga == c + 4)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga - 1][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga - 2][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga - 3][cordina_converita_num] = 5;
                }
                if (cordinataNUM_riga == c - 4)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga + 1][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga + 2][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga + 3][cordina_converita_num] = 5;
                }
                if (cordina_converita_num == d + 4)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga][cordina_converita_num - 1] = 5;
                    campo[cordinataNUM_riga][cordina_converita_num - 2] = 5;
                    campo[cordinataNUM_riga][cordina_converita_num - 3] = 5;
                }
                if (cordina_converita_num == d - 4)
                {
                    campo[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo[cordinataNUM_riga][cordina_converita_num + 1] = 5;
                    campo[cordinataNUM_riga][cordina_converita_num + 2] = 5;
                    campo[cordinataNUM_riga][cordina_converita_num + 2] = 5;
                }
                //

                stampacampo(campo);

                num_portaerei_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (num_navi_da_posizionare == 0)
            {
                printf("\nBen fatto! hai posizionato tutte le navi\n\n");
            }
        }
    } while (num_navi_da_posizionare != 0);
    //

    /********************************************************************************************************
    *                                  Giocatore 2 posiziona le navi                                        *
    ********************************************************************************************************/

    //giocatore 2 compilazione del campo

    //reimpostare variabili per navi
    num_navi_da_posizionare = 1;
    num_cacciatorpediniere_da_posizionare = 3;
    num_sottomarini_da_posizionare = 3;
    num_corazzieri_da_posizionare = 2;
    num_portaerei_da_posizionare = 1;
    //

    //compilazione del campo
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            campo2[r][c] = 0;
        }
    }
    //

    stampacampo(campo2);

    char b;
    printf("\nCiao Giocatore2, pronto a giocare (premi invio)?");
    scanf("%*c%c", &b);
    if (b == '\n')
    {
        printf("\n bene! posiziona le tue navi \n\n");
    }

    do
    { //posizionamento delle navi per il giocatore 2
        stampanavi(num_cacciatorpediniere_da_posizionare, num_sottomarini_da_posizionare, num_corazzieri_da_posizionare, num_portaerei_da_posizionare);

        printf("\nselezione la nave da posizionare:\ncacciatorpediniere: digita 2\nsottomarino: digita 3\ncorazzata: digita 4\nportaerei: digita 5\n");
        scanf("%d", &comando);

        if (comando > 5 && comando < 2)
            printf("scelta non disponibile");

        else
        {
            if (comando == 2)
            { //posizionare cacciatorpediniere
                stampacampo(campo2);
                printf("|STAI PER POSIZIONARE UN CACCAITORPEDINERE|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo2[cordinataNUM_riga][cordina_converita_num] = 2;
                stampacampo(campo2);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c++) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c--) && (cordina_converita_num == d)) || ((cordina_converita_num == d++) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d--) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo2);
                    }
                }

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo2[cordinataNUM_riga][cordina_converita_num] = 2;
                stampacampo(campo2);

                num_cacciatorpediniere_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (comando == 3)
            { //posizionare sottomarino
                stampacampo(campo2);
                printf("|STAI PER POSIZIONARE UN SOTTOMARINO|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo2[cordinataNUM_riga][cordina_converita_num] = 3;
                stampacampo(campo2);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c + 2) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c - 2) && (cordina_converita_num == d)) || ((cordina_converita_num == d + 2) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d - 2) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo2);
                    }
                }

                //per stampare il sottomarino sulla mappa
                if (cordinataNUM_riga == c + 2)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo2[cordinataNUM_riga - 1][cordina_converita_num] = 3;
                }
                if (cordinataNUM_riga == c - 2)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo2[cordinataNUM_riga + 1][cordina_converita_num] = 3;
                }
                if (cordina_converita_num == d + 2)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo2[cordinataNUM_riga][cordina_converita_num - 1] = 3;
                }
                if (cordina_converita_num == d - 2)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 3;
                    campo2[cordinataNUM_riga][cordina_converita_num + 1] = 3;
                }
                //

                stampacampo(campo2);

                num_sottomarini_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (comando == 4)
            { //posizionare corazzata
                stampacampo(campo2);
                printf("|STAI PER POSIZIONARE UNA CORAZZATA|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                //printf("\n%d %d",cordina_converita_num, cordinataNUM_riga);

                campo2[cordinataNUM_riga][cordina_converita_num] = 4;
                stampacampo(campo2);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c + 3) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c - 3) && (cordina_converita_num == d)) || ((cordina_converita_num == d + 3) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d - 3) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo2);
                    }
                }

                //per stampare il sottomarino sulla mappa
                if (cordinataNUM_riga == c + 3)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo2[cordinataNUM_riga - 1][cordina_converita_num] = 4;
                    campo2[cordinataNUM_riga - 2][cordina_converita_num] = 4;
                }
                if (cordinataNUM_riga == c - 3)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo2[cordinataNUM_riga + 1][cordina_converita_num] = 4;
                    campo2[cordinataNUM_riga + 2][cordina_converita_num] = 4;
                }
                if (cordina_converita_num == d + 3)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo2[cordinataNUM_riga][cordina_converita_num - 1] = 4;
                    campo2[cordinataNUM_riga][cordina_converita_num - 2] = 4;
                }
                if (cordina_converita_num == d - 3)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 4;
                    campo2[cordinataNUM_riga][cordina_converita_num + 1] = 4;
                    campo2[cordinataNUM_riga][cordina_converita_num + 2] = 4;
                }
                //

                stampacampo(campo2);

                num_corazzieri_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (comando == 5)
            { //posizionare portaerei
                stampacampo(campo2);
                printf("|STAI PER POSIZIONARE UNA PORTAEREI|\nscegli la casella dove posizionare la prua(prima la lettera, poi il numero): ");
                scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);

                cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

                campo2[cordinataNUM_riga][cordina_converita_num] = 5;
                stampacampo(campo2);

                int c = cordinataNUM_riga;
                int d = cordina_converita_num;

                for (int i = 0; i != 1; i--)
                {
                    printf("\nscegli la casella dove posizionare la poppa(prima la lettera poi il numero): ");
                    scanf("%*c %c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
                    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);
                    if (((cordinataNUM_riga == c + 4) && (cordina_converita_num == d)) || ((cordinataNUM_riga == c - 4) && (cordina_converita_num == d)) || ((cordina_converita_num == d + 4) && (cordinataNUM_riga == c)) || ((cordina_converita_num == d - 4) && (cordinataNUM_riga == c))) //condizioni per posizionare la nave
                    {
                        i = 2; //serve solo per uscire dal ciclo
                    }
                    else
                    {
                        printf("\nERRORE:impossibile posizionare la nave....Riprova\n\n");
                        stampacampo(campo2);
                    }
                }

                //per stampare la portaerei sulla mappa
                if (cordinataNUM_riga == c + 4)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga - 1][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga - 2][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga - 3][cordina_converita_num] = 5;
                }
                if (cordinataNUM_riga == c - 4)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga + 1][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga + 2][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga + 3][cordina_converita_num] = 5;
                }
                if (cordina_converita_num == d + 4)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga][cordina_converita_num - 1] = 5;
                    campo2[cordinataNUM_riga][cordina_converita_num - 2] = 5;
                    campo2[cordinataNUM_riga][cordina_converita_num - 3] = 5;
                }
                if (cordina_converita_num == d - 4)
                {
                    campo2[cordinataNUM_riga][cordina_converita_num] = 5;
                    campo2[cordinataNUM_riga][cordina_converita_num + 1] = 5;
                    campo2[cordinataNUM_riga][cordina_converita_num + 2] = 5;
                    campo2[cordinataNUM_riga][cordina_converita_num + 2] = 5;
                }
                //

                stampacampo(campo2);

                num_portaerei_da_posizionare--;
                num_navi_da_posizionare--;
            }

            if (num_navi_da_posizionare == 0)
            {
                printf("\nBen fatto! hai posizionato tutte le navi");
            }
        }
    } while (num_navi_da_posizionare != 0);
    //

    /*******************************************************************************************************
    *                                  Fase di combattimento                                               *
    ********************************************************************************************************/

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n Bene! ora tutte le navi sono in posizione\n\n\nGiocatore 1 a te la prima mossa\n");

    //compilazione del campo di attacco
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            campo_di_attacco[r][c] = 0;
        }
    }
    //

    //Colpito o Mancato
    printf("\necco le tue navi:\n");
    stampacampo(campo);
    char c;
    printf("pronto all'attacco?(premi invio)\n");
    scanf("%*c%c", &c);
    stampacampo(campo_di_attacco);

    printf("scegli la casella da colpiere(prima la lettere e poi il numero): ");
    scanf("%c %d", &cordinaLETT_colonna, &cordinataNUM_riga);
    cordina_converita_num = converti_lettere_in_numeri(cordinaLETT_colonna);

    if (campo2[cordinataNUM_riga][cordina_converita_num] > 0 && campo2[cordinataNUM_riga][cordina_converita_num] <= 5)
    {
        printf("\nCOLPITA!\n");
        campo2[cordinataNUM_riga][cordina_converita_num] = COLPITA;
        campo_di_attacco[cordinataNUM_riga][cordina_converita_num] = COLPITA;
    }
    else
    {
        printf("\nBersaglio mancato...\n");
        campo2[cordinataNUM_riga][cordina_converita_num] = MANCATO;
        campo_di_attacco[cordinataNUM_riga][cordina_converita_num] = MANCATO;
    }
    stampacampo(campo_di_attacco);
    //

    return 0;
}

/********************************************************************************************************
*                                        Sottoprogrammi                                                 *
*********************************************************************************************************/

void stampanavi(int num_cacciatorpediniere_da_posizionare, int num_sottomarini_da_posizionare, int num_corazzieri_da_posizionare, int num_portaerei_da_posizionare)
{
    //cacciarpedinere
    if (num_cacciatorpediniere_da_posizionare == 3)
        printf("cacciatorpedonieri: |2--2>   |2--2>    |2--2>");

    if (num_cacciatorpediniere_da_posizionare == 2)
        printf("cacciatorpedonieri: |2--2>   |2--2>");

    if (num_cacciatorpediniere_da_posizionare == 1)
        printf("cacciatorpedonieri: |2--2>");
    //

    //sottomarini
    if (num_sottomarini_da_posizionare == 3)
        printf("\nsottomarini: |3--3--3>   |3--3--3>   |3--3--3>");

    if (num_sottomarini_da_posizionare == 2)
        printf("\nsottomarini: |3--3--3>   |3--3--3>");

    if (num_sottomarini_da_posizionare == 1)
        printf("\nsottomarini: |3--3--3>");
    //

    //corazieri
    if (num_corazzieri_da_posizionare == 2)
        printf("\ncorazzieri: |4--4--4--4>    |4--4--4--4>");

    if (num_corazzieri_da_posizionare == 1)
        printf("\ncorazzieiri: |4--4--4--4>");
    //

    //portaerei
    if (num_portaerei_da_posizionare == 1)
        printf("\nporaerei: |5--5--5--5--5>\n");
    //
}

int converti_lettere_in_numeri(char cordinaLETT_colonna)
{
    int cordinata_convertita;
    if (cordinaLETT_colonna == 'A')
        cordinata_convertita = 0;
    if (cordinaLETT_colonna == 'B')
        cordinata_convertita = 1;
    if (cordinaLETT_colonna == 'C')
        cordinata_convertita = 2;
    if (cordinaLETT_colonna == 'D')
        cordinata_convertita = 3;
    if (cordinaLETT_colonna == 'E')
        cordinata_convertita = 4;
    if (cordinaLETT_colonna == 'F')
        cordinata_convertita = 5;
    if (cordinaLETT_colonna == 'G')
        cordinata_convertita = 6;
    if (cordinaLETT_colonna == 'H')
        cordinata_convertita = 7;
    if (cordinaLETT_colonna == 'I')
        cordinata_convertita = 8;
    if (cordinaLETT_colonna == 'L')
        cordinata_convertita = 9;

    return cordinata_convertita;
}

void stampacampo(int campo[MAX][MAX])
{
    // stampare il campo
    printf("    A  B  C  D  E  F  G  H  I  L\n");
    for (int r = 0; r < MAX; r++)
    {
        if (r < 10)
        {
            printf(":%d: ", r);
        }
        else
        {
            printf(":%d:", r);
        }

        for (int c = 0; c < MAX; c++)
        {
            if ((campo[r][c] != 0) && (campo[r][c] == campo[r][c + 1]) && (campo[r][c] != COLPITA) && (campo[r][c] != MANCATO))
                printf("%d--", campo[r][c]);
            else
            {
                if (campo[r][c] == COLPITA)
                {
                    printf("X  ");
                }
                else
                {
                    if (campo[r][c] == MANCATO)
                    {
                        printf("-  ");
                    }
                    else
                        printf("%d  ", campo[r][c]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    //
}
