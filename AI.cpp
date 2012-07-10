#include "AI.h"
#include <fstream>
#include <iostream>
#define MAX 1
#define MIN 0
using namespace std;
AI::AI(int d)
{
    dificultat = d;
    millorPosicioX = 0;
    millorPosicioY = 0;
}

int AI::minimax(Tablero* t, int nivell)
{
    int i, j;
    int resultat = 0;
    int resultatMillor = 0;
    if(nivell <= dificultat)
    {
        // Procés Minimax...
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if(t->llocLliure(i,j))
                {
                    if (tipusNivell(nivell) == 1) t->posarFitxa(i, j, 2);
                    else if (tipusNivell(nivell) == 0)
                    {
                        t->posarFitxa(i, j, 1);
                        resultatMillor = 100;
                    }
                    resultat = minimax(t, nivell + 1);
                    if(tipusNivell(nivell) == 0)
                    {
                        if(resultat < resultatMillor)
                        {
                            resultatMillor = resultat;
                            millorPosicioX = i;
                            millorPosicioY = j;
                            cout << "Resultats MIN: " << resultat << "," << millorPosicioX << "," << millorPosicioY << endl;
                        }
                    }
                    else if(tipusNivell(nivell) == 1)
                    {
                        if(resultat > resultatMillor)
                        {
                            resultatMillor = resultat;
                            millorPosicioX = i;
                            millorPosicioY = j;
                            cout << "Resultats MAX: " << resultat << "," << millorPosicioX << "," << millorPosicioY << endl;
                        }
                    }
                    if (tipusNivell(nivell) == 1) t->treureFitxa(i, j, 2);
                    else if (tipusNivell(nivell) == 0) t->treureFitxa(i, j, 1);
                }
            }
        }
    }
    else
    {
        // Valorem la jugada actual
        resultatMillor = valorarJugada(t);
        cout << "++++++++++PRIORITAT: " << resultatMillor << endl;
    }
    return resultatMillor;
}

int AI::tipusNivell(int nivell)
{
    int sortida;
    if(nivell % 2 != 0) sortida = 1;
    else sortida = 0;
    return sortida;
}

int AI::valorarJugada(Tablero* t)
{
    int valor = 0;
    if(bloquejat(t,2)) valor = 14;
    else if(tresEnRatlla(t,2)) valor = 10;
    else if(duesFitxes(t,2)) valor = 4;
    else if(duesFitxes(t,1)) valor = -5;
    else if(tresEnRatlla(t,1)) valor = -10;
    else
    {
        valor = 1;
    }
    return valor;
}

bool AI::tresEnRatlla(Tablero* t, int valor)
{
    bool final = false;
    if(t->posiciones[0][0] == valor && t->posiciones[0][0] == t->posiciones[1][1] && t->posiciones[0][0] == t->posiciones[2][2]) final = true;
    else if (t->posiciones[2][0] == valor && t->posiciones[2][0] == t->posiciones[1][1] && t->posiciones[2][0] == t->posiciones[0][2]) final = true;
    else if (t->posiciones[0][0] == valor && t->posiciones[0][0] == t->posiciones[1][0] && t->posiciones[0][0] == t->posiciones[2][0]) final = true;
    else if (t->posiciones[0][0] == valor && t->posiciones[0][0] == t->posiciones[0][1] && t->posiciones[0][0] == t->posiciones[0][2]) final = true;
    else if (t->posiciones[2][0] == valor && t->posiciones[2][0] == t->posiciones[2][1] && t->posiciones[2][0] == t->posiciones[2][2]) final = true;
    else if (t->posiciones[2][2] == valor && t->posiciones[2][2] == t->posiciones[1][2] && t->posiciones[2][2] == t->posiciones[0][2]) final = true;
    else if (t->posiciones[1][0] == valor && t->posiciones[1][0] == t->posiciones[1][1] && t->posiciones[1][0] == t->posiciones[1][2]) final = true;
    else if (t->posiciones[0][1] == valor && t->posiciones[0][1] == t->posiciones[1][1] && t->posiciones[0][1] == t->posiciones[2][1]) final = true;
    return final;
}

