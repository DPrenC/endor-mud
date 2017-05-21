/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/claustro/estanque.c
Autor: Yalin
Fecha: 03/04/2009 12:25
Descripción: Centro del claustro de la abadía, fichero base.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERAB("std/ext");

create()
{
    ::create();
    SetIntShort("el centro del claustro, ");
    SetIntLong("Justo en el centro del claustro, un magnífico estanque brinda con su visión y "
        "sonido, un remanso de paz y frescura.\nA su alrededor, un círculo de bancos de madera "
        "invita al descanso, mientras que la franja de césped que circunda a éstos, es muy "
        "apropiada para pasear mientras se medita sobre las profundidades del alma.\nMás allá, "
        "los setos de ciprés impiden pasar al resto del claustro, excepto por las cuatro "
        "aberturas que llevan a los arcos de entrada al edificio.\n");
    AddDetail(({"seto","setos","cipres","ciprés","cipreses"}),"Una pared verde formada por "
        "cipreses, muy juntos y recortados a una altura uniforme de 2 metros, aísla el jardín "
        "interior del pórtico exterior del claustro, formando una galería con la pared del "
        "edificio, sólo interrumpida por las 4 aberturas que llevan a los arcos de entrada.\n");
    AddDetail(({"cesped","césped","jardin","jardín"}),"Una corona circular de césped rodea el estanque, formando "
        "una alfombra verde y mullida. En las curvas del seto, puedes ver parterres de flores.\n");
    AddDetail(({"flores","parterres","parterre","plantas","tierra","trapecios"}),"En las curvas "
        "del seto, entre las aberturas de salida, hay unos trapecios de tierra cultivada con "
        "plantas florales de diversos tipos.\n");
    AddDetail(({"carpa","carpas","pez","peces"}),"Son unos bonitos peces de colores, de la familia "
        "de los ciprínidos. Miden entre 60 y 90 centímetros, con una espina dorsal serrada, y "
        "escamas concéntricas y uniformes.\nÉstas deben ser carpas puramente ornamentales, pues "
        "sus colores son muy variados, y no se dan en la especie en libertad.\nVan de aquí para "
        "allá rebuscando hierbas o bichos en el limo, y de tanto en tanto, alguna salta tratando de "
        "coger algún insecto en el aire.\n");
    SetIntNoise("Escuchas el rumor del agua del estanque.\n");
    SetIntSmell("El aroma de la hierba, del agua y los cipreses te llena de satisfacción.\n");
    AddItem(OTRO("sherek/abadia/fuente"));
    AddItem(OTRO("sherek/abadia/banco"));
    SetSoundEnvironment(SND_AMBIENTES("arroyo2"),10);
}

public void notify_leave(mixed to, int method, mixed extra)
{
    object ob=TP || PO;
    int sentado=ob->QueryAttribute("sentado");
    if (sentado)
    {
        object banco=present("banco");
        if (banco) banco->flevantarse();
    }
    ::notify_leave(to, method, extra);
}
        