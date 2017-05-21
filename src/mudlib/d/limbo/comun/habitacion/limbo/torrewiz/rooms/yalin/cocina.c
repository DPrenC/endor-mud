/* La cocina de la casa de Yalin.
Autor: yalin.
Descripción: cocina de la casa.
*/
#include "path.h"
#include <properties.h>
#include <magia.h>
#include <moving.h>
inherit ROOM;
inherit PUB;

/* la siguiente función da una respuesta coherente cuando el jugador intenta coger algo del decorado */
public int decor(string str)
{
    if ((str == "fogon") || (str == "fogón") || (str == "fogones") || (str == "armario"))
    {
        write("No tienes... fuerza suficiente.\n");
        return 1;
    }
    if ((str == "cacharro") || (str == "cacharros") || (str == "cacerola") || (str == "cacerolas") || (str == "sarten") || (str == "sartén") || (str == "sartenes"))
    {
        write("Todo está tan bonito y bien colocado, que te da pena tocarlo.\n");
        return 1;
    }
    return 0;
}

/* ahora interceptamos la acción abrir, para el armario. */
public int noabre(string str)
{
    if (str == "armario")
    {
        write("Está cerrado con llave, o tal vez por alguna fuerza que sólo la cocinera sabe "
            "utilizar.\n");
        say(CAP(TNAME)+" trata de abrir el armario, pero no puede.\n",TP);
        return 1;
    }
    return 0;
}

create()
{
    "*"::create();
    SetIntShort("la cocina");
    SetIntLong("Esto es la cocina de la casa.\nEl metal de los fogones brilla de puro limpio, "
        "así como los cacharros, que están perfectamente ordenados. Sospechas que la reina de "
        "las hadas no se rompería las uñas frotando cacerolas y sartenes, ni permitiría que su "
        "niño lo hiciera, así que te preguntas quién les hará la comida.\nJunto a una de las "
        "paredes hay un gran armario.\nEn un rincón ves lo que parece ser un mueble velador.\n");
    SetIntBright(50);
    SetIntSmell("huele ligeramente a comida y humo de leña.\n");
    AddDetail(({"mueble","muebles"}),"¿Qué mueble exactamente?\n");
    AddDetail(({"fogones"}),"Están muy limpios y relucientes.\n");
    AddDetail(({"cacharros","cacerolas","sartenes"}),"todo está pulido y ordenado, mejor no "
        "revuelvas nada.\n");
    AddDetail(({"armario"}),"Un robusto armario de roble, donde se guardarán probablemente "
        "la vajilla, la cubertería y la mantelería de mesa.\n");
    AddDetail(({"velador","mueble velador"}),"Es una especie de caja con forma de prisma cuadrangular con la superficie "
        "superior recubierta por una placa metálica en forma de bandeja, y sobre ésta, en la parte posterior ves un cuerpo "
        "cilíndrico con su parte frontal abierta, por donde se dispensan los alimentos que la cocinera ha dejado preparados "
        "para el consumo.\n¿Cómo se conservan? Estás en la torre de la magia, no preguntes.\nEn la pared, sobre "
        "el mueble, puedes leer el menú disponible.\n");
    Set(P_TPORT,TPORT_NO);
    AddRoomCmd("coger", "decor");
    AddRoomCmd("abrir", "noabre");
    AddExit("este", TORRE("rooms/yalin/pasillo"));
    AddDrink("agua","un vaso de",0,0,10,0,"Lo mejor para la sed.");
    AddDrink("cerveza","una jarra de",3,4,8,0,"Muy refrescante...");
    AddDrink("vino","un vaso de",5,7,5,0,"¡De la bodega de los monjes!");
    AddDrink("licor de madroño","una copita de",5,10,5,0,"Esta chica sí sabe ! ¡Está delicioso!");
    AddDrink("aguardiente","un vaso de",5,20,5,0,"¡Dios, cómo pega esto!");
    AddFood("sopa de verduras","un plato de",7,8,0,"mmmm, ¡de la vega de Gaddaro!");
    AddFood("estofado de ternera","un plato de",9,12,0,"¡Hurra por la cocinera!");
    AddFood("cocido simauriano","un plato de",12,20,0,"¡Qué bien se cuida la reina!");
    AddFood("pollo con patatas","un plato de",10,15,0,"Te chupas los dedos.");
    AddFood("cerdo","un trozo de",12,11,0,"Justo en su punto.");
    AddSpecial("tarta al whisky","una porción de",5,2,10,0,0,"Digna de los dioses.");
}
