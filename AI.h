#include <SDL/SDL.h>
#include "Tablero.h"

class AI
{
    public:
        int dificultat;
        int millorPosicioX;
        int millorPosicioY;
        AI(int d);
        int minimax(Tablero* t, int nivell);
        int tipusNivell(int nivell);
        int valorarJugada(Tablero* t);
        bool tresEnRatlla(Tablero* t, int valor);
        bool duesFitxes(Tablero* t, int valor);
        bool bloquejat(Tablero* t, int valor);
};
