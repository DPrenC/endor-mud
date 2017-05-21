/***************************************************************************************
 ARCHIVO:	vitrina.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	La vitrina de la plazoleta del dragón.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit CONTAINER;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"vitrina"}));
  SetAds(({"de cristal"}));
  SetWeight(10000000);
  SetValue(0);

  SetShort("una vitrina de cristal");
  SetLong("Una vitrina de cristal, dura como una roca.\n");

  /*AddItem(FLENVAR+"escama");*/
}
