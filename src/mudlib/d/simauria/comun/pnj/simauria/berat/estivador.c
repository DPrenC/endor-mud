/****************************************************************************
Fichero: estivador.c
Autor: Ratwor
Fecha: 30/06/2010
Descripción: unos estivadores para el puerto de Berat.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;

create(){
    "*"::create();
    SetStandard("un estivador", "humano", ([GC_LUCHADOR:30+d6()]), GENDER_MALE);
    AddId(({"estivador", "trabajador", "hombre"}));
    SetShort("un estivador");
    SetLong("Es uno de los estivadores que se esfuerzan en los muelles de Verat, "
    "cargando y descargando las mercancías traídas por infinidad de buques "
    "procedentes de tierras lejanas.\n");
    switch(d3()){
        case 1:
            SetLong(QueryLong()+ "En este caso se trata de un individuo de edad "
            "ya avanzada, barba cana y piel curtida por el sol; que hace tiempo "
            "que dejó atrás la juventud, por lo que sus días como trabajador en "
            "el puerto están tocando ya a su fin. Hecho remarcado por su aspecto "
            "fatigado y demacrado, y sus músculos algo caídos.\n");
            break;
        case 2:
            SetLong(QueryLong()+ "Se trata de un jóven de estatura baja, anchos "
            "hombros y  musculoso torso desnudo, que ejerce su trabajo con eficiencia "
            "y rapidez transportando bultos de un lado a otro, ya que el vigor "
            "de la juventud le permite ganarse la vida de esta guisa con relativa "
            "facilidad; pues en el puerto de Verat constantemente se cargan y "
            "descargan mercaderías procedentes de todos los rincones del mundo.\n");
            AddId("joven");
            break;
        case 3:
            SetLong(QueryLong()+ "En este caso se trata de un hombre de estatura "
            "elevada y constitución hercúlea, que parece capaz de mover él solo "
            "el cargamento de un barco. Probablemente se trate de un nórdico "
            "procedente de más allá de la región de Marhalt y los confines del "
            "reino de Simauria, que ha encontrado en Verat una forma sencilla de dar "
            "uso a su descomunal fuerza por unas cuantas monedas.\n");
            break;
    }
    AddQuestion(({"estivador", "estivadores", "ttrabajo"}), 
    "El estivador se detiene un momento apoyando en el suelo su carga y se limpia el "
    "sudor con el antebrazo mientras dice:\n 'Sí, un trabajo duro el de los muelles, "
    "pero no está tan mal pagado como urgar en la tierra como los campesinos de "
    "tierra adentro, y si tienes buenos brazos y espaldas nunca te faltarán unas "
    "monedas con las que pagar techo y llantar.'\n");
    AddQuestion(({"puerto", "berat", "berat", "muelle"}),
    "El estivador dice:\n 'Desde que la ciudad fuera edificada por los supervivientes "
    "de los Verati con ayuda de Ishtria, Verat ha sido un punto clave en el transporte "
    "de personas y mercancías por mar.\n Se sitúa entre las dos grandes ciudades "
    "de Nine al sur, e Ishtria al norte, y puesto que los buques de gran calado "
    "no pueden remontar el río Raxal hasta la capital, éstos dejan sus cargamentos en "
    "Verat.'\n");
    InitChats(4, ({"El estivador dice:\n 'En cuanto acabe mi turno me iré a la "
      "taberna más cercana a por unas cuantas jarras de cerveza... ¡el trabajo seca "
      "el gaznate!'\n",
    "El estivador se frota la espalda con expresión dolorida.\n",
    "El estivador se limpia el sudor de la frente con un gesto rudo del antebrazo.\n",
    "El estivador dice mientras te empuja:\n '¡Aparta de enmedio!, ¡estás estorbando!'\n",
    "El estivador apoya un pesado saco en el suelo mientras toma aliento. Luego "
    "recoge su carga y continúa trabajando.\n",
    "El estivador carraspea con rudeza y escupe al suelo.\n"}));
     
    AddItem(PROT("berat/botas_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/pantalon_ancho"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("berat"); 

} 
 