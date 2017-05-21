/* kobold.c
Autor: [n] Nemesis@simauria
       [a] Articman
Descripción: Un kobold como otro cualquiera
			Tendrá entre nivel 7 y 14.
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
 SetStandard("un sucio kobold","kobold",([GC_LUCHADOR:8+random(5)]),GENERO_MASCULINO);
  SetName("un sucio kobold");
  SetShort("un sucio kobold");
  SetSize(1);
  SetLong(W("Es un kobold. Como todos los de su raza es de menor tamaño que "
  "un humano y su piel es de tonos marrones. Está totalmente sucio debido a "
  "su vida en las cuevas y viste con viejas ropas desgarradas. Tiene unas "
  "prominentes orejas, al igual que su boca. Está muy encorvado, señal "
  "típica de su raza.\n"));
  SetHands(({({"mano derecha",0,3}),({"mano izquierda",0,3})}));
  SetIds(({"kobold","sucio kobold"}));
  SetAds(({"un"}));
  SetAlign(-1000);
  SetAggressive(1);
  InitChats(10,({
    "Un kobold grita: ¡Nos vamos a comerrrrr tus entrrrrañas!\n",
    "Un kobold grita: ¡Vas a morirrrrr! ¡Dalo porrr hecho!\n",
    "Un kobold grita: ¡Muerrrre!\n"
  }));
  AddItem(GOBJETO("arma/gundistyr/arma1"),REFRESH_REMOVE,SF(wieldme));
  AddItem(GOBJETO("arma/gundistyr/arma1"),REFRESH_REMOVE,SF(wieldme));
}
public varargs void Die(mixed silent) {
RemoveId(({"kobold"}));
RemoveId(({"sucio kobold"}));
::Die(silent);
}