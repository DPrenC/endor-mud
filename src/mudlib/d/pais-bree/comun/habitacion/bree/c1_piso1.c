/*
Fichero: c1_piso1.c
Autor: aul�
Fecha: 12/10/2014
Descripci�n: planta baja de la casa*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
public int ir_arriba(){
    write("Subes la empinada escalera hasta el piso superior.\n"
     "Algunos escalones crujen y chirr�an.\n");
    say(CAP(TNAME)+"  sube las escaleras hacia la planta superior mientras los "
    "escalones crujen y chirr�an.\n");
        tell_room(HABITACION+"bree/c1_piso2", CAP(TNAME)+ " llega subiendo "
    "la escalera desde el piso inferior.\n");
    TP->move( HABITACION+"bree/c1_piso2", M_GO);
return 1;
}

create()
{
    ::create();
    	SetIntShort("una humilde casa");
    	SetIntLong(
 "Esta estancia ocupa toda la planta baja de la casa y en ella se cocina, come y "
 "descansa. El suelo es de argamasa endurecida y las paredes est�n encaladas para "
 "rellenar los huecos y recovecos que hay entre las piedras. En la pared norte hay un "
 "banco de madera con respaldo y un tabl�n ancho que se puede subir y apoyar en "
 "la pared sobre el banco, oficia de mesa. Un par de bajos taburetes de cuatro patas se "
 "sit�an junto al hogar sobre el que cuelga una olla grande. Varios toscos estantes y "
 "armaritos jalonan las paredes donde se amontonan alimentos y utensilios dom�sticos.\n"
 "Dos ventanas dan sobre el jard�n delantero y otra, situada sobre el hogar, da al sur "
 "sobre un peque�o huerto. Al sur se accede al patio trasero por una puerta m�s peque�a.\n"
 "En el rinc�n una estrecha escalera sube al piso superior.\n");
 AddDetail(({"Banco", "mesa", "tablon", "tabl�n"}),
 "Es un banco con respaldo que cuenta con un ancho tabl�n abatible que suele estar "
 "levantado para no ocupar sitio, pero que puede baj�rse y apoyarse en los brazos del "
 "banco a modo de mesa.\n");
 AddDetail("hogar",
 "Es un espacio rectangular cerrado por piedras regulares donde se enciende el fuego.\n"
 "Sobre �l cuelga una olla grande y unos tr�vedes permiten poner recipientes a calentar.\n");
 AddDetail("olla",
 "Es una olla grande de cobre donde se prepara la comida familiar.\n");
 AddDetail("escalera",
 "Dos largas vigas puestas en diagonal del suelo al techo con una serie de piezas "
 "rectangulares a modo de escalones forman la empinada y estrecha escalera que sube al "
 "piso superior de la casa.\n");
 AddDetail(({"ventana oeste", "oeste", "o", "ventana del oeste"}),
 "Al mirar por la ventana ves un peque�o huerto que rodea la casa y m�s all�, bajando la "
 "ladera de la colina la l�nea del seto que cerca la aldea.\n");
 AddDetail("taburetes",
 "Hechos con una secci�n m�s o menos circular de un tronco y con cuatro patas incrustadas, "
 "estos peque�os taburetes permiten sentarse y calentarse junto al fuego.\n");
 SetIntNoise("Escuchas el movimiento y el sonido de los animales en el establo contiguo.\n");
 SetIntSmell("Huele a puchero, humo y madera");
 SetIndoors(1);
 AddExit("norte", "./c1_jardin");
 AddExit("sur", "./c1_patio");
     AddExit("arriba", SF(ir_arriba));
 AddDoor("sur", "la puerta trasera",
 "Una simple puerta con una tranca para cerrarla por dentro.\n",
 ({"sur", "s", "puerta s", "puerta sur", "trasera", "puerta trasera", "puerta"}));
      AddDoor("norte", "la puerta delantera",
     "Una puerta de madera lisa pintada de verde con un par de trancas"
     " cerrarla por dentro, adem�s de un grueso pestillo.\n",
    ({"puerta", "n", "norte", "jardin", "principal", "puerta delantera"}));
    }