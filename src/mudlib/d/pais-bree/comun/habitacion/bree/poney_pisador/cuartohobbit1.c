/*
Fichero: cuartohobbit1.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  peque�os cuartos en la planta baja hechos para hobbits. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("un peque�o cuarto");
    	SetIntLong("Esta peque�a y acogedora habitaci�n fue dispuesta para el alojo de los "
    	"hobbitss que visitaran la posada y tiene todas las caracter�sticas que gustan a "
    	"esta raza.\n"
    	"El suelo y los muros de piedra est�n cubiertos por una pulida tarima de madera "
    	"bien cuidada que proporciona calidez a la estancia, y las vigas del techo est�n "
    	"limpias y barnizadas. A ambos lados hay dispuestas dos peque�as camas de tama�o "
    	"hobbit equipadas con buenas mantas de lana y mullidos cobertores, con una "
    	"confortable almohada a la cabecera. Una fina esterilla de tupida lana cubre el "
    	"suelo y al pie de cada cama hay un peque�o arc�n. Una sencilla mesilla ocupa el "
    	"lugar bajo una ventana redonda con cortinas que cubren los cristales.\n"
    	"A ambos lados y junto a la puerta de la habitaci�n, tambi�n redonda, hay unos "
    	"percheros de madera para colgar ropas.\n");
    	AddDetail(({"cama", "camas"}),
    	"Peque�as camas compuestas por un buen colch�n sobre tablillas alternas y "
    	"dotado de pies y cabecera de madera, ambos no m�s altos que el colch�n y bien "
    	"trabajados, aunque exentos de adornos.\n");
    	AddDetail("esterilla",
    	"Una esterilla de gruesa lana, muy mullida, ocupa el espacio entre ambas camas.\n");
    	AddDetail(({"perchero", "percheros"}),
    	"Colgados a ambos lados de la puerta, hay unos percheros confeccionados con un "
    	"grueso tabl�n de roble recortado para que tenga una cierta forma ovalada, "
    	"barnizado y con unos ganchos as� mismo de madera rematados en medias esferas.\n");
    	AddDetail(({"suelo", "paredes", "muros"}),
    	"Suelo y muros est�n cubiertos por una tarima de madera.\n");
    	AddDetail("tarima",
    	"Est� formada por tablillas de roble bbarnizado que ensamblan entre s� y dan "
    	"calidez a la habitaci�n, aisl�ndola de la piedra del edificio.\n");
    	AddDetail("mesilla",
    	"Est� hecha de una superficie de madera y cuatro patas. Reposa bajo la ventana y a "
    	"la cabecera de las dos camas de la habitaci�n.\n");
    	AddDetail("cortinas",
    	"Espesas cortinas que cuelgan cubriendo la ventana redonda.\n");
    	AddDetail("mantas",
    	"Son gruesas, c�lidas y est�n limpias y hechas de lana de buena calidad.\n");
    	AddDetail("cobertores",
    	"Cobertores de tela rellenos as� mismo de lana que cubren las camas y resguardan "
    	"del fr�o.\n");
    	AddDetail("ventana",
    	"Una ventana de marco de madera y cristal grueso pero limpio. Tiene forma "
    	"redondeada y una manilla de lat�n permite abrirla hacia adentro.\n"
    	"En el exterior se puede ver la empinada ladera de la colina.\n");
    	SetIntNoise("Se escuchan lejanas voces, risas, entrechocar de cubiertos y "
    	"fragmentos de canciones.\n");
    	SetIntSmell("Por debajo del olor a madera envejecida y lana y s�banas limpias, "
    	"ueles a pan reci�n horneado, carne asada, humo de le�a y cerveza.\n");
    	SetIndoors(1);
    SetIntBright(25);
    AddExit("sur", "./pasillo2");
     AddDoor("sur", "la puerta",
     "Es una peque�a puerta redonda del estilo que gusta a los hobbits.\n"
     "Est� hecha de madera que, aunque aparenta antigua, est� bien pulida y barnizada.\n"
     "En el centro tiene una manilla de bronce de pomo redondeado.\n"
     "Un pestillo de lat�n   y una cerradura del mismo material se localizan en la "
     "parte cercana al marco y tres ganchos para colgar enseres o prendas de vestir se "
     "alinean cerca de la parte superior.\n",
     ({"puerta", "sur", "s", "puerta hobbit", "redonda", "puerta redonda"})); 
    }