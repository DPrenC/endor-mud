/***************************************************************************************
 ARCHIVO:	espada_larga.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Espada larga del herrero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,9,P_SIZE_MEDIUM,M_HIERRO);
  SetNumberHands(1);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"espada","espada larga"}));
  SetShort("una espada larga");
  SetLong(W("Es una espada larga forjada por un gran maestro herrero. Se nota por "
  	"los pequeños dientes del filo que se mantienen intactos después de duras "
  	"batallas. Tiene un símbolo grabado en la empuñadura parecido a una K, "
  	"distintivo de Kolen, el herrero, y está tan afilada que parece que corte "
  	"el viento.\n"));
  AddSubDetail(({"simbolo","símbolo","grabado","marca"}),W("Es la marca de su "
  	"creador: Kolen el herrero.\n"));
  AddSubDetail(({"dientes","diente"}),W("La espada conserva aún todos sus afilados "
  	"dientes.\n"));
  AddSubDetail(({"empuñadura","empunyadura"}),W("Es muy amplia y segura. Ideal para "
  	"coger con firmeza el arma.\n"));
}
