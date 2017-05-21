/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/claustro/estanque.c
Autor: Yalin
Fecha: 03/04/2009 12:25
Descripci�n: Centro del claustro de la abad�a, fichero base.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERAB("std/ext");

create()
{
    ::create();
    SetIntShort("el centro del claustro, ");
    SetIntLong("Justo en el centro del claustro, un magn�fico estanque brinda con su visi�n y "
        "sonido, un remanso de paz y frescura.\nA su alrededor, un c�rculo de bancos de madera "
        "invita al descanso, mientras que la franja de c�sped que circunda a �stos, es muy "
        "apropiada para pasear mientras se medita sobre las profundidades del alma.\nM�s all�, "
        "los setos de cipr�s impiden pasar al resto del claustro, excepto por las cuatro "
        "aberturas que llevan a los arcos de entrada al edificio.\n");
    AddDetail(({"seto","setos","cipres","cipr�s","cipreses"}),"Una pared verde formada por "
        "cipreses, muy juntos y recortados a una altura uniforme de 2 metros, a�sla el jard�n "
        "interior del p�rtico exterior del claustro, formando una galer�a con la pared del "
        "edificio, s�lo interrumpida por las 4 aberturas que llevan a los arcos de entrada.\n");
    AddDetail(({"cesped","c�sped","jardin","jard�n"}),"Una corona circular de c�sped rodea el estanque, formando "
        "una alfombra verde y mullida. En las curvas del seto, puedes ver parterres de flores.\n");
    AddDetail(({"flores","parterres","parterre","plantas","tierra","trapecios"}),"En las curvas "
        "del seto, entre las aberturas de salida, hay unos trapecios de tierra cultivada con "
        "plantas florales de diversos tipos.\n");
    AddDetail(({"carpa","carpas","pez","peces"}),"Son unos bonitos peces de colores, de la familia "
        "de los cipr�nidos. Miden entre 60 y 90 cent�metros, con una espina dorsal serrada, y "
        "escamas conc�ntricas y uniformes.\n�stas deben ser carpas puramente ornamentales, pues "
        "sus colores son muy variados, y no se dan en la especie en libertad.\nVan de aqu� para "
        "all� rebuscando hierbas o bichos en el limo, y de tanto en tanto, alguna salta tratando de "
        "coger alg�n insecto en el aire.\n");
    SetIntNoise("Escuchas el rumor del agua del estanque.\n");
    SetIntSmell("El aroma de la hierba, del agua y los cipreses te llena de satisfacci�n.\n");
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
        