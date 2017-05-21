/* El lobo que depreda el bosque de Nandor.
   (c) Bansee@Simauria.
   Revisado por Nemesis.
   [n] Castellanizado. (Oct'02)
*/
inherit NPC;

create()
{
::create();
 SetName("lobo");
AddId("lobo");
SetShort("un lobo feroz");
SetLong("No se ha dado cuenta de que estas aquí. Se está comiendo un ciervo.\n");
SetRace("animal");
SetLevel(6);
SetGender(1);
SetStr(8);
SetDex(9);
SetCon(6);
SetInt(2);
SetHP(50);
SetMaxHP(50);
SetAlign(-100);
SetHands(({({"la pata delantera derecha",0,2}),
		  ({"la pata delantera izquierda",0,2}),
		  ({"los colmillos",0,2})}));
InitChats(5,({"El lobo se esta comiendo unos despojos.\n",
              "GRRRRR.......NYAMMM....NYAMM.....\n"}));
}