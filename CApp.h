//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"
#include "Menu.h"
#include "AI.h"

//==============================================================================
class CApp : public CEvent {
    private:
        bool            Running;
        SDL_Surface*    pantalla;

    public:
        Tablero*        tablero;
        Menu*           menu;
        int             fase;
        AI*             inteligencia;
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);
        void OnEventMenu(SDL_Event* Event);

        void OnExit();

        void OnLButtonDown(int x, int y);

        void OnLoop();

        void OnRender();

        void OnCleanup();
        void OnCleanupMenu();
};

//==============================================================================

#endif
