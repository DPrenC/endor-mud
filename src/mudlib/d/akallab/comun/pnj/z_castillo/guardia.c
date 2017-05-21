/*
DESCRIPCION  : un guardia del castillo
FICHERO      : /d/akallab/comun/pnj/z_castillo/guardia.c
MODIFICACION : 14-10-98 [Angor@Simauria] Creacion
                        [n,u] Le quitamos el platino y el oro. Que son guardias,
                              tio!!!
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>      //por el PSIZE
#include <living.h>          //por el GENDER
#include AK_MACRO
#include <gremios.h>

inherit NPC;

create() {
  ::create();
  SetStandard("guardia","orco",([GC_LUCHADOR: random(5)+20]),random(10)>2?GENDER_MALE:GENDER_FEMALE );
  SetShort("un"+A_2+" guardia orc"+AO2);
  SetLong(
     "Es un"+AO2+" de los guardias orcos que hay en el castillo, un"+AO2+" orc"+AO2+" fuerte y robust"+AO2+" "
     "cuya mision es la de proteger este lugar. Va bien armad"+AO+" y parece un"+A_2+" dur"+AO2+" "
     "adversari"+AO2+". Por su gesto duro y seco no crees que este para muchas tonterias.\n");
  AddId(({"guardia","orc"+AO2}));
  SetWhimpy(0); // O mata o muere

  AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["cobre":random(9),"plata":random(7)])]));
  AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
  AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
  SetGuild(GC_LUCHADOR);

  InitAChats(10,({
    MAY(ART2)+" guardia orc"+AO2+" grita:'Vas a morir!!'\n",
    MAY(ART2)+" guardia orc"+AO2+" se defiende como puede.\n"}));

  InitChats(10,({
    MAY(ART2)+" guardia grita:'Eh tu! que demonios haces por aqui! Este no es lugar para ti'.\n",
    MAY(ART2)+" guardia repasa sus armas sin quitarte la vista de encima.\n",
    MAY(ART2)+" guardia orco te mira desconfiadamente.\n",
    MAY(ART2)+" guardia murmura algo sobre la tardanza del individuo que debe relevarle.\n"}));
}
