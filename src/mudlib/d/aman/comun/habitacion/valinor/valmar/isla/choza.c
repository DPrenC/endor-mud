/*****************************************************************************************
 ARCHIVO:       choza.c
 FECHA:         17-01-2006
 DESCRIPCIÓN:   Choza en el santuario.
 COMENTARIOS:
*****************************************************************************************/


#include "./path.h"
#include <nightday.h>
inherit BASE_ISLA;
public string mirar_abertura();
public int cmd_abrir(string str);

create()
{
    if(::create()) return 1;


    SetIntShort("una choza");

    SetIntLong("Te encuentras en un cuchitril. Una minúscula cabaña de piedra sólo "
        "iluminada por el fuego. Al fondo puedes ver una cocina de leña y una pequeña "
        "chimenea. El humo se eleva hasta las vigas ennegrecidas y sale a través de una "
        "abertura en el techo. Contra una de las paredes hay un camastro de lana y un "
        "arcón de madera. La entrada está orientada hacia el norte.\n");

    AddDetail("chimenea", "Es una chimenea de piedra, tintada de hollín y tan austera "
        "como el resto de la cabaña. Aún así, es más que suficiente para dar un ambiente "
        "cálido y acogedor. Siempre está encendida, sea cual sea la estación del año.\n");
    AddDetail("fuego", "Una vocecita en tu interior te dice: Si miras al fuego te vas a "
        "hacer pis.\n");
    AddDetail(({"cocina", "cocina de leña"}), "Tiene dos fogones y una puertecilla en la "
        "parte inferior por donde se introduce la leña.\n");

    AddDetail("humo", "Una bocanada de humo sale constantemente por la abertura.\n");
    AddDetail("abertura", SF(mirar_abertura));
    AddDetail(({"vigas", "vigas ennegrecidas"}), "Son simples troncos de árboles.\n");
    AddDetail("techo", "El techo está hecho con maderas y ramas.\n");
    AddDetail(({"arcón", "arcón de madera", "arcon"}), "No es muy grande y está "
        "cerrado.\n");
    AddDetail(({"camastro", "camastro de lana"}), "A simple vista no parece muy "
        "confortable.\n");

    SetIntSmell("Huele a humo.\n");
    SetIntNoise("Escuchas el rumor del fuego.\n");
    SetIndoors(1);
    SetIntBright(20);


    AddRoomCmd("abrir", "cmd_abrir");
    AddExit("norte", "./robledal39_santuario");
    AddDoor("norte", "la puerta de salida",
    "Es una vieja puerta de madera oscura para salir de la choza.\n",
    ({"puerta", "puerta de salida", "puerta sur", "puerta del sur", "puerta vieja"}));
   // AddItem(QUEST_RUNAS("cathrann"), REFRESH_DESTRUCT, 1);
}


public string mirar_abertura()
{
    if (NIGHTDAY->QueryState() == ND_NIGHT)
        return "Puedes ver la oscuridad de la noche através de ella.\n";
    return "Puedes ver una ligera luz que entra por la abertura, aún así no llega a "

           "ilumninar la estancia.\n";

}


public int cmd_abrir(string str){
    if(!str) return 0;
    if (str=="arcon" || str=="arcón" || str=="arcon de madera" || str=="arcón de madera"){
            write("Está cerrado y no ves cerradura por ningún sitio.\n");
            return 1;
        }else {
        if(str=="puertecilla"){
            write("No puedes abrir la puerta de la cocina.\n");
            return 1;
        }
            return 0;
    }

}
