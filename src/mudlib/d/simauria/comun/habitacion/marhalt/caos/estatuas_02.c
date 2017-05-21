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

  SetIntShort("el estanque de la habitaci�n de las estatuas");
  SetIntLong("Est�s en la parte norte de una estancia de forma irregular "
    "bastante amplia. Toda la estancia esta formada por rocas duras de "
    "color marr�n. y hay tres estatuas, una al suroeste, otra al sur, y "
    "la �ltima a tu lado.\nA tu lado tambi�n hay un estanque de agua en "
    "constante movimiento.\n");
  SetIntNoise("Escuchas el movimiento algo agitado de las aguas del estanque, "
    "con toda seguridad hay un paso subacu�tico, pero de momento prefieres no "
    "averiguar a donde lleva.\n");
  AddDetail(({"estatua","estatuas"}),
    "Las estatuas tienen forma de humanoides alados bastante feos, te das "
    "cuenta que la estatua de tu lado mira la salida del este, la del este "
    "mira al t�nel que esta al oeste, y la del oeste mira hacia el estanque. "
    "Lo mas curioso es que dan la sensacion de estar vigilado quien entra o "
    "sale.\n");
  AddDetail(({"estanque","agua","aguas","estanque de agua",
    "agua del estanque"}),
    "Al mirar dentro del estanque ves un t�nel subacuatico que va en "
    "direccion noroeste, la abertura del t�nel es gigantesca, debe medir "
    "entre seis y ocho metros de diametro, suficiente para que un "
    "gigante entre por ella.\n");
  AddExit("abajo",CAOSHAB"tunel_sub_05");
  HideExit("abajo",1);
  AddExit("sur",CAOSHAB"estatuas_01");
  AddExit("suroeste",CAOSHAB"estatuas_00");
}
