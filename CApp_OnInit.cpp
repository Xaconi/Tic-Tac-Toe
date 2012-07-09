//==============================================================================
#include "CApp.h"
#include <fstream>
#include <iostream>
using namespace std;

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    if((pantalla = SDL_SetVideoMode(669, 661, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    menu = new Menu();
    return true;
}

//==============================================================================
