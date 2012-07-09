#include "Button.h"

Button::Button(int x, int y, char* botoPolsat, char* botoNoPolsat)
{
    posicioX = x;
    posicioY = y;
    imatgePolsat = CSurface::OnLoad(botoPolsat);
    imatgeNoPolsat = CSurface::OnLoad(botoNoPolsat);
    polsat = false;
}

void Button::dibuixaBoto(SDL_Surface* pantalla)
{
    if(polsat)
    {
        CSurface::OnDraw(pantalla, imatgePolsat, posicioX, posicioY);
    }
    else
    {
        CSurface::OnDraw(pantalla, imatgeNoPolsat, posicioX, posicioY);
    }
}

bool Button::mirarSiPolsat(int x, int y)
{
    if((x > posicioX && x < posicioX + imatgeNoPolsat->w)
       && (y > posicioY && y < posicioY + imatgeNoPolsat->h))
    {
        polsat = !polsat;
    }
    return polsat;
}

void Button::lliberarMemoria()
{
    SDL_FreeSurface(imatgePolsat);
    SDL_FreeSurface(imatgeNoPolsat);
}
