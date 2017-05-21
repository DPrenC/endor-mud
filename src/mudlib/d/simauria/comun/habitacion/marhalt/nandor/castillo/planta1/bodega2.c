// bodega2.c
//La bodega del castillo...


#include "./path.h"
#include <moving.h>
#include <door.h>
#include <properties.h>
inherit SIM_ROOM;

buscar_algo(str) {

    object ob,tiene,esta;

    if (!str)
        write("Primero deberias decidir si vas a buscar un vino o un licor...\n");
    else {
        if (str!="vino" && str!="licor") write("No hay ningun "+str+" por aqui.\n");
        else {
            tiene=present("pcn",TP);
            esta=present("pcn",TO);
            if (tiene||esta) {
                if (tiene) write("Decides no llevarte nada más, no conviene tentar la suerte.\n");
                else write("Parece que alguien ya ha hecho el trabajo por ti...\n");
            }else {
                if (str=="vino") {
                    write("Encuentras una botella de vino interesante...\n");
                    ob=clone_object(BEBIDA("vino"));
                    ob->SetTipo(d3(), d2());
   // d3 para el tamaño(pequeño, mediano o grande), y d2 para la forma (cuadrada o redonda)
                    ob->move(TO,M_SILENT);
                }
                if (str=="licor") {
                    write("Encuentras una botella de licor interesante...\n");
                    ob=clone_object(BEBIDA("licor"));
                    ob->move(TO,M_SILENT);
                }
            }
        }
    }
    return 1;
}


init() {
    ::init();
    add_action("buscar_algo","buscar");
 }

create () {
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("la bodega del castillo");
    SetIntLong("Te encuentras en la bodega del castillo, donde se guardan parte "
    "de los más apreciados tesoros de los Des-blain.\n Hay todo tipo de vinos y licores, "
    "distribuidos en altas estanterías. Cientos de toneles se apilan unos encima de "
    "otros cubriendo lo largo y alto, de norte a sur,  de la pared oeste.\n  Hacia "
    "el norte están las escaleras que suben a las cocinas.\n");

    SetIntSmell("Huele a humedad.\n");
    AddDetail(({"botellas", "vinos", "licores"}),
    "Hay de todos los tipos. Tienes la sensación de que si te llevaras algo "
    "nadie se iba a dar ni cuenta... Solo es cuestion de BUSCAR...\n");
    AddDetail(({"toneles", "barriles", "pared oeste", "pared del oeste"}),
    "Son enormes toneles en los que cabrían sin ningún problema varias personas "
    "juntas, están apilados de manera horizontal, por lo que la multitud de tapas "
    "circulares, confieren un aspecto curioso a la pared del oeste.\n");

    AddExit("norte", "./bodega");
    AddExit("sur", "./sala_ero");
    AddDoor("sur", "una vieja puerta",
    "Es una destartalada puerta de madera vieja y negra, posiblemente no lleve a "
    "ningún lugar importante.\n", ({"puerta", "vieja puerta", "puerta vieja",
        "puerta de madera"}), "anillo_noble",
        ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    AddDetail(({"cerradura", "cerradura de la puerta", "cerradura de puerta"}),
    "La puerta tiene una extraña cerradura cuadrada.\n");
}
