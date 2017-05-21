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
      TP->move(Z_BOSQUE("arbol_17"),M_SPECIAL,
      ({"sube a la copa del arbol","llega trepando desde abajo",
        ""}));
      return 1;}

  if (TP->QueryDex()>0) como="con bastante dificultad";
  if (TP->QueryDex()>10) como="sin ningun problema";
  if (TP->QueryDex()>16) como="con una agilidad felina";

 TP->move(Z_BOSQUE("arbol_17"),M_SPECIAL,
    ({"trepa al arbol "+como,"llega trepando desde el suelo",
      "Tras un poco de esfuerzo alcanzas la copa del arbol"}));
 return 1;
}

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("el río Zarmaii");
  SetIntLong(
"Te hallas rodeado por el río Zarmaii, que te impide el paso desde el oeste "
"al este, vordeando el lugar en el que te encuentras por el sur. "
"La hierba es fresca y verde aqui, pero es la unica vegetacion que ves a "
"parte de un gran arbol de tronco ancho, posiblemente mas viejo que ningun "
"otro arbol del bosque, tal vez mas viejo que la mismisima raza orca\n");
  SetIndoors(0);
  AddExit("noroeste",Z_BOSQUE("bosque_25"));
  AddExit("norte",Z_BOSQUE("bosque_26"));
  AddExit("arriba",SF(subir));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"arbol"}),
  "Un grandioso arbol, viejo como el mundo, ha hechado raices junto al río. Al "
  "contemplarlo de cerca ves que tiene unos simbolos tallado en el tronco.\n");
  AddDetail(({"simbolos","tronco"}),
  "Observas detenidamente los simbolos tallados en el tronco, parece un antiguo "
  "dialecto de la lengua orca. Solo un orco podria leerlos.\n");
  SetIntNoise("Oyes fluir el agua a tu alrededor.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
}

init() {
  ::init();
  add_action("mensaje","leer");
}


mensaje (string str) {
  if ( (!str) || ( (str!="tronco") && (str!="simbolos") && (str!="mensaje") ) )
    {write("Leer el que?\n");
     return 1;}
  if (TP->QueryRace()!="orco")
    {write("No entiendes esos extranyos simbolos.\nTal vez si fueras un orco...\n");
     return 1;}
  write(
  "\tCreado antes que la luz "
  "\tsolo morira cuando esta muera.\n");
  return 1;
}

