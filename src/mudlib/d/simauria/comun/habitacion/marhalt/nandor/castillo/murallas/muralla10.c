/****************************************************************************
Fichero: muralla10.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
            SetIntLong("Te encuentras sobre el adarbe de la muralla norte del castillo.\n"
    "Al frente se sit�a la ladera menos empinada y accesible de la colina, y mas all� "
    "el gran bosque de Cored. Por todo ello, la muralla fue constru�da en piedra maciza "
    "en sus tres metros de anchura, dotada de unas robustas almenas y rematada en cada "
    "extremo por dos fuertes torreones redondos: el de C�nor al este y el de la "
    "Inmolaci�n al oeste.\n"
    "Aqu� la muralla se curva hacia el norte, adelant�ndose para formar el baluarte de "
    "las puertas. Por la parte interna del muro una estrecha escalera desciende al "
    "patio de armas.\n"
    "Toda la parte norte del castillo, muralla, torreones y puertas, son de "
    "construcci�n mas antigua que el resto de la fortaleza, y detalles como la forma de "
    "las almenas o el tama�o de los bloques y su colocaci�n muy ajustada dan la "
    "impresi�n de que las manos que levantaron esta zona eran mas h�biles y ten�an mas "
    "conocimientos de arquitectura que quienes edificaron el resto del castillo.\n");
    AddDetail("puertas", "Las puertas del castillo se sit�an justo en el centro de la "
    "muralla norte. Se adelantan ligeramente con respecto a la muralla, y la parte alta "
    "est� defendida por una garita volada a cada lado, lo que les da un aspecto de "
    "gran solidez.\n");
    AddDetail("bosque", "Al norte del camino de Marhalt, se extiende el bosque de "
    "Cored, una oscura masa de a�osos �rboles de aspecto ominoso.\n");
    AddDetail(({"colina", "ladera", "declive"}), "Al norte del castillo la ladera de la "
    "colina desciende en un declive poco pronunciado y cubierto de hierba, por el cual "
    "discurre el sendero trillado que al pie de la elevaci�n se une al camino norte de "
    "Marhalt.\n");
    AddDetail("almenas", "Es un fuerte muro de piedra rematado por unos fustes "
    "rectangulares entre los cuales hay huecos para facilitar la defensa de la muralla.\n"
    "El antepecho de esta parte de las almenas, sobresale de forma perceptible hacia "
    "fuera, para dificultar la escalada de qien pretenda penetrar por aqu� en el castillo.\n");
    AddDetail(({"escaleras", "escalera"}), "Una estrecha escalera de piedra algo "
    "deteriorada que comunica el adarbe de la muralla con el patio de armas, justo "
    "frente a una escalera gemela existente en la porci�n de muralla del otro lado de "
    "la puerta.\n"
    "�sta disposici�n obedece al prop�sito de facilitar el r�pido acceso entre lo alto "
    "del muro y el interior de las puertas, de forma que si alg�n enemigo penetra por "
    "ellas se encuentre atacado por ambos flancos por los defensores que bajen por las "
    "escaleras.\n");
    AddExit("este", "./muralla11");
    AddExit("norte", "./muralla09");
    AddExit("abajo", CASTILLO("patio/patio06"));
}


