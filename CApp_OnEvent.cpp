//==============================================================================
#include "CApp.h"
#include <fstream>
#include <iostream>
using namespace std;
//==============================================================================

void CApp::OnEventMenu(SDL_Event* Event) {
    int opcio;
    switch(Event->type) {
        case SDL_MOUSEBUTTONDOWN: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    opcio = menu->mirarSiBotoPolsat(Event->button.x,Event->button.y);
                    if(opcio == 1) fase = 1;
                    else if(opcio == 2) OnExit();
                    break;
                }
            }
            break;
        }
    }
}

void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnLButtonDown(int x, int y)
{
    tablero->ferJugada(pantalla, x,y);
    if(tablero->comprovarJugada()) Running = false;
}

//==============================================================================
