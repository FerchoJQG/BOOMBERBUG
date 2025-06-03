
#include <iostream>
#include "Jugador.h"

CJugador::CJugador() {};

CJugador::~CJugador() {};

CJugador::CJugador(int x, int y) {
  this->x = x;
  this->y = y;
  dx = 0;
  dy = 0;
  ultimaTecla = EDireccion::Abajo;
  direccion = EDireccion::Ninguna;
  indiceX = 0;
  indiceY = 2;
  for (int i = 0; i < HABILIDADES; i++) {
    habilidades[i] = false;
  }
  vidas = 3;
}

void CJugador::setDx(int dx) {
  this->dx = dx;
}
void CJugador::setDy(int dy) {
  this->dy = dy;
}
int CJugador::getX() {
  return x + 1 * FACTORZOOM;
}
int CJugador::getY() {
  return y + 20 * FACTORZOOM + dy;
}

void CJugador::setVidas(int vidas) {
  this->vidas = vidas;
}
int CJugador::getVidas() {
  return vidas;
}

void CJugador::disminuirVida() {
  vidas--;
}

void CJugador::setDireccion(EDireccion direccion) {
  this->direccion = direccion;
}

void CJugador::controlarLimitesMovimiento(const CanchaArray& cancha) {
  int X = 0, Y = 0;
  for (int i = 0; i < FILAS; i++) {
    X = 0;
    for (int j = 0; j < COLUMNAS; j++) {
      Rectangle intersecta = Rectangle(X, Y, ANCHOIMAGEN, ALTOIMAGEN);
      if ((cancha[i][j]->getTipo() == EElementos::paredes) || (cancha[i][j]->getTipo() == EElementos::rrompible)) {
        if (limiteArribaAbajo.IntersectsWith(intersecta)) { dy = 0; }
        if (limiteDerechaIzquierda.IntersectsWith(intersecta)) { dx = 0; }
      }
      X += ANCHOIMAGEN;
    }
    Y += ALTOIMAGEN;
  }
}

void CJugador::dibujar(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha) {
  limiteDerechaIzquierda = Rectangle(x+2*FACTORZOOM+dx, y+15*FACTORZOOM, (ANCHOJUGADOR-10) * FACTORZOOM, (ALTOJUGADOR - 20) * FACTORZOOM);
  limiteArribaAbajo = Rectangle(x+2*FACTORZOOM, y+15*FACTORZOOM+dy, (ANCHOJUGADOR-10) * FACTORZOOM, (ALTOJUGADOR - 20) * FACTORZOOM);

  g->DrawRectangle(Pens::Red, limiteDerechaIzquierda);
  g->DrawRectangle(Pens::Blue, limiteArribaAbajo);

  controlarLimitesMovimiento(cancha);

	 Rectangle rectangulo = Rectangle(indiceX * ANCHOJUGADOR, indiceY * ALTOJUGADOR, ANCHOJUGADOR, ALTOJUGADOR);
	 Rectangle zoom = Rectangle(x, y, ANCHOJUGADOR * FACTORZOOM, ALTOJUGADOR * FACTORZOOM);
   g->DrawImage(bmpJugador, zoom, rectangulo, GraphicsUnit::Pixel);
	 x += dx;
	 y += dy;
}

void CJugador::mover(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha) {
  switch (direccion) {
    case EDireccion::Arriba:
      indiceY = 0;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 0;
      dy = -10;
      ultimaTecla = EDireccion::Arriba;
      break;
    case EDireccion::Abajo:
      indiceY = 2;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 0;
      dy = 10;
      ultimaTecla = EDireccion::Abajo;
      break;
    case EDireccion::Izquierda:
      indiceY = 3;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = -10;
      dy = 0;
      ultimaTecla = EDireccion::Izquierda;
      break;
    case EDireccion::Derecha:
      indiceY = 1;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 10;
      dy = 0;
      ultimaTecla = EDireccion::Derecha;
      break;
    case EDireccion::Ninguna:
      dx = 0;
      dy = 0;
      switch (ultimaTecla) {
        case EDireccion::Abajo:
          indiceX = 0;
          indiceY = 2;
          break;
        case EDireccion::Arriba:
          indiceX = 0;
          indiceY = 0;
          break;
        case EDireccion::Izquierda:
          indiceX = 1;
          indiceY = 3;
          break;        
        case EDireccion::Derecha:
          indiceX = 0;
          indiceY = 1;
          break;
      }
      break;      
  }

  dibujar(g, bmpJugador, cancha);
}
// jugador.cpp
#include "jugador.h"

Jugador::Jugador() {
    vidas = 3;
    totalBombas = 1;
    velocidad = 10; // Valor por defecto
}

void Jugador::disminuirVida() {
    if (vidas > 0) vidas--;
    // Aquí puedes llamar a reiniciar el nivel o terminar el juego si vidas == 0
}

void Jugador::incrementarVida() {
    vidas++;
}

int Jugador::getVidas() const {
    return vidas;
}

void Jugador::adicionarTotalBombas(int cantidad) {
    totalBombas += cantidad;
}

int Jugador::getTotalBombas() const {
    return totalBombas;
}

void Jugador::aumentarVelocidad(int extra) {
    velocidad += extra;
}

