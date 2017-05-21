/*
DESCRIPCION : Meson del Negro
FICHERO     : posada/meson_negro/cocina.c
MODIFICACION:
16-09-07 [Angor] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("la cocina del mes�n del Negro");
    SetIntLong("En esta parte del mes�n se halla la cocina. La esquina est� ocupada por un "
        "gran horno de le�a del que sale un delicioso olor a pescado asado. Los fogones est�n "
        "sobre un banco de piedra. All� se agolpan los calderos sobre la reja que los separa de "
        "las brasas que los calientan. De una tabla sujeta a la pared cuelgan todo tipo de "
        "cacharros de cocina.\n");
    AddDetail(({"cocina","fuego","fuegos","brasas","fogones"}),"Los fogones son en realidad un "
        "banco de piedra donde se agolpan los calderos. En la parte baja del banco arden "
        "lentamente las brasas. Una reja en la parte alta del banco permite apoyar los "
        "calderos por encima de las brasas.\n");
    AddDetail(({"calderos","caldero"}),"Hay varios sobre las brasas donde se est� cocinando y "
        "otros sin usar colgados de la pared.\n");
    AddDetail(({"horno"}),"Est� en una esquina de la cocina. Es como un gran armario de "
        "ladrillo dividida en dos. En la parte de abajo se quema la le�a que lo calienta. Una "
        "peque�a puerta de metal permite acceder al interior de la parte de arriba donde se "
        "cocina la comida.\n");
    AddDetail(({"tabla","cacharros"}),"De la pared de la cocina cuelga una larga plancha de "
        "madera. En ella se halla clavada una larga hilera de clavos y enganches de los que "
        "cuelgan todo tipo de cacharros, cucharones, jarras, potes, cuchillos, y muchos otros "
        "utensilios que el Negro usa para hacer las comidas. Al estar colgados as�, es "
        "mucho m�s c�modo coger cualquiera de ellos cuando se necesita, que si estuviesen en "
        "alg�n caj�n o armario.\n");
    SetIntNoise("Las brasas del fuego crepitan ruidosamente.\n");
    SetIntSmell("El aire es c�lido y el olor de los calderos tentador...\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    AddItem(PNJ_AZZOR("negro_cocina"),REFRESH_DESTRUCT);
    SetMainRoom("comedor");
    SetLastDest(AZ_PUERTO("portico06"));
    SetNoSchedulerObject(1);
    SetThrowOutMsg("El negro da dos fuertes palmadas y grita:\nVamos, fuera todo el mundo, que "
        "cerramos ya.\n");
    SetNotifyExits(({}));
    SetInformCloseMsg("El negro se asoma al comedor y grita:\n�Koen! �Ve recogiendo, que nos "
        "vamos!\n");
    AddExit("este","comedor");
    AddExit("sur","despensa");
}
