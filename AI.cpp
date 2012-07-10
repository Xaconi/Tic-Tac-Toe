#include "AI.h"
#include <fstream>
#include <iostream>
using namespace std;
AI::AI(int d)
{
    dificultat = d;
}

int* AI::minimax(Tablero* t, int nivell)
{
    int sortida, i, j;
    int* resultat = new int[3];
    int* resultatMillor = new int[3];
    if(nivell <= dificultat)
    {
        // Procés Minimax...
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if(t->llocLliure(i,j))
                {
                    if (tipusNivell(nivell) == "MAX") t->posarFitxa(i, j, 2);
                    else if (tipusNivell(nivell) == "MIN")
                    {
                        t->posarFitxa(i, j, 1);
                        resultatMillor[0] = 100;
                    }
                    resultat = minimax(t, nivell + 1);
                    if(tipusNivell(nivell) == "MIN")
                    {
                        if(resultat[0] < resultatMillor[0])
                        {
                            resultatMillor[0] = resultat[0];
                            resultatMillor[1] = i;
                            resultatMillor[2] = j;
                            cout << "Resultats MIN: " << resultatMillor[0] << "," << resultatMillor[1] << "," << resultatMillor[2] << endl;
                        }
                    }
                    else if(tipusNivell(nivell) == "MAX")
                    {
                        if(resultat[0] > resultatMillor[0])
                        {
                            resultatMillor[0] = resultat[0];
                            resultatMillor[1] = i;
                            resultatMillor[2] = j;
                            cout << "Resultats MAX: " << resultatMillor[0] << "," << resultatMillor[1] << "," << resultatMillor[2] << endl;
                        }
                    }
                    if (tipusNivell(nivell) == "MAX") t->treureFitxa(i, j, 2);
                    else if (tipusNivell(nivell) == "MIN") t->treureFitxa(i, j, 1);
                }
            }
        }
    }
    else
    {
        // Valorem la jugada actual
        resultatMillor[0] = valorarJugada(t);
    }
    return resultatMillor;
}

char* AI::tipusNivell(int nivell)
{
    char* sortida;
    if(nivell % 2 != 0) sortida = "MAX";
    else sortida = "MIN";
    return sortida;
}

int AI::valorarJugada(Tablero* t)
{
    int valor;
    if(tresEnRatlla(t,2)) valor = 10;
    else if(bloquejat(t,2)) valor = 8;
    else if(duesFitxes(t,2)) valor = 6;
    else if(duesFitxes(t,1)) valor = 4;
    else if(tresEnRatlla(t,1)) valor = 1;
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
    int contrari;
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

    return final;
}