void Jugador::setDefaultVelocidad() {
    velocidad = 10;
}

int Jugador::getVelocidad() const {
    return velocidad;
}

#include "Jugador.h"

CJugador::CJugador() {
    vidas = 3;
    totalBombas = 1;
    velocidad = 10;
}

CJugador::~CJugador() {}

CJugador::CJugador(int x, int y) {
    this->x = x;
    this->y = y;
    dx = 0;
    dy = 0;
    ultimaTecla = EDireccion::Abajo;
    direccion = EDireccion::Ninguna;
    indiceX = 0;
    indiceY = 2;
    for (int i = 0; i < HABILIDADES; i++) {
        habilidades[i] = false;
    }
    vidas = 3;
    totalBombas = 1;
    velocidad = 10;
}

void CJugador::setDx(int dx) {
    this->dx = dx;
}

void CJugador::setDy(int dy) {
    this->dy = dy;
}

int CJugador::getX() {
    return x + 1 * FACTORZOOM;
}

int CJugador::getY() {
    return y + 20 * FACTORZOOM + dy;
}

void CJugador::setVidas(int vidas) {
    this->vidas = vidas;
}

int CJugador::getVidas() {
    return vidas;
}

void CJugador::disminuirVida() {
    vidas--;
}

void CJugador::incrementarVida() {
    vidas++;
}

void CJugador::adicionarTotalBombas(int cantidad) {
    totalBombas += cantidad;
}

int CJugador::getTotalBombas() {
    return totalBombas;
}

void CJugador::aumentarVelocidad(int extra) {
    velocidad += extra;
}

void CJugador::setDefaultVelocidad() {
    velocidad = 10;
}

int CJugador::getVelocidad() {
    return velocidad;
}

void CJugador::setDireccion(EDireccion direccion) {
    this->direccion = direccion;
}

void CJugador::controlarLimitesMovimiento(const CanchaArray& cancha) {
    int X = 0, Y = 0;
    for (int i = 0; i < FILAS; i++) {
        X = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            Rectangle intersecta = Rectangle(X, Y, ANCHOIMAGEN, ALTOIMAGEN);
            if ((cancha[i][j]->getTipo() == EElementos::paredes) || (cancha[i][j]->getTipo() == EElementos::rrompible)) {
                if (limiteArribaAbajo.IntersectsWith(intersecta)) { dy = 0; }
                if (limiteDerechaIzquierda.IntersectsWith(intersecta)) { dx = 0; }
            }
            X += ANCHOIMAGEN;
        }
        Y += ALTOIMAGEN;
    }
}

void CJugador::dibujar(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha) {
    limiteDerechaIzquierda = Rectangle(x + 2 * FACTORZOOM + dx, y + 15 * FACTORZOOM, (ANCHOJUGADOR - 10) * FACTORZOOM, (ALTOJUGADOR - 20) * FACTORZOOM);
    limiteArribaAbajo = Rectangle(x + 2 * FACTORZOOM, y + 15 * FACTORZOOM + dy, (ANCHOJUGADOR - 10) * FACTORZOOM, (ALTOJUGADOR - 20) * FACTORZOOM);

    controlarLimitesMovimiento(cancha);

    Rectangle rectangulo = Rectangle(indiceX * ANCHOJUGADOR, indiceY * ALTOJUGADOR, ANCHOJUGADOR, ALTOJUGADOR);
    Rectangle zoom = Rectangle(x, y, ANCHOJUGADOR * FACTORZOOM, ALTOJUGADOR * FACTORZOOM);
    g->DrawImage(bmpJugador, zoom, rectangulo, GraphicsUnit::Pixel);
    x += dx;
    y += dy;
}

void CJugador::mover(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha) {
    switch (direccion) {
    case EDireccion::Arriba:
        indiceY = 0;
        if ((indiceX >= 0) && (indiceX < 3)) indiceX++; else indiceX = 0;
        dx = 0; dy = -velocidad;
        ultimaTecla = EDireccion::Arriba;
        break;
    case EDireccion::Abajo:
        indiceY = 2;
        if ((indiceX >= 0) && (indiceX < 3)) indiceX++; else indiceX = 0;
        dx = 0; dy = velocidad;
        ultimaTecla = EDireccion::Abajo;
        break;
    case EDireccion::Izquierda:
        indiceY = 3;
        if ((indiceX >= 0) && (indiceX < 3)) indiceX++; else indiceX = 0;
        dx = -velocidad; dy = 0;
        ultimaTecla = EDireccion::Izquierda;
        break;
    case EDireccion::Derecha:
        indiceY = 1;
        if ((indiceX >= 0) && (indiceX < 3)) indiceX++; else indiceX = 0;
        dx = velocidad; dy = 0;
        ultimaTecla = EDireccion::Derecha;
        break;
    case EDireccion::Ninguna:
        dx = 0; dy = 0;
        switch (ultimaTecla) {
        case EDireccion::Abajo: indiceX = 0; indiceY = 2; break;
        case EDireccion::Arriba: indiceX = 0; indiceY = 0; break;
        case EDireccion::Izquierda: indiceX = 1; indiceY = 3; break;
        case EDireccion::Derecha: indiceX = 0; indiceY = 1; break;
        }
        break;
    }

    dibujar(g, bmpJugador, cancha);
}