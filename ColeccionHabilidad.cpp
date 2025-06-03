#include "ColeccionHabilidad.h"
#include <thread>
#include <chrono>

vector<CHabilidad*> CColeccionHabilidad::getHabilidades() {
	return habilidades;
}

void CColeccionHabilidad::crearHabilidad() {
	std::this_thread::sleep_for(std::chrono::seconds(1));	
	CHabilidad* habilidad;
	bool diferente = false;	
	while (!diferente) {
		habilidad = new CHabilidad();
		bool existe = false;
		for (int i = 0; i < habilidades.size(); i++) {
			if (habilidad->getHabilidad() == habilidades.at(i)->getHabilidad()) {
				existe = true;
				break;
			}
		}
		if (!existe) {
			diferente = true;
		}
	}
	
	habilidades.push_back(habilidad);
}

void CColeccionHabilidad::dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha) {
	for (int i = 0; i < habilidades.size(); i++) {
		habilidades.at(i)->dibujar(g, bmpHabilidad, cancha);
		habilidades.at(i)->animar();
	}
}
