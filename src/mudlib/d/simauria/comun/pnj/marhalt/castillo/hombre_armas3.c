/****************************************************************************
Fichero: hombre_armas3.c
Autor: Ratwor
Fecha: 16/05/2010
Descripción: pongamos unos hombres de armas en la posada emborrachándose.
****************************************************************************/
#include "./path.h"
#include <properties.h>
#include <gremios.h>#include <money.h>
inherit NPC;
inherit GUARD;
public void f_beber();
public string f_mujeres();
create(){
    "*"::create();
    SetStandard("un hombre de armas", "humano", ([GC_LUCHADOR:26+d6()]),  GENDER_MALE);
    SetShort("Un hombre de armas");
    switch(d4())
    {
        case 1:
            SetLong("\n");
            break;
        case 2:
            SetLong("\n");
            break;
        case 3:
            SetLong("\n");
            break;
        case 4:
            SetLong("n");
            break;
    }
    AddId(({"Hombre de armas", "guardia", "hombre"}));
    SetWhimpy(0);
    InitChats(10, ({SF(f_beber),
      // SF(f_mujeres)
      }));
    InitAChats(12, ({"El hombre de armas grita: ¡Peleea!\n",
    	  "El hombre de armas lanza un golpe poniendo en ello todas sus fuerzas.\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("\n");
    AddQuestion(({"aldeanas", "jóvenes", "mujeres"}), "El hombre ríe mientras dice: Sí, "
    "muchas de las campesinas de la aldea merecen algo mas que una segunda mirada. Había "
    "una... Tamara creo que se llamaba, de cabellos de fuego y mirada cautivadora pero "
    "he oído decir que se fugó con un bandido. Una verdadera lástima, nunca perdíamos la "
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
    AddQuestion(({"cored", "fortaleza", "Cored", "bandidos", "malhechores", "guarida"}),
    "El guardia te dice: \n"
    "Al noroeste de aquí se encuentra un espeso bosque. No son buenas tierras de cultivo "
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
     "¡Ahórrate tus preguntas estúpidas!\n");
    SetDrink(0);
    switch(d3())
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":d10(),"cobre":d10()])]));
}

public void f_beber(){
    object tabernero= present("tabernero") || present("tabernera") || present("posadero")
                    || present("posadera");
    if (tabernero && living(tabernero)){
      // le pongo 2 oro cada vez que vaya a beber porque las consumiciones son demasiado 
      //caras como para que llegue a estar borracho con el dinero que se le pueda poner 
      //encima.  Lo que le ongo se lo gasta en la misma acción y conserva un poco de dinero para disimular.
        object dinero;
        dinero = MONEY_LIB->QueryMoneyObject(TO);
        if (!dinero) { dinero = clone_object("/obj/money"); dinero->move(TO); }
        dinero->AdjustMoney((["oro":2]));
        tell_room(environment(), CAP(TO->QueryShort())+
        " grita:\n¡"+CAP(tabernero->QueryName())+", sírveme otra jarra de cerveza!\n");
        command_me("pedir cerveza");
    }else
    tell_room(environment(), CAP(QueryShort())+" comenta:\n Lo que daría yo ahora "
    "por una buena cerveza.\n");
}

      public string f_mujeres()
{
    object *mujeres = filter(all_inventory(environment()) - ({TO}), 
    (:living($1) && $1->QueryGender()==GENDER_FEMALE && ($1->QueryRace()=="humano" || 
      $1->QueryRace()=="elfo" || $1->QueryRace()=="medio elfo") :));
    object elegida = mujeres[random(sizeof(mujeres))];
    swithch(d4()){
        case 1:
            tell_room(environment(), "\n", ({elegida}));
            tell_object(elegida, ".\n");
            break;
        case 2:
            tell_room(environment(), "\n", ({elegida}));
            tell_object(elegida, ".\n");
            break;
        case 3:
            tell_room(environment(), "\n", ({elegida}));
            tell_object(elegida, ".\n");
            break;
       case 4:
            tell_room(environment(), "\n", ({elegida}));
            tell_object(elegida, ".\n");
            break;
    }
    return "";
}

