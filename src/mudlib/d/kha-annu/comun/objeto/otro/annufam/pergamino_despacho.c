/****************************************************************************
Fichero: pergamino_despacho.c
Autor: Tagoras
Fecha: 06/02/2009
Descripción: Pergamino del despacho de Altriv
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <messages.h>
inherit THING;

create()
{
    ::create();
    AddId("pergamino");
    SetShort("un pergamino");
    SetLong("Es un pergamino firmado por Belthain y que parece muy importante. Si quieres puedes intentar leerlo.\n");
    SetReadMsg("En el pergamino puedes leer:\n"
		"Yo, Belthain, señor de los enanos y dueño del dominio de Kha-annu, fundo la ciudad cuartel de Annufam y dejo al frente de la misma y con potestad absoluta sobre su territorio y sus moradores, a Altriv, hijo de Rifhur, nieto de Nefhur y comandante en jefe de mis ejércitos.\n");
	SetNoGet(1);
}
