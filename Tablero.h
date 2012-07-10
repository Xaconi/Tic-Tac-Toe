#include <SDL/SDL.h>
#include "CSurface.h"

class Tablero
{
    public:
        SDL_Surface* tablero;
        SDL_Surface* X;
        SDL_Surface* O;
        int posiciones[3][3];
        bool partida;
        int turno;

        Tablero();
        void dibuixa(SDL_Surface* pantalla);
        void lliberarMemoria();
        void ferJugada(SDL_Surface* pantalla, int x, int y, int valor);
        void dibuixaFitxes(SDL_Surface* pantalla);
        void modificarMatriu();
        bool comprovarJugada();
        bool llocLliure(int x, int y);
        void posarFitxa(int x, int y, int valor);
        void treureFitxa(int x, int y, int valor);
};
