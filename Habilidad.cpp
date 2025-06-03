#pragma once
#include <ctime>
#include <stdlib.h>
#include "Habilidad.h"

CHabilidad::CHabilidad() {
	srand(time(NULL));
	ubicado = false;
	i = rand() % (FILAS-2) + 1;
	j = rand() % (COLUMNAS-2) + 1;
	indiceX = 0;
	indiceY = 0;
	tipoHabilidad = (rand() % 5) + 1;
}

CHabilidad:: ~CHabilidad() {};

int CHabilidad::getHabilidad() {
	return tipoHabilidad;
}

void CHabilidad::dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha) {
	Rectangle rectangulo = Rectangle(indiceX * ANCHOIMAGEN, indiceY * ALTOIMAGEN, ANCHOIMAGEN, ALTOIMAGEN);

	while (!ubicado) {
		if (cancha[i][j]->getTipo() == EElementos::rrompible) {
			ubicado = true;
		} else {
			if (j < COLUMNAS) {
				i++;
				if (i == (FILAS-1)) {
					i = 0;
					j++;
				}
			}
		}
	}

	Rectangle zoom = Rectangle(j * ANCHOIMAGEN, i * ALTOIMAGEN, ANCHOIMAGEN, ALTOIMAGEN);
	g->DrawImage(bmpHabilidad, zoom, rectangulo, GraphicsUnit::Pixel);
}

void CHabilidad::animar() {
	switch (tipoHabilidad) {
	case 1: // Bomba
		indiceX = EHabilidades::bomba;
		if ((indiceY >= 0) && (indiceY < 1)) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
		break;
	case 2: // Fuego
		indiceX = EHabilidades::fuego;
		if ((indiceY >= 0) && (indiceY < 1)) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
		break;
	case 3: // Quitar vida
		indiceX = EHabilidades::quitaVida;
		if ((indiceY >= 0) && (indiceY < 1)) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
		break;
	case 4: // Mayor velocidad
		indiceX = EHabilidades::velocidad;
		if ((indiceY >= 0) && (indiceY < 1)) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
		break;
	case 5: // Aumentar vida
		indiceX = EHabilidades::vida;
		if ((indiceY >= 0) && (indiceY < 1)) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
		break;	
	}
}