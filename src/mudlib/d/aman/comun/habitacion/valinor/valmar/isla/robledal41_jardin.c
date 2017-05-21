/*****************************************************************************************
 ARCHIVO:       robledal41_jardin.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el Jardín de los Deseos");
    SetIntLong("Te encuentras entre la niebla de un pequeño jardín, iluminado por cuatro "
        "viejos robles blancos, floreciendo con tal fuerza, que te impide ver siquiera "
        "la luz del sol o la de las estrellas en el cielo. Varias raíces asoman del "
        "suelo, formando arcos concéntricos en dirección sur, sudeste y suroeste.\n");
    AddDetail(({"roble", "robles"}), "Forman los cuatro pilares de la especie de "
        "bóveda bajo la que te encuentras. Son de un blanco níveo e inocente. No son "
        "demasiado altos, pero su envergadura es tremendamente grande, por lo que las "
        "ramas de los cuatro se entremezclan en una nube espinada.\n");
    AddDetail(({"luz", "estrellas", "sol", "firmamento", "cielo"}), "Miras hacia arriba "
        "y te resulta imposible distinguir cualquier cosa que no sea la bóveda que "
        "forman las blanquecinas ramas entrelazadas.\n");
    AddDetail(({"raíz", "raíces", "raiz", "raices"}), "Emergen de la tierra junto a los "
        "robles, formando arcos en cada una de las salidas.\n");
    AddDetail("suelo", "Una densa capa de hierba azulada tapiza el suelo.\n");
    AddDetail(({"hierba", "hierba azulada"}), "");
    AddDetail(({"arco", "arcos"}), "Las raíces se ondulan febrilmente despegándose del "
        "suelo, para, trepando sobre los troncos, llenar de admirables filigranas la "
        "parte más alta de los arcos. Están especialmente engalanados los que se forman "
        "en la parte sur.\n");
    AddDetail("filigranas", "Son de una finura asombrosa, como labradas en la piedra "
        "o talladas en delicada madera de cerezo.\n");
    AddDetail(({"tronco", "troncos"}), "Son prodigiosamente gruesos. Están repletos de "
        "marcas rúnicas y tallas sinuosas que parecen innatas o concebidas mediante "
        "algún tipo de magia.\n");
    AddDetail(({"marcas", "marcas rúnicas", "runas", "marcas runicas", "tallas"}),
        "Parece que las huellas de las marcas no han sido realizadas mediante ningún "
        "objeto extraño, es como si los robles hubiesen crecido con ellas, sin embargo, "
        "todo lo que te rodea está tan perfectamente encajado que roza lo "
        "antinatural.\n");
    AddDetail(({"rama", "ramas"}), "Forman un techo tan tupido que te es imposible "
        "distinguir cuáles pertenecen a cada árbol.\n");
    AddDetail(({"bóveda", "boveda"}), "Tiene su origen en la base de los arcos. Su "
        "aspecto es irregular, aunque el trenzado de las ramas está ordenado.\n");
    SetIntSmell("Hay un profundo olor a nueces.\n");
    SetIntNoise("Se oye un leve rumor de hojas.\n");
    SetIndoors(0);

    AddExit("sur", HAB_BOSQUE_ISLA("robledal39_santuario.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal40.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal38.c"));
}
