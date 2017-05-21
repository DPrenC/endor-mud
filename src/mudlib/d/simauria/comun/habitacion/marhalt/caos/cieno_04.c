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

  SetIntShort("una pequeña estancia");
  SetIntLong("Estás en una pequeña estancia de paredes amarillentas, en "
    "ella no hay nada destacable salvo una pequeña charca cuya agua está "
    "en constante movimiento.\n");
  SetIntSmell("Hueles el fétido hedor que proviene del este.\n");
  SetIntNoise("Escuchas el ruido que forma el agua de la charca al "
    "agitarse.\n");
  AddDetail(({"charca","pequeña charca","agua"}),W(
    "El agua de la charca esta en constante movimiento, con toda probabilidad"
    " la charca debe estar conectada con un río subterraneo.\n"));
  AddExit("este",CAOSHAB"cieno_02");
}
