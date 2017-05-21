/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";
#define HABSDP(x) "./../senderodelpomar/"+x

public create() {
  ::create();

  SetIntShort("las cercanías de una caverna");
  SetIntLong("Te encuentras en las proximidades de una caverna. Las paredes "
    "tienen unos 20 metros de altura. La roca que forma las paredes es "
    "uniforme, pasando del tono marrón (en lo más alto) hasta el rojo "
    "(a ras de suelo).\n"
    "Hacia el sur se encuentra la boca de la caverna y montones de basura "
    "y detritus, y hacia el suroeste llegas al Sendero del Pomar.\n");
  SetIndoors(0);
  SetIntSmell("Hueles el mal olor que desprenden los detritus que se "
    "amontonan en la entrada de la caverna.\n");
  AddDetail(({"basura","detritus","montones","montones de basura"}),
    "Estan en la entrada de la caverna. Sería mejor acercarse hasta allí "
    "para poder mirarlos mejor.\n");
  AddDetail(({"boca","caverna","entrada","boca de la caverna",
    "entrada de la caverna"}),
    "Esta hacia el sur.\n");
  AddExit("sur",CAOSHAB"entrada_01");
  AddExit("suroeste",POMARHAB"sendero35");
}
