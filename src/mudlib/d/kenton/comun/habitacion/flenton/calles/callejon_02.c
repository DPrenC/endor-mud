/***************************************************************************************
 ARCHIVO:	callejon_02.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Callej�n.
 MODIFICACION:  21-04-2003 A�ado un par de pnjs para un quest. Un ladr�n de koek y
 			   su 'maestro' kender.
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Oyes el rumor de la calle tras la valla.\n");
  SetIntSmell("No huele a nada en especial.\n");

  SetIntShort("un callej�n oscuro");
  SetIntLong("Est�s al final del callej�n oscuro. Al norte ves la ventana "
  	"trasera de una casa. Al sur est� la empalizada de madera que rodea "
  	"al poblado. El callej�n contin�a hacia el oeste. Hacia el este una "
  	"pared te bloquea el paso. Hay un barril junto a la empalizada.\n");

  AddExit("oeste",FLENHAB+"calles/callejon_01");
  AddItem(FLENPNJ+"poblado/kyder",REFRESH_DESTRUCT);
}