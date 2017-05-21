/*****************************************************************************************
 ARCHIVO:       choza.c
 FECHA:         17-01-2006
 DESCRIPCI�N:   Choza en el santuario.
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

    SetIntLong("Te encuentras en un cuchitril. Una min�scula caba�a de piedra s�lo "
        "iluminada por el fuego. Al fondo puedes ver una cocina de le�a y una peque�a "
        "chimenea. El humo se eleva hasta las vigas ennegrecidas y sale a trav�s de una "
        "abertura en el techo. Contra una de las paredes hay un camastro de lana y un "
        "arc�n de madera. La entrada est� orientada hacia el norte.\n");

    AddDetail("chimenea", "Es una chimenea de piedra, tintada de holl�n y tan austera "
        "como el resto de la caba�a. A�n as�, es m�s que suficiente para dar un ambiente "
        "c�lido y acogedor. Siempre est� encendida, sea cual sea la estaci�n del a�o.\n");
    AddDetail("fuego", "Una vocecita en tu interior te dice: Si miras al fuego te vas a "
        "hacer pis.\n");
    AddDetail(({"cocina", "cocina de le�a"}), "Tiene dos fogones y una puertecilla en la "
        "parte inferior por donde se introduce la le�a.\n");

    AddDetail("humo", "Una bocanada de humo sale constantemente por la abertura.\n");
    AddDetail("abertura", SF(mirar_abertura));
    AddDetail(({"vigas", "vigas ennegrecidas"}), "Son simples troncos de �rboles.\n");
    AddDetail("techo", "El techo est� hecho con maderas y ramas.\n");
    AddDetail(({"arc�n", "arc�n de madera", "arcon"}), "No es muy grande y est� "
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
        return "Puedes ver la oscuridad de la noche atrav�s de ella.\n";
    return "Puedes ver una ligera luz que entra por la abertura, a�n as� no llega a "

           "ilumninar la estancia.\n";

}


public int cmd_abrir(string str){
    if(!str) return 0;
    if (str=="arcon" || str=="arc�n" || str=="arcon de madera" || str=="arc�n de madera"){
            write("Est� cerrado y no ves cerradura por ning�n sitio.\n");
            return 1;
        }else {
        if(str=="puertecilla"){
            write("No puedes abrir la puerta de la cocina.\n");
            return 1;
        }
            return 0;
    }

}
