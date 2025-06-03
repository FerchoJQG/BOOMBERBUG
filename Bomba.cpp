#pragma once
#include "Bomba.h"

CBomba::CBomba(int x, int y) {
	this->x = (x / ANCHOIMAGEN) * ANCHOIMAGEN + (ANCHOIMAGEN / 2) - ((ANCHOIMAGEN * 0.7) / 2);
	this->y = (y / ALTOIMAGEN) * ALTOIMAGEN + (ALTOIMAGEN / 2) - ((ALTOIMAGEN * 0.7) / 2);
	estado = EBomba::puesto;
	tiempoExplosion = 0;
	indiceX = 0;

	// para explosion
	indiceEX = 0;
	indiceEY = 0;	
}

EBomba CBomba::getEstado() {
	return estado;
}

int CBomba::getX() {
	return x;
}
int CBomba::getY() {
	return y;
}

void CBomba::animarExplosion() {
	if (indiceEX >= 0 && indiceEX < 3) {
		indiceEX++;
	}
	else {
		estado = EBomba::explotado;
	}
}

void CBomba::getPosicionCancha(int x, int y, int& i, int& j) {
	i = x / ANCHOIMAGEN;
	j = y / ALTOIMAGEN;
}

bool CBomba::verificarLugar(int i, int j, const CanchaArray& cancha) {	
	if ((cancha[j][i]->getTipo() == EElementos::piso) || (cancha[j][i]->getTipo() == EElementos::libre)) {
		return true;
	}

	return false;
}


void CBomba::dibujar(Graphics^ g, Bitmap^ bmpBomba, int jugadorX, int jugadorY, const CanchaArray& cancha) {
	int i, j;
	getPosicionCancha(jugadorX, jugadorY, i, j);

	if (verificarLugar(i, j, cancha)) {
		Rectangle rectangulo = Rectangle(indiceX * ANCHOBOMBA, 0, ANCHOBOMBA, ALTOBOMBA);
		Rectangle zoom = Rectangle(x, y, ANCHOIMAGEN * 0.7, ALTOIMAGEN * 0.7);
		g->DrawImage(bmpBomba, zoom, rectangulo, GraphicsUnit::Pixel);
		if (tiempoExplosion == TIEMPOEXPLOSION) {
			estado = EBomba::explosion;
		}
	}
}

void CBomba::animar() {
	if ((indiceX >= 0) && (indiceX < 2)) {
		indiceX++;
	}
	else {
		tiempoExplosion++;
		indiceX = 0;
	}
}

void CBomba::dibujarExplosion(Graphics^ g, Bitmap^ bmpExplosion, const CanchaArray& cancha) {
	int c, f;
	getPosicionCancha(x, y, c, f);

	Rectangle centro = Rectangle(x-10, y - 10, ANCHOIMAGEN, ALTOIMAGEN);
	Rectangle posicionCentro = Rectangle(indiceEX * ANCHOEXPLOSION, indiceEY * ALTOEXPLOSION, ANCHOEXPLOSION, ALTOEXPLOSION);
	g->DrawImage(bmpExplosion, centro, posicionCentro, GraphicsUnit::Pixel);

	Rectangle izquierdaDerecha = Rectangle(indiceEX * ANCHOEXPLOSION, indiceEY + 2 * ALTOEXPLOSION, ANCHOEXPLOSION, ALTOEXPLOSION);
	Rectangle arribaAbajo = Rectangle(indiceEX * ANCHOEXPLOSION, indiceEY + 6 * ALTOEXPLOSION, ANCHOEXPLOSION, ALTOEXPLOSION);
	
	if (cancha[f][c - 1]->getTipo() != EElementos::paredes) {
		Rectangle izquierda = Rectangle((x - ANCHOIMAGEN - 10), (y - 10), ANCHOIMAGEN, ALTOIMAGEN);
		g->DrawImage(bmpExplosion, izquierda, izquierdaDerecha, GraphicsUnit::Pixel);
		if (cancha[f][c - 1]->getTipo() == EElementos::rrompible) {
			cancha[f][c - 1]->setTipo(EElementos::libre);
		}
	}
	if (cancha[f][c + 1]->getTipo() != EElementos::paredes) {
		Rectangle derecha = Rectangle((x + ANCHOIMAGEN - 10), (y - 10), ANCHOIMAGEN, ALTOIMAGEN);
		g->DrawImage(bmpExplosion, derecha, izquierdaDerecha, GraphicsUnit::Pixel);
		if (cancha[f][c + 1]->getTipo() == EElementos::rrompible) {
			cancha[f][c + 1]->setTipo(EElementos::libre);
		}
	}	
	if (cancha[f - 1][c]->getTipo() != EElementos::paredes) {
		Rectangle arriba = Rectangle((x - 10), (y - ALTOIMAGEN - 10), ANCHOIMAGEN, ALTOIMAGEN);
		g->DrawImage(bmpExplosion, arriba, arribaAbajo, GraphicsUnit::Pixel);
		if (cancha[f - 1][c]->getTipo() == EElementos::rrompible) {
			cancha[f - 1][c]->setTipo(EElementos::libre);
		}
	}
	if (cancha[f + 1][c]->getTipo() != EElementos::paredes) {
		Rectangle abajo = Rectangle((x - 10), (y + ALTOIMAGEN - 10), ANCHOIMAGEN, ALTOIMAGEN);
		g->DrawImage(bmpExplosion, abajo, arribaAbajo, GraphicsUnit::Pixel);
		if (cancha[f + 1][c]->getTipo() == EElementos::rrompible) {
			cancha[f + 1][c]->setTipo(EElementos::libre);
		}
	}
}

// bomba.cpp
#include "bomba.h"

Bomba::Bomba() {
	rangoExplosion = 1;
}

void Bomba::aumentarRangoExplosion() {
	rangoExplosion++;
}

int Bomba::getRangoExplosion() const {
	return rangoExplosion;
}

void Bomba::dibujarExplosion(int x, int y) {
	// Lógica para dibujar la explosión en cruz según rangoExplosion
	for (int i = -rangoExplosion; i <= rangoExplosion; ++i) {
		// Dibuja en (x+i, y) y (x, y+i)
	}
}
