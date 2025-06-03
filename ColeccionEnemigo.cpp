#pragma once
#include "ColeccionEnemigo.h"

vector<CEnemigo*> CColeccionEnemigo::getEnemigos() {
	return enemigos;
}

//void CColeccionEnemigo::buscarEspacioLibre(const CanchaArray& cancha) {
//	for (int i = 1; i < FILAS; i++) {
//		for (int j = 1; j < COLUMNAS; j++) {
//			if (cancha[i][j]->getTipo() == EElementos::libre) {
//				posLibres.push_back({ i, j });
//				//(cancha[i][j - 1]->getTipo() == EElementos::libre || (cancha[i][j]->getTipo() == EElementos::piso))) &&				
//				//posicionLibre.push_back({ i, j - 1 });
//			}
//		}
//	}
//}

void CColeccionEnemigo::crearEnemigo() {
	std::this_thread::sleep_for(std::chrono::seconds(1));

	/*int indice = rand() % posLibres.size();
	int x = posLibres[indice].first;
	int y = posLibres[indice].second;
	posEnemigos.push_back({ x, y });
	posLibres.erase(posLibres.begin() + indice);*/

	int spriteEnemigos[] = { 0, 5, 8, 12, 15, 18 };
	CEnemigo* enemigo;	
	bool diferente = false;
	while (!diferente) {
		enemigo = new CEnemigo();
		bool existe = false;
		for (int i = 0; i < enemigos.size(); i++) {
			if (enemigo->getTipoEnemigo() == enemigos.at(i)->getTipoEnemigo()) {
				existe = true;
				break;
			}
		}
		if (!existe) {
			diferente = true;
		}
	}

	/*enemigo->setX(x);
	enemigo->setY(y);*/
	enemigo->setIndiceY(spriteEnemigos[enemigo->getTipoEnemigo()]);
	enemigos.push_back(enemigo);
}

void CColeccionEnemigo::dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha) {
	for (int i = 0; i < enemigos.size(); i++) {
		enemigos.at(i)->dibujar(g, bmpEnemigo, cancha);
		enemigos.at(i)->animar();
	}
}