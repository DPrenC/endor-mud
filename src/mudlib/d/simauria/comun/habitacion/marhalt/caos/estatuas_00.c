/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el oeste de la habitaci�n de las estatuas");
  SetIntLong("Est�s en la parte oeste de una estancia de forma irregular "
    "bastante amplia. Toda la estancia est� formada por rocas duras de color "
    "marr�n. En la estancia hay tres estatuas, una al noreste, otra al este, "
    "y la �ltima a tu lado. Adem�s en la zona Noreste hay un estanque de "
    "agua en constante movimiento.\n");
  SetIntNoise("Escuchas el movimiento algo agitado de las aguas del estanque, "
    "con toda seguridad hay un paso subacu�tico, pero de momento prefieres "
    "no averiguar a donde lleva.\n");
  AddDetail(({"estatua","estatuas"}),
    "Las estatuas tienen forma de humanoides alados bastante feos, te das "
    "cuenta que la estatua de tu lado mira al estanque, la del este mira al "
    "t�nel que est� a tu lado, y la que esta junto al estanque mira la salida "
    "del este. Lo m�s curioso es que dan la sensaci�n de estar vigilado quien "
    "entra o sale.\n");
  AddExit("noroeste",CAOSHAB"arroyo_estatuas");
  AddExit("este",CAOSHAB"estatuas_01");
  AddExit("nordeste",CAOSHAB"estatuas_02");
}
