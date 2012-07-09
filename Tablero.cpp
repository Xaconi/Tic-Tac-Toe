#include "Tablero.h"
#include <fstream>
#include <iostream>
using namespace std;

Tablero::Tablero()
{
    tablero = CSurface::OnLoad("C:\\Users\\Xaconi\\Documents\\GitHub\\Tic-Tac-Toe\\Image\\tablero.bmp");  // Creem la imatge del tablero...
    X = CSurface::OnLoad("C:\\Users\\Xaconi\\Documents\\GitHub\\Tic-Tac-Toe\\Image\\cruz.bmp");
    O = CSurface::OnLoad("C:\\Users\\Xaconi\\Documents\\GitHub\\Tic-Tac-Toe\\Image\\circulo.bmp");
    partida = false;
    turno = 0;
    modificarMatriu();
}

void Tablero::dibuixa (SDL_Surface* pantalla)
{
    CSurface::OnDraw(pantalla, tablero, 0, 0);
}

void Tablero::lliberarMemoria()
{
    SDL_FreeSurface(tablero);
}

void Tablero::ferJugada(SDL_Surface* pantalla, int x, int y)
{
    if(x > 0 && x <= 220 && y > 0 && y <= 220)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[0][0] = 1;
            CSurface::OnDraw(pantalla, X, 4, 4);
        }
        else    // Torn de la O
        {
            posiciones[0][0] = 2;
            CSurface::OnDraw(pantalla, O, 4, 4);
        }
    }
    else if (x > 220 && x <= 440 && y > 0 && y <= 220)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[1][0] = 1;
            CSurface::OnDraw(pantalla, X, 224, 4);
        }
        else    // Torn de la O
        {
            posiciones[1][0] = 2;
            CSurface::OnDraw(pantalla, O, 224, 4);
        }
    }
    else if (x > 440 && x <= 660 && y > 0 && y <= 220)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[2][0] = 1;
            CSurface::OnDraw(pantalla, X, 444, 4);
        }
        else    // Torn de la O
        {
            posiciones[2][0] = 2;
            CSurface::OnDraw(pantalla, O, 444, 4);
        }
    }
    else if (x > 0 && x <= 220 && y > 220 && y <= 440)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[0][1] = 1;
            CSurface::OnDraw(pantalla, X, 4, 224);
        }
        else    // Torn de la O
        {
            posiciones[0][1] = 2;
            CSurface::OnDraw(pantalla, O, 4, 224);
        }
    }
    else if (x > 220 && x <= 440 && y > 220 && y <= 440)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[1][1] = 1;
            CSurface::OnDraw(pantalla, X, 224, 224);
        }
        else    // Torn de la O
        {
            posiciones[1][1] = 2;
            CSurface::OnDraw(pantalla, O, 224, 224);
        }
    }
    else if (x > 440 && x <= 660 && y > 220 && y <= 440)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[2][1] = 1;
            CSurface::OnDraw(pantalla, X, 444, 224);
        }
        else    // Torn de la O
        {
            posiciones[2][1] = 2;
            CSurface::OnDraw(pantalla, O, 444, 224);
        }
    }
    else if (x > 0 && x <= 220 && y > 440 && y <= 660)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[0][2] = 1;
            CSurface::OnDraw(pantalla, X, 4, 444);
        }
        else    // Torn de la O
        {
            posiciones[0][2] = 2;
            CSurface::OnDraw(pantalla, O, 4, 444);
        }
    }
    else if (x > 220 && x <= 440 && y > 440 && y <= 660)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[1][2] = 1;
            CSurface::OnDraw(pantalla, X, 224, 444);
        }
        else    // Torn de la O
        {
            posiciones[1][2] = 2;
            CSurface::OnDraw(pantalla, O, 224, 444);
        }
    }
    else if (x > 440 && x <= 660 && y > 440 && y <= 660)
    {
        if(turno % 2 == 0)  // Torn de la X
        {
            posiciones[2][2] = 1;
            CSurface::OnDraw(pantalla, X, 444, 444);
        }
        else    // Torn de la O
        {
            posiciones[2][2] = 2;
            CSurface::OnDraw(pantalla, O, 444, 444);
        }
    }
    turno++;
}

void Tablero::dibuixaFitxes(SDL_Surface* pantalla)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(posiciones[i][j] == 1)
            {
                CSurface::OnDraw(pantalla, X, i*220+2, j*220+2);
            }
            else if (posiciones[i][j] == 2)
            {
                CSurface::OnDraw(pantalla, O, i*220+2, j*220+2);
            }
        }
    }
}

void Tablero::modificarMatriu()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            posiciones[i][j] = 0;
        }
    }
}

bool Tablero::comprovarJugada()
{
    // Mirem si algú ha guanyat
    bool final;
    if(posiciones[0][0] != 0 && posiciones[0][0] == posiciones[1][1] && posiciones[0][0] == posiciones[2][2]) final = true;
    else if (posiciones[2][0] != 0 && posiciones[2][0] == posiciones[1][1] && posiciones[2][0] == posiciones[0][2]) final = true;
    else if (posiciones[0][0] != 0 && posiciones[0][0] == posiciones[1][0] && posiciones[0][0] == posiciones[2][0]) final = true;
    else if (posiciones[0][0] != 0 && posiciones[0][0] == posiciones[0][1] && posiciones[0][0] == posiciones[0][2]) final = true;
    else if (posiciones[2][0] != 0 && posiciones[2][0] == posiciones[2][1] && posiciones[2][0] == posiciones[2][2]) final = true;
    else if (posiciones[2][2] != 0 && posiciones[2][2] == posiciones[1][2] && posiciones[2][2] == posiciones[0][2]) final = true;
    else if (posiciones[1][0] != 0 && posiciones[1][0] == posiciones[1][1] && posiciones[1][0] == posiciones[1][2]) final = true;
    else if (posiciones[0][1] != 0 && posiciones[0][1] == posiciones[1][1] && posiciones[0][1] == posiciones[2][1]) final = true;
    else
    {
        int i,j;
        int k = 0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(posiciones[i][j] == 0) k++;
            }
        }
        if(k == 0) final = true;
        else final = false;
    }
    return final;
}
