/***************************************************************************************
 ARCHIVO:	kendarg_04.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Calle de Kendarg
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Oyes el canto de los p�jaros.\n");
  SetIntSmell("No huele a nada en especial.\n");

  SetIntShort("la calle de Kendarg");
  SetIntLong("Est�s en la calle de Kendarg. A lo lejos divisas el Gran "
  	"�rbol, destacando en medio del poblado. Al sur ves una valla de "
  	"madera y un poste, al norte hay un sinuoso sendero. Al suroeste "
  	"ves una peque�a plaza rodeada de casas. La calle Kendarg contin�a "
  	"hacia el este.\n");

  AddDetail(({"arbol","�rbol"}),"A lo lejos ves un gran �rbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"sendero"}),"Un sinuoso sendero se aleja hacia el norte.\n");
  AddDetail(({"valla"}),"Es una valla de madera lo suficientemente alta para "
  	"que no puedas ver lo que hay detr�s.\n");
  AddDetail(({"plaza"}),"Es una plaza peque�a rodeada de casas.\n");
  AddDetail(({"poste"}),"Es un poste de madera. Hay un cartel clavado en el.\n");
  AddDetail(({"casas"}),"Hay varias casas rodeando la plaza, pero una destaca "
  	"claramente frente al resto\n");
  AddDetail(({"cartel"}),"El cartel pone:\n\n"
  		"+-----------------------------------------\n"
		"|        Casa del Shaman.                |\n"
		"|               *                        |\n"
		"|               |                        |\n"
		"|               N                        |\n"
		"|               |       * Plaza Principal|\n"
		"|               +- E - /                 |\n"
		"|             /                          |\n"
		"|           SO                           |\n"
		"|         *                              |\n"
		"|  Casa de Kendarg                       |\n"
		"+----------------------------------------+\n");

  AddExit("norte",FLENHAB+"calles/sendero_00");
  AddExit("este",FLENHAB+"calles/kendarg_03");
  AddExit("suroeste",FLENHAB+"calles/plaza_01");
}