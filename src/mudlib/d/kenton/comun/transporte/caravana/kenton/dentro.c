/***************************************************************************************
 ARCHIVO:	kenton.c
 AUTOR:		[k] Korsario
 FECHA:		02-04-1998
 COMENTARIOS:	Basada en la caravana de Gorthem.
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(0);
  SetPreIntShort("dentro de");
  SetIntShort("la caravana Kenton");
  SetIntLong(W("Estás dentro de la caravana Kenton. Esta caravana une el "
  	"poblado Flenton, con la ciudad de Kha-annu. Vas rodeado por un montón "
  	"de viajeros, principalmente kenders y enanos. Algunos van en carretas "
  	"y otros en sus propias monturas. No puedes dejar la caravana hasta que "
  	"llegues a la parada.\n"));
}