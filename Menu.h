#include <SDL/SDL.h>
#include "CSurface.h"
#include "Button.h"

class Menu
{
    public:
        // Variables
        Button* botons[2];
        SDL_Surface* capsalera;
        SDL_Surface* fons;
        int posicioX;
        int posicioY;

        // Métodos
        Menu();
        void dibuixaMenu(SDL_Surface* pantalla);
        int mirarSiBotoPolsat(int x, int y);
        void lliberarMemoria();
};
