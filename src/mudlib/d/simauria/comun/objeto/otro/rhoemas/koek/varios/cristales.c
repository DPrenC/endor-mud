/***************************************************************************************
 ARCHIVO:	cristales.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Unos cristales rotos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("unos cristales");
 SetLong("Esto fue un espejo en su día. Ahora no es mas que una maraña de cristales.\n");
 SetIds(({"cristales"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_PLURAL);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetDieMsg("#jug# ha muerto con la cara llena de cristales clavados debido a una gran estupidez.");
 SetWeight(10);
 SetValue(0);
 SetMaterial(M_CRISTAL);
}

init(){
  ::init();
  TP->Die();
  if (!living(environment(TO)))
  {
  	TO->remove();
  }
}
