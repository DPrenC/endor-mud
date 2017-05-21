/* Archivo:         granero01.C
* Descripción:      Granero de la granja de la aldea de Sloch.
* Autor: Lug y Yalin.
* Fecha: 18/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("un granero en la granja de la aldea de Sloch");
    SetIntLong("Te encuentras en el interior de un gran almacén donde se "
        "guardan todas las cosechas que se recogen en los campos de la "
        "granja en espera a que sean transportadas a los silos que tienen "
        "los monjes dentro del recinto abadial.\nPor todos lados puedes ver "
        "sacos amontonados, así como aperos para la labranza de los campos.\n");
    SetIntSmell("Huele a cereales y a polvo en suspensión.\n");
    SetIntNoise("No se escucha nada en especial. Los montones de sacos que te "
        "rodean amortiguan casi totalmente cualquier sonido.\n");
    AddDetail(({"suelo"}), "Es de madera y no se puede decir que esté "
        "demasiado limpio.\n");
    AddDetail(({"paredes", "pared"}), "Están formadas por largos maderos que "
        "dejan pasar el aire del exterior ya que están ligeramente separados "
        "entre sí.\nContra ellas se apilan sacos y aperos de labranza.\n");
    AddDetail(({"techo"}), "Está formado por tejas de barro sujetas por "
        "grandes vigas de madera. ¡Te sorprende que en esta zona de simauria "
        "se use la teja!, dado que los techos suelen ser de paja y cañas "
        "cuando son pobres y de pizarras en el resto de los casos.\n");
    AddDetail(({"sacos", "saco"}), "Contienen en su interior los cereales "
        "cosechados que han de ser llevados a los silos de la abadía.\n");
    AddDetail(({"cereal", "cereales"}), "no los puedes ver, ya que están "
        "dentro de los sacos.\n");
    AddDetail(({"apero", "aperos", "herramientas"}), "Son distintos tipos de "
        "herramientas para poder labrar el campo. Toma una si quieres ayudar "
        "en alguna de las tareas.\n");
    AddExit("sur", SHERALD("granja/granja05"));
}
