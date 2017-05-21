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
  "Este claro del bosque es fruto de antiguas batallas que aqui tuvieron lugar, "
  "esto, junto con la tala indiscriminada que los orcos hacen del bosque no ha "
  "favorecido nada a su repoblacion. No hay ni un arbol en pie, ni una planta; "
  "puedes ver pequenyos brotes de vida pero que han sido aplastados antes de que "
  "pudieran formar una planta o arbol resistentes. "
  "Tambien puedes contemplar algunos cadaveres dispersos por el suelo, y en la "
  "lejania algunos esqueletos atravesados por estacas para auyentar a los  "
  "viajeros.\n");
  AddDetail(({"cadaveres","cuerpos","esqueletos"}),
  "En el suelo encuentras algunos cuerpos de los que tan solo queda un blanco "
  "esqueleto vestido con arapos. En la lejania otros esqueletos se alzan en  "
  "estacas como muestra de poca hospitalidad.\n");
  AddDetail(({"vegetacion","plantas","arboles","brotes"}),
  "La vegetacion ha sido quemada, arrasada, cortada o talada. Y los nuevos brotes "
  "han sido aplastados sin miramientos; ya nada volvera a crecer en esta zona.\n");
  AddExit("norte",Z_BOSQUE("bosque_58"));
  AddExit("noroeste",Z_BOSQUE("bosque_57"));
  AddExit("oeste",Z_BOSQUE("bosque_48"));
  AddExit("sur",Z_BOSQUE("bosque_39"));
  SetIndoors(0);
  SetIntSmell("El aire es limpio y no esta viciado.\n");
  SetIntNoise("Tan solo el silencio te rodea.\n");
  SetLocate("bosque de Zarkam");
}
