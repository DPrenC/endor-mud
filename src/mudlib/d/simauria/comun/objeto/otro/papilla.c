/***************************************************************************************
 ARCHIVO:	papilla.c
 AUTOR:		[k] Karu
 FECHA:		20-02-2002
 COMENTARIOS:	Una papilla de lenguaron cocinado
 MODIFICACI�N:  A�ado los Owners, quito los Give-Drop....
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

string powner;

public void SetOwner(string name) { powner = name; }
public string QueryOwner() { return powner; }

create () {
 ::create();

  SetShort("una papilla");
  SetLong(W("Es una papilla de lenguar�n. Resulta apetitosa pero ser� mejor que "
  	"no la comas, igual alguien lo necesite m�s.\n"));
  SetIds(({"papilla","papilla de lenguaron"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(2000);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}
