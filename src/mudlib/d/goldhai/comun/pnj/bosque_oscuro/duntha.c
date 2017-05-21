/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 08-10-98                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>

inherit NPC;

create()
{
  ::create();
 SetStandard("Duntha","gigante",([GC_LUCHADOR:30]),GENERO_MASCULINO);
 SetIds(({"Duntha","duntha","duntha el gigante","gigante","siervo","siervo de evah"}));
 SetShort("Duntha el gigante");
 SetLong("\
Duntha es el fiel siervo de la vieja curandera Evah desde que ésta lo recogió\n\
del bosque donde sus padres le habian abandonado. Como gigante, Duntha no\n\
pudo aprender gran cosa de la vieja ya que la inteligencia no es algo que\n\
les caracterice, pero si que desarrolló una gran fuerza y habilidad en la\n\
lucha a manos de su madrastra y tutora Evah. Ahora se dedica a protegerla.\n");
 SetAlign(500); // Un pedazo de pan..
 SetWhimpy(0); // No puede huir y dejar a Evah desprotegida.

 AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
  InitChats(2,({"El gigante se rasca la cabeza.\n"}));
  InitAChats(10,({"El gigante grita: Lárgate antes de que te aplaste!!\n"}));
}

public int QueryGuardian() { return 1;}

private status existe_jugador(string jugador) {
 return find_savefile(jugador)||find_object(lower_case(jugador));
}

init() {
::init();
 write("Duntha te mira y te hace una reverencia.\n");
 say("Duntha mira a "+CAP(TNAME)+" y le hace una reverencia.\n",TP);
 return;
}

private int IsGuardian(object mon) { return (mon->QueryGuardian())?1:0;}

public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras) { // Si le atacan busca a los guardias para que le defiendan.
 int i;
 object *guardias;

 guardias = filter(deep_inventory(environment(TO)),SF(IsGuardian));

 if(sizeof(guardias))
  for(i=0;i<sizeof(guardias);i++)
   guardias[i]->Kill(TP || PO);

 return ::DoDamage( dmg,  type,  gentle,  xtras);
}

public varargs void Die(mixed silent) {
 say("Duntha grita: Evahhh, Evahhh.. no quiero abandonarte!!!\n");
 ::Die(silent);
}
