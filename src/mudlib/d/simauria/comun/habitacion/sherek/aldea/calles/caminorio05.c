/* Carchivo:        caminorio05.c
   Autor:           Yalin y Lug
   Descripci�n:     camino que conecta la aldea con el r�o, el lavadero y los vi�edos
   Fecha:           29/05/2006
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el camino hacia el r�o");
    SetIntLong("Est�s en una especie de peque�a plataforma donde termina el camino que baja desde "
    "la aldea de Sloch hacia el r�o Kandal.\nAl suroeste de aqu� puedes ver una peque�a "
    "construcci�n que alberga el lavadero, hacia el norte asciende un camino hacia la aldea y al "
    "este est� laentrada a los vi�edos.\n");
    SetIntSmell("Huele a campo.\n");
    SetIntNoise("Puedes escuchar el sonido del agua en el r�o.\n");
    AddDetail(({"suelo"}), "Est� formado por tierra endurecida de tanto ser "
        "pisada por los viandantes que caminan por aqu�. En algunos lugares "
        "est� salpicado por grandes lajas planas.\n");
    AddDetail(({"laja", "lajas", "piedra", "piedras"}), "son algunas grandes "
        "piedras de color blancuzco que salpican el sendero en el que est�s.\n");
    AddDetail(({"rio", "r�o", "Kandal", "cauce"}), "Es el cauce del R�o "
        "Kandal que pasa encajado entre grandes rocas. Tiene bastante fuerza, "
        "por lo que no ser�a buena cosa caerse aqu� al agua.\n");
    AddDetail(({"suroeste", "lavadero", "construcci�n", "edificaci�n"}), "es "
        "un peque�o cobertizo en cuyo interior est� el lavadero que usan los "
        "habitantes de la aldea.\n");
    AddDetail(({"este", "vi�edos", "vi�edo"}), "Es una peque�a extensi�n de "
        "tierras dedicadas al cultivo de la vid. Las zepas est�n en hileras "
        "y casi a ras del suelo apoyadas en varales para que sea m�s f�cil "
        "recoger el fruto en tiempos de vendimia.\n");
    AddExit("norte", SHERALD("calles/caminorio04"));
    AddExit("suroeste", SHERALD("calles/lavadero"));
    AddExit("este", SHERALD("campo/vinyedo00"));
}
