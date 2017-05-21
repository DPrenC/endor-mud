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
    SetIntShort("la cocina del mesón del Negro");
    SetIntLong("En esta parte del mesón se halla la cocina. La esquina está ocupada por un "
        "gran horno de leña del que sale un delicioso olor a pescado asado. Los fogones están "
        "sobre un banco de piedra. Allí se agolpan los calderos sobre la reja que los separa de "
        "las brasas que los calientan. De una tabla sujeta a la pared cuelgan todo tipo de "
        "cacharros de cocina.\n");
    AddDetail(({"cocina","fuego","fuegos","brasas","fogones"}),"Los fogones son en realidad un "
        "banco de piedra donde se agolpan los calderos. En la parte baja del banco arden "
        "lentamente las brasas. Una reja en la parte alta del banco permite apoyar los "
        "calderos por encima de las brasas.\n");
    AddDetail(({"calderos","caldero"}),"Hay varios sobre las brasas donde se está cocinando y "
        "otros sin usar colgados de la pared.\n");
    AddDetail(({"horno"}),"Está en una esquina de la cocina. Es como un gran armario de "
        "ladrillo dividida en dos. En la parte de abajo se quema la leña que lo calienta. Una "
        "pequeña puerta de metal permite acceder al interior de la parte de arriba donde se "
        "cocina la comida.\n");
    AddDetail(({"tabla","cacharros"}),"De la pared de la cocina cuelga una larga plancha de "
        "madera. En ella se halla clavada una larga hilera de clavos y enganches de los que "
        "cuelgan todo tipo de cacharros, cucharones, jarras, potes, cuchillos, y muchos otros "
        "utensilios que el Negro usa para hacer las comidas. Al estar colgados así, es "
        "mucho más cómodo coger cualquiera de ellos cuando se necesita, que si estuviesen en "
        "algún cajón o armario.\n");
    SetIntNoise("Las brasas del fuego crepitan ruidosamente.\n");
    SetIntSmell("El aire es cálido y el olor de los calderos tentador...\n");
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
    SetInformCloseMsg("El negro se asoma al comedor y grita:\n¡Koen! ¡Ve recogiendo, que nos "
        "vamos!\n");
    AddExit("este","comedor");
    AddExit("sur","despensa");
}
