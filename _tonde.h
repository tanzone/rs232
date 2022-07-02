#ifndef _tonde_h_INCLUDED
#define _tonde_h_INCLUDED

#define DIM (8)
#define ZERO (0)
#define PIU (1)
#define ZERO_PIU (2)
#define PIU_ZERO (3)

void stampaLegenda(char* szonde);
void idle(int visibile);
void bitStart(int linea, char* szonde);
void bitStop(int linea, char* szonde);
void funzione_sopra(char* szonde);
void funzione_sotto(char* szonde);
void BitOndaSopra(int come);
void BitOndaSotto(int come);

#endif // _tonde_h_INCLUDED
