/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el oeste de la habitación de las estatuas");
  SetIntLong("Estás en la parte oeste de una estancia de forma irregular "
    "bastante amplia. Toda la estancia está formada por rocas duras de color "
    "marrón. En la estancia hay tres estatuas, una al noreste, otra al este, "
    "y la última a tu lado. Además en la zona Noreste hay un estanque de "
    "agua en constante movimiento.\n");
  SetIntNoise("Escuchas el movimiento algo agitado de las aguas del estanque, "
    "con toda seguridad hay un paso subacuático, pero de momento prefieres "
    "no averiguar a donde lleva.\n");
  AddDetail(({"estatua","estatuas"}),
    "Las estatuas tienen forma de humanoides alados bastante feos, te das "
    "cuenta que la estatua de tu lado mira al estanque, la del este mira al "
    "túnel que está a tu lado, y la que esta junto al estanque mira la salida "
    "del este. Lo más curioso es que dan la sensación de estar vigilado quien "
    "entra o sale.\n");
  AddExit("noroeste",CAOSHAB"arroyo_estatuas");
  AddExit("este",CAOSHAB"estatuas_01");
  AddExit("nordeste",CAOSHAB"estatuas_02");
}
