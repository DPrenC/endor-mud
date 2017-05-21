/****************************************************************************
Fichero: centinela.c
Autor: Ratwor
Fecha: 03/12/2007
Descripci�n: El guardia de la puerta del castillo.
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
            SetLong("Es un humano no muy alto, pero de cuerpo fornido y cara ce�uda en la "
            "que exhibe el enorme costur�n de una fea herida mal cicatrizada que le "
            "recorre toda la parte baja de la boca, creando casi un segundo ment�n de "
            "malsano aspecto. No parece muy contento de su puesto como centinela a las "
            "puertas de la fortaleza.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos j�venes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su misma gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su se�or a cambio de un pobre rancho, un "
            "jerg�n de paja y algunas monedas de cobre.\n");
            break;
        case 2:
            SetLong("Es un guardia humano de rostro macilento y aspecto cansado, "
            "seguramente debido todo ello a la falta de sue�o y al magro rancho del que "
            "se alimenta. No parece muy contento de su puesto como centinela a las "
            "puertas de la fortaleza.\n"
            "Es uno de los hombres de armas del castillo, gente habitualmente elegida de "
            "entre los aldeanos j�venes y vigorosos que pronto olvidan su origen humilde "
            "y cometen contra su propia gente toda clase de atrocidades.  Su deber es "
            "servir y defender fielmente a su se�or a cambio de un pobre llantar, un "
            "jerg�n de paja y algunas monedas de cobre.\n");
            break;
    }
    AddId(({"centinela", "guardia", "humano", "hombre"}));
    SetWeight(82100);
    SetAlign(80);
    SetWhimpy(10);
    Set(P_CANT_LURE,1);
    InitChats(5, ({"El guardia se apoya en su alabarda con hast�o.\n",
        "El guardia se urga distra�damente la nariz y pega algo en el muro.\n",
        "El guardia dice: �Fuera de aqu�, escoria!\n",
        "El guardia se aparta un poco el casco y se rasca la cabeza grasienta.\n",
        "El guardia dice: en cuanto me releven bajar� a tomar unas cervezas en la posada "
        "y tal vez le pueda hechar el guante a una de esas aldeanas "
        "j�venes de apetitosas carnes.\n",
        "El guardia comenta: parece que mi se�or Rocher est� preparando un ataque contra "
        "los malechores de Cored, aunque temo que no seamos suficientes para asaltar "
        "su guarida.\n",
        "El guardia te vigila mientras apresta su alabarda.\n"}));
    InitAChats(16, ({"El guardia grita: �A las armas! �Tratan de penetrar en el "
        "castillo! �Trancad el port�n!\n",
    	  "El guardia grita: Maldito vagabundo, pagar�s tu osad�a con la vida!\n",
    	  "El guardia empu�a con ambas manos su alabarda a la altura del pecho us�ndola "
    	  "a modo de lanza.\n",
    	"El guardia gru�e fren�ticamente: Te env�a Cored, �verdad?\n",
    	  "El guardia lanza un tajo con su alabarda.\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El guardia se lanza al ataque mientras grita: �ah! �Con que "
    "Tratando de abrirse paso hasta el castillo a golpes eh? �Yo te ense�ar� lo que "
    "es bueno! �Por mi se�or Rocher que lo pagar�s caro!\n");
    SetIVision(0);
    AddQuestion(({"aldeanas", "j�venes", "mujeres"}), "El guardia r�e mientras dice: S�, "
    "muchas de las campesinas de la aldea merecen algo mas que una segunda mirada. Hab�a "
    "una... Tamara creo que se llamaba, de cabellos de fuego y mirada cautivadora pero "
    "he o�do decir que se fug� con un bandido. Una verdadera l�stima, nunca perd�amos la "
    "oportunidad de admirarla cada vez que alguno de nosotros bajaba hasta el pueblo, "
    "aunque ninguno consigui� sorprenderla sola... como digo, una "
    "l�stima.\n La esposa de uno de los viejos que suelen zanganear en la plaza no est� "
    "nada mal, aunque ninguna se puede comparar con la hija de nuestro se�or.\n");
    AddQuestion(({"hija", "sherilin", "Sherilin"}),
    "El guardia mira nerviosamente a su alrrededor.\n"
    "A continuaci�n se te acerca y te susurra: S�, la hija de nuestro se�or Rocher..\n"
    "Se pasa la lengua por los labios.\n"
    "El hombre te susurra: Ah, es bella como la diosa Valevisa, dar�a cualquier cosa "
    "por compartir su lecho una noche, pero su padre me colgar�a de las almenas en el "
    "mejor de los casos, o me despellejar�a vivo en el peor.\n", 1);
    AddQuestion(({"su se�or", "se�or", "Rocher", "rocher"}),
    "el hombre adopta una postura "
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
    SetShrugMsg("El guardia te mira con cara de malas pulgas y grita: �y yo que s�?\n"
     "�Ah�rrate tus preguntas est�pidas, o te encerrar� en los calabozos!\n");
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddItem(ARMANANDOR("alabarda"), REFRESH_REMOVE, SF(wieldme));
    if(d2()==1)
            AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["cobre":random(10),"plata":d6()])]));
}
