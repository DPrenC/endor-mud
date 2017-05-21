/***************************************************************************************
 ARCHIVO:	musgo.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Musgo del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <herbs.h>

inherit HERB;

create () {
  ::create();

  SetShort("un poco de musgo");
  SetLong("Es un poco de musgo fresco de color verde intenso. Algunos habitantes "
  	    "de la zona usan las propiedades de ciertos musgos para diferentes "
  	    "pociones, puede que este sirva de algo.\n");
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"musgo"}));
  SetPower(random(100));

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
