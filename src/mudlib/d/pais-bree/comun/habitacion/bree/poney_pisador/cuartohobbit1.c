/*
Fichero: cuartohobbit1.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pequeños cuartos en la planta baja hechos para hobbits. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("un pequeño cuarto");
    	SetIntLong("Esta pequeña y acogedora habitación fue dispuesta para el alojo de los "
    	"hobbitss que visitaran la posada y tiene todas las características que gustan a "
    	"esta raza.\n"
    	"El suelo y los muros de piedra están cubiertos por una pulida tarima de madera "
    	"bien cuidada que proporciona calidez a la estancia, y las vigas del techo están "
    	"limpias y barnizadas. A ambos lados hay dispuestas dos pequeñas camas de tamaño "
    	"hobbit equipadas con buenas mantas de lana y mullidos cobertores, con una "
    	"confortable almohada a la cabecera. Una fina esterilla de tupida lana cubre el "
    	"suelo y al pie de cada cama hay un pequeño arcón. Una sencilla mesilla ocupa el "
    	"lugar bajo una ventana redonda con cortinas que cubren los cristales.\n"
    	"A ambos lados y junto a la puerta de la habitación, también redonda, hay unos "
    	"percheros de madera para colgar ropas.\n");
    	AddDetail(({"cama", "camas"}),
    	"Pequeñas camas compuestas por un buen colchón sobre tablillas alternas y "
    	"dotado de pies y cabecera de madera, ambos no más altos que el colchón y bien "
    	"trabajados, aunque exentos de adornos.\n");
    	AddDetail("esterilla",
    	"Una esterilla de gruesa lana, muy mullida, ocupa el espacio entre ambas camas.\n");
    	AddDetail(({"perchero", "percheros"}),
    	"Colgados a ambos lados de la puerta, hay unos percheros confeccionados con un "
    	"grueso tablón de roble recortado para que tenga una cierta forma ovalada, "
    	"barnizado y con unos ganchos así mismo de madera rematados en medias esferas.\n");
    	AddDetail(({"suelo", "paredes", "muros"}),
    	"Suelo y muros están cubiertos por una tarima de madera.\n");
    	AddDetail("tarima",
    	"Está formada por tablillas de roble bbarnizado que ensamblan entre sí y dan "
    	"calidez a la habitación, aislándola de la piedra del edificio.\n");
    	AddDetail("mesilla",
    	"Está hecha de una superficie de madera y cuatro patas. Reposa bajo la ventana y a "
    	"la cabecera de las dos camas de la habitación.\n");
    	AddDetail("cortinas",
    	"Espesas cortinas que cuelgan cubriendo la ventana redonda.\n");
    	AddDetail("mantas",
    	"Son gruesas, cálidas y están limpias y hechas de lana de buena calidad.\n");
    	AddDetail("cobertores",
    	"Cobertores de tela rellenos así mismo de lana que cubren las camas y resguardan "
    	"del frío.\n");
    	AddDetail("ventana",
    	"Una ventana de marco de madera y cristal grueso pero limpio. Tiene forma "
    	"redondeada y una manilla de latón permite abrirla hacia adentro.\n"
    	"En el exterior se puede ver la empinada ladera de la colina.\n");
    	SetIntNoise("Se escuchan lejanas voces, risas, entrechocar de cubiertos y "
    	"fragmentos de canciones.\n");
    	SetIntSmell("Por debajo del olor a madera envejecida y lana y sábanas limpias, "
    	"ueles a pan recién horneado, carne asada, humo de leña y cerveza.\n");
    	SetIndoors(1);
    SetIntBright(25);
    AddExit("sur", "./pasillo2");
     AddDoor("sur", "la puerta",
     "Es una pequeña puerta redonda del estilo que gusta a los hobbits.\n"
     "Está hecha de madera que, aunque aparenta antigua, está bien pulida y barnizada.\n"
     "En el centro tiene una manilla de bronce de pomo redondeado.\n"
     "Un pestillo de latón   y una cerradura del mismo material se localizan en la "
     "parte cercana al marco y tres ganchos para colgar enseres o prendas de vestir se "
     "alinean cerca de la parte superior.\n",
     ({"puerta", "sur", "s", "puerta hobbit", "redonda", "puerta redonda"})); 
    }