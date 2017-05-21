/*
DESCRIPCION  : Gremio de Aventureros
FICHERO      : /guilds/aventurero/aventurero.c
MODIFICACION :
24-10-98 [Angor] Creacion
04-11-98 [Theuzifan] Modifica el gremio heredado a /std/guild
08-10-99 [Woo] Quitado de Limbo, unido los dos archivos que componian el gremio.
26-08-07 [Angor] Separado en gremio base y sedes
--------------------------------------------------------------------------------
*/

//El gremio base
#include <gremios.h>
#include <guild.h>
#include <config.h>
inherit "std/guild";

#define A_       (TP->QueryGender()==2?"a":"")
#define AO       (TP->QueryGenderEndString())
#define NOMBRE   (capitalize(TP->QueryName()))

//funcion principal
public void create_ob() {
 ::create_ob();
  SetIntShort("el Gremio de Aventureros");
  SetIntLong(
     W("Te encuentras en una sede del Gremio de Aventureros. Es una "
     "habitación de mediano tamaño con algunas estanterias y mapas en sus "
     "paredes.\n"));

  AddDetail(({"estanterias","libros","libro"}),
     W("Hay varias estanterias junto a las paredes de la habitación. Tienen "
     "algunos viejos libros y mucho, mucho polvo. Parece que los miembros de "
     "este gremio pasan mucho más tiempo por ahí en busca de aventuras que en "
     "el propio gremio.\n"));

  AddDetail(({"mapas"}),
     W("Hay algunos mapas colgados en las paredes del gremio. No sabes de "
     "donde son y no parecen estar muy bien hechos. Juzgas que lo mejor será "
     "salir a explorar este mundo y te hagas los tuyos propios.\n"));

 SetIntNoise("No oyes gran cosa.\n");
 SetIntSmell("No huele a nada en espacial.\n");

 SetIndoors(1);
 SetIntBright(50);
 
 SetGuildclass(GC_AVENTUREROS); //clase del gremio
 SetGuildname("Gremio de los Aventureros");  //nombre del gremio
 SetGuildDomain("limbo");
 SetCreators( ({"Angor"}) );                 //creador
 
 ForbidAllMagic("No puedes reunir suficiente energía para lanzar tu hechizo.\n");
}

