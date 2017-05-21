/* kobduerme.c
Autor: [a] Articman
Descripción: Un kobold dormido. No tiene equipo
Modificado: 26-Ene-2002 [a] Creación
*/


#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include "../path.h"
#include <gremios.h>

inherit NPC;


create() {
  ::create();
 SetStandard("un kobold","kobold",([GC_LUCHADOR:7+random(8)]),GENERO_MASCULINO);
  SetName("un kobold");
  SetShort("un kobold durmiendo");
  SetLong(W("Es un kobold. Como todos los de su raza es de menor tamaño que "
  "un humano y su piel es de tonos marrones. Está totalmente sucio debido a "
  "su vida en las cuevas y viste con viejas ropas desgarradas. Tiene unas "
  "prominentes orejas, al igual que su boca. Está muy encorvado, señal "
  "típica de su raza.\n"));
  SetIds(({"kobold","kobold durmiendo"}));
  SetAds(({"un"}));
  SetAlign(-1000);
  SetAggressive(0);
  //No tiene chats porque "dormido" no hablara y "despierto" (cuando luche)
  //no roncara
  //No tiene armas porque le han pillao desprevenio
}