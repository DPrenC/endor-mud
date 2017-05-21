/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
    ::create();
    SetStandard("el chambel�n","medioelfo",10+random(3),GENERO_MASCULINO);
    SetShort("el chambel�n");
    SetLong("Es el criado encargado de anunciar qui�n entra al sal�n. Viste "
    "ropajes pomposos y recargados.\n");
    SetIds(({"criado","chambelan","chambel�n","heraldo"}));
    SetAlign(100);
}

init(){
  ::init();

  write("El chambelan te mira a los ojos y tras esto anuncia tu nombre.\n");
  say("El chambelan avanza un paso y hace un gesto para llamar la atenci�n.\n",this_player());
  if (this_player()->Query(P_GENDER) == 1 )
  	say(W("El chambelan anuncia: Ha entrado el magn�fico "+CATP+" en la sala.\n"), this_player());
  else
  	say(W("El chambelan anuncia: Ha entrado la magn�fica "+CATP+" en la sala.\n"), this_player());
}
