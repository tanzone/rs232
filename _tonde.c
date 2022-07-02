#include "_tonde.h"

/**
*STAMPO TUTTO IL TITOLO
**/
void stampaLegenda(char* szonde)
{
    int i;

    printf("Rs232 9600,n,8,1 sui bit %s\n", szonde);
    printf("  idle s ");

    for(i = 0; i < strlen(szonde); i++)
        printf("%c ", szonde[i]);

    printf("s idle\n");
}


/**
*IDLE INIZIALE O FINALE
**/
void idle(int visibile)
{
    if(visibile)
        printf("%c%c%c%c", 196,196,196,196);
    else
        printf("    ");
}

/**
*BIT DI START CON LE CONDIZIONI DEL PRIMO BIT DELLA STRINGA
**/
void bitStart(int linea, char* szonde)
{
    ///SOPRA
    if(linea == 1 && szonde[0] == '0')
        printf("%c %c%c", 191,218,196);

    if(linea == 1 && szonde[0] == '1')
        printf("%c   ", 191);

    ///SOTTO
    if(linea == 0 && szonde[0] == '0')
        printf("%c%c%c ", 192,196,217);

    if(linea == 0 && szonde[0] == '1')
        printf("%c%c%c%c", 192,196,196,196);
}

/**
*BIT DI STOP CON LE CONDIZIONI DELL'ULTIMO BIT DELLA STRINGA
**/
void bitStop(int linea, char* szonde)
{
    ///SOPRA
    if(linea == 1 && szonde[7] == '0')
        printf("%c%c%c", 196,196,196);

    if(linea == 1 && szonde[7] == '1')
        printf("%c%c%c", 218,196,196);

    ///SOTTO
    if(linea == 0 && szonde[7] == '0')
        printf("   ");

    if(linea == 0 && szonde[7] == '1')
        printf("%c  ", 217);
}

/**
*CONTROLLI PER GUARDARE COME STAMPARE L'ONDA QUADRA DEL +
**/
void funzione_sopra(char* szonde)
{
    int i;

    for(i = 0; i <= strlen(szonde); i++)
    {
        if( szonde[i] == '0' && szonde[i+1] == '0' )
            BitOndaSopra(PIU);

        else if( szonde[i] == '1' && szonde[i+1] == '1' )
            BitOndaSopra(ZERO);

        else if( szonde[i] == '0' && szonde[i+1] == '1' )
            BitOndaSopra(PIU_ZERO);

        else if( szonde[i] == '1' && szonde[i+1] == '0' )
            BitOndaSopra(ZERO_PIU);
    }
}

/**
*CONTROLLI PER GUARDARE COME STAMPARE L'ONDA QUADRA DEL 0
**/
void funzione_sotto(char* szonde)
{
    int i;

    for(i = 0; i <= strlen(szonde); i++)
    {
        if( szonde[i] == '0' && szonde[i+1] == '0' )
            BitOndaSotto(PIU);

        else if( szonde[i] == '1' && szonde[i+1] == '1' )
            BitOndaSotto(ZERO);

        else if( szonde[i] == '0' && szonde[i+1] == '1' )
            BitOndaSotto(PIU_ZERO);

        else if( szonde[i] == '1' && szonde[i+1] == '0' )
            BitOndaSotto(ZERO_PIU);
    }
}

/**
*STAMPA A SECONDA DELLA CONDIZIONE PER LA LINEA SOPRA
**/
void BitOndaSopra(int come)
{
    switch (come)
    {
        case ZERO:
            printf("  ");
            break;

        case PIU:
            putchar(196);
            putchar(196);
            break;

        case ZERO_PIU:
            putchar(218);
            putchar(196);
            break;

        case PIU_ZERO:
            putchar(191);
            printf(" ");
            break;
    }
}

/**
*STAMPA A SECONDA DELLA CONDIZIONE PER LA LINEA SOTTO
**/
void BitOndaSotto(int come)
{
    switch (come)
    {
        case ZERO:
            putchar(196);
            putchar(196);
            break;

        case PIU:
            printf("  ");
            break;


        case ZERO_PIU:
            putchar(217);
            printf(" ");
            break;

        case PIU_ZERO:
            putchar(192);
            putchar(196);
            break;
    }
}
