/***************************************************************************************
 ARCHIVO:	sendero_02.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Sendero que lleva a casa del Sham�n
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Oyes el canto de los pajaros.\n");
  SetIntSmell("Huele a hierbabuena y otras hierbas olorosas.\n");

  SetIntShort("el sendero del Sham�n");
  SetIntLong("Llegas al final del sendero. Est�s enfrente de una curiosa "
  	"casa de madera de cuya chimenea sale un humo muy extra�o. Hay un "
  	"tronco de �rbol partido a un lado, y en el otro una gran cacerola. "
  	"Las hierbas crecen por todos lados.\n");

  AddDetail(({"arbol","�rbol"}),"A lo lejos ves un gran �rbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"casa"}),"Es una destartalada casa de madera. Est� toda "
  	"recubierta de enredaderas y flores. Tiene una chimenea de la que "
  	"sale un humo muy extra�o.\n");
  AddDetail(({"hierbas"}),"Ves hierbas y flores por todos lados.\n");
  AddDetail(({"cacerola"}),"Est� bastante sucia. Desprende un olor bastante "
  	"extra�o.\n");
  AddDetail(({"chimenea"}),"Una chimenea de ladrillos de la que sale un humo "
  	"muy extra�o.\n");
  AddDetail(({"humo"}),"El humo que sale de la chimenea cambia de color a cada "
  	"momento.\n");
  AddDetail(({"tronco"}),"Un gran tronco de �rbol partido. Hay un hacha clavada "
  	"en �l.");
  AddDetail(({"hacha"}),"Un hacha de tama�o medio, que est� clavada en el tronco.");

  AddExit("norte",FLENHAB+"casas/shaman");
  AddExit("suroeste",FLENHAB+"calles/sendero_01");
}