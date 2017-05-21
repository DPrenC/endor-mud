/*
DESCRIPCION  : Orilla este del río Zarmaii, en el bosque de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_26.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/


#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("el río Zarmaii");
  SetIntLong(
    "Estas en un ensanchamiento de la orilla del Zarmaii, te encuentras rodeado "
    "de troncos dispersos en circulo alrededor de un circulo negro en el suelo. "
    "Parece ser que el circulo se ha formado por los restos lo que antiguamente "
    "pudo ser una hoguera. Quien quiera que viniera a disfrutar del paisaje en "
    "este lugar, ya hace mucho que no ha vuelto. "
    "Al noroeste ves un pequenyo puente mientras que al sur logras distinguir un "
    "gran arbol que se alza sobre el río.\n");

  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
    "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
    "cauce es ciertamente considerable.\n");

  AddDetail(({"arbol"}),
    "Al sur ves un gran arbol que parece ser muy antiguo. Al mirar al otro lado "
    "del río ves otro arbol, mas pequenyo, que entrecruza sus ramas con este.\n");

  AddDetail(({"circulo","negro","hoguera"}),
    "En el suelo hay restos de madera quemada, hace tiempo alguien debio encender "
    "una hoguera en este lugar.\n");

  AddDetail(({"puente"}),
    "Al noroeste ves un puente no muy grande pero seguro que eficiente y muy util "
    "para atravesar el río.\n");

  AddDetail(({"tronco","troncos"}),
    "Unos troncos se agrupan entorno a una antigua hoguera, seguramente sirvieron "
    "de asiento a quienes la encendieron.\n");

  SetIntNoise("Oyes el rumor del agua.\n");
  SetIntSmell("El aire es limpio.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_BOSQUE("bosque_25"));
  AddExit("sur",Z_BOSQUE("bosque_17"));
  AddExit("noroeste",Z_BOSQUE("bosque_35"));

  AddItem(PNJ("animal/aguila"),REFRESH_DESTRUCT);
}
