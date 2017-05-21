/*
Perfume de agua de rosas
Autor: [T] Tagoras
Versión: 1.00
Fecha: 20/03/2009
*/

#include "path.h"

inherit BASE_PERFUME;

public void create()
{
	::create();

	SetValue(120);					// El frasco vale 120 cobres
	SetContent(65);					// No está lleno del todo
	SetMaxContent(75);				// La capacidad del frasco es de 75 cc
	SetBaseWeight(220);				// El frasco vacio pesa 220 gr
	SetContentWeight(1.1);			// La densidad del perfume es de 1.1 gr/cc
	SetContentValue(80);			// Cada cc de perfume vale 80 cobres
	SetPerfume("agua de rosas");	// El perfume es agua de rosas
}
