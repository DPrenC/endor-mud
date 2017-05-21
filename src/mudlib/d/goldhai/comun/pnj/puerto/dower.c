/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 29-10-98               |
 |               Ultima Modificacion... 14-05-10               |
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
    SetStandard("Dower","humano",25,GENERO_MASCULINO);
    SetIds(({"Dower","dower","pescadero","tendero","humano", "joven"}));
    SetShort("Dower, el pescadero");
    SetLong(
    "Dower es un joven humano musculoso con apariencia de ser bastante fuerte.\n Su "
    "juventud la pasó ayudando a su padre a transladar enormes bloques de hielo "
   "de un lado a otro. Fruto de ello un día que se quedó dormido entre los bloques "
    "se le congelaron ambas manos y tuvieron que cortárselas. Desde aquel incidente "
    "es el pescadero de esta lonja.\n");
     SetAlign(300);
     SetStr(QueryStr()+5); // Tiene bastante fuerza
    SetDex(QueryDex()+5); // Y es muy habil
    SetSmell(QueryName()+ " apesta a pescado.\n");
    SetHands(({({"muñón derecho",0,4}),({"muñón izquierdo",0,4})}));
    AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "un garfio",
      P_LONG:  "Un simple garfio de pescador.\n",
      P_IDS: ({"garfio","garfio pescador","garfio de pescador"}),
      P_WC: 3,
      P_GENDER: GENERO_MASCULINO,
      P_WEIGHT: 200,
      P_NUMBER_HANDS: 1,
      P_WEAPON_TYPE:WT_CUCHILLO,
      P_DAM_TYPE:DT_SLASH]));

     InitChats(3,({
    "Dower se rasca con el garfio.\n",
    "Dower te dice: No permanezcas mucho tiempo aquí u olerás también a pescado.\n",
    "El pescadero coge hábilmente una gambita y se la come.\n"}));
    SetCitizenship("goldhai");
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
