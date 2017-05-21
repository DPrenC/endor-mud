/****************************************************************************
Fichero: yelmo_noble.c
Autor: Ratwor
Fecha: 25/11/2007
Descripci�n: Un yelmo para el noble de Nandor.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CASCO, 3, P_SIZE_LARGE, M_HIERRO);
    SetShort("un pesado yelmo");
    SetLong("Es un pesado yelmo de hierro que cubre toda la cabeza y parte de la nuca con"
    "dos estrechas rendijas a la altura de los ojos. La parte superior est� formada por"
    "una �nica placa de hierro a la que van soldadas las dos secciones semicirculares que"
    "al unirse forman el cuerpo del casco. La parte posterior se curva ligeramente hacia"
    "atr�s mientras que la parte frontal termina en pico hacia abajo con el fin de"
    "desviar los golpes dirigidos a la garganta.\n"
    "Estos yelmos son muy pesados y estorban los movimientos del cuello y la visi�n de"
    "quien los lleva pero a cambio ofrecen una gran protecci�n.\n"
    "Son habitualmente utilizados por los caballeros y se�ores de la baja nobleza.\n");
    AddId(({"yelmo", "pesado", "casco", "armadura"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(3100);
}
