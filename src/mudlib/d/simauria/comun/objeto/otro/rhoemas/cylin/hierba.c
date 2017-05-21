/***************************************************************************************
 ARCHIVO:	hierba.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Hierba del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <herbs.h>

inherit HERB;

create () {
  ::create();

  SetShort("una hierba extra�a");
  SetLong("Es una extra�a hierba que nunca hab�as visto en ninguna parte. "
  	    "Por el color verde oscuro que tiene debe ser propia del bosque "
  	    "de Cylin. Puede que tenga alg�n tipo de propiedades.\n");
  SetPower(random(100));
  SetIds(({"hierba","hierba extra�a","hierba extranya"}));

  switch(d6())
  {
    case 1:  SetClass(HERB_CLASS_POISONOUS); break;
    case 2:  SetClass(HERB_CLASS_HEALING);   break;
    case 3:  SetClass(HERB_CLASS_MAGIC);     break;
    case 4:  SetClass(HERB_CLASS_TOXIC);     break;
    case 5:  SetClass(HERB_CLASS_FOOD);      break;
    default: SetClass(HERB_CLASS_HEALING);   break;
  }
}

