/*
Fichero: c1_huerto1.c
Autor: Aul�
Fecha: 02/12/2014
Descripci�n: huerto de la casa.
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("un huerto");
    	SetIntLong(
    	"Est�s en un peque�o terreno que parece ser el huerto de la casa. Situado al oeste de la misma, es una peque�a parecela soleada delimitada al oeste por un bajo pero grueso muro y al norte por un espeso seto. La tierra est� cavada y trabajada y algunas plantas comestibles nacen en ordenadas l�neas.\n");
    	AddDetail("casa",
    	"Una casita de dos pisos cuyas ventanas dan sobre este huerto.\n");
    	AddDetail("muro",
    	"Es un grueso y bajo muro de grandes piedras que sirve para contener la tierra de "
    	"esta peque�a parcela que ha sido aplanada sobre la ladera inclinada de la colina.\n"
    	"M�s al oeste puedes ver una corta pendiente que desciende hasta la empalizada.\n");
    	AddDetail("pendiente",
    	"La pendiente llena de maleza desciende hasta la empalizada que cerca la aldea.\n"
    	"Te das cuenta que un peque�o sendero la jalona por la parte interior.\n"
    	"Un buen salto podr�a llevarte a este camino.\n");
    	AddDetail("plantas",
    	"Algunas lechugas, repollos, remolachas y unas cuantas hileras de plantas de "
    	"patatas.\n");
    	AddDetail("seto",
    	"Un seto espeso que llega al pecho de un hombre y cierra la propiedad por el norte.\n");   	
    	AddExit("noreste", "./c1_jardin");
    	AddExit("sur", "./c1_huerto2");
    	}