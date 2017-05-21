/*
Archivo: broche_darwen.c
Autor: [T] Tagoras
Fecha: 18/03/2009
Descripción: Broche para los retos de Darwen.
*/

#include "path.h"
#include <colours.h>
#include <properties.h>

inherit BASE_ITEM_DARWEN;

public void create()
{
	::create();
	SetShort("el broche de Darwen");
	SetLong("Es un broche de "+TC_BOLD+TC_YELLOW+"oro"+TC_NORMAL+" con una pequeña talla de "+TC_BLUE+"lapislázuli"+TC_NORMAL+" en su parte frontal.\n");
	AddSubDetail(({"talla"}), "Es una talla de la luna que aprovecha espléndidamente los diferentes matices "+TC_BLUE+"azules"+TC_NORMAL+" del "+TC_BLUE+"lapislázuli"+TC_NORMAL+" con que está hecha.\n");
	SetMaterial(M_ORO);
	SetValue(10000);
	SetIds(({"broche", "broche_darwen"}));
}
