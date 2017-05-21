        /*Viejo para la plaza de Nandor */
        /*(c) Nemesis 1997
	* [n] Castellanizado. (Oct'02)
	      Ya puestos, le cambio el nombre.
	*/
        /* Articman 05/12/02
             Añadido un AddQuestion sobre el quest de Guennir
             Juraría que esto ya lo hice en su día...
             Y ya de paso arreglados un par de fallos ortográficos
			 

        */
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetStandard("Uthur", "humano", 11, GENDER_MALE);
    SetShort("Uthur");
    SetLong("Es un anciano de cara amable, barba poblada y nariz chata.\n Parece "
    "un viejete entrañable, seguro que será un buen abuelo.\n Quizá le puedas preguntar "
    "algo sobre los caminos y la villa.\n");
    AddId(({"uthur","anciano", "viejo", "viejete"}));
    AddQuestion(({"villa","noble villa"}),
        "Uthur dice: 'Se llama Nandor, aunque antes tenía otro nombre, ya que "
        "aquí vivían elfos, Noseque-nin. Nunca he comprendido los nombres élficos. En "
        "fin, cuando esto se convirtió en una pradera, los elfos se marcharon y sólo "
        "dejaron ruinas. Entonces, hace unos 2 siglos, nuestros antepasados vinieron "
        "y la reconstruyeron por completo. Desde entonces nos dedicamos a cultivar la "
        "tierra y a criar animales. No somos ricos, pero vivimos bien y los nobles del "
        "castillo no piden demasiado.'\n");
    AddQuestion(({"camino oeste", "camino del oeste", "oeste"}),
        "Uthur dice: '¿El camino del oeste?. Va hacia la colina donde se asienta "
        "el castillo de nuestro señor, y luego más allá, siguiendo el camino del norte "
        "de Marhalt se llega al bonito pueblo de Enalel.\n");
    AddQuestion(({"camino del este", "camino este", "este"}),
        "Uthur dice: '¿El camino del este?. Ese camino te lleva hacia la región de "
        "Sherek, con sus gentes, su cantera y su abadía.\n Pero antes pasas nuestro "
        "cementerio, donde deberás de tener mucho cuidado, y a mitad de camino verás "
        "un cruce que te lleva a unas ruínas muy antiguas.'\n");
    AddQuestion(({"camino sur", "camino del sur", "sur"}),
        "Uthur dice: 'Ese camino va hacia el sur, ¿qué mas necesitas saber?'\n");
  AddQuestion("cementerio",
        "Uthur te dice asustado: 'No lo visites de noche. Muchos lo han hecho y "
        "no han vuelto. Dicen que se oyen extraños ruidos y algunas sepulturas han "
        "aparecido profanadas.'\n");
    AddQuestion(({"Guennir","guennir","bardo guennir","bardo Guennir"}),
        "Uthur dice: 'El pobre de Guennir... hace un rato lo vi andando muy triste "
        "camino del bosque, no sé hacia dónde iba.'\n");
    InitChats(2,({"Uthur dice: '¡Ah! ¿Recordáis cuando eramos jóvenes?'\n",
        "Uthur dice: 'hay  que ver lo que ha prosperado la aldea en los últimos tiempos.'\n",
        "Uthur dice: Mmmm... Yo diría que este año va a ser muy seco.\n"
        "Podríamos ir a tomarnos unos vinitos a la tasca.\n"}));
    InitAChats(10,({
        "Uthur gruñe: '¡Qué juventud! ¡En mis tiempos te ibas a enterar! ¡Gamberro!'\n",
        "Uthur grita: ¡Maldición!\n"}));
    SetCitizenship("nandor");
}
