//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
    if(fase == 0)
    {
        menu->dibuixaMenu(pantalla);
        SDL_Flip(pantalla);
    }
    else if(fase == 1)
    {
        OnCleanupMenu();
    }
    else if(fase == 2)
    {
        tablero->dibuixa(pantalla);
        tablero->dibuixaFitxes(pantalla);
        SDL_Flip(pantalla);
    }
}

//==============================================================================
