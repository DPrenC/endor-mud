/*
DESCRIPCION  : un guardia
FICHERO      : /d/akallab/comun/pnj/guardia.c
MODIFICACION : 14-10-98 [Angor@Simauria] Creacion
               28-03-00 [nemesis@simauria] Añadida la espada como tiene que
                        ser: con variables y SetStandard.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit NPC;

object arma;

create() {
  ::create();
 SetStandard("guardia","orco",([GC_LUCHADOR:10]),GENDER_MALE);
  SetShort("un guardia orco");
  SetLong(
     "Es uno de los guardias orcos que se encargan de hacer trabajar a los esclavos de "
     "los campos de cultivo del valle. Parte de su trabajo tambien consiste en evitar "
     "que se escapen y si esto sucede, de perseguirlos y traerlos de vuelta.\n");
  AddId(({"guardia","orco"}));
  SetAlign(-500);

  /*InitChats(10,({
    "El guardia grita:'Eh tu! maldito humano! Ponte a trabajar de una vez'.\n",
    "El guardia exclama: 'Venga, ya esta bien de hacer el vago! A trabajar'.\n",
    "El guardia repasa sus armas sin quitar la vista de encima a los esclavos.\n",
    "El guadia va a ver que quiere uno de los esclavos.\n",
    "El guardia ordena que se le lleve agua a un esclavo desfallecido.\n"
    }));*/

  //AddItem(PROT("casco_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("escudo_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("guantes_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("botas_orco"), REFRESH_REMOVE, SF(wearme));

  arma=clone_object("/std/weapon");
  arma->SetStandard(WT_ESPADA, 12, P_SIZE_MEDIUM, M_ACERO);
  arma->SetShort("una enorme espada");
  arma->SetLong("Una espada metálica, un poco desgastada, pero muy peligrosa...\n");
  arma->Set(P_ADS, ({"enorme", "gran"}));
  AddItem(arma,REFRESH_REMOVE,SF(wieldme));

}
