/****************************************************************************
Fichero: arquero.c
Autor: Ratwor
Fecha: 03/12/2007
Descripci�n: un guardia para el castillo.
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
            SetLong("Es un humano j�ven de aspecto fam�lico, aunque sus ojos oscuros "
            "de mirada rapaz explican el por qu� de que se encuentre en el castillo con "
            "un arco y un carcaj colgados del hombro en vez de estar arando en los campos de sol a sol.\n");
            break;
        case 2:
            SetLong("Por su aspecto �ste debe de ser uno de los arqueros mas veteranos "
            "del castillo, a juzgar por las arrugas que recorren su rostro demacrado, "
            "sus ojos cansados aunque no por ello menos atentos y la forma familiar en "
            "que porta su arco y el carcaj.\n");
            break;
        case 3:
            SetLong("Un hombre de poblada barba y mirada hura�a. Sus manos de dedos "
            "largos est�n recubiertas de cayos y rozaduras debido al continuo uso del arco.\n"
            " En sus robustos hombros lleva colgados tanto su inseparable arco como "
            "el necesario carcaj.\n");
            break;
    }
    SetLong(QueryLong()+
    "Los arqueros del castillo son campesinos escogidos a este efecto por ser "
    "r�pidos, tener vista aguda y sobretodo punter�a con el arco. El se�or de "
    "la villa suele mandarlos tambi�n a patrullar los lindes de los bosques de "
    "la zona, o a espiar posibles fuerzas enemigas.\n");
    AddId(({"arquero", "humano", "hombre", "guardia_castillo_nandor", "guardia"}));
    SetAlign(180);
    SetWhimpy(30);
    InitChats(3, ({"El arquero te mira de arriba a abajo.\n",
        "El arquero tamborilea con los dedos sobre su arco.\n",
        "El arquero se reacomoda el carcaj en la espalda.\n",
        "El humano dice: en cuanto me releven bajar� a tomar unas cervezas en la posada "
        "y tal vez le pueda hechar el guante a una de esas aldeanas "
        "j�venes de apetitosas carnes.\n",
        "El arquero comenta: parece que mi se�or Rocher est� preparando un ataque contra "
        "los malechores de Cored, aunque temo que no seamos suficientes para asaltar "
        "su guarida.\n",
        "El arquero te vigila disimuladamente.\n",
        "El  arquero te pregunta: �Te ha dado permiso mi se�or para andar "
        "libremente por el castillo?\n"}));
    InitAChats(13, ({"El arquero grita: �No saldr�s vivo de aqu�, pronto estar�s rodeado de "
    	  "hombres armados �Te haremos picadillo!\n",
    	  "El hombre gru�e fren�ticamente: Te env�a Cored, verdad?\n",
    	  "El humano grita: �A m�, camaradas!\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El  arquero se prepara para el combate mientras grita:\n �Por "
    "mi se�or Rocher! �Por Nandor!\n");
    AddQuestion(({"aldeanas", "j�venes", "mujeres"}), "El hombre r�e mientras dice: S�, "
    "muchas de las campesinas de la aldea merecen algo mas que una segunda mirada. Hab�a "
    "una... Tamara creo que se llamaba, de cabellos de fuego y mirada cautivadora pero "
    "he o�do decir que se fug� con un bandido. Una verdadera l�stima, nunca perdiamos la "
    "oportunidad de admirarla cada vez que alguno de nosotros bajaba hasta el pueblo, "
    "aunque ninguno consigui� sorprenderla sola... como digo, una "
    "l�stima. La esposa de uno de los viejos que suelen zanganear en la plaza no est� "
    "nada mal, aunque ninguna se puede comparar con la hija de nuestro se�or.\n");
    AddQuestion(({"hija", "sherilin", "Sherilin"}),
    "El hombre mira nerviosamente a su alrrededor.\n"
    "A continuaci�n se te acerca y te susurra: S�, la hija de nuestro se�or Rocher..\n"
    "El arquero se pasa la lengua por los labios.\n"
    "El hombre te susurra: Ah, es bella como la diosa Valevisa, dar�a cualquier cosa "
    "por compartir su lecho una noche, pero su padre me colgar�a de las almenas en el "
    "mejor de los casos, o me despellejar�a vivo en el peor.\n", 1);
    AddQuestion(({"su se�or", "se�or", "Rocher", "rocher"}), "el arquero adopta una postura "
    "marcial mientras dice: Mi se�or Rocher Dhes-Bl�in es un gran guerrero y un hombre "
    "justo, digan lo que digan esos campesinos. Cuando yo era j�ven me eligi� de entre "
    "los aldeanos por mi fuerza y valor para servirlo, y gracias a �l llevo la vida de "
    "un hombre de armas, en vez de estar segando trigo como un esclavo sin hombr�a.\n"
    "Es heredero de una larga l�nea de guerreros, y si no fuera por su defensa de la "
    "frontera norte de nuestro reino, tiempo ha que los malhechores de Cored y las "
    "criaturas de las monta�as habr�an devastado �stas tierras y avanzado hasta Ihstria.\n");
    AddQuestion(({"Cored", "bandidos", "malhechores", "guarida"}), "El hombre te dice: \n"
    "Al nordeste de aqu� se encuentra un espeso bosque. No son buenas tierras de cultivo "
    "as� que  a nadie se le ocurri� desbrozarlo y se mantuvo como reserva de caza para "
    "los Dhes-Bl�in. Sin embargo, a medida que el reino se fue recuperando de las "
    "guerras, se comenz� a dar caza a todos aquellos que se saltaban las leyes: "
    "ladrones, bandidos, mercenarios, y gentuza de toda cala�a que hall� en �ste bosque "
    "un refugio seguro. Entonces, nadie sabe de donde, apareci� el peor de todos.\n"
    "Se hac�a llamar Cored y en poco tiempo se erigi� en cabecilla supremo, "
    "reconstruy� una antigua fortaleza abandonada siglos atr�s convirti�ndola en su "
    "guarida, y estableci� una fuerte disciplina en la banda, eligiendo a sus capitanes "
    "entre los mas h�biles de sus secuaces.\n"
    "Desde entonces no ha dejado de lanzar incursiones desde Enalel hasta Nandor, y en "
    "no pocas ocasiones hemos trabado batalla con sus hombres, aunque no tiene "
    "escr�pulos en incorporar orcos en sus filas.\n", 1);
    SetShrugMsg("El hombre te mira con cara de malas pulgas y grita: �y yo que s�?\n");
    SetIVision(0);
    AddItem(ARMANANDOR("daga"), REFRESH_REMOVE, SF(wieldme));
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("azmodan/cuero"), REFRESH_REMOVE, SF(wearme),
    ([P_LONG: "Es una cota de resistente cuero endurecido con un par de cortas "
      "mangas que protegen la parte superior de los brazos. Est� cubierta por tachones "
      "y argollas de hierro para ofrecer mayor resistencia a los golpes.\n"]));
    AddItem("/obj/arco", REFRESH_REMOVE,
    ([P_LONG: "el arco es el arma de proyectiles por antonomasia, utilizado por casi "
        "todas las razas de simauria tanto en la caza como en la guerra.\n Este en "
        "particular, es de tama�o medio y fabricado con una sola pieza de madera "
        "cuyo origen no podr�as precisar.\n  los extremos en los cuales se ajusta la "
        "cuerda son met�licos para evitar que la pieza se deteriore por el uso. En la "
        "parte media tiene una peque�a acanaladura para facilitar la colocaci�n de las "
        "flechas.\n",
        P_SHORT: "un arco"]));
    AddItem("/obj/carcaj", REFRESH_REMOVE);
    if(d2()==1)
        AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":random(3),"cobre":d10()])]));
    Set(P_CANT_STEAL, "Podr�as meterte en un buen l�o.\n");
    Set(P_CANT_LURE,1);
}
