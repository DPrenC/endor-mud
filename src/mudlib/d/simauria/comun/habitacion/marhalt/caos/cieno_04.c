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

  SetIntShort("una peque�a estancia");
  SetIntLong("Est�s en una peque�a estancia de paredes amarillentas, en "
    "ella no hay nada destacable salvo una peque�a charca cuya agua est� "
    "en constante movimiento.\n");
  SetIntSmell("Hueles el f�tido hedor que proviene del este.\n");
  SetIntNoise("Escuchas el ruido que forma el agua de la charca al "
    "agitarse.\n");
  AddDetail(({"charca","peque�a charca","agua"}),W(
    "El agua de la charca esta en constante movimiento, con toda probabilidad"
    " la charca debe estar conectada con un r�o subterraneo.\n"));
  AddExit("este",CAOSHAB"cieno_02");
}
