#include <stdio.h>
#include <string.h>
#include "_tonde.h"

int main(void)
{
    char szonde[DIM];
    strcpy(szonde, "00100100");

    stampaLegenda(szonde);

    //ONDE QUADRE LINEA SOPRA
    printf("+ ");
    idle(1);                ///IDLE INIZIALE
    bitStart(1,szonde);     ///BIT DI START INIZIALE
    funzione_sopra(szonde); ///STAMPO LE ONDE QUADRE
    bitStop(1,szonde);      ///BIT DI STOP FINALE
    idle(1);                ///IDLE FINALE

    //ONDE QUADRE LINEA SOTTO
    printf("\n0 ");
    idle(0);                ///IDLE INIZIALE
    bitStart(0,szonde);     ///BIT DI START INIZIALE
    funzione_sotto(szonde); ///STAMPO LE ONDE QUADRE
    bitStop(0,szonde);      ///BIT DI STOP FINALE
    idle(0);                ///IDLE FINALE


return 0;
}
