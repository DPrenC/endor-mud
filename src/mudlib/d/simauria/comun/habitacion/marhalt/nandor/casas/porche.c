/****************************************************************************
Fichero: porche.c
Autor: Ratwor
Fecha: 04/11/2006
Descripci�n: el porche de una casa en la calle Narwhald.
****************************************************************************/


#include "./path.h"
inherit SIM_ROOM;

public string f_calle(){
    object calle = find_object(MARH("nandor/calle11"));
    if (!calle){
        write("La calle est� adornada con unos bonitos guijarros en el suelo y "
        "distintas plantas que le dan colorido y alegr�a al entorno.\n");
        return "";
    }else{
    write("La calle est� adornada con unos bonitos guijarros en el suelo y "
        "distintas plantas que le dan colorido y alegr�a al entorno.\n" +
        calle->Content());
        return "";
    }
}

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetPreIntShort("bajo");
    SetIntShort("el porche de una casa");
    SetIntLong("Est�s bajo el techo del porche de la vivienda que tiene su puerta al "
        "norte y que parece estar cerrada.\n Ciertamente est� todo algo destartalado y"
        " sucio, posiblemente no habr�n barrido en algunos meses.\n Desde aqu� se ve muy "
        "bien la calle Narwhald al sur y las personas que por all� transitan.\n");
    SetSunBright(50); // Probemos a ver si funciona...
    SetIntSmell("Hasta aqu� llegan los olores de las plantas de la calle Narwhald.\n");
    SetIndoors(0); // No tengo muy claro si un porche debe ir cubierto o descubierto.
    AddDetail("suelo","Est� todo lleno de polvo.\n");
    AddExit("sur",MARH("nandor/calle11"));
        AddExit("norte",(:write("La casa est� cerrada, mejor no entrar por si te ve alguien"
        ".\n"),1:));
    AddDetail(({"calle", "calle Narwhald", "sur", "calle narwhald"}), SF(f_calle));
    AddDetail(({"gente","personas"}), "Caminan tranquilamente admirando la calle "
    "Narwhald.\n");
    AddDetail(({"plantas", "planta", "macetero", "maceteros"}), "Desde aqu� no se "
        "aprecian muy bien, aunque alegran la calle de todas formas.\n");
    AddItem(PNJ("marhalt/loca_nandor"),REFRESH_DESTRUCT,1);
}
