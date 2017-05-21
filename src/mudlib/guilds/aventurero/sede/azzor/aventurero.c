/*
DESCRIPCION  : Sede de Azzor del gremio de Aventureros
FICHERO      : /guilds/aventurero/sede/azzor/aventurero.c
MODIFICACION :
09-09-07 [Angor] Creacion
--------------------------------------------------------------------------------
*/

inherit "/guilds/aventurero/aventurero_base";

public void create_ob()
{
  ::create_ob();
  SetIntShort("el gremio de aventureros en Azzor");
  SetIntLong(
     W("Esta sede del gremio de aventureros es agradable aunque no muy grande. "
     "El mobiliario es simple y práctico. Al fondo de la estancia se encuentran "
     "algunas viejas estanterías con libros y de las paredes cuelgan algunos descoloridos "
     "mapas. Unos bancos junto a la pequeña chimenea invitan a descansar a los "
     "miembros tras cada viaje y a compartir experiencias.\n"));

  AddDetail(({"estanterias", "estanterías","libros","libro"}),
     W("Hay varias estanterías junto a las paredes de la habitación. Tienen "
     "algunos viejos libros y mucho, mucho polvo. Parece que los miembros de "
     "este gremio pasan mucho más tiempo por ahí en busca de aventuras que en "
     "el propio gremio.\n"));

  AddDetail(({"mapas"}),
     W("Hay algunos mapas colgados en las paredes del gremio. No sabes de "
     "donde son y no parecen estar muy bien hechos. Juzgas que lo mejor será "
     "salir a explorar este mundo y hacerte los tuyos propios.\n"));

  AddDetail(({"bancos"}),
     W("Hay varios rústicos bancos de madera junto a la chimenea.\n"));

  AddDetail(({"chimenea"}),
     W("La pequeña chimenea empotrada en el muro calienta la estancia.\n"));

 SetIntSmell("Huele a mar.\n");
 SetLocate("ciudad de Azzor");
 AddExit("este","/d/akallab/comun/habitacion/akallab/azzor/puerto/portico07");
}

