/*
DESCRIPCION  : Orilla este del río Zarmaii, en el bosque de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
	       31-10-01 [Nemesis@Simauria] Rehecho lo del fruto dorado.
	                Ahora hay que 'buscarlo', porque no aparece y sólo
			se puede coger uno.
			Ya que estaba, lo he castellanizado.
	       24-03-03 [Nemesis@Simauria] RE-rehecho lo del fruto dorado
	                Ahora sólo hay como mucho 2, y sólo puedes tener 1
			en tu inventario.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <messages.h>
#include <moving.h>


inherit ROOM;

int frutos;

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("el río Zarmaii");
  SetIntLong(
"Ésta es una zona bastante peculiar, gracias a la proximidad del Zarmaii y\n"
"a la total ausencia de árboles o grandes plantas que compitan por la luz\n"
"se favorece el hecho de que aquí crezca una rara vegetacion espinosa. Te\n"
"encuentras totalmente rodeado por estos arbustos tan peculiares que dan un\n"
"fruto bastante preciado pero en los que te pinchas al mínimo descuido.\n"
"Al suroeste divisas un puente que cruza el río.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("bosque_45"));
  AddExit("norte",Z_BOSQUE("bosque_56"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente","río"}),
  "Éste es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su\n"
  "cauce es ciertamente considerable.\n");
  AddDetail(({"puente"}),
  "Al suroeste ves un puente no muy grande pero seguro que eficiente y muy útil\n"
  "para atravesar el río.\n");
  AddDetail(({"arbustos","vegetacion","plantas","vegetación"}),
  "Son unos raros arbustos espinosos que sólo crecen en esta zona del bosque.\n"
  "Forman una gran extension aunque normalmente sólo entre ellos se puede\n"
  "encontrar un único fruto dorado. Debe ser importante cuando tantas espinas\n"
  "intentan protegerlo. Tal vez merecería la pena buscarlo.\n");
  SetIntNoise("Al norte escuchas un extraño ruido.\n");
  SetIntSmell("Estas plantas no desprenden ningún aroma.\n");
  SetLocate("bosque de Zarkam");
  AddItem(QUEST+"amuleto/urraca", REFRESH_DESTRUCT);
 // AddItem(OTRO("fruta_dorada"), REFRESH_ALWAYS);
}

init() {
  ::init();
  frutos=random(1)+1;
 // add_action("fruto","coger");
 add_action("fruto","buscar");
}

QueryDieMsg() {
 return "#jug# ha muerto desangrado.";
}


fruto (string str) {
object ob, tiene, esta;
  if (!str) return 0;
  if ( (str!="fruta") && (str!="fruto") && (str!="dorado") ) write("No hay ningún "+str+" por aquí\n");
  tiene = present("frt",TP);
  esta = present("frt",TO);
  if (tiene || esta)
   write("Decides que por hoy ya te has llevado bastantes frutos.\n");
  else {
    if ( (random(TP->QueryDex()+100)) <= (TP->QueryDex()) && (frutos>0) ) {
     write("Con mucho cuidado introduces tus manos entre las espinas...\n");
     frutos=frutos--;
     ob = clone_object(OTRO("fruta_dorada"));
     if ( ob->move(TP,M_SILENT)!=ME_OK )
     ob->move(environment(TP), M_TELEPORT, "... y un fruto cae al suelo");
     else write("... y recoges un fruto dorado.\n");
    } else {
       if(frutos==0) {
         write("... pero no encuentras nada.\n");
       }
       else {
         write("Fallas en tu intento y te clavas cientos de espinas en la mano.\n");
         tell_room(TO, ({ MSG_SEE, TP->QueryName()+" intenta coger el fruto dorado pero se pincha la mano.\n"}), ({ TP }));
         TP->AddHP(-random(50));
       }

      }
   }
  return 1;
}
