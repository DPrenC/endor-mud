/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include "path.h"
#include <materials.h>
#include <properties.h>
#define TGENDER TP->QueryGender()

inherit WEAPON;

create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_ESPADA,6,P_SIZE_MEDIUM,M_HIERRO);
 SetWeight(2000);
 SetShort("una espada corta élfica");
 SetIds(({"espada","espada elfica","espada corta","espada corta elfica"}));
 SetValue(1200);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetBright(5);
 SetLong("\
Es una antigua espada corta proveniente de la zona de los elfos. Tiene una\n\
empuñadura de madera y su hoja contiene unas palabras.\n");
}

init() {::init();
 add_action("_leer","leer");
 add_action("_mirar","m");
 add_action("_mirar","mirar");
}

_leer(str)
{
 if (!str) return 0;
 if (str=="hoja")
 return write("Puedes leer 'Solo aquellos que demuestren su pureza de sangre me empuñaran'.\n"),1;
 return 0;
}

_mirar(str)
{
 if(!str) return 0;
 if(str=="hoja")
  return write("Tiene unas letras grabadas que quizás debieras leer.\n"),1;
 return 0;
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  if (!wielder->QueryIsPlayer()) return EQ_OK;
  if (wielder->QueryRace()!="elfo" && wielder->QueryRace()!="elfo-oscuro" && wielder->QueryRace()!="medio-elfo")
  {
    call_out("no_wield", 2, wielder);
    return "No eres un"+(TGENDER==2?"a":"")+" elf"+(TGENDER==2?"a":"o")+" por lo tanto no puedes empuñar este arma.\n";
  }
  return ::ChkEquip(wielder, weapon, flags);
}

void no_wield(object wielder)
{
 if (ENV(TO)==wielder)
 {
  tell_object(wielder,"La espada elfica se ilumina y explota..\n");
  wielder->Defend((wielder->QueryStr()+wielder->QueryCon())/2);
 }
 else
  tell_room(ENV(TO),"La espada elfica se ilumina y desaparece..\n");
 TO->remove();
 return;
}
