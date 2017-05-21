/* Archivo        templo.c
   Autor:         Yalin y Lug
   Fecha:         07/05/006
   Descripci�n:   templo de la aldea (proyecto)
*/


#include "path.h"
#include <sounds.h>
inherit SHERALD("ceroom");

create ()
{
    ::create();
    SetIntShort("un templo en la aldea de Sloch");
    SetIntLong("Est�s ahora en el interior de un templete donde se celebran "
        "los ritos religiosos en la aldea de Sloch. Es muy sencillo y "
        "pr�ctico, no olvidemos que en este lugar vive poca gente y no con "
        "demasiados recursos. Puedes ver un peque�o altar de piedra, una "
        "hornacina con la estatua de la diosa Sherek y, por toda la nave,  "
        "unos bancos desgastados de madera en los que toman asiento los "
        "aldeanos durante el culto.\n");
    SetIntNoise("A penas si escuchas ning�n ruido desde aqu�.\n");
    SetIntSmell("Huele a cera quemada y a incienso.\n");
    AddDetail(({"hornacina"}), "es una peque�a hornacina colocada tras el "
        "altar, dentro de la cual descansa una peque�a reproducci�n de la "
        "diosa Sherek.\n");
    AddDetail(({"estatua", "diosa", "sherek"}), "Puedes ver una peque�a "
        "reproducci�n de la diosa. Permanece hier�tica, tocada con una tiara "
        "en forma de b�ho. En su mano y brazo derecho se enrosca una "
        "serpiente, y con la izquierda empu�a una daga con la que corta la "
        "cabeza al animal. �Da la sensaci�n de ser una escena real!\n");
    AddDetail(({"serpiente", "culebra"}), "Se enrosca, apretando con fuerza,  "
        "sobre el brazo de la estatua ... �Parece estar viva!\n");
    AddDetail(({"daga"}), "Es la daga con la que la diosa decapita a la "
        "serpiente en el grupo escult�rico que ves. Est� tan pulida que da "
        "la sensaci�n de ser de metal.\n");
    AddDetail(({"altar"}), "Como altar hay un extra�o bloque de una rara "
        "piedra tan pulida que asemeja cristal.\n");
    AddDetail(({"techo"}), "Es un artesonado de madera bellamente tallado "
        "con dibujos.\n");
    AddDetail(({"tallas", "dibujos"}), "son motivos florales que recorren "
        "todo el artesonado.\n");
    AddDetail(({"paredes", "pared", "muro", "muros"}), "Las paredes son "
        "gruesas y est�n construidas a base de grandes sillares. En la parte "
        "superior puedes ver unas peque�as ventanas.\n");
    AddDetail(({"sillar", "sillares"}), "son grandes cubos p�treos. "
        "Conociendo el estilo constructivo del resto de la aldea, da la "
        "sensaci�n que estas piedras fueron tra�das de alg�n otro lugar para "
        "levantar este templo.\n");
    AddDetail(({"ventanas", "ventana"}), "se trata de peque�as y estrechas "
        "ventanas colocadas en lo alto de las paredes, ya muy cerca del "
        "techo, destinadas a dejar pasar algo de luz al interior.\n");
    AddDetail(({"suelo"}), "Es de piedra, construido con losas regulares.\n");
    AddItem(PNJ("sherek/aldea/sieghen"), REFRESH_DESTRUCT,1);
    AddExit("norte", SHERALD("calles/plazoleta"));
    SetSoundEnvironment(SND_SUCESOS("canon"));
}
