#include "path.h"
inherit SIM_ROOM;

void describe()
{
    string str;
    switch (d4())
    {
        case 1:
            str="Te hallas en el camino que une el valle de Sherek con la cima de la montaña del "
                "mismo nombre.\nEs un camino empinado, que trata de cubrir la distancia más corta "
                "entre ambos puntos.\n";
        break;
        case 2:
            str="Estás en el único camino que accede a la abadía de los monjes de Sherek, y que "
                "desciende por la montaña hasta el camino que une el valle con las lejanas tierras "
                "de Marhalt, muy al oeste.\n";
        break;
        default:
            str="Éste es el camino que comunica las tierras del valle de Sherek con la abadía de "
                "los monjes, situada en lo más alto de la montaña.\n";
        break;
    }
    SetIntLong(str);
    return;
}
              
create()
{
    ::create();
    SetLocate("la montaña de Sherek, camino a la abadía");
    SetIntShort("un camino de montaña");
    describe();
    if (d4()==1) AddItem(PNJ("camino/aveboske"),REFRESH_DESTRUCT,1);
    }
