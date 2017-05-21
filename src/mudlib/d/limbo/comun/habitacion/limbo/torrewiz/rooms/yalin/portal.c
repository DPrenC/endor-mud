/****************************************************************************
fichero: transporte.c
Autor: Kastwey
Descripción: Sala de teletransporte
****************************************************************************/

#include "path.h"
inherit ROOM;

create()
{
    ::create();
    SetIndoors(1);
    SetIntBright(75);
    SetIntSmell("hueles a incienso. La reina de las hadas presume demasiado.\n");
    SetIntNoise("Escuchas el susurro de los portales de teletransporte.\n");
    SetIntShort("la sala de transporte de Yalin");
    SetIntLong("Te encuentras en la sala de transportes de Yalin.\n"
        "Aquí podrás dirigirte a casi cualquier parte de simauria, gracias a "
        "los numerosos portales de teletransporte situados en toda la habitación.\n");
    AddDetail(({"portales","portal"}),"Son puertas mágicas que te llevan donde quieres ir.\n");
    AddExit("annufam", "/d/kha-annu/comun/habitacion/annufam/ciudad/entrada");
    AddExit("atbalnin",   "/d/lad-laurelin/comun/habitacion/atbalnin/bosque/bosque17");
    AddExit("azzor",      "/d/akallab/comun/habitacion/akallab/azzor/puerto/muelle00");
    AddExit("berat",      "/d/simauria/comun/habitacion/simauria/berat/cprin7");
    AddExit("cored",      "/d/simauria/comun/habitacion/marhalt/fortaleza/senda/senda1");
    AddExit("crowy",      "/d/goldhai/comun/habitacion/bosque_oscuro/alrededor_crowy1");
    AddExit("enalel", "/d/simauria/comun/habitacion/marhalt/enalel/poblado/calles/calle01");
    AddExit("flenton",    "/d/kenton/comun/habitacion/flenton/calles/plaza_00");
    AddExit("gaddaro",    "/d/akallab/comun/habitacion/akallab/azzor/camino/camino11");
    AddExit("goldhai",    "/d/goldhai/comun/habitacion/puerto/muelle2");
    AddExit("gorat",      "/d/simauria/comun/habitacion/caminos/nandor-simauria/puerto");
    AddExit("glucksfall", "/d/goldhai/comun/habitacion/glucksfall/muelle");
    AddExit("khaannu",    "/d/kha-annu/comun/habitacion/kha-annu/ciudad/puertanor/hall2");
    AddExit("koek","/d/simauria/comun/habitacion/simauria/rhoemas/koek/calles/plaza");
    AddExit("krigor", "/d/simauria/comun/habitacion/nyne/krigor/sendero06");
    AddExit("limbo",      "/d/limbo/comun/habitacion/limbo/limbo/camino03");
    AddExit("nandor",     "/d/simauria/comun/habitacion/marhalt/nandor/calle0");
    AddExit("narad",      "/d/akallab/comun/habitacion/akallab/azzor/camino/camino01");
    AddExit("nyne", "/d/simauria/comun/habitacion/caminos/nyne_berat/cam01");
    AddExit("siempreunidos", "/d/lad-laurelin/comun/habitacion/faeria/siempreunidos/calles/calle_01");
    AddExit("sloch","/d/simauria/comun/habitacion/sherek/aldea/calles/plazoleta");
    AddExit("zarkam",     "/d/akallab/comun/habitacion/akallab/zarkam/ciudad/plaza_01");
    AddExit("asesino",    "/guilds/asesinos/gremio");
    AddExit("aventurero", "/guilds/aventurero/aventurero");
    AddExit("conjurador", "/guilds/conjuradores/gremio");
    AddExit("guardabosques","/guilds/guardabosques/gremio");
    AddExit("guerrero",   "/guilds/guerreros/sedes/nandor/sede_nandor");
    AddExit("kisala",     "/guilds/kisalas/habitacion/gremio");
    AddExit("este", TORRE("rooms/yalin/workroom"));
}
