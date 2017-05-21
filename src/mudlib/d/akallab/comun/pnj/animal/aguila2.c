/*
Nombre: 	Aguila.c
Localizacion: 	Bosque de Zarkam.
Estado: 	En fase de desarrolo.
Comentarios:	Como las aguilas reales, anidan en zonas rocosas,
		aunque tb podra verse por zonas de bosque no muy
		frondosas.
*/

#include <properties.h>
#include <moving.h>
inherit NPC;

create() {
  if (::create ()) {return;}

SetName("aguila");
SetShort("un aguila");
SetLong(
"Se trata de un aguila de coloracion marron oscura, con reflejos dorados en la "
"nuca. Suelen habitar bosques como este, aunque anidan en zonas rocosas. "
"Su pico es lo suficientemente poderoso como para rasgar la carne de sus presas. "
"Posee la precision necesaria para lanzarse en picado sobre ti, sacarte los ojos "
"y emprender de nuevo el vuelo.\n");
SetRace("animal");
SetIds(({"aguila"}));
SetMaxHP(80);
SetGoChance(10);
SetLevel(6);
SetCon(6);
SetInt(8);
SetDex(10);
SetStr(7);
SetAggressive(0);
SetAlign(100);
SetHands(({({"pico",0,1}),({"garra derecha",0,1}),({"garra izquierda",0,1})}));
InitChats(6,({
"Un aguila pasa cerca tuya en vuelo rasante.\n",
"Un aguila te observa desde una rama.\n",
"Un aguila busca algun roedor.\n"}));
InitAChats(3,({
"El aguila pierde algunas plumas en el combate.\n",
"El aguila clava sus ojos en ti.\n"}));
}

