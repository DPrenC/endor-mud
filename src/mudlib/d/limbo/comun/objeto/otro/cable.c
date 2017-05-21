/***************************************************************************************
 ARCHIVO:	cable.c
 AUTOR:		[k] Karu
                [n] Nemesis
 FECHA:		20-02-2002
 COMENTARIOS:	Un cable para cazar cosas escurridizas
 MODIFICADO :
               09-07-03 [n] Añadido el manejo de Owners.
	                    Retocada la descripción
 ***************************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>


inherit WEAPON;

string powner;

public void SetOwner(string name) { powner = name; }
public string QueryOwner() { return powner; }


create () {
 ::create();

  SetStandard(WT_LATIGO,1,P_SIZE_GENERIC,M_ACERO);
  SetDamType(DT_SLASH);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetShort("un cable");
  SetLong("Es un cable de un extraño metal. Puedes ver que tiene una "
  	"lazada en una punta. Quizás sirva para cazar algún animal.\n");
  SetIds(({"cable","cable para cazar"}));
  SetWeight(100);
 /*
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
*/
}

init(){
  ::init();

  if (environment() && living(environment()) && environment(TO)->id("ladron"))
  	TO->remove();
}
