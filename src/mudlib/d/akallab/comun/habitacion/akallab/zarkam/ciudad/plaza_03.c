/*
DESCRIPCION : sur de la plaza central de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/plaza_03.c
MODIFICACION: 13-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

public create() {
 ::create();
SetIntShort("la plaza central de Zarkam");
 SetIntLong(
    "Te encuentras en la parte sur de la plaza central de la ciudad de Zarkam, una "
    "gran explanada en el medio de la ciudad. Entre los altos edificios que la rodean "
    "destaca el impresionante castillo del gobernador que se alza al oeste. Observas "
    "que en el centro de la plaza hay construido un patibulo del que cuelgan varias "
    "horcas. Una ancha calle parte de aqui hacia el este, y justo al sur de aqui se "
    "halla la posada 'el Cuervo Blanco' donde el viajero puede hallar habitacion y "
    "comida caliente. Puedes ver un llamativo cartel colgado de su fachada.\n");

  AddDetail(({"posada"}),
    "Es un gran edificio de tres plantas de altura. Su fachada esta llena de ventanas "
    "y sobre la puerta principal cuelga un cartel de madera con la figura de un "
    "cuervo blanco tallada en el.\n");

  AddDetail(({"cuervo","cartel"}),
    "Sobre la puerta principal de la posada y colgando de una barra de metal hay un "
    "cartel de madera. En el se halla tallado un gran cuervo pintado de blanco, que "
    "da nombre a la posada y al que, de vez en cuando, alguna rafaga de viento hace "
    "balancearse No has visto un cuervo blanco en tu vida, por lo que dejas de "
    "preguntarte como se les habra ocurrido llamar asi a la posada.\n");

  AddDetail(({"calle"}),
    "Una ancha calle parte desde aqui hacia el este de la ciudad.\n");

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

AddExit("sur",Z_POSADA("entrada"));
AddExit("este",Z_CIUDAD("calle_29"));
AddExit("oeste",Z_CIUDAD("plaza_02"));
AddExit("norte",Z_CIUDAD("plaza_01"));

//AddCaravana("/d/akallab/comun/objeto/transporte/caravana/caravana");
}
