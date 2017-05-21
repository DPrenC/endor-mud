/***************************************************************************************
 ARCHIVO:	llave_cylin.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Una llave... weno... varias... pero nada de chivarse
 ***************************************************************************************/

#include "path.h"
#include <materials.h>
#include <properties.h>

inherit THING;

string material;

create () {
  ::create();
  switch(random(5))
  {
  	case 0:	SetShort("una llave cobriza");
  		SetLong(W("Es una llave cobriza, brillante y muy elaborada. "
  		"Puede que abra algo importante... o puede que no... tendrás "
  		"que probar.\n"));
  		SetIds(({"llave","llave cobriza","llave de seri-solderteg"}));
  		SetMaterial(M_COBRE);
  		SetValue(10);
  		break;
  	case 1: SetShort("una llave plateada");
  		SetLong(W("Es una llave plateada, brillante y muy elaborada. "
  		"Puede que abra algo importante... o puede que no... tendrás "
  		"que probar.\n"));
  		SetIds(({"llave","llave plateada","llave de seri-solderteg"}));
  		SetMaterial(M_PLATA);
  		SetValue(20);
  		break;
  	case 2: SetShort("una llave dorada");
  		SetLong(W("Es una llave dorada, brillante y muy elaborada. "
  		"Puede que abra algo importante... o puede que no... tendrás "
  		"que probar.\n"));
  		SetIds(({"llave","llave dorada","llave de seri-solderteg"}));
  		SetMaterial(M_ORO);
  		SetValue(30);
  		break;
  	case 3: SetShort("una llave brillante");
  		SetLong(W("Es una llave de platino, brillante y muy elaborada. "
  		"Puede que abra algo importante... o puede que no... tendrás "
  		"que probar.\n"));
  		SetIds(({"llave","llave de platino","llave brillante","llave de seri-solderteg"}));
  		SetMaterial(M_PLATINO);
  		SetValue(40);
  		break;
  	default:SetShort("una llave de mithril");
  		SetLong(W("Es una llave de mithril, brillante y muy elaborada. "
  		"Puede que abra algo importante... o puede que no... tendrás "
  		"que probar.\n"));
  		SetIds(({"llave","llave de mithril","llave de seri-solderteg"}));
  		SetMaterial(M_MITHRIL);
  		SetValue(50);
  		break;
  }
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
}
