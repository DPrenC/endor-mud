
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   amacasa.c                         *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en  cocinero.c               *
//* Creacion: 21.10.98                  *
//* Modificacion: 21.10.98              *
//* Agras: Izet (of course)             *
//* [Woo] Modificado                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>
#define NAME TP->QueryName()
inherit KBASE;


create() {
  ::create();
 SetStandard("Garina","enano",2,2);
  SetShort("Garina, el ama de casa");
  SetLong(
"Garina es una enana algo mayor, duenya de sus labores.\n"
"Sus cabellos son de color negros y tiene una ligera barba recogida en trenzas.\n"
"Va vestida con una gran tunica, marron oscuro, que le queda muy olgada.\n"
"Tiene un caracter alegre y pasea por Kha-annu, seguramente en busca de una tienda.\n");

  SetAlign(200);
  SetGoChance(70);
  SetAC(1);
  SetHands( ({ ({"mano derecha",0,1}),({"mano izquierda",1,0}) }) );
  SetIds(({"enana","ama","chacha","ama de casa"}));
  SetAds(({"una","enana"}));
  InitAChats(8,({
   "Garina grita atemorizada: ¡¡¡Socorro!!! ¡¡¡Guardias!!!\n"
  }));
  InitChats(7,({
   "Garina dice: A las muy buenas.\n",
   "Garina se queda pensativa: mmm ... ¿Qué me falta por comprar?\n",
   "Garina mira a todas partes como si estuviera desorientada.\n"}));
   AddItem("/obj/money",REFRESH_REMOVE,
(["Money": (["plata":random(5),"cobre":random(30)]) ]) );
  AddItem("/std/weapon",REFRESH_REMOVE,
            ([P_SHORT:"un rodillo de amasar",
              P_LONG:"Es un rodillo de amasar, con restos de harina.\n",
              P_IDS:({"rodillo","rodillo de cocina"}),
              P_ADS:({"un"}),
              P_WC:1,
              P_WEAPON_TYPE:WT_VARA,
              P_DAM_TYPE:DT_BLUDGEON,
              P_MATERIAL:M_MADERA,
              P_WEIGHT:1000,
              P_VALUE:2]),SF(wieldme));
   AddItem("/std/armour",REFRESH_REMOVE,
             ([P_SHORT:"una tunica marron",
               P_LONG:"Es una simple túnica marron.\n",
               P_IDS:({"túnica","tunica","tunica marron"}),
               P_ADS:({"una"}),
               P_AC:1,
               P_MATERIAL:M_TELA,
               P_ARMOUR_TYPE:AT_MAIL]),SF(wearme));
}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
    "Garina tose.\n"
    "Garina dice antes de morir: "+NAME+", traidor!!!... NOOO!\n");
    TP->SetAttribute("asesino",(TP->QueryAttribute("asesino"))+1);
    ::Die(silent);
}

move(dest,method,stuff) // No puede salir de Kha-annu
{
 if(method==M_GO && dest->QueryLocate()!="Kha-annu")
    return ME_NO_ENTER;
        return ::move(dest,method,stuff);
}

