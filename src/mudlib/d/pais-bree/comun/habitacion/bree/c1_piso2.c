/*
Fichero: c1_piso2.c
Autor: aul�
Fecha: 12/10/2014
Descripci�n: piso superior y habitaci�n de la casa*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
public int ir_abajo(){
    write("Bajas, no sin precauciones, la empinada escalera hasta el piso inferior.\n"
     "Algunos escalones crujen y chirr�an.\n");
    say(CAP(TNAME)+" desaparece por la empinada escalera hacia la planta inferior.\n");
        tell_room(HABITACION+"bree/c1_piso1", CAP(TNAME)+" baja cuidadosamente la empinada escalera.\n");
    TP->move( HABITACION+"bree/c1_piso1", M_GO);
return 1;
}


create()
{
    ::create();
    	SetIntShort("Una habitaci�n");
    	SetIntLong(
"El piso superior de la casita sirve de dormitorio. El suelo es de madera que cruje al "
"andar y las paredes de piedra est�n as� mismo cubiertas por l�minas de madera que "
"hacen del dormitorio un lugar m�s acogedor, algo que est� favorecido por el calor del "
"hogar de la planta inferior que asciende y lo calienta. Hay una cama con colch�n de "
"paja, algunos estantes y un cofre en un rinc�n. Tres ventanas dan al norte, sur y "
"oeste respectivamente. En un rinc�n hay una abertura en el suelo por donde se accede a "
"la escalera que baja a la planta inferior.\n");
AddDetail(({"paredes", "muros"}),
"La madera aisla las paredes. En la del norte descubres una peque�a puertecita.\n");
AddDetail("estantes",
"Unas simples valdas de madera.\n");
AddDetail("escalera",
"Dos largas vigas puestas en diagonal del suelo al techo con una serie de piezas "
 "rectangulares a modo de escalones forman la empinada y estrecha escalera que desciende al "
 "piso inferior.\n");
AddDetail("ventanas",
"Hay tres: al sur, al oeste y al norte.\n");
AddDetail(({"ventana n", "ventana norte", "ventana del norte"}),
"Al norte ves el jard�n, el seto y el camino del oeste que cruza la aldea.\n");
AddDetail(({"ventana sur", "ventana s", "ventana del sur"}),
"A trav�s de ella puedes ver un patio trasero con un pozo y m�s all� un peque�o "
"cobertizo.\n");
AddDetail(({"ventana del oeste", "ventana oeste", "ventana o"}),
"A trav�s de ella puedes ver un peque�o huerto y m�s all�, la empalizada de la aldea y "
"los campos cultivados. A�n m�s lejos, el Camino Verde transcurre de norte a sur.\n");
HideExit("norte");
     AddExit("abajo", SF(ir_abajo));
AddExit("norte", "./c1_pajar2");
AddDoor("este", "una puertecita",
"Es una puertecita baja y estrecha  con un peque�o pasador de bronce para asegurarla.\n",
({"e", "puerta e", "este", "puerta este", "puerta"}));
}