#include <SDL/SDL.h>
#include "CSurface.h"

class Button
{
    public:
        // Variables
        SDL_Surface* imatgeNoPolsat;
        SDL_Surface* imatgePolsat;
        int posicioX;
        int posicioY;
        bool polsat;

        // Métodos
        Button(int x, int y, char* botoPolsat, char* botoNoPolsat);
        void dibuixaBoto(SDL_Surface* pantalla);
        bool mirarSiPolsat(int x, int y);
        void lliberarMemoria();
};
