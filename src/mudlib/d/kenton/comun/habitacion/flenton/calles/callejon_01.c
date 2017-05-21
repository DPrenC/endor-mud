/***************************************************************************************
 ARCHIVO:	callejon_01.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Callej�n.
 MODIFICACION:  20-04-2003 [z] A�ado funciones para un quest (Draego concretamente).
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Oyes el rumor de la calle tras la valla.\n");
  SetIntSmell("No huele a nada en especial.\n");

  SetIntShort("un callej�n oscuro");
  SetIntLong("Est�s en un callej�n oscuro. Est� detr�s de las casas de la "
  	"calle Kendarg. Al norte ves la ventana trasera de una casa. Al sur "
  	"est� la empalizada de madera que rodea al poblado. El callej�n "
  	"contin�a hacia el este y el oeste.\n");

  AddDetail(({"ventana"}),"Es la ventana trasera de la casa.\n");
  AddDetail(({"empalizada"}),"Es la empalizada de madera que rodea a todo "
  	"el poblado.\n");
  AddDetail(({"casa"}),"Ves la trasera de una de las casas.\n");
  AddDetail(({"suelo"}),"El suelo est� bastante sucio.\n");
  AddRoomCmd("entrar","fentrar");
  AddRoomCmd("saltar","fentrar");

  AddExit("este",FLENHAB+"calles/callejon_02");
  AddExit("oeste",FLENHAB+"calles/callejon_00");
}

fentrar(string str)
{
	if ((str=="por la ventana")|(str=="por ventana"))
	{
		write("Parece que la ventana no se abre por esta parte. Tendr�s que "
		"buscar otra forma de salir del callej�n.\n");
		return 1;
	}
	else return notify_fail("�Saltar por <d�nde>?\n");

}