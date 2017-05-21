/************************************************************************/
/*									*/
/*	Esta es la Espada Bastarda [ sip, como suena :) ], que portan	*/
/*	los ogros estandar de las Cavernas del Caos.			*/
/*	No tiene nada de especial. Salvo que se puede empuñar a una	*/
/*	mano, pero por lo demas es una "vulgar" espada			*/
/*									*/
/*	[k] Kintups (jobarmar@eui.upv.es)				*/
/*									*/
/*	04-05-99: Creacion [k]						*/
/*									*/
/************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON; 

create()
{
  ::create();
// Definimos las Caracteristicas Iniciales de la Espada
// Le ponemos P_SIZE_GENERIC porque las Espadas Bastardas son lo suficientemente
// pequeñas como para que un Humano la empuñe y lo suficientemente grande como
// para que la empuñe un Troll, el problema esta con los duendes :(
  SetStandard(WT_ESPADA,6,P_SIZE_GENERIC,M_ACERO);

// Definimos el Numero de Manos para Empuñarla
  SetNumberHands(1);

// Establecemos las Descripciones y los Identificadores
  SetShort("una espada bastarda");
  SetLong("Es una espada bastarda de acero finamente trabajada.\n");
  SetIds(({"espada","espada bastarda","espada de acero","bastarda"}));

// Ponemos el Genero y Numero Correctos
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
}

