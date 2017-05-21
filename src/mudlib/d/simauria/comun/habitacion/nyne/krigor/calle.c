/* **********************************************************************
   *  DESCRIPCION  : Casas de Krigor
   *  FICHERO      : calles.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit SIM_ROOM;

create()
{
	::create();

	SetIntShort("las callejuelas de Krigor");
  	SetIntLong("Est�s en unas callejuelas del pueblo de Krigor. A los lados "
  	  "tienes diferentes construciones.El suelo esta hecho de adoquines.\n");

	SetIntSmell("Huele a vaca\n");
	SetIntNoise("oyes algun mugido\n");

  	//aqui se a�adiran bastantes mas detalles
  	AddDetail(({"adoquin","adoquines","adoqu�n"}), "Pues eso adoquines.\n");
  	AddItem(PNJKRIG("krigoriano"),REFRESH_DESTRUCT,random(2)+1);
  	SetLocate("Krigor");
}