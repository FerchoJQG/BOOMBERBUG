#pragma once
//#include <vector>
#include <thread>
#include <chrono>
#include "Enemigo.h"

using namespace std;

class CColeccionEnemigo {
	vector<CEnemigo*> enemigos;
	//std::vector<std::pair<int, int>> posEnemigos;
	//std::vector<std::pair<int, int>> posLibres;

public:	
	vector<CEnemigo*> getEnemigos();
	//void buscarEspacioLibre(const CanchaArray& cancha);
	void crearEnemigo();	
	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha);
};
