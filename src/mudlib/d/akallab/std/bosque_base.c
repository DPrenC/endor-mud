/*
DESCRIPCION  : Habitacion base del bosque
FICHERO      : bosque_base.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
	       20-11-04 [Gw] Modificacion para que herede AK_ROOM y del create()
*/

#include "path.h"
#include AK_MACRO
inherit AK_ROOM;

//probabilidades de que aparezcan obj/pnj (%)
#define PROB_SETA     10
#define PROB_HIERBA   15
#define PROB_AVE      20
#define PROB_MAMIFERO 15
#define PROB_OSO      10
#define PROB_BANDIDO  10

private static int prob_seta;
private static string NombreBosque;

void   SetNombreBosque(string n)
{
    NombreBosque=n;
    return;
}

string QueryNombreBosque(){return NombreBosque;}

string Desc()
{
    string s;
    s="";
     //Descripción general del bosque
    switch(random(5))
    {
        case 0:
            s+="Te encuentras en algún lugar del inmenso bosque "+
                QueryNombreBosque()+". A tu alrededor puedes observar "
                "cientos de grandes y frondosos árboles que deben llevar "
                "aquí desde tiempos inmemoriales.\n";
        break;
        case 1:
            s+="En esta zona el bosque "+QueryNombreBosque()+" que se "
                "extiende a tu alrededor se vuelve algo más denso y sombrío "
                "debido a la gran cantidad de árboles que hay. Te resulta un "
                "poco inquietante.\n";
        break;
        case 2:
            s+="El terreno del bosque presenta en esta zona una cierta "
                "pendiente. Piensas que no estaría de más tener un poco de "
                "precaución al avanzar para evitar alguna desagradable caída.\n";
        break;
        case 3:
            s+="Observas que en esta zona el bosque se vuelve algo mas claro, "
                "debido a que gran parte de los árboles son aún jóvenes y "
                "con poco tamaño. Esto hace que el bosque sea aquí algo más "
                "luminoso que en otras zonas.\n";
            AddDetail(({"arboles","árboles"}),"Son árboles jóvenes con toda "
                "una vida por delante.\n");
        break;
        case 4:
            s+="Observas que en esta parte del bosque abundan especialmente "
                "los robles en comparación con otros tipos de árboles. Son "
                "unos árboles grandes y frondosos.\n";
            AddDetail(({"robles"}),"En esta zona hay bastantes de ellos.\n");
        break;
    }

    //Descripción de los detalles de la zona
    switch(d6())
    {
        case 1:
            s+="En esta zona del bosque, la tierra que pisas está más bien "
                "húmeda, quizá debido a alguna lluvia reciente o al paso de "
                "algún acuífero subterráneo cerca de aquí.\n";
            AddDetail(({"suelo"}),"La tierra del suelo que pisas está húmeda.\n");
            prob_seta=MIN(100,prob_seta*4);
        break;
        case 2:
            s+="El suelo está cubierto de una mullida capa de hojarasca que "
                "cruje al pisarla.\n";
            AddDetail(({"hojarasca","hojas"}),"La hojarasca es la capa de "
                "hojas secas caídas de los árboles que hay en el suelo.\n");
        break;
        case 3:
            s+="Unos altos y espesos matorrales te impiden continuar hacia "
                "algunas direcciones.\n";
            AddDetail(({"matorrales"}),"Son lo bastante grandes como para "
                "impedirte avanzar en algunas direcciones.\n");
        break;
        case 4:
            s+="Junto a ti se encuentra un viejo tronco medio podrido de lo "
                "que alguna vez debió ser un gran árbol. Es posible que "
                "sirva de refugio para algún pequeño animal.\n";
            AddDetail(({"tronco"}),"Es sólo un viejo tronco.\n");
        break;
        case 5:
            s+="En el suelo puedes distinguir las huellas dejadas por algún "
                "animal del bosque.\n";
            AddDetail(({"huellas"}),"Parecen las huellas de un conejo.\n");
        break;
        case 6:
            s+="Cerca de aquí ves un grupo de rocas.\n";
            AddDetail(({"rocas"}),"Son sólo un grupo de rocas en medio del "
                "bosque.\n");
        break;
    }
    return s;
}

InitVars()
{
    prob_seta=PROB_SETA;
   return;
}


AnyadirPnjs()
{
    if (d20(5)<PROB_AVE) AddItem(PNJ("animal/aveboske"),REFRESH_DESTRUCT,1);
    if (d20(5)<PROB_MAMIFERO) AddItem(PNJ("animal/mamboske"),REFRESH_DESTRUCT,1);
    if (d20(5)<PROB_OSO) AddItem(PNJ("animal/oso_base"),REFRESH_DESTRUCT,1);
    //if (d20(5)<PROB_BANDIDO) AddItem(PNJ_STD("bandido"),REFRESH_DESTRUCT,1);
    return;
}

AnyadirHierbas()
{
    int nhierba,i;
    string tipo;
    nhierba=(d20(5)<PROB_HIERBA?random(2)+1:0);
    if (nhierba==0) return;
    for(i=0;i<nhierba;i++)
    {
        switch(d20(5))
        {
            case  1..25:
                tipo="hierba";
            break;
            case 26..35:
                tipo="hierba_narcotica";
            break;
            case 36..50:
                tipo="hierba_curativa";
            break;
            case 51..65:
                tipo="hierba_magica";
            break;
            case 66..90:
                tipo="hierba_saciante";
            break;
            case 91..100:
                tipo="hierba_venenosa";
            break;
        }
        AddItem(HERBS(tipo),REFRESH_DESTRUCT,1);
    }
    return;
}


AnyadirSetas()
{
    int nseta,i;
    string tipo;
    nseta=(d20(5)<prob_seta?random(2)+1:0);
    if (nseta==0) return;
    for(i=0;i<nseta;i++)
    {
        switch(d20(5))
        {
            case 1..25:
                tipo="seta";
            break;
            case 26..35:
                tipo="seta_narcotica";
            break;
            case 36..50:
                tipo="seta_curativa";
            break;
            case 51..65:
                tipo="seta_magica";
            break;
            case 66..90:
                tipo="seta_saciante";
            break;
            case 91..100:
                tipo="seta_venenosa";
            break;
        }
        AddItem(HERBS(tipo),REFRESH_DESTRUCT,1);
    }
    return;
}


create()
{
    ::create();
    InitVars();
    if (!QueryNombreBosque()) SetNombreBosque("de nadie");
    SetIntShort("el bosque "+QueryNombreBosque());
    SetIntLong(Desc());
    SetIntNoise("Oyes el canto de los pajaros.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("bosque "+QueryNombreBosque());
    SetIndoors(0);
    AnyadirSetas();
    AnyadirHierbas();
    AnyadirPnjs();
}
