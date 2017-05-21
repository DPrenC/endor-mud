/****************************************************************************
Fichero: guardia_noble.c
Autor: Ratwor
Fecha: 08/12/2007
Descripción: la guardia ersonal del noble.
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
    SetStandard("un guardia", "humano", ([GC_LUCHADOR:50+d4()]),  GENDER_MALE);
    SetShort("Un guardia");
    SetLong("Éste guardia es uno de los hombres de confianza de Rocher Dhes-Bláin, "
    "sirviéndole como emisario y escolta. Al mirarlo detenidamente, notas en sus rasgos "
    "un cierto parecido con su señor, lo que puede dar a entender que por sus venas "
    "corre la misma sangre, algo bastante probable, teniendo en cuenta que los "
    "Dhes-Bláin no solo son conocidos por sus hazañas y su férreo gobierno, si no "
    "también por la multitud de descendientes bastardos que han tenido a lo largo "
    "de los años.\n");
    AddId(({"guardia", "hombre", "humano"}));
    SetWeight(84100);
    SetAlign(80);
    SetWhimpy(5);
    InitChats(3, ({"El guardia apresta su espada mientras te mira con gesto serio, al "
        "parecer no le inspiras confianza.\n",
        "El guardia se ajusta el casco.\n",
        "El guardia se mantiene erguido y alerta.\n",
        "El guardia examina complacido su larga espada.\n",
        "El guardia te dice: No te quedes ahí plantado, expón a mi señor el motivo de "
        "tu visita o lárgate!\n ¡Y más vale que lo trates con respeto, o tu cabeza "
        "clavada en una lanza adornará las almenas.\n",
        "El guardia se ajusta el gran escudo al brazo.\n"}));
    InitAChats(12, ({"El guardia alza su gran escudo para defenderse.\n",
        "El guardia se adelanta cubriéndose con el escudo mientras lanza una serie de "
        "precisos tajos con su espada.\n",
        "El guardia grita: ¡Aquí soldados! ¡Se está vertiendo sangre en la misma sala "
        "de nuestro señor! ¡Por Rocher Dhes-Bláin!\n",
        "El guardia se abalanza hacia adelante enarbolando su espada sobre la "
        "cabeza para a continuación dejarla caer con todas sus fuerzas.\n",
        "El guardia lanza un ataque con la parte inferior del escudo.\n",
        "El guardia grita: ¡Tu cabeza adornará las murallas como advertencia para los "
        "enemigos del reino!\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    Set(P_CANT_LURE,1);
    SetGuardDefendMsg("Inmediatamente  el guardia  desenvaina su espada con gran "
    "presteza mientras grita con voz tonante:\n ¡Maldito asesino, no hay perdón "
    "para los que derraman sangre en éste castillo!\n  ¡Dispónte a morir, villano!");
    AddSkill(HAB_ESCUDO, 90, P_DEX);
    SetDex(QueryDex()+5);
    AddQuestion(({"hija", "Sherilin", "sherilin"}), "El guardia se sobresalta mirando de reojo a Rocher.\n"
    "El guardia exclama rápidamente: Sí, Sherilin. Ese es el nombre de la hija de mi "
    "señor, por lo cual se le debe un respeto,  y si tu irrespetuosa lengua no se está "
    "quieta, te quedarás sin ella y recibirás una docena de latigazos de propina, así "
    "que, !déjame en paz, y no me preguntes mas!\n");
    AddQuestion(({"su señor", "señor", "rocher", "Rocher"}), "el hombre adopta una postura "
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
    "escrúpulos en incorporar orcos en sus filas.\n");
    SetShrugMsg("El guardia se inclina y dice con tono amenazante: ¿De manera que osas "
    "presentarte ante mi señor con el exclusivo objetivo de hacer preguntas ridículas?\n"
    "El guardia se iergue súbitamente mientras grita:\n"
    "Fuera de aquí vagabundo, ¡antes de que ordene que te azoten por tamaña osadía.\n");
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("gran_escudo"), REFRESH_REMOVE, SF(wearme));
    AddItem(ARMANANDOR("espada_larga"), REFRESH_REMOVE, SF(wieldme));

    AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":d4(),"oro":d3()])]));
}
