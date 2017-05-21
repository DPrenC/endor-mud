/*
DESCRIPCION : centro de la plaza de central de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/plaza_00.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <scheduler.h>
#include <door.h>
#include <properties.h>
#include <materials.h>


inherit ROOM;

create() {
  ::create();
  SetIntShort("el norte de la plaza");
  SetIntLong(
    "Estas en la esquina noroeste de la plaza central de la ciudad de Zarkam. Es una "
    "amplia explanada rodeada de altos edificios en cuyo centro se halla un patibulo "
    "junto a la entrada del castillo, una impresionante construccion de piedra que "
    "se alza al oeste y en la que vive el gobernador. Una ancha calle parte hacia el "
    "oeste junto al muro del castillo. En el lujoso palacete bien custodiado que se "
    "halla al norte se encuentra un banco.\n");

  AddDetail(({"banco"}),
    "Es un edificio grande y lujoso que se alza al norte de la plaza central.\n");

  AddDetail(({"calle"}),
    "Una ancha calle parte desde aqui hacia el oeste de la ciudad junto a la muralla "
    "del castillo.\n");

  AddDetail(({"patibulo"}),
    "Es una plataforma elevada de madera con varias horcas. Es alli donde se ejecuta "
    "publicamente a los delincuentes o prisioneros de guerra como castigo publico y "
    "como advertencia al resto de la poblacion.\n");

  AddDetail(({"horcas"}),
    "Varias horcas hechas con una gruesa soga cuelgan de la viga superior del "
    "en ellas los orcos ajustician publicamente a quien el governador decide.\n");

  AddDetail(({"plaza","plaza central"}),
    "Es una gran explanada que se encuentra en el centro de la ciudad de Zarkam. A su "
    "alrededor se alzan altos edificios y al oeste el castillo de la ciudad. Es el "
    "lugar en que se reune la gente cuando se producen ejecuciones publicas o cuando "
    "el governador realiza algun importante anuncio.\n");

  AddDetail(({"castillo"}),
    "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
    "al suroeste de aqui. En el vive el governador orco que el emperador ha elegido "
    "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
    "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
    "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("sur",Z_CIUDAD("plaza_02"));
  AddExit("este",Z_CIUDAD("plaza_01"));
  AddExit("oeste",Z_CIUDAD("calle_19"));
  AddExit("norte",Z_TIENDA("banco"));
  AddDoor("norte", "la puerta del banco", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

}
