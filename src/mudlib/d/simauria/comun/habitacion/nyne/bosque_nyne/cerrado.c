/* ***********************************************************************
   *  DESCRIPCION :	Habitacion para darle salida a la aduana del del *
   *			SO del bosque de krigor  			 *
   *  FICHERO	  : 	cerrado.c					 *
   *  CREACION	  :	Chaos [ChS]					 *
   *  MODIFICACION:	30-06-03 [ChS]  Creacion 			 *
   ***********************************************************************
*/
#include "path.h"
inherit SIM_ROOM;

create()
{
	::create();
	SetIntShort("un camino cortado");

	SetIntLong(W("Te encuentras en el principio de un camino, que sale del bosque "
		"pero esta cerrado. Hay una valla que cruza de lado a lado y te cierra"
		" el camino. Solo puedes retroceder por donde has venido.\n"));

	
// Ahora se le daran detalles de olor y oido

	SetNoise(W(	"Oyes el rumor del viento sobre las copas"
			" de los árboles.\n"));
	SetSmell(	"Huele a humedad.\n");

// Donde localizamos esta zona

	SetLocate("Bosque de Nyne");

// se encuentra al aire libre, es un prado

	SetIndoors(0);

// Salidas de la habitación

	AddExit("norte",BOSQUE_NYN("aduanaso"));
}