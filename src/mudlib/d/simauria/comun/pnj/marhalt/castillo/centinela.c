/****************************************************************************
Fichero: centinela.c
Autor: Ratwor
Fecha: 03/12/2007
Descripción: El guardia de la puerta del castillo.
****************************************************************************/
#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;
inherit GUARD;
create()
{
    "*"::create();
    SetStandard("un centinela", "humano", ([GC_LUCHADOR:28+d6()]),  GENDER_MALE);
    SetShort("Un centinela");
    switch(d2())
    {
        case 1:
            SetLong("Es un humano no muy alto, pero de cuerpo fornido y cara ceñuda en la "
            "que exhibe el enorme costurón de una fea herida mal cicatrizada que le "
            "recorre toda la parte baja de la boca, creando casi un segundo mentón de "
            "malsano aspecto. No parece muy contento de su puesto como centinela a las "
            "puertas de la fortaleza.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos jóvenes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su misma gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su señor a cambio de un pobre rancho, un "
            "jergón de paja y algunas monedas de cobre.\n");
            break;
        case 2:
            SetLong("Es un guardia humano de rostro macilento y aspecto cansado, "
            "seguramente debido todo ello a la falta de sueño y al magro rancho del que "
            "se alimenta. No parece muy contento de su puesto como centinela a las "
            "puertas de la fortaleza.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos jóvenes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su propia gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su señor a cambio de un pobre llantar, un "
            "jergón de paja y algunas monedas de cobre.\n");
            break;
    }
    AddId(({"centinela", "guardia", "humano", "hombre"}));
    SetWeight(82100);
    SetAlign(80);
    SetWhimpy(10);
    Set(P_CANT_LURE,1);
    InitChats(5, ({"El guardia se apoya en su alabarda con hastío.\n",
        "El guardia se urga distraídamente la nariz y pega algo en el muro.\n",
        "El guardia dice: ¡Fuera de aquí, escoria!\n",
        "El guardia se aparta un poco el casco y se rasca la cabeza grasienta.\n",
        "El guardia dice: en cuanto me releven bajaré a tomar unas cervezas en la posada "
        "y tal vez le pueda hechar el guante a una de esas aldeanas "
        "jóvenes de apetitosas carnes.\n",
        "El guardia comenta: parece que mi señor Rocher está preparando un ataque contra "
        "los malechores de Cored, aunque temo que no seamos suficientes para asaltar "
        "su guarida.\n",
        "El guardia te vigila mientras apresta su alabarda.\n"}));
    InitAChats(16, ({"El guardia grita: ¡A las armas! ¡Tratan de penetrar en el "
        "castillo! ¡Trancad el portón!\n",
    	  "El guardia grita: Maldito vagabundo, pagarás tu osadía con la vida!\n",
    	  "El guardia empuña con ambas manos su alabarda a la altura del pecho usándola "
    	  "a modo de lanza.\n",
    	"El guardia gruñe frenéticamente: Te envía Cored, ¿verdad?\n",
    	  "El guardia lanza un tajo con su alabarda.\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El guardia se lanza al ataque mientras grita: ¡ah! ¿Con que "
    "Tratando de abrirse paso hasta el castillo a golpes eh? ¡Yo te enseñaré lo que "
    "es bueno! ¡Por mi señor Rocher que lo pagarás caro!\n");
    SetIVision(0);
    AddQuestion(({"aldeanas", "jóvenes", "mujeres"}), "El guardia ríe mientras dice: Sí, "
    "muchas de las campesinas de la aldea merecen algo mas que una segunda mirada. Había "
    "una... Tamara creo que se llamaba, de cabellos de fuego y mirada cautivadora pero "
    "he oído decir que se fugó con un bandido. Una verdadera lástima, nunca perdíamos la "
    "oportunidad de admirarla cada vez que alguno de nosotros bajaba hasta el pueblo, "
    "aunque ninguno consiguió sorprenderla sola... como digo, una "
    "lástima.\n La esposa de uno de los viejos que suelen zanganear en la plaza no está "
    "nada mal, aunque ninguna se puede comparar con la hija de nuestro señor.\n");
    AddQuestion(({"hija", "sherilin", "Sherilin"}),
    "El guardia mira nerviosamente a su alrrededor.\n"
    "A continuación se te acerca y te susurra: Sí, la hija de nuestro señor Rocher..\n"
    "Se pasa la lengua por los labios.\n"
    "El hombre te susurra: Ah, es bella como la diosa Valevisa, daría cualquier cosa "
    "por compartir su lecho una noche, pero su padre me colgaría de las almenas en el "
    "mejor de los casos, o me despellejaría vivo en el peor.\n", 1);
    AddQuestion(({"su señor", "señor", "Rocher", "rocher"}),
    "el hombre adopta una postura "
    "marcial mientras dice: Mi señor Rocher Dhes-Bláin es un gran guerrero y un hombre "
    "justo, digan lo que digan esos campesinos. Cuando yo era jóven me eligió de entre "
    "los aldeanos por mi fuerza y valor para servirlo, y gracias a él llevo la vida de "
    "un hombre de armas, en vez de estar segando trigo como un esclavo sin hombría.\n"
    "Es heredero de una larga línea de guerreros, y si no fuera por su defensa de la "
    "frontera norte de nuestro reino, tiempo ha que los malhechores de Cored y las "
    "criaturas de las montañas habrían devastado éstas tierras y avanzado hasta Ihstria.\n");
    AddQuestion(({"Cored", "bandidos", "malhechores", "guarida"}), "El hombre te dice: \n"
    "Al nordeste de aquí se encuentra un espeso bosque. No son buenas tierras de cultivo "
    "así que  a nadie se le ocurrió desbrozarlo y se mantuvo como reserva de caza para "
    "los Dhes-Bláin. Sin embargo, a medida que el reino se fue recuperando de las "
    "guerras, se comenzó a dar caza a todos aquellos que se saltaban las leyes: "
    "ladrones, bandidos, mercenarios, y gentuza de toda calaña que halló en éste bosque "
    "un refugio seguro. Entonces, nadie sabe de donde, apareció el peor de todos.\n"
    "Se hacía llamar Cored y en poco tiempo se erigió en cabecilla supremo, "
    "reconstruyó una antigua fortaleza abandonada siglos atrás convirtiéndola en su "
    "guarida, y estableció una fuerte disciplina en la banda, eligiendo a sus capitanes "
    "entre los mas hábiles de sus secuaces.\n"
    "Desde entonces no ha dejado de lanzar incursiones desde Enalel hasta Nandor, y en "
    "no pocas ocasiones hemos trabado batalla con sus hombres, aunque no tiene "
    "escrúpulos en incorporar orcos en sus filas.\n", 1);
    SetShrugMsg("El guardia te mira con cara de malas pulgas y grita: ¿y yo que sé?\n"
     "¡Ahórrate tus preguntas estúpidas, o te encerraré en los calabozos!\n");
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddItem(ARMANANDOR("alabarda"), REFRESH_REMOVE, SF(wieldme));
    if(d2()==1)
            AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["cobre":random(10),"plata":d6()])]));
}
