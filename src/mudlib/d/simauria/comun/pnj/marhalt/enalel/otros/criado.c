/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
    ::create();
    SetStandard("el chambelán","medioelfo",10+random(3),GENERO_MASCULINO);
    SetShort("el chambelán");
    SetLong("Es el criado encargado de anunciar quién entra al salón. Viste "
    "ropajes pomposos y recargados.\n");
    SetIds(({"criado","chambelan","chambelán","heraldo"}));
    SetAlign(100);
}

init(){
  ::init();

  write("El chambelan te mira a los ojos y tras esto anuncia tu nombre.\n");
  say("El chambelan avanza un paso y hace un gesto para llamar la atención.\n",this_player());
  if (this_player()->Query(P_GENDER) == 1 )
  	say(W("El chambelan anuncia: Ha entrado el magnífico "+CATP+" en la sala.\n"), this_player());
  else
  	say(W("El chambelan anuncia: Ha entrado la magnífica "+CATP+" en la sala.\n"), this_player());
}
