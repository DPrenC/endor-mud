/*
Fichero: c1_establo1.c
Autor: aul�
Fecha: 12/10/2014
Descripci�n: establo de la granja
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
public int ir_arriba(){
    write("Te aferras a los lados de la estrecha escalera y subes por los travesa�os hasta el pajar.\n\n");
    say(CAP(TNAME)+"  se aferra con fuerza a la estrecha escalera y trepa hasta desaparecer por el agujero del techo.\n");
        tell_room(HABITACION+"bree/c1_pajar1", CAP(TNAME)+ " asoma la cabeza por el agujero del suelo y termina de trepar trabajosamente por la escalera de mano.\n");
    TP->move( HABITACION+"bree/c1_pajar1", M_GO);
return 1;
}

create()
{
    ::create();
    	SetIntShort("el establo");
    	SetIntLong(
    	"Este largo establo recorre toda la parte norte de la casa y est� dividido en "
    	"distintas zonas para los diferentes animales. El largo pesebre, la paja del suelo "
    	"y los collares de madera y gruesas cuerdas que cuelgan de la pared indican que "
    	"aqu� es donde se estabulan las reses mayores. El techo de vigas y tablones de madera "
    	"sucia y oscurecida por el tiempo se apoya sobre gruesos muros de piedras "
    	"irregulares que tambi�n forman el piso del establo. Un estrecho canalillo de "
    	"piedra y argamasa canaliza los orines de los animales hacia el exterior. En una "
    	"esquina, junto al pesebre hay una estrecha escalera de mano que desaparece "
    	"entre las vigas.\n");
    	AddDetail(({"escalera", "escalerilla", "escalera de mano"}),
    	"Es una larga escalera formada por dos largas mitades de tronco recto y delgado "
    	"unidas por travesa�os cil�ndricos de madera situados a una buena distancia entre s�.\n");
    	AddDetail(({"pesebre", "pesebres"}),
    	"Est� hecho de unos largos tablones sujetos con piedra y argamasa, dejando un "
    	"hueco contra la pared donde se vierte la paja.\n");
    	AddDetail("paja",
    	"Hay una buena capa cubriendo las piedras para que el ganado se acueste.\n");
    	
 SetIntNoise("Oyes el movimientos, mugidos, cacareos y dem�s sonidos propios de los animales.\n");-
 SetIntSmell("Huele a esti�rcol de distintos tipos, paja seca, orines y animales");
 SetIndoors(1);
 AddExit("sur", "./c1_establo2");
     AddExit("arriba", SF(ir_arriba));
 AddDoor("oeste", "una pesada puerta",
 "Es una gruesa puerta de grandes tablones cuadrados de madera toscamente trabajada "
    "clavados sobre un armaz�n de soportes macizos del mismo material. Consta de una "
    "parte inferior y un cuarter�n superior que puede abrirse de forma independiente.\n"
    "No hay cerradura ni manilla, la puerta se abre con un simple empuj�n.\n"
    "Pueden observarse algunas telara�as entre los travesa�os que la sustentan, el "
    "�xido de las bisagras y un peque�o tranco de madera que, clavado en la parte "
    "interna, gira para impedir que la puerta pueda abrirse desde fuera.\n",
    ({"oeste", "e", "puerta", "puerta pesada"});
  }