/***************************************************************************************
 ARCHIVO:	caldero.c
 AUTOR:		[k] Karu
 FECHA:		20-02-2002
 COMENTARIOS:	Un caldero para cocinar
 MODIFICACION:  07-07-2003 [z] Quito NoGive, NoDrop, Can't Steal
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

string powner;

public void SetOwner(string name) { powner = name; }
public string QueryOwner() { return powner; }

create () {
 ::create();

  SetShort("un caldero");
  SetLong("Es un caldero de color negro y tiene unos extra�os s�mbolos "
  	"grabados en color dorado. A simple vista parece muy pesado, pero "
  	"cuando lo coges resulta ligero y manejable. Tal vez cocinar algo "
  	"en �l sea peligroso, dejalo en manos de otra persona.\n");
  SetIds(({"caldero","caldero de la ermita","caldero negro"}));
  AddSubDetail(({"s�mbolos","simbolos","signos"}),
  "Son unos extra�os s�mbolos dorados. No crees que puedas descifrarlos.\n");
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(10000);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}
