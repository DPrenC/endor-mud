#include "path.h"
inherit SIM_ROOM;

void describe()
{
    string str;
    switch (d4())
    {
        case 1:
            str="Te hallas en el camino que une el valle de Sherek con la cima de la monta�a del "
                "mismo nombre.\nEs un camino empinado, que trata de cubrir la distancia m�s corta "
                "entre ambos puntos.\n";
        break;
        case 2:
            str="Est�s en el �nico camino que accede a la abad�a de los monjes de Sherek, y que "
                "desciende por la monta�a hasta el camino que une el valle con las lejanas tierras "
                "de Marhalt, muy al oeste.\n";
        break;
        default:
            str="�ste es el camino que comunica las tierras del valle de Sherek con la abad�a de "
                "los monjes, situada en lo m�s alto de la monta�a.\n";
        break;
    }
    SetIntLong(str);
    return;
}
              
create()
{
    ::create();
    SetLocate("la monta�a de Sherek, camino a la abad�a");
    SetIntShort("un camino de monta�a");
    describe();
    if (d4()==1) AddItem(PNJ("camino/aveboske"),REFRESH_DESTRUCT,1);
    }
