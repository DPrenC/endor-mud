/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>



inherit ROOM;

int subir(){
  string nom,como;
  if (!TP->QueryIsPlayer()) {
    nom=TP->QueryName();
    if ( (nom=="oso") || (nom=="lobo") || (nom=="liebre") ) {return 0;}
      TP->move(Z_BOSQUE("arbol_16"),M_SPECIAL,
      ({"sube a la copa del arbol","llega trepando desde abajo",
        ""}));
      return 1;}

  if (TP->QueryDex()>0) como="con bastante dificultad";
  if (TP->QueryDex()>10) como="sin ningun problema";
  if (TP->QueryDex()>16) como="con una agilidad felina";

 TP->move(Z_BOSQUE("arbol_16"),M_SPECIAL,
    ({"trepa al arbol "+como,"llega trepando desde el suelo",
      "Tras un poco de esfuerzo alcanzas la copa del arbol"}));
 return 1;
}


create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("el río Zarmaii");
  SetIntLong(
"Te encuentras en la orilla del río Zarmaii, uno de los afluentes naturales "
"del Kusaii. Si bien no es tan grande como este, posee el suficiente caudal "
"y fuerza como para disuadir a cualquiera de cruzarlo a nado. "
"La orilla esta repleta de huellas, posiblemente de animales que vienen a "
"saciar su sed, y de otros que vienen a saciar su apetito con estos. "
"Ves un arbol que se alza curvandose sobre el río.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("bosque_15"));
  AddExit("suroeste",Z_BOSQUE("bosque_07"));
  AddExit("arriba",SF(subir));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"arbol"}),
  "Es un arbol de mediano tamanyo que extiende sus ramas hacia el otro lado del "
  "río. No te costaria mucho subir a su copa.\n");
  AddDetail(({"huellas","pisadas"}),
  "Cualquiera hubiera deducido que se trata tanto de huellas de herviboros como "
  "algunas de carnivoros. Tambien hay senyales de lucha entre estos.\n");
  SetIntNoise("Lo unico que puedes oir es el estridente ruido de la cascada.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
  switch (random(2)) {
  case 0:  AddItem(PNJ("animal/ardilla2"),REFRESH_DESTRUCT);
           break;
  case 1:  AddItem(PNJ("animal/ardilla"),REFRESH_DESTRUCT);
           break;
  }
}

