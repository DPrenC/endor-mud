/*
DESCRIPCION    : anteojos
FICHERO        :
CREACION       : 1-99 Alura
U.MODIFICACION :
*/


#include "path.h"
#include <properties.h>
inherit ARMOUR;

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
  liv->SetAttribute("erudito", 0);
  
  ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
  liv->SetAttribute("erudito", 0);
  
  ::NotifyUnequip(liv, armour, flags);
}

/* destruct(){
TP->SetAttribute("erudito",0);
::destruct();
}
*/

create() {
  if (clonep()) return;
  ::create();

	SetShort("unos anteojos de vision verdadera.\n");
	SetLong("Parecen unos anteojos normales, de esos que no sirven para nada.\n");
	AddId("anteojos");       //identificativo, esto es como se llama
	SetWeight(300);     //peso en gramos
	SetValue(5000);      // valor en monedas de cobre
}
