
#pragma once
#include "Cancha.h"
#include "Jugador.h"
#include "ColeccionBomba.h"
#include "ColeccionHabilidad.h"
#include "ColeccionEnemigo.h"

class CControladora {
private:
	CCancha* cancha;
	CJugador* jugador;
	CColeccionBomba* bombas;
	CColeccionHabilidad* habilidades;
	CColeccionEnemigo* enemigos;
	int nivel;

public:
	CControladora();
	~CControladora() {};

	void setNivel(int nivel);
	int getNivel();
	void inicializar();
	void Dibujar();
	void CControladora::dibujarCancha(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible, Bitmap^ bmpHabilidad);
	void dibujarJugador(Graphics^ g, Bitmap^ bmpJugador);
	void adicionarBomba();
	void verificarColisionHabilidad();
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpEnemigo);
	CJugador* getJugador();
	void crearHabilidades();
	void crearEnemigos();
	CColeccionHabilidad* getColeccionHabilidades();
	CColeccionEnemigo* getColeccionEnemigos();

	void usarHabilidad(int tipo);


	void quitarVidaEnemigo() {
		for (int i = 0; i < enemigos->getEnemigos().size(); i++) {
			return

		}
	}

	void quitarVidaExplosion() {
		for (int i = 0; i < bombas->getBombas().size(); i++) {

		}
	}
};


#pragma once

#include "Cancha.h"
#include "Jugador.h"
#include "ColeccionBomba.h"
#include "ColeccionHabilidad.h"
#include "ColeccionEnemigo.h"

class CControladora {
private:
	CCancha* cancha;
	CJugador* jugador;
	CColeccionBomba* bombas;
	CColeccionHabilidad* habilidades;
	CColeccionEnemigo* enemigos;
	int nivel;

public:
	CControladora();
	~CControladora() {};

	void setNivel(int nivel);
	int getNivel();
	void inicializar();
	void Dibujar();
	void dibujarCancha(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible, Bitmap^ bmpHabilidad);
	void dibujarJugador(Graphics^ g, Bitmap^ bmpJugador);
	void adicionarBomba();
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpEnemigo);
	CJugador* getJugador();
	void crearHabilidades();
	void crearEnemigos();
	CColeccionHabilidad* getColeccionHabilidades();
	CColeccionEnemigo* getColeccionEnemigos();
	void usarHabilidad(int tipo);
};void CControladora::quitarVidaEnemigo() {
    Rectangle jugadorRect = Rectangle(jugador->getX(), jugador->getY(), ANCHOJUGADOR * FACTORZOOM, ALTOJUGADOR * FACTORZOOM);
    
    for (int i = 0; i < enemigos->getEnemigos().size(); i++) {
        CEnemigo* enemigo = enemigos->getEnemigos().at(i);
        Rectangle enemigoRect = Rectangle(enemigo->x, enemigo->y, ANCHOIMAGEN, ALTOIMAGEN); // Ajusta tamaño si es necesario

        if (jugadorRect.IntersectsWith(enemigoRect)) {
            jugador->disminuirVida();
            if (jugador->getVidas() <= 0) {
                MessageBox::Show("¡Has perdido todas tus vidas! Fin del juego.");
                Application::Exit();
            }
        }
    }
}

void CControladora::quitarVidaExplosion() {
    Rectangle jugadorRect = Rectangle(jugador->getX(), jugador->getY(), ANCHOJUGADOR * FACTORZOOM, ALTOJUGADOR * FACTORZOOM);

    for (int i = 0; i < bombas->getBombas().size(); i++) {
        CBomba* bomba = bombas->getBombas().at(i);

        if (bomba->getEstado() == EBomba::explosion) {
            int bx = bomba->getX();
            int by = bomba->getY();

            // Centro
            Rectangle centro = Rectangle(bx - 10, by - 10, ANCHOIMAGEN, ALTOIMAGEN);
            if (jugadorRect.IntersectsWith(centro)) {
                jugador->disminuirVida();
            }

            // Cruces: izquierda, derecha, arriba, abajo
            Rectangle izquierda = Rectangle((bx - ANCHOIMAGEN - 10), (by - 10), ANCHOIMAGEN, ALTOIMAGEN);
            Rectangle derecha   = Rectangle((bx + ANCHOIMAGEN - 10), (by - 10), ANCHOIMAGEN, ALTOIMAGEN);
            Rectangle arriba    = Rectangle((bx - 10), (by - ALTOIMAGEN - 10), ANCHOIMAGEN, ALTOIMAGEN);
            Rectangle abajo     = Rectangle((bx - 10), (by + ALTOIMAGEN - 10), ANCHOIMAGEN, ALTOIMAGEN);

            if (jugadorRect.IntersectsWith(izquierda) ||
                jugadorRect.IntersectsWith(derecha) ||
                jugadorRect.IntersectsWith(arriba) ||
                jugadorRect.IntersectsWith(abajo)) {
                jugador->disminuirVida();
            }

            if (jugador->getVidas() <= 0) {
                MessageBox::Show("¡Has muerto por la explosión!");
                Application::Exit();
            }
        }
    }
}