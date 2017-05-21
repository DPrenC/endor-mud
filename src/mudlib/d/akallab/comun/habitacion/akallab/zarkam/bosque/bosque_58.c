/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("un claro en el bosque");
  SetIntLong(
  "Estas en una antigua zona de combate. Hace algun tiempo aqui se libraron "
  "batallas entre las razas oscuras y sus eternos enemigos. Con el dominio  "
  "orco, las batallas cesaron y los invasores fueron expulsados. Ahora, de esta "
  "zona tan solo se extrae madera para la ciudad de Zarkam. Aunque en prueba de "
  "la supremacia orca y como excarmiento para futuros invasores, los cuerpos de "
  "los vencidos se exiben a la luz del sol para hacer mas cruda la vision del "
  "viajero que se interne en el bosque.\n");
  AddDetail(({"madera","arboles","arbol"}),
  "Todos los arboles que no fueron debastados, han sido talados, poco a poco, "
  "para abastecer a la ciudad de Zarkam de la madera que necesita periodicamente.\n");
  AddDetail(({"cuerpos","vencidos","esqueletos"}),
  "Los cuerpos de los vencidos blanquean sus huesos al sol, clavados en sendas "
  "estacas, como simbolo de lo que aqui paso hace mucho tiempo.\n");
  AddExit("suroeste",Z_BOSQUE("bosque_48"));
  AddExit("sur",Z_BOSQUE("bosque_49"));
  AddExit("oeste",Z_BOSQUE("bosque_57"));
  AddExit("sudeste",Z_BOSQUE("bosque_50"));
  SetIndoors(0);
  SetIntSmell("La muerte se uele en el ambiente.\n");
  SetIntNoise("El silencio solo es roto por el ligero rumor del viento.\n");
  AddItem(PNJ("animal/ardilla2"),REFRESH_DESTRUCT);
  SetLocate("bosque de Zarkam");
}
