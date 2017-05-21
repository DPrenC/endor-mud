/*
DESCRIPCION  : guardian de los esclavos en los campos de cultivo
FICHERO      : /d/limbo/comun/pnj/guardia_esclavo.c
MODIFICACION : 07-10-98 [Angor@Simauria] Creacion
               05-04-00 [Nemesis@Simauria] Puesta el arma como debe
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <combat.h>


inherit NPC;

create() {
  object arma;

  ::create();
  SetStandard("guardia","orco",([GC_LUCHADOR:10]),GENDER_MALE);
  SetShort("un guardia orco");
  SetLong(
     "Es uno de los guardias orcos que se encargan de hacer trabajar a los esclavos de "
     "los campos de cultivo del valle. Parte de su trabajo tambien consiste en evitar "
     "que se escapen y si esto sucede, de perseguirlos y traerlos de vuelta.\n");
  AddId(({"guardia","orco"}));
  SetAlign(-500);

  InitChats(10,({
    "El guardia grita:'Eh tu! maldito humano! Ponte a trabajar de una vez'.\n",
    "El guardia exclama: 'Venga, ya esta bien de hacer el vago! A trabajar'.\n",
    "El guardia repasa sus armas sin quitar la vista de encima a los esclavos.\n",
    "El guardia va a ver que quiere uno de los esclavos.\n",
    "El guardia ordena que se le lleve agua a un esclavo desfallecido.\n"}));

  //AddItem(PROT("casco_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("escudo_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("guantes_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("botas_orco"), REFRESH_REMOVE, SF(wearme));

  arma=clone_object("/std/weapon");
  arma->SetStandard(WT_ESPADA, 7, P_SIZE_MEDIUM, M_ACERO);
  arma->SetShort("una enorme espada");
  arma->SetLong("Una espada metálica, un poco desgastada pero muy peligrosa...\n");
  arma->AddId(({"enorme espada","espada","espada enorme"}));
  AddItem(arma, REFRESH_REMOVE, SF(wieldme));
}
