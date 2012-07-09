#include "Menu.h"

Menu::Menu()
{
    capsalera = CSurface::OnLoad("O:\\Pooyan Remake\\Image\\logo.bmp");  // Creem la imatge de la capçalera del menu...
    fons = CSurface::OnLoad("O:\\Pooyan Remake\\Image\\fons.bmp");
    botons[0] = new Button(220,350,"O:\\Pooyan Remake\\Image\\boto1Polsat.bmp","O:\\Pooyan Remake\\Image\\boto1NoPolsat.bmp");
    botons[1] = new Button(220,450,"O:\\Pooyan Remake\\Image\\boto2Polsat.bmp","O:\\Pooyan Remake\\Image\\boto2NoPolsat.bmp");
    posicioX = 180;
    posicioY = 80;
}

void Menu::dibuixaMenu(SDL_Surface* pantalla)
{
    CSurface::OnDraw(pantalla, fons, 0, 0);
    CSurface::OnDraw(pantalla, capsalera, posicioX, posicioY);
    botons[0]->dibuixaBoto(pantalla);
    botons[1]->dibuixaBoto(pantalla);
}

int Menu::mirarSiBotoPolsat(int x, int y)
{
    int boto = 0;
    if(botons[0]->mirarSiPolsat(x,y))
    {
        boto = 1;
    }
    else if (botons[1]->mirarSiPolsat(x,y))
    {
        boto = 2;
    }
    return boto;
}

void Menu::lliberarMemoria()
{
    SDL_FreeSurface(capsalera);
    SDL_FreeSurface(fons);
    botons[0]->lliberarMemoria();
    botons[1]->lliberarMemoria();
}
