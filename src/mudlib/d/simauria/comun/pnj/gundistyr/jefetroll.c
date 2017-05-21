/* jefetroll.c
Autor: [n] Nemesis@simauria
       [a] Articman
Descripción: El jefe de la banda de kobolds. Fuerte e hijoputa,
			tendrá alrededor de nivel 40.
Modificado: 26-Jul-2001 [n] Creación
            27-Ago-2001 [a] Modificaciones y adaptaciones
*/


#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include "path.h"
#include <gremios.h>


inherit NPC;

create() {
  ::create();
 SetStandard("Korthal","troll",([GC_LUCHADOR:37+random(5)]),GENERO_MASCULINO);
  SetName("Korthal");
  SetShort("Korthal el troll");
  SetLong(W("Este es Korthal,un enorme troll, más de lo que suele ser la "
  "media de su raza. Es una criatura bastante fuerte y fiera. Lidera a los "
  "sucios kobolds a quienes tiraniza y esclaviza aprovechando su mayor "
  "fuerza física y su levemente mayor inteligencia. No duda en abusar de "
  "ellos e incluso sacrificarlos si lo cree conveniente.\n"));
  SetIds(({"Korthal","korthal","troll"}));
  SetAds(({"un"}));
  SetMaxHP(450);
  SetHP(450);
  SetAlign(-5000);
  SetAC(4);
  SetAggressive(1);
  InitAChats(5,({
    "Korthal grita: '¡Te arrancaremos el alma a pedazos!'\n",
    "Korthal grita: '¿Que haces aquí? ¡Te mataré!'",
    "Korthal grita: '¡Atacad, inmundas criaturas!'"
  }) );
  AddItem(GOBJETO("arma/gundistyr/espada_ancha"),REFRESH_REMOVE,SF(wieldme));
  AddItem(GOBJETO("proteccion/gundistyr/armadtroll"),REFRESH_REMOVE,SF(wearme));
  AddItem(GOBJETO("proteccion/gundistyr/escudotroll"),REFRESH_REMOVE,SF(wearme));
}

public varargs void Die(mixed silent){
RemoveId(({"Korthal","korthal","troll"}));
::Die(silent);
}