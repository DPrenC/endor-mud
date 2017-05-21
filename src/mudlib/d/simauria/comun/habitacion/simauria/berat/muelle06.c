/*
DESCRIPCION  : el muelle del puerto
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/muelle06.c
[Ratwor] 02/07/2010 Añado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Estás en el centro del muelle del puerto de Berat.\n Aquí atracan todo "
    "tipo de barcos de mercancías, debido a que Berat es un punto de paso obligado "
    "hacia Ishtria Capital, y por tanto una constante entrada de comercio.\n El "
    "muelle continúa de este a oeste, mientras que al norte se puede ver un solar "
    "abandonado lleno de maleza.\n");
    AddDetail(({"solar", "solar abandonado", "maleza"}), "Al norte tan solo hay un "
    "simple solar abandonado lleno de maleza. Quizá en el pasado había ahí construida "
    "alguna otra taberna.\n");
    AddDetail("puerto",
 "El puerto está construido sobre las rocas de la costa de la bahía y de él sale"
" el muelle donde se amarran las barcas de pesca. El puerto continua tanto hacia"
" el este como al oeste. Hacia el este está la zona de carga, mientras que "
" al oeste se encuentran las instalaciones destinadas a pasajeros.\n");

    AddDetail("muelle",
    "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
    "que se hunden en el mar apoyándose en su fondo. Tiene una serie de amarres donde "
    "los pescadores pueden atar sus barcas.\n");

    AddDetail(({"barcas","las barcas"}),"En el muelle están amarradas las barcas de "
    "varios pescadores.\n");
    AddDetail(({"mar", "agua", "el mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");

    SetIntNoise("Oyes a las olas chocar contra el muelle.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("Berat");
    SetIndoors(0);
    AddExit("este","./muelle07");
    AddExit("oeste","./muelle05");
    AddExit("norte", "./cpuerto");
    HideExit("norte",1);
    AddRoomCmd("subir", "cmd_subir");
    
    if(d3()==1)
        AddItem(THING, REFRESH_DESTRUCT, ([P_SHORT: "un barco mercante",
            P_LONG: "Es uno de los tantos barcos mercantes que amarran en el puerto de "
            "Berat para descargar sus mercancías.\n",
            P_SIZE: P_SIZE_LARGE, P_WEIGHT: 10000000,
            P_NOGET: "¿Pretendes coger un barco?\n",
            P_IDS:({"barco", "mercante", "barco mercante"})]));

    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

public int cmd_subir(string str){
    if(!str) return 0;
    if(str=="barco" || str=="mercante" || str=="barco mercante")
        return notify_fail("En estos instantes están descargando las mercancías y no se "
        "permite el acceso a nadie que no pertenezca a la tripulación del mercante.\n", 
        NOTIFY_NOT_VALID);
}
