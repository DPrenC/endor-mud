/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 07-10-98                |
 |               Ultima Modificacion.. 28-04-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <wizlevels.h>
#include <combat.h>

#define ASESINOS DOM_STD "asesinos"

inherit NPC;

create()
{
  ::create();
 SetStandard("Ernes","enano",20,GENERO_MASCULINO);
 SetIds(({"ernes","Ernes","armero","viejo ernes","enano"}));
 SetShort("Ernes, el armero");
 SetLong("\
Ernes es un viejo enano descendiente de una de las primeras parejas que\n\
llegaron a Goldhai. Pero que no te enganye su edad, pese a ello tiene mucha\n\
fuerza y una gran resistencia, que ha adquirido trabajando duramente en los\n\
campos del exterior de Crowy.\n");
 SetMaxHP(700);
 SetHP(700); // Es un viejo resistente
 SetAlign(100);
 SetAC(20);
 SetWhimpy(0); // Es el tendero, no puede huir
 SetStr(25); // Tiene bastante fuerza

 AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "una hacha de combate",
      P_LONG:  "Una estupenda hacha de combate. La hoja esta afilada para poder traspasar\n"+"casi cualquier tipo de armadura.\n",
      P_IDS: ({"hacha de combate","hacha"}),
      P_WC: 6,
      P_WEIGHT: 3900,
      P_VALUE: 610,
      P_NUMBER_HANDS: 1,
      P_WEAPON_TYPE:WT_HACHA,
      P_DAM_TYPE:DT_SLASH]));
 AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "una vieja espada",
      P_LONG:  "Ves una espada muy vieja, sucia y con la hoja oxidada.\n",
      P_IDS: ({"espada","espada vieja"}),
      P_WC: 4,
      P_VALUE: 2000,
      P_WEIGHT: 1500,
      P_WEAPON_TYPE:WT_ESPADA,
      P_DAM_TYPE:DT_SLASH]));
 AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "una coraza de acero",
      P_LONG:  "Es una coraza totalmente forjada de acero y que cubre practicamente el cuerpo.\n",
      P_IDS: ({"coraza","coraza de acero"}),
      P_AC: 4,
      P_WEIGHT: 6900,
      P_VALUE: 6000,
      P_ARMOUR_TYPE:AT_MAIL,
      P_DAM_TYPE:DT_SLASH]));

  InitChats(3,({
 "Ernes cambia las armas de orden mientras te mira de reojo.\n",
 "Ernes te dice: Hola, le puedo ayudar en algo?\n",
 "El armero da una vuelta por la tienda, parece aburrido.\n"}));
}


public int QueryCrowiano()
{
 return 1;
}

private status existe_jugador(string jugador) {
 return find_savefile(jugador)||find_object(lower_case(jugador));
}

private int IsGuardian(object mon) { return (mon->QueryGuardian())?1:0;}

public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras) // Si le atacan busca a los guardias para que le defiendan.
{
 int i;
 object *guardias;

 guardias = filter(deep_inventory(environment(TO)),SF(IsGuardian));

 if(sizeof(guardias))
  for(i=0;i<sizeof(guardias);i++)
   guardias[i]->Kill(TP || PO);

 return ::DoDamage(dmg,type,gentle,xtras);

}

public varargs void Die(mixed silent) {
 object ASESINO;

 ASESINO=PO;
 if (!ASESINO->QueryIsPlayer()) {return ::Die(silent);}
 if(!existe_jugador(ASESINO->QueryRealName())) {return ::Die(silent);}
 ASESINOS->SetAsesino(ASESINO->QueryRealName(),2,1,0,1);
 ::Die(silent);
}
