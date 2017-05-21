/*
DESCRIPCION  : Bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : ??-??-?? [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>



inherit ROOM;

int subir () {
  string nom,como;
  if (!TP->QueryIsPlayer()) {
    nom=TP->QueryName();
    if ( (nom=="oso") || (nom=="lobo") || (nom=="liebre") ) {return 0;}
      TP->move(Z_BOSQUE("arbol_19"),M_SPECIAL,
      ({"sube a la copa del arbol","llega trepando desde abajo",
        ""}));
      return 1;}

  if (TP->QueryDex()>0) como="con bastante dificultad";
  if (TP->QueryDex()>10) como="sin ningun problema";
  if (TP->QueryDex()>16) como="con una agilidad felina";

 TP->move(Z_BOSQUE("arbol_19"),M_SPECIAL,
    ({"trepa al arbol "+como,"llega trepando desde el suelo",
      "Tras un poco de esfuerzo alcanzas la copa del arbol"}));
 return 1;
}

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
"El bosque es realmente denso, te encuentras rodeado de arboles que te "
"impiden el paso en muchas direcciones. Solo en algunos lugares por la "
"poca proximidad de unos arboles con otros o por las caprichosas formas "
"que estos adoptan serias capaz de pasar. "
"La forma de uno de estos te permitiria escalarlo sin excesiva dificultad.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("sur",Z_BOSQUE("bosque_10"));
  AddExit("oeste",Z_BOSQUE("bosque_18"));
  AddExit("arriba",SF(subir));
  AddDetail(({"arbol","arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado... "
  "Hay uno que por su peculiar forma parece facil de escalar.\n");
  SetIntNoise("Todo esta en silencio, un silencio preocupante.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
  SetLocate("bosque de Zarkam");
}

