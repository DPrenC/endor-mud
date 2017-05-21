/* gkobold.c
Autor: [n] Nemesis@simauria
       [a] Articman
Descripci�n: Un guardi�n kobold.
			Tendr� entre nivel 16 y 25.
			Hay de tres tipos: los que llevan dos armas, los que llevan arma
			y escudo; y los que s�lo llevan un arma a dos manos.
Modificado: 26-Jul-2001 [n] Creaci�n
            27-Ago-2001 [a] Modificaci�nes y adaptaciones
*/


#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include "path.h"
#include <gremios.h>

inherit NPC;

int tipo;

create() {
  ::create();
 SetStandard("un guardia kobold","kobold",([GC_LUCHADOR:17+random(5)]),GENERO_MASCULINO);
  SetSize(P_SIZE_SMALL);
  SetName("un guardia kobold");
  SetShort("un guardia kobold");
  SetLong(W("Un guardia kobold, es m�s fuerte y robusto que el resto de sus "
  "cong�neres. Tiene una dura piel de tonos marrones y es algo menor que un "
  "humano. Tiene unas prominentes orejas, al igual que su boca. Est� muy "
  "encorvado, se�al t�pica de su raza. Vigila los t�neles para evitar "
  "visitantes indeseados.\n"));
  SetHands(({({"mano derecha",0,4}),({"mano izquierda",0,4})}));
  SetIds(({"kobold","guardia kobold"}));
  SetAds(({"un"}));
  SetAlign(-1000);
  SetAggressive(1);
  InitChats(10,({
    "Un guardia grita: �Te arrancaremos la piel a tiras!\n",
    "Un guardia grita: �Intrusos! �A por ellos!\n",
    "Un guardia grita: �Ayuda!\n"
  }) );
 // selecci�n de tipo
  tipo = random(3);
  if (!tipo) {
   AddItem(GOBJETO("arma/gundistyr/arma_guardias1"),REFRESH_REMOVE,SF(wieldme));
   AddItem(GOBJETO("arma/gundistyr/misericordia"),REFRESH_REMOVE,SF(wieldme));
  }
  else {
   if (tipo == 1) {
    AddItem(GOBJETO("arma/gundistyr/arma_guardias1"),REFRESH_REMOVE,SF(wieldme));
    AddItem(GOBJETO("proteccion/gundistyr/escudo"),REFRESH_REMOVE,SF(wearme));
   }
   else AddItem(GOBJETO("arma/gundistyr/arma_guardias2"),REFRESH_REMOVE,SF(wieldme));
  }
}
public varargs void Die(mixed silent){
RemoveId(({"kobold"}));
RemoveId(({"guardia kobold"}));
::Die(silent);
}