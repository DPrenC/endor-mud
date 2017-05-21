#include "./path.h"
inherit ROOM;
static void SetDesc();

SetDesc()
{
    switch (random(4))
    {
        case 0:
            return(SetIntLong("Te encuentras en un sendero entre las montañas y el bosque de "
                "Kenton.\n"));
        break;
        case 1:
            return(SetIntLong("El camino sigue el curso del río en dirección sur-sudeste hasta "
                "el bosque de Kenton.\n"));
        break;
        case 2:
            return(SetIntLong("Las grandes montañas de Kha-annu resguardan el camino entre "
                "Kha-annu y el bosque de Kenton, y junto al río hacen la travesía agradable y "
                "segura de asaltantes.\n"));
        break;
        case 3:
            return(SetIntLong("Este sendero te permite viajar desde Kha-annu hasta el bosque de "
                "Kenton siguiendo la travesía del río Kilok.\n"));
        break;
    }
}

int detalles()
{
    AddDetail(({"camino","travesia","travesía"}),"Lleva desde Kha-annu hasta Kenton y esta "
        "empedrado.\n");
    AddDetail(({"rio","río","río kilok","río guat-kilok","el río"}),"Es el río Guat-Kilok, que "
        "nace en las montañas de Kha-annu.\n");
    AddDetail(({"montañas","montañas de kha-annu","cordilleras","montanyas","montanyas de "
        "kha-annu"}),"Son las grandes montañas de Kha-annu, unas increíbles cordilleras.\n");
    return 1;
}
