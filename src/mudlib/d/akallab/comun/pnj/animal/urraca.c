/*
Nombre:         urraca.c
Localizacion:   Bosque de Zarkam.
Estado:         En fase de desarrollo
Comentarios:
*/

#include <properties.h>
#include <moving.h>
inherit NPC;

create() {
  if (::create ()) {return;}

  SetStandard("urraca","ave",3,GENDER_FEMALE);
  SetShort("una urraca");
  SetLong(
    "Ves una oscura ave, por su forma y sus ojos rojos deduces que es una urraca. "
    "Este animal tiene fama de sentirse atraido por objetos brillantes, tal vez "
    "si encuentras su nido hayes cosas de interes en su interior. "
    "Normalmente no son agresivas, pero atacan para proteger sus nidos y su vida.\n");
  SetIds(({"urraca","pajaro"}));
  SetIds(({"urraca"}));
  SetWeight(2000);
  SetLevel(3);
  SetCon(2);
  SetInt(0);
  SetDex(6);
  SetStr(1);
  SetAggressive(0);
  SetHands(({({"el pico",0,1})}));
  InitChats(6,({
    "Una urraca se posa ante ti.\n",
    "Oyes un graznido...\n",
    "Cruuuaakkkk...\n"}));
  InitAChats(3,({
    "Cruuakkk.... cruakkkkkkkk!!!!!\n",
    "La urraca intenta sacarte un ojo...\n"}));
}
