//==============================================================================
#include "CApp.h"
#include <fstream>
#include <iostream>
using namespace std;
//==============================================================================
CApp::CApp() {
    pantalla = NULL;
    //tablero = NULL;

    Running = true;
    fase = 0;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
    SDL_Event Event;
    while(Running) {
        if(fase == 0)
        {
            while(SDL_PollEvent(&Event)) {
                OnEventMenu(&Event);
            }
            OnLoop();
            OnRender();
        }
        else if(fase == 1)
        {
            tablero = new Tablero();
            fase = 2;
        }
        else if(fase == 2)
        {
            while(SDL_PollEvent(&Event)) {
                OnEvent(&Event);
            }
            OnLoop();
            OnRender();
        }
    }
    OnCleanup();
    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;
    return theApp.OnExecute();
}

//==============================================================================
