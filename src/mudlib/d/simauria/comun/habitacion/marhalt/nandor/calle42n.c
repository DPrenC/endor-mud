/* calle42n.c Plaza de Nandor enfrente del Ayuntamiento. */

#include <properties.h>
#include "./path.h"
#include <door.h>
#include <nightday.h>

inherit SIM_ROOM;

create()
{
    ::create();

    SetIntShort("la plaza de Nandor");
    SetLocate("la aldea de Nandor");
    SetIntLong("Est�s en la plaza de Nandor. El suelo est� cubierto de guijarros "
        "redondeados, por debajo de los cuales asoma algo de hierba en algunas zonas.\n"
        " La plaza est� limpia y cuidada. Hay algunos grandes maceteros con flores "
        "que dan color al paisaje.\n  Al norte se halla la casa de tributos "
        "de la villa, y al sur est� la parada de un par de diligencias que recorren toda"
        " Simauria.\n  hacia el oeste puedes escuchar una fuente.\n   Aqu�, una gran encina "
        "proporciona un lugar ideal para que la gente se siente a charlar. Quiz�s por "
        "eso, alguien ha puesto en este lugar algunos bancos de piedra.\n  Al este "
        "de aqu� ves un peque�o templo, y Al nordeste est� el inicio de un callej�n "
        "algo estrecho.\n");
    SetIndoors(0);
    AddDetail(({"maceteros", "macetero"}),"Son grandes cuadrados de piedra bien cuidados"
        " y que parecen reci�n pintados. Han sido construidos sobre el pavimento de "
        "guijarros, y est�n llenos de tierra fina donde crecen flores de distintos "
        "colores que dan m�s vida a la plaza.\n");
    AddDetail("flores", "Las hay de los tipos m�s variados, y dan un toque de color a "
        "toda la plaza.\n");
    AddDetail("bancos",
        "Son unos bancos de piedra. No parecen muy c�modos.\n");
    AddDetail(({"casa de tributos","casa del tributo"}),
        "Es un gran edificio de piedra. Tiene una placa sobre la puerta que pone:"
        "\n\n\t\t\t    'Casa de tributos'\n");
    AddDetail("guijarros","Son guijarros peque�os y redondeados que se han puesto "
        "aqu� para cubrir esta parte del terreno. Debajo parece haber s�lo tierra "
        "delgada.\n");
    AddDetail(({"hierba", "algo de hierba"}), "En algunas zonas del suelo, algunos "
        "matojos de hierba parecen haberse abierto camino entre la tierra cubierta de "
        "guijarros.\n");

    AddItem(OTRO("encina"),REFRESH_REMOVE,1);
    AddExit("nordeste","./calle8");
    AddExit("norte", "./casas/casa4");
    AddExit("sur","./calle42s");
    AddExit("este", "./tiendas/iglesia");
    AddExit("oeste", "./calle41n");
    AddDoor("norte", "la puerta de la casa de tributos",
    "Es la puerta de la casa de tributos, de madera maciza y sin ning�n relieve.\n",
    ({"puerta", "puerta de madera", "puerta de madera maciza", "puerta de la casa de tributos",
        "puerta del norte"}),
        ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
        AddDoor("este", "la puerta del templo",
        "Es una puerta de madera taraceada con tachuelas de bronce deslustrado, hecha "
        "de dos batientes aunque solo se abre uno de ellos, y cuyo marco inferior "
        "forma un escal�n.\n",
        ({"puerta", "puerta de madera", "puerta de madera taraceada", "puerta del templo",
        "puerta del este"}));
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,d3());
}

