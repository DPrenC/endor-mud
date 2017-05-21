/*
Fichero: c1_huerto2.c
Autor: Aulë
Fecha: 02/12/2014
Descripción: huerto de la casa.
*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <skills.h>
#include <moving.h>
#include <sounds.h>
inherit BREE_ROOM;

public int subir_manzano(){
    object manzano = load_object(BREE("manzano"));
    int intento=TP->UseSkill(HAB_TREPAR, 10);
    if (query_once_interactive(TP)){
        if (TP->QueryTP()<1)
            return notify_fail("No tienes suficientes energías como para trepar al manzano.\n");
        if (intento> 0){
            TP->move(manzano, M_SPECIAL,
            ({"Se agarra a las ramas inferiores y trepa a lo alto del manzano",
              " trepa al manzano junto a ti...",
              "Te agarras a una de las ramas inferiores y trepas a lo alto del manzano.\n"}));
            TP->AddTP(-d3());
            return 1;
        } else {
            write ("Intentas subir al manzano pero tus pies resbalan sobre la corteza y "
            "caes al suelo.\n");
            say (CAP(TNAME)+" intenta trepar al manzano, pero resbala sobre el tronco y "
            "cae de bruces al suelo.\n");
            tell_room(manzano, CAP(TNAME)+
            " intenta trepar hasta tu posición pero resbala y cae torpemente de bruces.\n");
            TP->Defend(d20(),TD_APLASTAMIENTO,DEFEND_NOMSG);
            TP->AddTP(-d3());
            play_sound(manzano, SND_SUCESOS("caida_fuerte"), 0, 50);
            play_sound(TO, SND_SUCESOS("caida_fuerte"));
            return 1;
        }
    }
}


create()
{
    ::create();
    	SetIntShort("un huerto");
    	SetIntLong(
"Esta pequeña parcela de tierra llana está dedicada al cultivo de algunas hortalizas y "
"verduras para el uso de la casa. La tierra se ve removida, cavada y sin hierbajos y "
"algunas plantas y brotes asoman de la tierra en ordenadas filas. En una esquina hay un "
"gran manzano. Al este ves un patio rodeado de edificios y al oeste un bajo y grueso "
"muro de piedra limita la propiedad.\n");
    	AddDetail("muro",
    	"Es un grueso y bajo muro de grandes piedras que sirve para contener la tierra de "
    	"esta pequeña parcela que ha sido aplanada sobre la ladera inclinada de la colina.\n"
    	"Más al oeste puedes ver una corta pendiente que desciende hasta la empalizada.\n");
    	AddDetail("pendiente",
    	"La pendiente llena de maleza desciende hasta la empalizada que cerca la aldea.\n"
    	"Te das cuenta que un pequeño sendero la jalona por la parte interior.\n"
    	"Un buen salto podría llevarte a este camino.\n");
    	AddDetail("plantas",
    	"Algunas lechugas, repollos, remolachas y unas cuantas hileras de plantas de "
    	"patatas.\n");
    	AddDetail("muro",
    	"Es un grueso y bajo muro de grandes piedras que sirve para contener la tierra de "
    	"esta pequeña parcela que ha sido aplanada sobre la ladera inclinada de la colina.\n"
    	"Más al oeste puedes ver una corta pendiente que desciende hasta la empalizada.\n");
    	AddDetail("pendiente",
    	"La pendiente llena de maleza desciende hasta la empalizada que cerca la aldea.\n"
    	"Te das cuenta que un pequeño sendero la jalona por la parte interior.\n"
    	"Un buen salto podría llevarte a este camino.\n");
    	AddDetail("plantas",
    	"Algunas lechugas, repollos, remolachas y unas cuantas hileras de plantas de "
    	"patatas.\n");
    	AddDetail("manzano",
    	"Un manzano de gran tamaño se iergue en la parte sur del huerto.\n");

    	AddExit("norte", "./c1_huerto1");
    	AddExit("este", "./c1_patio");
    //AddExit(({"trepar","subir","arriba"}), SF(subir_manzano));
    AddExit("arriba", SF(subir_manzano));
    //HideExit(({"subir", "trepar","arriba"}),1);
    HideExit("arriba",1);
AddRoomCmd(({"subir","trepar"}), "subir_manzano");
    AddRoomCmd("coger", "cmd_coger");
    AddRoomCmd("gritar", "cmd_gritar");
    SetIndoors(0);
    AddDetail(({"manzana", "manzanas", "frutos", "fruto"}),
    "Son manzanas de distintos tamaños y en distintos estados de maduración que cuelgan "
    "solas o por grupos de las ramas del manzano.\n");
}

public int cmd_coger(string str){
    string *quecoger = ({"manzana", "manzanas", "fruto", "frutos", "manzanas de manzano",
                         "manzanas del manzano", "manzana de manzano",
                         "manzana del manzano", "fruto de manzano", "fruto del manzano",
                         "frutos de manzano", "frutos del manzano"});
    if (!str) return 0;
    if (member(quecoger, str) >= 0) {
        write("Pegas algunos saltos intentando coger alguna manzana pero están todas fuera de tu alcance.\n");
        say(CAP(TNAME)+ " salta para intentar coger una manzana del manzano pero están demasiado altas.\n");
        return 1;
    }
    return 0;
}

public void init(){
    ::init();
    call_out("merodear",1);
}

public void merodear(){
    object manzano= load_object(BREE("manzano"));
    tell_room(manzano, CAP(TNAME)+ " llega y se para bajo las ramas que tú ocupas.\n");
}

public void notify_leave(mixed to, int method, mixed extra)
{
    ::notify_leave(to, method, extra);
    call_out("irse",1);
}

public void irse(){
    object manzano= load_object(BREE("manzano"));
    if(!present(TP,manzano))
    tell_room(manzano, CAP(TNAME)+" se aleja del manzano.\n",({TP}));
}

public int cmd_gritar(string str){
    object manzano= load_object(BREE("manzano"));
    if (!str){
        tell_room(manzano, "Alguien grita bajo el manzano.\n");
        return 0;
    }else{
        tell_room(manzano, "Alguien grita desde abajo: '"
        +str+"'.\n");
        return 0;
    }
}
