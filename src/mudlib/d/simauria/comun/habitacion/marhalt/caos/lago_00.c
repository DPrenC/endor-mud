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

  SetIntShort("la entrada de la c�mara del lago");
  SetIntLong("La estancia triangular es una playa de arena bastante grande. "
    "Est� cubierta de fragmentos de conchas de caracol de gran tama�o. Hay "
    "dos estatuas hechas escombros junto a la entrada, una a cada lado.\n"
    "Hacia el suroeste hay un puente y hacia el noroeste se vislumbra la "
    "salida. La estancia sigue hacia el este y al sur se encuentra un "
    "peque�o lago.\n");
  AddDetail(({"fragmentos","conchas","fragmentos de conchas",
    "conchas de caracol"}),
    "Hay fragmentos de conchas por todos lados, casi todas las conchas est�n "
    "rotas salvo una de un tama�o enorme para ser un simple caracol (casi "
    "metro y medio).\n");
  AddDetail(({"estatuas","estatua"}),
    "Posiblemente en alg�n tiempo fueron bellas estatuas, pero actualmente "
    "no son m�s que escombros.\n");
  AddDetail(({"playa","lago","peque�o lago","paquenyo lago"}),
    "El lago de aguas cristalinas se encuentra hacia el sur.\n");
  AddExit("noroeste",CAOSHAB"entrada_03");
  AddExit("suroeste",CAOSHAB"lago_04");
  AddExit("sur",CAOSHAB"lago_03");
  AddExit("este",CAOSHAB"lago_01");
}
