/*
DESCRIPCION  : Sede de Limbo del gremio de Aventureros
FICHERO      : /guilds/aventurero/sede/limbo/aventurero.c
MODIFICACION :
26-08-07 [Angor] Creacion
--------------------------------------------------------------------------------
*/

#define LIMBO(x) "/d/limbo/comun/habitacion/limbo/limbo/"+x

inherit "/guilds/aventurero/aventurero_base";

public void create_ob()
{
  ::create_ob();
  SetIntShort("Gremio de Aventureros en Limbo");
  SetIntLong(
     W("Te encuentras en el Gremio de Aventureros de la isla Limbo. Es una "
     "habitaci�n de mediano tama�o con algunas estanterias y mapas en sus "
     "paredes. Este es un gremio para iniciarse y aprender, que te permitir� "
     "avanzar de nivel si te unes a �l. Cuando con el tiempo conozcas m�s "
     "mundo, puedes dejarlo y unirte a otro distinto. Al este se encuentra "
     "la entrada al ayuntamiento.\n"));

  AddDetail(({"estanterias","libros","libro"}),
     W("Hay varias estanterias junto a las paredes de la habitaci�n. Tienen "
     "algunos viejos libros y mucho, mucho polvo. Parece que los miembros de "
     "este gremio pasan mucho m�s tiempo por ah� en busca de aventuras que en "
     "el propio gremio.\n"));

  AddDetail(({"mapas"}),
     W("Hay algunos mapas colgados en las paredes del gremio. No sabes de "
     "donde son y no parecen estar muy bien hechos. Juzgas que lo mejor ser� "
     "salir a explorar este mundo y te hagas los tuyos propios.\n"));

 SetIntNoise("Oyes papeleo en la habitaci�n de al lado.\n");
 SetIntSmell("No huele a nada en espacial.\n");
 SetLocate("isla Limbo");
 AddExit("este",LIMBO("ayuntamiento"));
}

