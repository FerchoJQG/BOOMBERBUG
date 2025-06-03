#pragma once
#include <ctime>
#include <stdlib.h>
#include "Enemigo.h"

std::vector<std::pair<int, int>> posEnemigos;
std::vector<std::pair<int, int>> posLibres;

CEnemigo::CEnemigo() {
	srand(time(NULL));
	x = 0;
	y = 0;
	dx = VELOCIDADENEMIGO;
	dy = VELOCIDADENEMIGO;
	indiceX = 0;
	indiceY = 18;
	ubicado = false;
	tipoEnemigo = (rand() % 6);
	estado = EEstadoEnemigo::Vivo;
}

CEnemigo::~CEnemigo() {}

void CEnemigo::setX(int x) {
	this->x = x;
}
void CEnemigo::setY(int y) {
	this->y = y;
}

int CEnemigo::getTipoEnemigo() {
	return tipoEnemigo;
}

void CEnemigo::setIndiceY(int y) {
	indiceY = y;
}

bool CEnemigo::buscarLugar(const CanchaArray& cancha, int &i, int &j) {	
	for (int i = 1; i < FILAS; i++) {
		for (int j = 1; j < COLUMNAS; j++) {
			if (cancha[i][j]->getTipo() == EElementos::libre && std::find(posEnemigos.begin(), posEnemigos.end(), std::make_pair(i, j)) == posEnemigos.end()) {
				posLibres.push_back({ i, j });
			}
		}
	}

	if (posLibres.size() > 0) {
		int indice = rand() % posLibres.size();
		i = posLibres[indice].first;
		j = posLibres[indice].second;
		posEnemigos.push_back({ i, j });
		return true;
	}

	return false;
}

void CEnemigo::dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha) {	
	/*if (!ubicado) {
		x = x * ANCHOIMAGEN;
		y = y * ALTOIMAGEN;
	}*/
	int px, py;
	bool existe = buscarLugar(cancha, px, py);
	if (existe && !ubicado) {
		x = py * ANCHOIMAGEN;
		y = px * ALTOIMAGEN;
	}

	ubicado = true;
	Rectangle rectangulo = Rectangle(indiceX * ANCHOIMAGEN, indiceY * ALTOIMAGEN, ANCHOIMAGEN, ALTOIMAGEN);
	Rectangle zoom = Rectangle(x, y, ANCHOIMAGEN * 0.9, ALTOIMAGEN * 0.9);
	g->DrawImage(bmpEnemigo, zoom, rectangulo, GraphicsUnit::Pixel);

	x += dx;
	if ((cancha[y / ALTOIMAGEN][(x + ANCHOIMAGEN) / ANCHOIMAGEN]->getTipo() == EElementos::rrompible) ||
		(cancha[y / ALTOIMAGEN][(x + ANCHOIMAGEN) / ANCHOIMAGEN]->getTipo() == EElementos::paredes) ||
		(cancha[y / ALTOIMAGEN][(x - 5) / ANCHOIMAGEN]->getTipo() == EElementos::rrompible) ||
		(cancha[y / ALTOIMAGEN][(x - 5) / ANCHOIMAGEN]->getTipo() == EElementos::paredes)) {
		dx *= -1;
	}
};

void CEnemigo::animar() {
	if (indiceX >= 0 && indiceX < 5) {
		indiceX++;
	}
	if (indiceX == 5) {
		while (indiceX != 0) {
			indiceX--;
		}
	}
}
