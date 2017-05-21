/* cruce_nor.c
   Camino hacia el Gremio de Psiónicos
   Creación: [n] Nemesis, 10-Abr-2001 23:54:31 CEST
   Notas: Da un punto de exploración por saltar, aunque te hace pupita.
*/

#include <colours.h>
#include <combat.h>
#include "./path.h"

inherit SIM_ROOM;

int saltar() {
 if (!TI || !TP || TI != TP) return 0;

 write("Saltas hacia el vacío.\n");
 write("Caes rebotando por las montañas.\n");
 TP->SetExplored();
 say(capitalize(TP->QueryRealName())+" se lanza al vacío y cae rebotando por la montaña... RIP.\n");
 tell_room("/d/simauria/comun/habitacion/caminos/gremio/cam_cortado06","¡CRAAAAAAAAASH!\n"+
           TI->QueryRealName()+" cae rebotando desde la cima de la montaña.\n");
 TP->move("/d/simauria/comun/habitacion/caminos/gremio/cam_cortado06");

 tell_room("/d/simauria/comun/habitacion/caminos/gremio/cam_cortado06",
            capitalize(TP->QueryRealName()) + " cae desde lo alto y se "
            "estrella contra el suelo.\n", ({TP}));
 write("Te estrellas contra el suelo.\n");

 // Como prometí, pa caerse y hacerse polvo ;)...
 TP->Defend( d6(20), DT_BLUDGEON, DEFEND_NOMSG | DEFEND_NOLIV | DEFEND_NO_DEF_SK | DEFEND_NO_AC);

 return 1;
}

QueryDieMsg() {
 return "#jug# puso fin a su miserable existencia. Descanse en paz.";
}


create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("frente a");
SetIntShort("un antiguo puente");
SetIntLong(
"Estás en el borde de un puente que cruzaba un pequeño precipicio. Por "
"desgracia, el puente parece haberse derrumbado tiempo ha, de manera que "
"sólo puedes volver por donde has venido.\n");
SetIndoors(0);

AddDetail(({"puente"}),
"Sólo queda un pequeño vestigio de lo que un día fue un majestuoso puente "
"de piedra. Ahora sólo parece un buen lugar para saltar y poner fin a una "
"existencia miserable.\n");
AddDetail(({"precipicio"}),
"No es demasiado ancho, pero desde luego nadie podría salvarlo de un salto. "
"A cambio, es bastante profundo. Para caerse y hacerse polvo, vamos.\n");

AddExit("sur","camino05");
AddExit("saltar",SF(saltar));
HideExit("saltar",1);

}