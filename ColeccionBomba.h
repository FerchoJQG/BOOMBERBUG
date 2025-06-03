#pragma once

#include <vector>
#include "Bomba.h";

#define TOTALBOMBAS 3

using namespace std;

class CColeccionBomba {
    vector<CBomba*> bombas;
    int totalBombas;
    int rangoExplosion; // NUEVO

public:
    CColeccionBomba();

    void crearBomba(int x, int y);
    void dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int jugadorX, int jugadorY, const CanchaArray& cancha);
    vector<CBomba*> getBombas();

    // NUEVOS MÉTODOS
    void aumentarRangoExplosion();
    int getRangoExplosion();
};