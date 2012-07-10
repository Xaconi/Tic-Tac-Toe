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
                    else if(opcio == 2) fase = 3;
                    else if(opcio == 3) OnExit();
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
    if(fase == 2)
    {
        if(tablero->turno % 2 == 0) tablero->ferJugada(pantalla, x,y,1);
        else tablero->ferJugada(pantalla, x,y,2);
    }
    else if(fase == 4)
    {
        tablero->ferJugada(pantalla, x,y,1);
        int* moviment = inteligencia->minimax(tablero, 1);
        cout << moviment[1] << endl;
        tablero->posarFitxa(moviment[1], moviment[2], 2);
        tablero->turno++;
    }
    if(tablero->comprovarJugada()) Running = false;
}

//==============================================================================
