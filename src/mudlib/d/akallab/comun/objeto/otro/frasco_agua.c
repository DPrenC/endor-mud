/*******************************************************************************
 ARCHIVO:	frasco_agua.c
 AUTOR:		[k] Karu
 FECHA:		20-02-2002
 COMENTARIOS:	Un frasco lleno de agua del río Darmaii
 MODIFICADO :
               09-07-03 [n] Añadido el manejo de Owners.
*******************************************************************************/


#include "path.h"
#include <properties.h>

inherit THING;

string powner;

public void SetOwner(string name) { powner = name; }
public string QueryOwner() { return powner; }

create(){
 ::create();

  SetShort("un frasco con agua");
  SetLong("Es un frasco con agua del Darmaii, transparente y refrescante. "
  	"Se rumorea que tiene propiedades medicinales.\n");
  SetIds(({"frasco","frasco con agua","agua","agua del darmaii","agua del Darmaii"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetMaterial(M_CRISTAL);
  SetWeight(100);
/*
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOBUY, 1);
*/
  Set(P_NOSELL,1);
}

init(){
  ::init();

  if (environment() && living(environment()) && environment()->id("ladron"))
  	TO->remove();
}
