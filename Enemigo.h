#pragma once
#include <thread>
#include <chrono>
#include "Items.h"
#include "Cancha.h"
#include<vector>

#define VELOCIDADENEMIGO 5

using namespace System::Drawing;

//std::vector<std::pair<int, int>> posEnemigos;
//std::vector<std::pair<int, int>> posLibres;

enum EEstadoEnemigo {
	Vivo = 0,
	Eliminado
};

class CEnemigo {
	int x;
	int y;
	int indiceX;
	int indiceY;
	int dx;
	int dy;
	bool ubicado;
	int tipoEnemigo;
	EEstadoEnemigo estado;
public:
	CEnemigo();
	~CEnemigo();

	int getTipoEnemigo();
	void setX(int x);
	void setY(int y);
	void setIndiceY(int y);
	bool buscarLugar(const CanchaArray& cancha, int &i, int &j);
	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha);
	void animar();
};
