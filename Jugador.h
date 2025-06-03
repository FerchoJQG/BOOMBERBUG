#pragma once
#include <iostream>
#include "Cancha.h"

#define HABILIDADES 7
#define ANCHOJUGADOR 70
#define ALTOJUGADOR 128
#define FACTORZOOM 0.4

using namespace System::Drawing;

enum EDireccion {
	Ninguna = 0,
	Abajo,
	Arriba,
	Izquierda,
	Derecha
};

class CJugador {
	int x;		// posicion en el eje X
	int y;		// posicion en el eje y
	int dx;	// desplazamiento en x
	int dy;	// desplazamiento en y
	int indiceX;
	int indiceY;
	int vidas;
	EDireccion ultimaTecla;
	EDireccion direccion;
	Rectangle limiteArribaAbajo;
	Rectangle limiteDerechaIzquierda;
	bool habilidades[HABILIDADES];
public:
	CJugador();
	~CJugador();
	
	CJugador(int x, int y);
	void setDx(int dx);	
	void setDy(int dy);
	int getX();
	int getY();
	void setVidas(int vidas);
	int getVidas();
	void dibujar(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha);
	void mover(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha);
	void setDireccion(EDireccion direccion);
	void controlarLimitesMovimiento(const CanchaArray& cancha);
	void disminuirVida();	
};
// jugador.h
class Jugador {
private:
	int vidas;
	int totalBombas;
	int velocidad; // Nueva propiedad

public:
	Jugador();

	void disminuirVida();
	void incrementarVida();
	int getVidas() const;

	void adicionarTotalBombas(int cantidad);
	int getTotalBombas() const;

	void aumentarVelocidad(int extra);
	void setDefaultVelocidad();
	int getVelocidad() const;
};
