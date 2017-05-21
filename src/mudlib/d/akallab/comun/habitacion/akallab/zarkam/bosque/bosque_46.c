/*
DESCRIPCION  : Orilla este del r�o Zarmaii, en el bosque de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
	       31-10-01 [Nemesis@Simauria] Rehecho lo del fruto dorado.
	                Ahora hay que 'buscarlo', porque no aparece y s�lo
			se puede coger uno.
			Ya que estaba, lo he castellanizado.
	       24-03-03 [Nemesis@Simauria] RE-rehecho lo del fruto dorado
	                Ahora s�lo hay como mucho 2, y s�lo puedes tener 1
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
  SetIntShort("el r�o Zarmaii");
  SetIntLong(
"�sta es una zona bastante peculiar, gracias a la proximidad del Zarmaii y\n"
"a la total ausencia de �rboles o grandes plantas que compitan por la luz\n"
"se favorece el hecho de que aqu� crezca una rara vegetacion espinosa. Te\n"
"encuentras totalmente rodeado por estos arbustos tan peculiares que dan un\n"
"fruto bastante preciado pero en los que te pinchas al m�nimo descuido.\n"
"Al suroeste divisas un puente que cruza el r�o.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("bosque_45"));
  AddExit("norte",Z_BOSQUE("bosque_56"));
  AddDetail(({"r�o","zarmaii","Zarmaii","afluente","r�o"}),
  "�ste es el r�o Zarmaii, afluente del Kusaii. Aunque no es muy grande, su\n"
  "cauce es ciertamente considerable.\n");
  AddDetail(({"puente"}),
  "Al suroeste ves un puente no muy grande pero seguro que eficiente y muy �til\n"
  "para atravesar el r�o.\n");
  AddDetail(({"arbustos","vegetacion","plantas","vegetaci�n"}),
  "Son unos raros arbustos espinosos que s�lo crecen en esta zona del bosque.\n"
  "Forman una gran extension aunque normalmente s�lo entre ellos se puede\n"
  "encontrar un �nico fruto dorado. Debe ser importante cuando tantas espinas\n"
  "intentan protegerlo. Tal vez merecer�a la pena buscarlo.\n");
  SetIntNoise("Al norte escuchas un extra�o ruido.\n");
  SetIntSmell("Estas plantas no desprenden ning�n aroma.\n");
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
  if ( (str!="fruta") && (str!="fruto") && (str!="dorado") ) write("No hay ning�n "+str+" por aqu�\n");
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
