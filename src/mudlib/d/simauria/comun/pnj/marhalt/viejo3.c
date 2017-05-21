        /*Viejo para la plaza de Nandor */
        /*(c) Nemesis 1997
	* [n] Castellanizado. (Oct'02)
	      Ya puestos, le cambio el nombre.
	*/
        /* Articman 05/12/02
             A�adido un AddQuestion sobre el quest de Guennir
             Jurar�a que esto ya lo hice en su d�a...
             Y ya de paso arreglados un par de fallos ortogr�ficos
			 

        */
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetStandard("Uthur", "humano", 11, GENDER_MALE);
    SetShort("Uthur");
    SetLong("Es un anciano de cara amable, barba poblada y nariz chata.\n Parece "
    "un viejete entra�able, seguro que ser� un buen abuelo.\n Quiz� le puedas preguntar "
    "algo sobre los caminos y la villa.\n");
    AddId(({"uthur","anciano", "viejo", "viejete"}));
    AddQuestion(({"villa","noble villa"}),
        "Uthur dice: 'Se llama Nandor, aunque antes ten�a otro nombre, ya que "
        "aqu� viv�an elfos, Noseque-nin. Nunca he comprendido los nombres �lficos. En "
        "fin, cuando esto se convirti� en una pradera, los elfos se marcharon y s�lo "
        "dejaron ruinas. Entonces, hace unos 2 siglos, nuestros antepasados vinieron "
        "y la reconstruyeron por completo. Desde entonces nos dedicamos a cultivar la "
        "tierra y a criar animales. No somos ricos, pero vivimos bien y los nobles del "
        "castillo no piden demasiado.'\n");
    AddQuestion(({"camino oeste", "camino del oeste", "oeste"}),
        "Uthur dice: '�El camino del oeste?. Va hacia la colina donde se asienta "
        "el castillo de nuestro se�or, y luego m�s all�, siguiendo el camino del norte "
        "de Marhalt se llega al bonito pueblo de Enalel.\n");
    AddQuestion(({"camino del este", "camino este", "este"}),
        "Uthur dice: '�El camino del este?. Ese camino te lleva hacia la regi�n de "
        "Sherek, con sus gentes, su cantera y su abad�a.\n Pero antes pasas nuestro "
        "cementerio, donde deber�s de tener mucho cuidado, y a mitad de camino ver�s "
        "un cruce que te lleva a unas ru�nas muy antiguas.'\n");
    AddQuestion(({"camino sur", "camino del sur", "sur"}),
        "Uthur dice: 'Ese camino va hacia el sur, �qu� mas necesitas saber?'\n");
  AddQuestion("cementerio",
        "Uthur te dice asustado: 'No lo visites de noche. Muchos lo han hecho y "
        "no han vuelto. Dicen que se oyen extra�os ruidos y algunas sepulturas han "
        "aparecido profanadas.'\n");
    AddQuestion(({"Guennir","guennir","bardo guennir","bardo Guennir"}),
        "Uthur dice: 'El pobre de Guennir... hace un rato lo vi andando muy triste "
        "camino del bosque, no s� hacia d�nde iba.'\n");
    InitChats(2,({"Uthur dice: '�Ah! �Record�is cuando eramos j�venes?'\n",
        "Uthur dice: 'hay  que ver lo que ha prosperado la aldea en los �ltimos tiempos.'\n",
        "Uthur dice: Mmmm... Yo dir�a que este a�o va a ser muy seco.\n"
        "Podr�amos ir a tomarnos unos vinitos a la tasca.\n"}));
    InitAChats(10,({
        "Uthur gru�e: '�Qu� juventud! �En mis tiempos te ibas a enterar! �Gamberro!'\n",
        "Uthur grita: �Maldici�n!\n"}));
    SetCitizenship("nandor");
}
