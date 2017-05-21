/*
Fichero: c1_piso2.c
Autor: aulë
Fecha: 12/10/2014
Descripción: piso superior y habitación de la casa*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
public int ir_abajo(){
    write("Bajas, no sin precauciones, la empinada escalera hasta el piso inferior.\n"
     "Algunos escalones crujen y chirrían.\n");
    say(CAP(TNAME)+" desaparece por la empinada escalera hacia la planta inferior.\n");
        tell_room(HABITACION+"bree/c1_piso1", CAP(TNAME)+" baja cuidadosamente la empinada escalera.\n");
    TP->move( HABITACION+"bree/c1_piso1", M_GO);
return 1;
}


create()
{
    ::create();
    	SetIntShort("Una habitación");
    	SetIntLong(
"El piso superior de la casita sirve de dormitorio. El suelo es de madera que cruje al "
"andar y las paredes de piedra están así mismo cubiertas por láminas de madera que "
"hacen del dormitorio un lugar más acogedor, algo que está favorecido por el calor del "
"hogar de la planta inferior que asciende y lo calienta. Hay una cama con colchón de "
"paja, algunos estantes y un cofre en un rincón. Tres ventanas dan al norte, sur y "
"oeste respectivamente. En un rincón hay una abertura en el suelo por donde se accede a "
"la escalera que baja a la planta inferior.\n");
AddDetail(({"paredes", "muros"}),
"La madera aisla las paredes. En la del norte descubres una pequeña puertecita.\n");
AddDetail("estantes",
"Unas simples valdas de madera.\n");
AddDetail("escalera",
"Dos largas vigas puestas en diagonal del suelo al techo con una serie de piezas "
 "rectangulares a modo de escalones forman la empinada y estrecha escalera que desciende al "
 "piso inferior.\n");
AddDetail("ventanas",
"Hay tres: al sur, al oeste y al norte.\n");
AddDetail(({"ventana n", "ventana norte", "ventana del norte"}),
"Al norte ves el jardín, el seto y el camino del oeste que cruza la aldea.\n");
AddDetail(({"ventana sur", "ventana s", "ventana del sur"}),
"A través de ella puedes ver un patio trasero con un pozo y más allá un pequeño "
"cobertizo.\n");
AddDetail(({"ventana del oeste", "ventana oeste", "ventana o"}),
"A través de ella puedes ver un pequeño huerto y más allá, la empalizada de la aldea y "
"los campos cultivados. Aún más lejos, el Camino Verde transcurre de norte a sur.\n");
HideExit("norte");
     AddExit("abajo", SF(ir_abajo));
AddExit("norte", "./c1_pajar2");
AddDoor("este", "una puertecita",
"Es una puertecita baja y estrecha  con un pequeño pasador de bronce para asegurarla.\n",
({"e", "puerta e", "este", "puerta este", "puerta"}));
}