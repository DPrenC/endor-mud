/*    ratan.c
	  Creado por : Nemesis
	  Fecha : 29-Dic-97
	  Descripcion : Una rata negra que camina por las alcantarillas.
          Modificado por : Seadrik
          Fecha : 2-Jul-98
          Anyadir codigo para la quest de limpieza de las cloacas.
          Modificado por Nyh.
*/

#include <living.h>
#include <combat.h>
#include <moving.h>

inherit NPC;

create() {
  ::create();
 SetStandard("una rata","rata",2,GENDER_FEMALE);
  SetShort("una rata negra");
  SetLong(
"Es una gran rata negra. No tiene el tamanyo espectacular de las variedades\n"
"gigantes, pero tiene un tamanyo respetable.\n");
  AddId(({"rata"}));
  SetAds(({"gran","asquerosa"}));
  SetWeight(500);
  SetAlign(0);
  SetHands(({({"pata izquierda",0,1}),
             ({"pata derecha",0,1}),
	     ({"dientes",0,1})})
		  );
  SetGoChance(20);
}
/*
public varargs void Die(mixed silent) {
  if (QueryKiller())  QueryKiller()->SetAttribute("mataratas",QueryKiller()->QueryAttribute("mataratas")+1);
  return ::Die(silent);
}
*/