bool AI::duesFitxes(Tablero* t, int valor)
{
    bool final = false;
    if(t->posiciones[0][0] == valor && t->posiciones[0][0] == t->posiciones[1][1]) final = true;
    else if (t->posiciones[2][0] == valor && t->posiciones[2][0] == t->posiciones[1][1]) final = true;
    else if (t->posiciones[0][0] == valor && t->posiciones[0][0] == t->posiciones[1][0]) final = true;
    else if (t->posiciones[0][0] == valor && t->posiciones[0][0] == t->posiciones[0][1]) final = true;
    else if (t->posiciones[2][0] == valor && t->posiciones[2][0] == t->posiciones[2][1]) final = true;
    else if (t->posiciones[2][2] == valor && t->posiciones[2][2] == t->posiciones[1][2]) final = true;
    else if (t->posiciones[1][0] == valor && t->posiciones[1][0] == t->posiciones[1][1]) final = true;
    else if (t->posiciones[0][1] == valor && t->posiciones[0][1] == t->posiciones[1][1]) final = true;
    else if (t->posiciones[0][1] == valor && t->posiciones[0][1] == t->posiciones[1][1]) final = true;
    return final;
}

bool AI::bloquejat(Tablero* t, int valor)
{
    int contrari = 1;
    bool final = false;
    if (valor == 2) contrari = 1;
    // Cas 1
    if(t->posiciones[0][0] == valor && t->posiciones[1][1] == contrari && t->posiciones[2][2] == contrari) final = true;
    else if(t->posiciones[0][0] == contrari && t->posiciones[1][1] == valor && t->posiciones[2][2] == contrari) final = true;
    else if(t->posiciones[0][0] == contrari && t->posiciones[1][1] == contrari && t->posiciones[2][2] == valor) final = true;
    // Cas 2
    else if (t->posiciones[2][0] == valor && t->posiciones[1][1] == contrari && t->posiciones[0][2] == contrari) final = true;
    else if (t->posiciones[2][0] == contrari && t->posiciones[1][1] == valor && t->posiciones[0][2] == contrari) final = true;
    else if (t->posiciones[2][0] == contrari && t->posiciones[1][1] == contrari && t->posiciones[0][2] == valor) final = true;
    // Cas 3
    else if (t->posiciones[0][0] == valor && t->posiciones[1][0] == contrari && t->posiciones[2][0] == contrari) final = true;
    else if (t->posiciones[0][0] == contrari && t->posiciones[1][0] == valor && t->posiciones[2][0] == contrari) final = true;
    else if (t->posiciones[0][0] == contrari && t->posiciones[1][0] == contrari && t->posiciones[2][0] == valor) final = true;
    // Cas 4
    else if (t->posiciones[0][0] == valor && t->posiciones[0][1] == contrari && t->posiciones[0][2] == contrari) final = true;
    else if (t->posiciones[0][0] == contrari && t->posiciones[0][1] == valor && t->posiciones[0][2] == contrari) final = true;
    else if (t->posiciones[0][0] == contrari && t->posiciones[0][1] == contrari && t->posiciones[0][2] == valor) final = true;
    // Cas 5
    else if (t->posiciones[2][0] == valor && t->posiciones[2][1] == contrari && t->posiciones[2][2] == contrari) final = true;
    else if (t->posiciones[2][0] == contrari && t->posiciones[2][1] == valor && t->posiciones[2][2] == contrari) final = true;
    else if (t->posiciones[2][0] == contrari && t->posiciones[2][1] == contrari && t->posiciones[2][2] == valor) final = true;
    // Cas 6
    else if (t->posiciones[2][2] == valor && t->posiciones[1][2] == contrari && t->posiciones[0][2] == contrari) final = true;
    else if (t->posiciones[2][2] == contrari && t->posiciones[1][2] == valor && t->posiciones[0][2] == contrari) final = true;
    else if (t->posiciones[2][2] == contrari && t->posiciones[1][2] == contrari && t->posiciones[0][2] == valor) final = true;
    // Cas 7
    else if (t->posiciones[1][0] == valor && t->posiciones[1][1] == contrari && t->posiciones[1][2] == contrari) final = true;
    else if (t->posiciones[1][0] == contrari && t->posiciones[1][1] == valor && t->posiciones[1][2] == contrari) final = true;
    else if (t->posiciones[1][0] == contrari && t->posiciones[1][1] == contrari && t->posiciones[1][2] == valor) final = true;
    // Cas 8
    else if (t->posiciones[0][1] == valor && t->posiciones[1][1] == contrari && t->posiciones[2][1] == contrari) final = true;
    else if (t->posiciones[0][1] == contrari && t->posiciones[1][1] == valor && t->posiciones[2][1] == contrari) final = true;
    else if (t->posiciones[0][1] == contrari && t->posiciones[1][1] == contrari && t->posiciones[2][1] == valor) final = true;

    else final = false;

    return final;
}
