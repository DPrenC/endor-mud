/****************************************************************************
Fichero: muralla23.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
            SetIntLong("Te encuentras sobre la muralla del castillo alzada justo al borde del "
    "acantilado en el que acaba la colina por su parte sur. Es un muro estrecho, y algo "
    "ruinoso, pues al estar ubicado en un lugar donde un ataque sería muy improbable "
    "por no decir imposible, fue levantado mas para cerrar el patio de armas por su "
    "extremo sur que como medio de defensa. Algunas piedras de las almenas aparecen "
    "medio sueltas, y el suelo se hunde ligeramente en algunos puntos.\n"
    "Asomandote a las almenas observas la considerable caída que hay hasta los verdes "
    "pastos de Nandor que descienden en una suave pendiente desde el pie de la pared "
    "rocosa hasta las orillas del río Kandal, al sur del cual el terreno se alza en "
    "pedregosos riscos que ascienden al agreste territorio montañoso del suroeste de "
    "Marhalt.\n"
    "La muralla termina al oeste uniéndose a la torre del homenaje, extendiéndose al "
    "este hasta la torre de la Dama. Una vieja escalera de piedra  unen el patio de "
    "armas con el adarbe.\n");
    AddDetail(({"río", "rio", "kandal", "Kandal", "río Kandal"}),
    "El río Kandal procedente del este, limita por el sur las tierras de Nandor, "
    "dirigiéndose hacia el mar al oeste. En su orilla sur se extiende el jóven bosque "
    "de Marhalt, en el que los animales de caza abundan, y un territorio montañoso, "
    "deshabitado y salvaje.\n");
    AddDetail("pastos", "Al pie de la pared de la colina sobre la que se alza el "
    "castillo, se extiende una pradera larga y estrecha que desciende suavemente hasta "
    "la baja orilla del río. Es allí donde los aldeanos de Nandor apacentan sus escasos "
    "animales.\n");
    AddDetail("riscos", "La orilla sur del río Kandal se levanta en una serie de "
    "terrazas y riscos hasta las grandes peñas y barrancos que forman un terreno "
    "anfractuoso y de dificil acceso, en el que nadie suele aventurarse, pues es "
    "imposible precisar que clase de criaturas podrían vivir en tales baldíos.\n");
    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posición cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que éste pueda hacer "
    "nada para evitarlo.\n");
    AddDetail("escalera", "Una empinada escalera de piedra con algunos escalones a "
    "medio derrumbar que une el patio de armas con la muralla sur.\n");
    AddExit("abajo", CASTILLO("patio/patio20"));
    AddExit("este", "./muralla22");
}


