/* Archivo        templo.c
   Autor:         Yalin y Lug
   Fecha:         07/05/006
   Descripción:   templo de la aldea (proyecto)
*/


#include "path.h"
#include <sounds.h>
inherit SHERALD("ceroom");

create ()
{
    ::create();
    SetIntShort("un templo en la aldea de Sloch");
    SetIntLong("Estás ahora en el interior de un templete donde se celebran "
        "los ritos religiosos en la aldea de Sloch. Es muy sencillo y "
        "práctico, no olvidemos que en este lugar vive poca gente y no con "
        "demasiados recursos. Puedes ver un pequeño altar de piedra, una "
        "hornacina con la estatua de la diosa Sherek y, por toda la nave,  "
        "unos bancos desgastados de madera en los que toman asiento los "
        "aldeanos durante el culto.\n");
    SetIntNoise("A penas si escuchas ningún ruido desde aquí.\n");
    SetIntSmell("Huele a cera quemada y a incienso.\n");
    AddDetail(({"hornacina"}), "es una pequeña hornacina colocada tras el "
        "altar, dentro de la cual descansa una pequeña reproducción de la "
        "diosa Sherek.\n");
    AddDetail(({"estatua", "diosa", "sherek"}), "Puedes ver una pequeña "
        "reproducción de la diosa. Permanece hierática, tocada con una tiara "
        "en forma de búho. En su mano y brazo derecho se enrosca una "
        "serpiente, y con la izquierda empuña una daga con la que corta la "
        "cabeza al animal. ¡Da la sensación de ser una escena real!\n");
    AddDetail(({"serpiente", "culebra"}), "Se enrosca, apretando con fuerza,  "
        "sobre el brazo de la estatua ... ¡Parece estar viva!\n");
    AddDetail(({"daga"}), "Es la daga con la que la diosa decapita a la "
        "serpiente en el grupo escultórico que ves. Está tan pulida que da "
        "la sensación de ser de metal.\n");
    AddDetail(({"altar"}), "Como altar hay un extraño bloque de una rara "
        "piedra tan pulida que asemeja cristal.\n");
    AddDetail(({"techo"}), "Es un artesonado de madera bellamente tallado "
        "con dibujos.\n");
    AddDetail(({"tallas", "dibujos"}), "son motivos florales que recorren "
        "todo el artesonado.\n");
    AddDetail(({"paredes", "pared", "muro", "muros"}), "Las paredes son "
        "gruesas y están construidas a base de grandes sillares. En la parte "
        "superior puedes ver unas pequeñas ventanas.\n");
    AddDetail(({"sillar", "sillares"}), "son grandes cubos pétreos. "
        "Conociendo el estilo constructivo del resto de la aldea, da la "
        "sensación que estas piedras fueron traídas de algún otro lugar para "
        "levantar este templo.\n");
    AddDetail(({"ventanas", "ventana"}), "se trata de pequeñas y estrechas "
        "ventanas colocadas en lo alto de las paredes, ya muy cerca del "
        "techo, destinadas a dejar pasar algo de luz al interior.\n");
    AddDetail(({"suelo"}), "Es de piedra, construido con losas regulares.\n");
    AddItem(PNJ("sherek/aldea/sieghen"), REFRESH_DESTRUCT,1);
    AddExit("norte", SHERALD("calles/plazoleta"));
    SetSoundEnvironment(SND_SUCESOS("canon"));
}
