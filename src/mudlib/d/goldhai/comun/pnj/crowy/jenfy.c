/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 23-09-99                |
 |               Ultima Modificacion.. 23-09-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <wizlevels.h>
#include <properties.h>

#define ASESINOS DOM_STD "asesinos"

inherit NPC;

int ayuda;

create()
{
  ::create();
 SetStandard("Jenfy","humano",4,GENERO_MASCULINO);
 SetIds(({"jenfy","Jenfy","tendera","tendero","humana","propietaria"}));
 SetShort("Jenfy, la propietaria");
 SetLong("\
Es una vieja humana muy pequeñita y que siempre está sonriendo.\n");
 SetMaxHP(200);
 SetHP(200); // Es un viejo resistente
 SetAlign(250);
 SetAC(20);
 SetWhimpy(0); // Es el tendero, no puede huir
 SetDex(15);
 SetInt(30);

  InitChats(5,({"Jenfy te mira quizás esperando a que le compres algo.\n",
                "Jenfy te observa y no te quita ojo.\n"}));
}

reset()
{
 ::reset();
 ayuda=0;
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
 object *guardias,proteccion;

 if (!ayuda)
 {
  say("Cuatro guardianes entran por la puerta subitamente.\n");
  proteccion = clone_object(PNJ("crowy/guardia_orco"));
  proteccion->move(environment(TO));
  proteccion->Kill(TP || PO);
  proteccion = clone_object(PNJ("crowy/guardia_gigante"));
  proteccion->move(environment(TO));
  proteccion->Kill(TP || PO);
  proteccion = clone_object(PNJ("crowy/guardia_humano"));
  proteccion->move(environment(TO));
  proteccion->Kill(TP || PO);
  proteccion = clone_object(PNJ("crowy/guardia_elfo"));
  proteccion->move(environment(TO));
  proteccion->Kill(TP || PO);
  ayuda=1;
 }

 guardias = filter(deep_inventory(environment(TO)),SF(IsGuardian));

 if(sizeof(guardias))
  for(i=0;i<sizeof(guardias);i++)
   guardias[i]->Kill(TP || PO);

 return ::DoDamage(dmg,type,gentle,xtras);
}

public varargs void Die(mixed silent) {
 object ASESINO;

 ASESINO=PO;
 if(!ASESINO->QueryIsPlayer()) {return ::Die(silent);}
 if(!existe_jugador(ASESINO->QueryRealName())) {return ::Die(silent);}
 ASESINOS->SetAsesino(ASESINO->QueryRealName(),2,1,0,1);
 ::Die(silent);
}
