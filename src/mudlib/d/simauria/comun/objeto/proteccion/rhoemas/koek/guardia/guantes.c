/***************************************************************************************
 ARCHIVO:	guantes.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Guantes de la Guardia de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_GUANTES,1,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"guantes","guantes blancos"}));
  SetShort("unos guantes blancos");
  SetLong(W("Son los guantes de gala de la guardia de Koek. Están hechos de una tela "
  "muy suave pero resistente y están impecablemente blancos. Tienen un pequeño bordado "
  "del escudo de Koek en la parte superior.\n"));
  AddSubDetail(({"bordado","escudo","escudo bordado"}),W("En la parte superior de los "
  	"guantes hay un precioso escudo bordado en hilo de oro. Parece el de la guardia "
  	"de Koek.\n"));
}