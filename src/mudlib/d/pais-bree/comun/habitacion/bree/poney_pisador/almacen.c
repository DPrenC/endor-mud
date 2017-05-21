/*
Fichero: almacen.c
Autor: aulë
Fecha: 18/03/2013
Descripción:  almacén del establo del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bestablo";
create()
{
    ::create();
    	SetIntShort("almacén de arreos");
    	SetIntLong("Este rincón del establo está dedicado al almacenaje de sillas, "
    	"alforjas, riendas y demás arreos para las monturas que aquí se albergan.\n"
    	"Apoyos de madera para las sillas se alinean junto a los muros en los que se han "
    	"colocado ganchos y clavijas de distintos tipos y tamaños para colgar los arreos.\n"
    	"Es aquí también donde  se guardan los carros, carretas y demás vehículos de tiro "
    	"que los huéspedes de la taberna traen consigo de cuando en cuando.\n"
    	"Suelo y muros son de piedra bastante bien tallada aunque irregular, y grandes "
    	"vigas de roble sustentan el techo en penumbra.\n");
    	AddDetail("arreos",
    	"Cabezadas, sillas, riendas, bocados.. una gran variedad de arreos para "
    	"cabalgaduras de todo tipo y tamaño cubren las paredes y los apoyos de madera que "
    	"las jalonan.\n");
    	    	AddDetail(({"vigas", "techo"}),
    	"El techo está sustentado por grandes y antiguas vigas de añoso roble, cubiertas "
    	"de polvo y telarañas.\n");
    	    AddDetail(({"piedra", "piedras", "suelo", "pared", "paredes", "muro", "muros"}),
    "muros y paredes están hechos con piedra extraída de la colina, bien cimentada pero "
    "toscamente tallada, conformando una superficie irregular y rugosa.\n");
  AddDetail(({"ganchos", "clavijas"}),
  "Distintos tipos de clavos, clavijas y ganchos encastrados en las paredes, algunos de "
  "ellos algo oxidados y ennegrecidos por el uso y el tiempo, donde se cuelgan los "
  "arreos.\n");
  AddDetail("apoyos",
  "Son secciones de tronco, cortas, gruesas y descortezadas apoyadas sobre patas de "
  "madera. La forma redondeada de estos apoyos se usa para colocar las sillas de montar "
  "y que no se deformen.\n");
  AddDetail("alforjas",
  "Las alforjas constan de un par de enormes bbolsas de tela fuerte o cuero curtido que "
  "se atan sobre una montura para portar cargas. De los muros cuelgan alforjas de "
  "diversos tamaños, formas y materiales, haciendo notar la variedad de razas y "
  "procedencias geográficas de los huéspedes de la taberna.\n");
  AddDetail("sillas",
  "Sobre los apoyos de madera reposan distintos tipos de sillas de montar, de distintos "
  "materiales y tamaños, algunas repujadas y otras muy usadas, denotando la gran "
  "variedad de huéspedes que pasan por la posada.\n");
  AddDetail("riendas",
  "Desde las confeccionadas con simple cuerda gruesa a las elaboradas con fino cuero "
  "trenzado, una variedad pintoresca de riendas cuelga de las paredes.\n");
    	    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("este", "./establo1");
    }