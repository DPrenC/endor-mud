/****************************************************************************
Fichero: malgdher.c
Autor: Ratwor
Fecha: 30/01/2007
Descripción: el guardabosques del bosque de Marhalt.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <materials.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Malgdher", "medio-elfo", ([GC_GUARDABOSQUES:100+d4()]), GENDER_MALE);
    AddId(({"guardabosques", "malgdher", "guarda", "medio elfo", "semi elfo",
        "medio-elfo", "medio_elfo", "semi-elfo", "semi_elfo"}));
    SetShort("Malgdher el guardabosques");
    SetLong("Es un medio elfo de mediana edad, fuerte y musculoso, con la piel "
        "morena por el sol y curtida por el frío. Su cabello en greñas habla a las "
        "claras de su condición de ermitaño. Su rostro no es duro pero tampoco amigable."
        " Sus manos callosas son sin embargo las de un artista, ya que de ellas salen"
        " unas figuritas de madera que talla en la soledad de su cabaña.\n"
        " Tiene un porte imponente que te muestra que no será fácil huir de él si se le "
        "provoca.\n");
    SetAlign(200);
    Set(P_CANT_LURE,1);
    SetSmell("Huele a hierbas.\n");
    InitChats(4,({"el guardabosques te clava una mirada inquietante.\n",
        "El guardabosques respira profundamente.\n",
        "El guardabosques habla para sí mismo: no sé que voy a hacer con el niño.\n",
        CAP(QueryName())+" dice: yo no se como curarle.\n",
        "El guardabosques manipula una figurilla que lleva en las manos.\n"}));
    AddSubDetail(({"figura", "figurita", "figurilla"}), "Es de madera de roble y "
        "todavía  no tiene forma definida.\n");
    AddQuestion("cabaña", "Malgdher te dice: \n La construí yo con estas manos hace "
        "muchos años, aunque en algo sí me ayudó el leñador. A veces tengo que hacerle "
        "algunas reparaciones, pero siempre hay madera disponible y me gusta trabajar "
        "con ella.\n  Esta cabaña me ha protegido del frío y del calor desde que "
        "decidí llevar esta vida solitaria.\n",1);
    AddQuestion(({"corl", "Corl", "leñador"}), "El guardabosques te dice: \n"
        "Ah, ese vejete. Sí, alguna vez le hice una figura de madera, una de las "
        "más bonitas que salieron de mis manos. Pero el pobre está medio chalado,"
        "la vida en soledad no le sienta bien y se ha vuelto un poco excéntrico, "
        "aunque me consta que es un buen tipo.\n",1);
    AddQuestion(({"figuritas", "figuras de madera", "figurillas"}), "Malgdher te dice:"
        "\n Me gusta trabajar la madera, y suelo tallar figuritas en las largas noches "
        "de invierno.\n  Son cosas que he visto o me han inspirado alguna vez.\n "
        "Guardo las imágenes en mi mente y luego las reproduzco en madera. Cada vez "
        "que las miro recuerdo lo que me inspiró a hacer cada una.\n",1);
    AddQuestion("bosque", "El guardabosques te dice:\n  Es un bosque más o menos mediano"
        " aunque todavía está en crecimiento. Yo mismo he plantado algunos de esos "
        "robles, y espero verlos crecer junto con el resto del bosque.\n",1);
    AddQuestion(({"niño", "ninyo", "sobrino", "sobrino de leyma", "sobrino de leyma",
        "bebe", "bebé"}),
        "El guardabosques te dice: me lo encontré cerca del río, pero en ese momento "
        "no sabía de quien era, así que lo traje a la cabaña. Luego me enteré que es "
        "familiar de una tendera de la aldea de Nandor, cerca de donde me lo encontré,"
        " pero yo nunca piso la civilización, además que el niño se encuentra "
        "lamentablemente mal y en estas condiciones no puede viajar.\n Necesita tomar "
        "algo de comida que le cure de su mal, pero yo no tengo conocimientos "
        "suficientes para ello, sería preciso una curandera.\n",1);
    AddQuestion(({"mal", "enfermedad"}), "El guardabosques dice: Está muy inquieto,"
        " parece que tiene fiebre y se le nota que se encuentra débil.\n",1);
    AddQuestion(({"curandera", "remedio", "ingredientes", "papilla", "cura", "comida",
         "solucion", "solución"}),
        "El guardabosques te dice: he oído hablar de una curandera gnomo, Evah creo "
        "que se llama, que vive en un bosque de la isla de Goldhai y que tiene "
        "experiencia en estas cosas, ve a preguntarle por el remedio que necesitamos "
        "para el niño.\n",1);
    AddQuestion(({"isla", "isla de goldhai", "isla de Goldhai", "goldhai", "goldhai"}),
        "El guardabosques te dice: lo siento, pero es que yo no me muevo de este bosque "
        "y nunca he viajado a dicha isla.\n",1);

    SetShrugMsg("Malgdher dice: ni idea.\n");
    SetGoChance(30);
    AddItem(ARMANANDOR("espada_1mano"), REFRESH_REMOVE,
            ([P_SHORT:"una espada larga",
            P_LONG:" Es una bella espada con la empuñadura recubierta de cuero y "
                "el pomo en forma trapezoidal, cuyos gabilanes se curvan hacia la "
                "larga hoja de acero pulido de doble filo. Parece ser "
                "extraordinariamente ligera, perfectamente equilibrada y fácil de "
                "manejar.\n Tanto las elegantes líneas recurvadas de los filos y "
                "la empuñadura finamente trabajada, como el acero plateado de la "
                "hoja y los grabados que la recorren denotan su  orígen élfico.\n",
            P_IDS:({"espada", "larga", "espada larga"}), P_WEIGHT:3900]), SF(wieldme));

    AddItem(ARMA("marhalt/espada_corta"),REFRESH_REMOVE, SF(wieldme));
    AddItem(PROT("marhalt/pantalon_cuero"),REFRESH_REMOVE,SF(wearme));
    AddItem(PROT("marhalt/botas_verdosas"),REFRESH_REMOVE,SF(wearme));
    AddItem(PROT("marhalt/camisa_guardabosques"),REFRESH_REMOVE,SF(wearme));

}
