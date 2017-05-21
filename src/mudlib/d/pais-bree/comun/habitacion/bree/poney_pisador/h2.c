/*
Fichero: h2.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  habitaci�n para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	SetIntLong(QueryIntLong()+"El cuarto se encuentra situado sobre las cocinas, "
    	"pues as� te lo dan a entender los olores y sonidos que percibes.\n"
    	"Por la ventana puedes ver el patio situado entre las dos alas de la posada.\n");
    	SetIntSmell("El olor a comida variada se cuela por los intersticios del suelo, "
    	"mezcl�ndose con el de la madera antigua y  la ropa de cama limpia.\n");
    	SetIntNoise("Escuchas voces, llamadas, �rdenes y traqueteo de cacharros que llega "
    	"desde el piso inferior.\n");
    	AddExit("norte", "./pasillo4");
     AddDoor("norte", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "norte", "n", "puerta norte"})); 
    }