/*#include "ColeccionBomba.h"

CColeccionBomba::CColeccionBomba() {
	totalBombas = 1;
}

void CColeccionBomba::crearBomba(int x, int y) {
	if (bombas.size() < totalBombas) {
		CBomba* nuevaBomba = new CBomba(x, y);
		bombas.push_back(nuevaBomba);
	}
}

void CColeccionBomba::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int jugadorX, int jugadorY, const CanchaArray& cancha) {
	for (int i = 0; i < bombas.size(); i++) {
		switch (bombas.at(i)->getEstado()) {
		case EBomba::puesto:
			bombas.at(i)->dibujar(g, bmpBomba, jugadorX, jugadorY, cancha);
			bombas.at(i)->animar();
			break;
		case EBomba::explosion:
			bombas.at(i)->dibujarExplosion(g, bmpExplosion, cancha);
			bombas.at(i)->animarExplosion();
			break;
		case EBomba::explotado:
			bombas.erase(bombas.begin() + i);
			break;
		}
	}
}

vector<CBomba*> CColeccionBomba::getBombas() {
	return bombas;
}*/

#include "ColeccionBomba.h"

CColeccionBomba::CColeccionBomba() {
    totalBombas = 1;
    rangoExplosion = 1; // INICIAL
}

void CColeccionBomba::crearBomba(int x, int y) {
    if (bombas.size() < totalBombas) {
        CBomba* nuevaBomba = new CBomba(x, y);
        bombas.push_back(nuevaBomba);
    }
}

void CColeccionBomba::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int jugadorX, int jugadorY, const CanchaArray& cancha) {
    for (int i = 0; i < bombas.size(); i++) {
        switch (bombas.at(i)->getEstado()) {
        case EBomba::puesto:
            bombas.at(i)->dibujar(g, bmpBomba, jugadorX, jugadorY, cancha);
            bombas.at(i)->animar();
            break;
        case EBomba::explosion:
            bombas.at(i)->dibujarExplosion(g, bmpExplosion, cancha);
            bombas.at(i)->animarExplosion();
            break;
        case EBomba::explotado:
            bombas.erase(bombas.begin() + i);
            break;
        }
    }
}

vector<CBomba*> CColeccionBomba::getBombas() {
    return bombas;
}

// NUEVOS MÉTODOS
void CColeccionBomba::aumentarRangoExplosion() {
    rangoExplosion++;
}

int CColeccionBomba::getRangoExplosion() {
    return rangoExplosion;
}