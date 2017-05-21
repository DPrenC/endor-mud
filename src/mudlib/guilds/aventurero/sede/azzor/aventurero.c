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
     "El mobiliario es simple y pr�ctico. Al fondo de la estancia se encuentran "
     "algunas viejas estanter�as con libros y de las paredes cuelgan algunos descoloridos "
     "mapas. Unos bancos junto a la peque�a chimenea invitan a descansar a los "
     "miembros tras cada viaje y a compartir experiencias.\n"));

  AddDetail(({"estanterias", "estanter�as","libros","libro"}),
     W("Hay varias estanter�as junto a las paredes de la habitaci�n. Tienen "
     "algunos viejos libros y mucho, mucho polvo. Parece que los miembros de "
     "este gremio pasan mucho m�s tiempo por ah� en busca de aventuras que en "
     "el propio gremio.\n"));

  AddDetail(({"mapas"}),
     W("Hay algunos mapas colgados en las paredes del gremio. No sabes de "
     "donde son y no parecen estar muy bien hechos. Juzgas que lo mejor ser� "
     "salir a explorar este mundo y hacerte los tuyos propios.\n"));

  AddDetail(({"bancos"}),
     W("Hay varios r�sticos bancos de madera junto a la chimenea.\n"));

  AddDetail(({"chimenea"}),
     W("La peque�a chimenea empotrada en el muro calienta la estancia.\n"));

 SetIntSmell("Huele a mar.\n");
 SetLocate("ciudad de Azzor");
 AddExit("este","/d/akallab/comun/habitacion/akallab/azzor/puerto/portico07");
}

