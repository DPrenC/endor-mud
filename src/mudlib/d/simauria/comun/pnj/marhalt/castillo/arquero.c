/****************************************************************************
Fichero: arquero.c
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
    SetStandard("un arquero", "humano", ([GC_LUCHADOR:23+d6()]),  GENDER_MALE);
    SetShort("un arquero");
    switch(d3())
    {
        case 1:
            SetLong("Es un humano jóven de aspecto famélico, aunque sus ojos oscuros "
            "de mirada rapaz explican el por qué de que se encuentre en el castillo con "
            "un arco y un carcaj colgados del hombro en vez de estar arando en los campos de sol a sol.\n");
            break;
        case 2:
            SetLong("Por su aspecto éste debe de ser uno de los arqueros mas veteranos "
            "del castillo, a juzgar por las arrugas que recorren su rostro demacrado, "
            "sus ojos cansados aunque no por ello menos atentos y la forma familiar en "
            "que porta su arco y el carcaj.\n");
            break;
        case 3:
            SetLong("Un hombre de poblada barba y mirada huraña. Sus manos de dedos "
            "largos están recubiertas de cayos y rozaduras debido al continuo uso del arco.\n"
            " En sus robustos hombros lleva colgados tanto su inseparable arco como "
            "el necesario carcaj.\n");
            break;
    }
    SetLong(QueryLong()+
    "Los arqueros del castillo son campesinos escogidos a este efecto por ser "
    "rápidos, tener vista aguda y sobretodo puntería con el arco. El señor de "
    "la villa suele mandarlos también a patrullar los lindes de los bosques de "
    "la zona, o a espiar posibles fuerzas enemigas.\n");
    AddId(({"arquero", "humano", "hombre", "guardia_castillo_nandor", "guardia"}));
    SetAlign(180);
    SetWhimpy(30);
    InitChats(3, ({"El arquero te mira de arriba a abajo.\n",
        "El arquero tamborilea con los dedos sobre su arco.\n",
        "El arquero se reacomoda el carcaj en la espalda.\n",
        "El humano dice: en cuanto me releven bajaré a tomar unas cervezas en la posada "
        "y tal vez le pueda hechar el guante a una de esas aldeanas "
        "jóvenes de apetitosas carnes.\n",
        "El arquero comenta: parece que mi señor Rocher está preparando un ataque contra "
        "los malechores de Cored, aunque temo que no seamos suficientes para asaltar "
        "su guarida.\n",
        "El arquero te vigila disimuladamente.\n",
        "El  arquero te pregunta: ¿Te ha dado permiso mi señor para andar "
        "libremente por el castillo?\n"}));
    InitAChats(13, ({"El arquero grita: ¡No saldrás vivo de aquí, pronto estarás rodeado de "
    	  "hombres armados ¡Te haremos picadillo!\n",
    	  "El hombre gruñe frenéticamente: Te envía Cored, verdad?\n",
    	  "El humano grita: ¡A mí, camaradas!\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El  arquero se prepara para el combate mientras grita:\n ¡Por "
    "mi señor Rocher! ¡Por Nandor!\n");
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
    "El arquero se pasa la lengua por los labios.\n"
    "El hombre te susurra: Ah, es bella como la diosa Valevisa, daría cualquier cosa "
    "por compartir su lecho una noche, pero su padre me colgaría de las almenas en el "
    "mejor de los casos, o me despellejaría vivo en el peor.\n", 1);
    AddQuestion(({"su señor", "señor", "Rocher", "rocher"}), "el arquero adopta una postura "
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
    SetShrugMsg("El hombre te mira con cara de malas pulgas y grita: ¿y yo que sé?\n");
    SetIVision(0);
    AddItem(ARMANANDOR("daga"), REFRESH_REMOVE, SF(wieldme));
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("azmodan/cuero"), REFRESH_REMOVE, SF(wearme),
    ([P_LONG: "Es una cota de resistente cuero endurecido con un par de cortas "
      "mangas que protegen la parte superior de los brazos. Está cubierta por tachones "
      "y argollas de hierro para ofrecer mayor resistencia a los golpes.\n"]));
    AddItem("/obj/arco", REFRESH_REMOVE,
    ([P_LONG: "el arco es el arma de proyectiles por antonomasia, utilizado por casi "
        "todas las razas de simauria tanto en la caza como en la guerra.\n Este en "
        "particular, es de tamaño medio y fabricado con una sola pieza de madera "
        "cuyo origen no podrías precisar.\n  los extremos en los cuales se ajusta la "
        "cuerda son metálicos para evitar que la pieza se deteriore por el uso. En la "
        "parte media tiene una pequeña acanaladura para facilitar la colocación de las "
        "flechas.\n",
        P_SHORT: "un arco"]));
    AddItem("/obj/carcaj", REFRESH_REMOVE);
    if(d2()==1)
        AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":random(3),"cobre":d10()])]));
    Set(P_CANT_STEAL, "Podrías meterte en un buen lío.\n");
    Set(P_CANT_LURE,1);
}
