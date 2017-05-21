/* Fichero: hoz.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: hoz gen�rica para desbrozar matorrales, despejar caminos. .*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA,3,P_SIZE_LARGE,M_HIERRO);
 SetDamType(DT_SLASH);
 SetShort("una hoz");
AddAdjective(({"de", "hierro"}));
 AddId(({"hoz", "herramienta"}));
    SetLong(
    "�sta herramienta suele utilizarse para desbrozar matorrales o podar setos. Est� "
    "formada por un mango de madera aplanado y una hoja cuya �ltimo tercio se curva "
    "hacia dentro. El filo se localiza en la parte c�ncava de la hoja mientras que en la "
    "parte no cortante hay un peque�o gancho que se curva hacia adelante para atrapar o "
    "apartar la maleza y las ca�as permitiendo un uso de la hoz m�s c�modo.\n");
        SetWeight(1800);
        

SetNumberHands(2);
}