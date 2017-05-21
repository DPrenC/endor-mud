/*
  Descripciones aleatorias para la zona del bosque de Nyne del Gremio de los Contrabandistas.
  Antes de que nadie piensa nada raro, no, no es un gremio de verdad, y por tanto nadie puede unirse.

  10-10-01 [Bomber] Bomber@simauria.upv.es

*/

#include "path.h"

inherit SIM_ROOM;
create() {
 ::create();

/* Location */
SetLocate("Bosque de Nyne");

/* Estamos al aire libre */
SetIndoors(0);

SetIntSmell("Huele a humo de Pipa y de Puro. Aqui todo el mundo fuma al cerra un trato.\n");

SetIntNoise("Estas en una 'Zona Comercial'. Aunque la gente se va en cuanto te acercas, oyes bastante murmullo.\n");

/* Descripcion Corta */
SetIntShort("el Gremio de los Contrabandistas");

SetIntLong(W("Estas en un Claro del Bosque de Nyne, que hace a su vez de Gremio"
             " Improvisado de los Contrabandistas y 'Zona Comercial'. Puedes ver"
             " tiendas en todas direcciones. No sería mala idea pasarse por una a"
             " ver que cosas pueden ofrecerte. Tal vez haya algo interesante que comprar.\n"));

ForbidAllMagic();
AddRoomCmd("matar","_matar");
}

int _matar(string str)
{
 if (!str) return 0;
 else {
 write("Hechas mano de tu arma para darle lo suyo a "+str+".\n");
 write("El sonido de un arco tensándose hace que te lo pienses dos veces.\n");
 write("Este no es buen lugar para empezar una pelea.\n");
 return 1;
 }
}

