/* Ciervo que pasta por el bosque de Nandor.
   (c) Bansee@Simauria
   Revisado por Nemesis mientras escuchaba "Magic Shower", de la
   banda sonora del Out Run, esa leyenda de los arcades...
   [n] Castellanizado. (Oct'02)
 */
inherit NPC;

create()
{
::create();
SetName("un ciervo");
AddId("ciervo");
SetShort("un ciervo marron");
SetLong("Un hermoso ciervo que pasta unas raquíticas hierbas.\n");
SetRace("animal");
SetGender(1);
SetLevel(5);
SetStr(2);
SetDex(3);
SetInt(1);
SetCon(2);
SetHP(35);
SetMaxHP(35);
SetAlign(0);
SetHands(({({"la pata delantera derecha",0,1}),
		  ({"la pata delantera izquierda",0,1}),
		  ({"la cornamenta",0,3})}));
InitChats(5,({"Un ciervo come tranquilamente unas hierbas.\n",
"Un ciervo se te queda mirando con curiosidad.\n"}));
}