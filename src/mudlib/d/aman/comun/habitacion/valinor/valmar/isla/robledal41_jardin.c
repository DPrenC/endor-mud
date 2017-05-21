/*****************************************************************************************
 ARCHIVO:       robledal41_jardin.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el Jard�n de los Deseos");
    SetIntLong("Te encuentras entre la niebla de un peque�o jard�n, iluminado por cuatro "
        "viejos robles blancos, floreciendo con tal fuerza, que te impide ver siquiera "
        "la luz del sol o la de las estrellas en el cielo. Varias ra�ces asoman del "
        "suelo, formando arcos conc�ntricos en direcci�n sur, sudeste y suroeste.\n");
    AddDetail(({"roble", "robles"}), "Forman los cuatro pilares de la especie de "
        "b�veda bajo la que te encuentras. Son de un blanco n�veo e inocente. No son "
        "demasiado altos, pero su envergadura es tremendamente grande, por lo que las "
        "ramas de los cuatro se entremezclan en una nube espinada.\n");
    AddDetail(({"luz", "estrellas", "sol", "firmamento", "cielo"}), "Miras hacia arriba "
        "y te resulta imposible distinguir cualquier cosa que no sea la b�veda que "
        "forman las blanquecinas ramas entrelazadas.\n");
    AddDetail(({"ra�z", "ra�ces", "raiz", "raices"}), "Emergen de la tierra junto a los "
        "robles, formando arcos en cada una de las salidas.\n");
    AddDetail("suelo", "Una densa capa de hierba azulada tapiza el suelo.\n");
    AddDetail(({"hierba", "hierba azulada"}), "");
    AddDetail(({"arco", "arcos"}), "Las ra�ces se ondulan febrilmente despeg�ndose del "
        "suelo, para, trepando sobre los troncos, llenar de admirables filigranas la "
        "parte m�s alta de los arcos. Est�n especialmente engalanados los que se forman "
        "en la parte sur.\n");
    AddDetail("filigranas", "Son de una finura asombrosa, como labradas en la piedra "
        "o talladas en delicada madera de cerezo.\n");
    AddDetail(({"tronco", "troncos"}), "Son prodigiosamente gruesos. Est�n repletos de "
        "marcas r�nicas y tallas sinuosas que parecen innatas o concebidas mediante "
        "alg�n tipo de magia.\n");
    AddDetail(({"marcas", "marcas r�nicas", "runas", "marcas runicas", "tallas"}),
        "Parece que las huellas de las marcas no han sido realizadas mediante ning�n "
        "objeto extra�o, es como si los robles hubiesen crecido con ellas, sin embargo, "
        "todo lo que te rodea est� tan perfectamente encajado que roza lo "
        "antinatural.\n");
    AddDetail(({"rama", "ramas"}), "Forman un techo tan tupido que te es imposible "
        "distinguir cu�les pertenecen a cada �rbol.\n");
    AddDetail(({"b�veda", "boveda"}), "Tiene su origen en la base de los arcos. Su "
        "aspecto es irregular, aunque el trenzado de las ramas est� ordenado.\n");
    SetIntSmell("Hay un profundo olor a nueces.\n");
    SetIntNoise("Se oye un leve rumor de hojas.\n");
    SetIndoors(0);

    AddExit("sur", HAB_BOSQUE_ISLA("robledal39_santuario.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal40.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal38.c"));
}
