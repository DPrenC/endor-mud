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

  SetIntShort("la entrada de la cámara del lago");
  SetIntLong("La estancia triangular es una playa de arena bastante grande. "
    "Está cubierta de fragmentos de conchas de caracol de gran tamaño. Hay "
    "dos estatuas hechas escombros junto a la entrada, una a cada lado.\n"
    "Hacia el suroeste hay un puente y hacia el noroeste se vislumbra la "
    "salida. La estancia sigue hacia el este y al sur se encuentra un "
    "pequeño lago.\n");
  AddDetail(({"fragmentos","conchas","fragmentos de conchas",
    "conchas de caracol"}),
    "Hay fragmentos de conchas por todos lados, casi todas las conchas están "
    "rotas salvo una de un tamaño enorme para ser un simple caracol (casi "
    "metro y medio).\n");
  AddDetail(({"estatuas","estatua"}),
    "Posiblemente en algún tiempo fueron bellas estatuas, pero actualmente "
    "no son más que escombros.\n");
  AddDetail(({"playa","lago","pequeño lago","paquenyo lago"}),
    "El lago de aguas cristalinas se encuentra hacia el sur.\n");
  AddExit("noroeste",CAOSHAB"entrada_03");
  AddExit("suroeste",CAOSHAB"lago_04");
  AddExit("sur",CAOSHAB"lago_03");
  AddExit("este",CAOSHAB"lago_01");
}
