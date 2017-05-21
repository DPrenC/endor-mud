/*
DESCRIPCION  : folleto 'en_obras'
FICHERO      : /d/limbo/comun/objeto/otro/armario_posada.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit THING;

create() {
  ::create();
  SetShort("un folleto");
         //--------------------------------------------------------------------------------
  SetLong("\nNOTA PARA LOS JUGADORES DE ESTA ZONA:\n\n"
          "A aquellos que hayais decidido jugar en este territorio he de deciros que si\n"
          "bien el valle esta abierto y se puede jugar en el, debeis tener en cuenta que\n"
          "aun faltan algunas cosas por hacer, asi que no os extranyeis si hay cosas que\n"
          "faltan o no funcionan. Aun quedan por hacer las minas, gran parte de la ciudad,\n"
          "los quests, etc...\n"
          "Resumiendo: estamos en obras. Espero que disculpeis las molestias.\n\n"
          "Angor, Dios de Simauria y Lord de este dominio.\n");
  SetIds(({"folleto","obras"}));
  SetWeight(0);
  SetValue(0);
}
