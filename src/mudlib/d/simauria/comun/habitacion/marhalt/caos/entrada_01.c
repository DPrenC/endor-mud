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

  SetIntShort("la boca de la caverna");
  SetIntLong("Te encuentras en la boca de la caverna. A un lado y otro de "
    "la misma hay montones de basura y detritus. En el suelo se ven algunas "
    "huellas.\nEl camino se aleja de la caverna en direccion norte, y la "
    "entrada a la misma se encuentra al este.\n");
  SetIndoors(0);
  SetIntSmell("Hueles el mal olor que desprenden los detritus que se "
    "amontonan a ambos lados de la caverna.\n");
  AddDetail(({"basura","detritus","montones","montones de basura"}),
    "Están a un lado y otro de la boca de la caverna. El alto grado de "
    "descomposición impide reconocer su posible origen. Lo único seguro es "
    "que, sea lo que sea lo que vive dentro de la caverna, es muy sucia.\n");
  AddDetail(({"entrada","caverna","entrada de la caverna"}),
    "Esta hacia el este.\n");
  AddDetail(({"huella","huellas"}),
    "Hay huellas de todos las tamaños, desde las huellas de las ratas que "
    "habitan las cuevas, pasando por las de seres humanoides (la mayoría), "
    "y tres o cuatro de tamaño gigantesco.\n");
  AddExit("norte",CAOSHAB"entrada_00");
  AddExit("este",CAOSHAB"entrada_02");
}
