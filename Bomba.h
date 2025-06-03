#pragma once
#include "Items.h"
#include "Cancha.h"

#define ANCHOBOMBA 24
#define ALTOBOMBA 24
#define ANCHOEXPLOSION 20
#define ALTOEXPLOSION 20
#define TIEMPOEXPLOSION 6

using namespace System::Drawing;

enum EBomba {
	puesto,
	explosion,
	explotado
};

class CBomba {
	int x;
	int y;
	int indiceX;
	int tiempoExplosion;

	EBomba estado;

	// explosion
	int indiceEX;
	int indiceEY;	
public:
	CBomba(int x, int y);

	EBomba getEstado();	

	int getX();	
	int getY();
	void animarExplosion();
	void getPosicionCancha(int jugadorX, int jugadorY, int &i, int &j);
	bool verificarLugar(int i, int j, const CanchaArray& cancha);
	void dibujar(Graphics^ g, Bitmap^ bmpBomba, int jugadorX, int jugadorY, const CanchaArray& cancha);		
	void animar();
	void dibujarExplosion(Graphics^ g, Bitmap^ bmpExplosion, const CanchaArray& cancha);	
};

// bomba.h
class Bomba {
private:
	int rangoExplosion;
public:
	Bomba();
	void aumentarRangoExplosion();
	int getRangoExplosion() const;
	void dibujarExplosion(int x, int y); // Asume que tienes coordenadas
};
