#include "./path.h"
inherit ROOM;
static void SetDesc();

SetDesc()
{
    switch (random(4))
    {
        case 0:
            return(SetIntLong("Te encuentras en un sendero entre las monta�as y el bosque de "
                "Kenton.\n"));
        break;
        case 1:
            return(SetIntLong("El camino sigue el curso del r�o en direcci�n sur-sudeste hasta "
                "el bosque de Kenton.\n"));
        break;
        case 2:
            return(SetIntLong("Las grandes monta�as de Kha-annu resguardan el camino entre "
                "Kha-annu y el bosque de Kenton, y junto al r�o hacen la traves�a agradable y "
                "segura de asaltantes.\n"));
        break;
        case 3:
            return(SetIntLong("Este sendero te permite viajar desde Kha-annu hasta el bosque de "
                "Kenton siguiendo la traves�a del r�o Kilok.\n"));
        break;
    }
}

int detalles()
{
    AddDetail(({"camino","travesia","traves�a"}),"Lleva desde Kha-annu hasta Kenton y esta "
        "empedrado.\n");
    AddDetail(({"rio","r�o","r�o kilok","r�o guat-kilok","el r�o"}),"Es el r�o Guat-Kilok, que "
        "nace en las monta�as de Kha-annu.\n");
    AddDetail(({"monta�as","monta�as de kha-annu","cordilleras","montanyas","montanyas de "
        "kha-annu"}),"Son las grandes monta�as de Kha-annu, unas incre�bles cordilleras.\n");
    return 1;
}
