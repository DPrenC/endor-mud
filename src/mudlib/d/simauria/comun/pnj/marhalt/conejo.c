/* Conejo del bosque de Nandor.
   (c) Bansee@Simauria.
   Revisado por Nemesis.
   [n] Castellanizado. (Oct'02)
 */

#include <moving.h>
inherit NPC;

create()
{
 ::create();
 SetName("un conejo");
 AddId("conejo");
 SetShort("un lindo conejillo");
 SetLong("Ves un lindo conejito que come hierba tranquilamente.\n");
 SetRace("animal");
 SetLevel(2);
 SetStr(1);
 SetCon(1);
 SetInt(1);
 SetDex(3); // Pegarle a un conejillo es dificil. Se te mete entre los pies!
 SetHP(17);
 SetMaxHP(17); /* Al fin y al cabo, es un vulgar conejo. No puede tener 66 HP! */
 SetGender(1);
 SetAlign(0);
 SetHands(({
          ({"la pata delantera derecha",0,1}),
	  ({"la pata delantera izquierda",0,1})
		  }));
 InitChats(5,({"Un conejo come hierba pacíficamente.\n",
 "Un conejo te ve y se aparta de tu camino.\n"}));
}