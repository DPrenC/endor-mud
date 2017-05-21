/* La cocina de la casa de Yalin.
Autor: yalin.
Descripci�n: cocina de la casa.
*/
#include "path.h"
#include <properties.h>
#include <magia.h>
#include <moving.h>
inherit ROOM;
inherit PUB;

/* la siguiente funci�n da una respuesta coherente cuando el jugador intenta coger algo del decorado */
public int decor(string str)
{
    if ((str == "fogon") || (str == "fog�n") || (str == "fogones") || (str == "armario"))
    {
        write("No tienes... fuerza suficiente.\n");
        return 1;
    }
    if ((str == "cacharro") || (str == "cacharros") || (str == "cacerola") || (str == "cacerolas") || (str == "sarten") || (str == "sart�n") || (str == "sartenes"))
    {
        write("Todo est� tan bonito y bien colocado, que te da pena tocarlo.\n");
        return 1;
    }
    return 0;
}

/* ahora interceptamos la acci�n abrir, para el armario. */
public int noabre(string str)
{
    if (str == "armario")
    {
        write("Est� cerrado con llave, o tal vez por alguna fuerza que s�lo la cocinera sabe "
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
        "as� como los cacharros, que est�n perfectamente ordenados. Sospechas que la reina de "
        "las hadas no se romper�a las u�as frotando cacerolas y sartenes, ni permitir�a que su "
        "ni�o lo hiciera, as� que te preguntas qui�n les har� la comida.\nJunto a una de las "
        "paredes hay un gran armario.\nEn un rinc�n ves lo que parece ser un mueble velador.\n");
    SetIntBright(50);
    SetIntSmell("huele ligeramente a comida y humo de le�a.\n");
    AddDetail(({"mueble","muebles"}),"�Qu� mueble exactamente?\n");
    AddDetail(({"fogones"}),"Est�n muy limpios y relucientes.\n");
    AddDetail(({"cacharros","cacerolas","sartenes"}),"todo est� pulido y ordenado, mejor no "
        "revuelvas nada.\n");
    AddDetail(({"armario"}),"Un robusto armario de roble, donde se guardar�n probablemente "
        "la vajilla, la cuberter�a y la manteler�a de mesa.\n");
    AddDetail(({"velador","mueble velador"}),"Es una especie de caja con forma de prisma cuadrangular con la superficie "
        "superior recubierta por una placa met�lica en forma de bandeja, y sobre �sta, en la parte posterior ves un cuerpo "
        "cil�ndrico con su parte frontal abierta, por donde se dispensan los alimentos que la cocinera ha dejado preparados "
        "para el consumo.\n�C�mo se conservan? Est�s en la torre de la magia, no preguntes.\nEn la pared, sobre "
        "el mueble, puedes leer el men� disponible.\n");
    Set(P_TPORT,TPORT_NO);
    AddRoomCmd("coger", "decor");
    AddRoomCmd("abrir", "noabre");
    AddExit("este", TORRE("rooms/yalin/pasillo"));
    AddDrink("agua","un vaso de",0,0,10,0,"Lo mejor para la sed.");
    AddDrink("cerveza","una jarra de",3,4,8,0,"Muy refrescante...");
    AddDrink("vino","un vaso de",5,7,5,0,"�De la bodega de los monjes!");
    AddDrink("licor de madro�o","una copita de",5,10,5,0,"Esta chica s� sabe ! �Est� delicioso!");
    AddDrink("aguardiente","un vaso de",5,20,5,0,"�Dios, c�mo pega esto!");
    AddFood("sopa de verduras","un plato de",7,8,0,"mmmm, �de la vega de Gaddaro!");
    AddFood("estofado de ternera","un plato de",9,12,0,"�Hurra por la cocinera!");
    AddFood("cocido simauriano","un plato de",12,20,0,"�Qu� bien se cuida la reina!");
    AddFood("pollo con patatas","un plato de",10,15,0,"Te chupas los dedos.");
    AddFood("cerdo","un trozo de",12,11,0,"Justo en su punto.");
    AddSpecial("tarta al whisky","una porci�n de",5,2,10,0,0,"Digna de los dioses.");
}
