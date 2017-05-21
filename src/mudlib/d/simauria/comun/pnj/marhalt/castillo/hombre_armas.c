/****************************************************************************
Fichero: hombre_armas.c
Autor: Ratwor
Fecha: 03/12/2007
Descripción: un guardia para el castillo.
****************************************************************************/
#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <skills.h>
inherit NPC;
inherit GUARD;
create()
{
    "*"::create();
    SetStandard("un hombre de armas", "humano", ([GC_LUCHADOR:26+d6()]),  GENDER_MALE);
    SetShort("Un hombre de armas");
    switch(d4())
    {
        case 1:
            SetLong("Es un humano más bien bajo, de anchas espaldas y barriga proeminente "
            "que parece a punto de reventar su cota de mallas. Ostenta una larga "
            "cicatriz que engrosa de forma algo repulsiva su ceja derecha y baja, "
            "sesgada, hasta el barbudo mentón.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos jóvenes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su misma gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su señor a cambio de un pobre rancho, un "
            "jergón de paja y algunas monedas de cobre.\n");
            break;
        case 2:
            SetLong("Es un humano de unos cincuenta años y facciones duras cuyo "
            "cabello ya muestra varias hebras grises. Debe de ser uno de los hombres "
            "mas veteranos de la guarnición del castillo, o almenos así lo "
            "demuestran la manera diestra con la que porta sus armas y su "
            "multitud de viejas cicatrices. Al andar cojea ligeramente "
            "de la pierna derecha.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos jóvenes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su propia gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su señor a cambio de un pobre llantar, un "
            "jergón de paja y algunas monedas de cobre.\n");
            break;
        case 3:
            SetLong("Se trata de un humano jóven, de rostro rubicundo y barba de tres "
            "días. Por su juventud, la manera envarada de caminar y su torpeza a la "
            "hora de sostener sus armas como si no supiera muy bien que hacer con "
            "ellas, se  puede deducir que es un hombre de armas recién reclutado "
            "entre los plebeyos de Nandor y sus alrededores.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos jóvenes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su propia gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su señor a cambio de un pobre llantar, un "
            "jergón de paja y algunas monedas de cobre.\n");
            break;
        case 4:
            SetLong("Es un musculoso humano de estatura media. El rostro pálido a medias "
            "rasurado, a medias cubierto de una barba castaña salpicada de restos de "
            "comida, los ojos hinchados y enrrojecidos y su tambaleante caminar "
            "demuestran que su pobre soldada ha sido derrochada en la tasca de Nandor "
            "la noche pasada.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos jóvenes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su propia gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su señor a cambio de un pobre llantar, un "
            "jergón de paja y algunas monedas de cobre.\n");
            break;
    }
    AddId(({"Hombre de armas", "guardia", "humano", "hombre", "guardia_castillo_nandor"}));
    SetAlign(80);
    SetWhimpy(20);
    InitChats(3, ({"El hombre de armas te mira de arriba a abajo.\n",
        "El hombre de armas se urga distraídamente la nariz y pega su hallazgo en el muro.\n",
        "El hombre de armas se aparta un poco el casco y se rasca la sucia cabeza.\n",
        "El humano dice: en cuanto me releven bajaré a tomar unas cervezas en la posada "
        "y tal vez le pueda hechar el guante a una de esas aldeanas "
        "jóvenes de apetitosas carnes.\n",
        "El hombre comenta: parece que mi señor Rocher está preparando un ataque contra "
        "los malechores de Cored, aunque temo que no seamos suficientes para asaltar "
        "su guarida.\n",
        "El guardia te vigila disimuladamente.\n",
        "El hombre de armas te pregunta: ¿Te ha dado permiso mi señor para andar "
        "libremente por el castillo?\n"}));
    InitAChats(20, ({"El hombre de armas grita: ¡A las armas! ¡Nos atacan!\n",
    	  "El guardia grita: ¡No saldrás vivo de aquí, pronto estarás rodeado de "
    	  "hombres armados ¡Te haremos picadillo!\n",
    	  "El hombre gruñe frenéticamente: Te envía Cored, verdad?\n",
    	  "El hombre de armas lanza un golpe poniendo en ello todas sus fuerzas.\n",
    	  "El humano grita: ¡A mí, camaradas!\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El hombre de armas grita:\n ¡Por mi señor Rocher! ¡Por Nandor!\n");
    AddQuestion(({"aldeanas", "jóvenes", "mujeres"}), "El hombre ríe mientras dice: Sí, "
    "muchas de las campesinas de la aldea merecen algo mas que una segunda mirada. Había "
    "una... Tamara creo que se llamaba, de cabellos de fuego y mirada cautivadora pero "
    "he oído decir que se fugó con un bandido. Una verdadera lástima, nunca perdiamos la "
    "oportunidad de admirarla cada vez que alguno de nosotros bajaba hasta el pueblo, "
    "aunque ninguno consiguió sorprenderla sola... como digo, una "
    "lástima. La esposa de uno de los viejos que suelen zanganear en la plaza no está "
    "nada mal, aunque ninguna se puede comparar con la hija de nuestro señor.\n");
    AddQuestion(({"hija", "sherilin", "Sherilin"}),
    "El hombre mira nerviosamente a su alrrededor.\n"
    "A continuación se te acerca y te susurra: Sí, la hija de nuestro señor Rocher..\n"
    "El hombre de armas se pasa la lengua por los labios.\n"
    "El hombre te susurra: Ah, es bella como la diosa Valevisa, daría cualquier cosa "
    "por compartir su lecho una noche, pero su padre me colgaría de las almenas en el "
    "mejor de los casos, o me despellejaría vivo en el peor.\n", 1);
    AddQuestion(({"su señor", "señor", "Rocher", "rocher"}), "el hombre adopta una postura "
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
    SetShrugMsg("El hombre te mira con cara de malas pulgas y grita: ¿y yo que sé?\n"
     "¡Ahórrate tus preguntas estúpidas, o te encerraré en los calabozos!\n");
    SetGoChance(100);
    AddWalkZones(({CASTILLO("murallas"), CASTILLO("patio"), CASTILLO("planta"),
    CASTILLO("mazmorras")}));
    //AddWalkZones(({CASTILLO("murallas/"), CASTILLO("patio/"), CASTILLO("planta")}));
    SetIVision(0);
    switch(d3())
    {
        case 1:
            AddItem(ARMANANDOR("alabarda"), REFRESH_REMOVE, SF(wieldme));
            break;
        case 2:
            AddItem(ARMANANDOR("espada_ancha"), REFRESH_REMOVE, SF(wieldme));
            AddItem(PROTNANDOR("escudo_normal"), REFRESH_REMOVE, SF(wearme));
            break;
        case 3:
            AddItem(ARMANANDOR("lanza_1mano"), REFRESH_REMOVE, SF(wieldme));
            AddItem(PROTNANDOR("escudo_normal"), REFRESH_REMOVE, SF(wearme));
            break;
    }
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddSkill(HAB_ESCUDO, 90, P_DEX);
    if(d2()==1)
            AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":random(3),"cobre":d10()])]));
}
