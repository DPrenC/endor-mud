/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino05.c
MODIFICACION : 05-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("un puente sobre el río Kuneii");
  SetIntLong(
    "Estas sobre un ancho puente de piedra que permite al Camino del Este atravesar\n"
    "el caudaloso río Kuneii. Es un puente de varios ojos con gruesos pilares\n"
    "firmemente asentados en el cauce del río. Al norte de aqui se halla la fonda\n"
    "del 'orco errante', un buen lugar donde descansar y comer algo tras un largo\n"
    "camino. Hay un cruce al nordeste de aqui.\n");

  AddDetail(({"fonda"}),"Es el bajo edificio que se halla al norte de aqui.\n");

  AddDetail(({"puente","puente de piedra"}),
    "Un ancho puente piedra permite atravesar el caudaloso río Kuneii. Es un puente\n"
    "de varios ojos con gruesos pilares firmemente asentados en el cauce del río.\n"
    "Se haya en buen estado, aunque ya se nota el efecto de la humedad en el.\n");

  AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),
    "El río Kuneii recorre este valle de este a oeste. Es un río caudaloso plagado\n"
    "de rapidos que hacen que no sea navegable. Nace en el vecino valle de Zarkam y\n"
    "a traves de las Cataratas de Nurr atraviesa las Montanyas Negras y entra en\n"
    "este valle. Desemboca al sur de la ciudad de Azzor.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
    "Es un importante camino que comunica el valle de Zarkam con los territorios del\n"
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Sopla una suave brisa desde el este.\n");
 SetIntSmell("Hueles el fresco aroma del campo.\n");
 SetLocate("valle de Azzor");
 SetIndoors(0);

 AddExit("norte",AZ_CAMINO("fonda"));
 AddExit("nordeste",AZ_CAMINO("camino06"));
 AddExit("sur",AZ_CAMINO("camino04"));
}
