#include "path.h"
#include <properties.h>
#include <magia.h>
#include <moving.h>
#include <sounds.h>
inherit ROOM;

create ()
{
    ::create();
    SetIntShort("la terraza");
    SetIntLong("Estás en la terraza de la casa de Yalin.\nEs una plataforma que se extiende de este a oeste de la casa, "
        "por la cara sur de la torre, por lo que recibe el sol casi todo el día.\nRodeada en sus tres lados abiertos por "
        "una balaustrada a modo de barandilla, da directamente sobre el mar, varios metros más abajo.\n");
    AddDetail(({"balaustrada","balaustre","balaustres","pilar","pilares"}),"Alineados a lo largo de los tres lados libres "
        "de la terraza, unos pilares o balaustres cuadrados de mármol blanco, se unen formando arcos, que sostienen, a un "
        "metro del suelo, una plancha de 30 centímetros de ancho labrada en la misma piedra.\nPor su centro discurre una "
        "barandilla ornamental de bronce.\n");
    AddDetail(({"barandilla","barrote","barrotes"}),"Sobre la balaustrada, embutiéndose justo sobre cada pilar, una "
        "sucesión de barrotes de medio metro labrados en bronce soporta una labor de pasamanería de forma cilíndrica con "
        "el mismo labrado.\nEn las esquinas, cada uno de los tramos cortos se une al más largo encajando con éste en "
        "sendas columnas de piedra sobre las cuales se ha tallado una cabeza de elfo que mira al interior de la terraza.\n");
    AddDetail(({"elfo","elfos","cabeza","cabezas","cabeza de elfo","cabezas de elfo"}),"Las dos tallas que adornan las "
        "columnas de la barandilla son cabezas de elfo labradas en granito.\n");
    SetIntSmell("Sientes el aire impregnado de salitre y el aroma de los bosques costeros.\n");
    SetIntNoise("Sólo oyes el rumor del mar.\n");
    SetIndoors(0);
    SetSoundEnvironment(SND_AMBIENTES("olas"),30);
    AddExit("norte",TORRE("rooms/yalin/workroom"));
}
