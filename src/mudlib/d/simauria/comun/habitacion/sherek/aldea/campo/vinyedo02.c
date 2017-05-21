/* Archivo:         vi�edo02.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el oeste y el sur impide el paso el "
        "cauce del r�o Kandal. Al norte un peque�o muro te separa del camino "
        "que te trajo aqu�. Hacia el este contin�an los vi�edos.\n");
    SetIntNoise("Escuchas el fuerte ru�do del agua al correr por entre las "
        "rocas del cauce del r�o Kandal.\n");
    AddDetail(({"rio","r�o","cauce","este","sur"}),"Ves el cauce pedregoso "
        "del r�o Kandal que aqu� hace una pronunciada curva de norte a este. "
        "La corriente baja con fuerza y hace bastante estruendo.\n");
    AddDetail(({"muro","peque�o muro"}),"El muro que separa el vi�edo del "
        "camino est� hecho con un par de sillares de piedra colocados uno "
        "sobre el otro. Es m�s testimonial que otra cosa.\n");
    AddExit("este", SHERALD("campo/vinyedo03"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
