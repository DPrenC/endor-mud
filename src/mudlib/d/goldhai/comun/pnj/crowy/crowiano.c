/*
 * crowiano.c
 */


#include "./path.h"
#include <properties.h>
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");


string nombre, raza, raza1, art, tmp2;
int nivel, sexo, edad, guerrero,borracho,tmp, cobre, plata, oro;
object item;

create()
{
    nombre = "";
    ::create();
    // sexo
    switch(d2())
    {
        case 1: sexo = GENDER_MALE; art = "un "; break;  //masculino
        case 2: sexo = GENDER_FEMALE; art="una "; break;  //femenino
    }

    // edad:
    switch(d10())
    {
        case 1..2: edad = BEBE; nombre = "bebé "; AddId(({"bebe", "bebé"})); break;
        case 3..4:
             edad = PEQUENYO;
             nombre = (sexo == GENDER_MALE?"pequeño ":"pequeña ");
             AddId((sexo == GENDER_MALE ? ({"pequeño", "pequenyo"}) : ({"pequeña", "pequenya"})));
             break;
        case 5..6: edad = MEDIANA; break; // Mediana edad
        case 7..8:
             edad=VIEJO;
             nombre = (sexo == GENDER_MALE ? "viejo ":"vieja ");
             AddId((sexo == GENDER_MALE ? "viejo" : "vieja"));   break;
        case 9..10:
             edad = ANCIANO;
             nombre = (sexo == GENDER_MALE ? "anciano ": "anciana ");
             AddId((sexo==1?"anciano":"anciana"));  break;
    }

    if(edad != BEBE && edad != ANCIANO && d4() == 3)
    // si no es bebé ni anciano y un dado de 4 caras ha dado 3...
    {
        guerrero=1;
        if (nombre) AddId((sexo == GENDER_MALE ? nombre + "guerrero": nombre + "guerrera"));
        nombre += (sexo == GENDER_MALE ? "guerrero " : "guerrera ");
        AddId((sexo == GENDER_MALE ? "guerrero" : "guerrera"));
    }

    switch(d6()) // distintas razas... Qué ciudad más multiétnica :P esto no tiene sentido, pero bueno
    {
        case 1: raza1 = (sexo == GENDER_MALE ? "elfo" : "elfa"); raza = "elfo"; break;
        case 2: raza1 = (sexo == GENDER_MALE ?"enano" : "enana"); raza = "enano"; break;
        case 3: raza1 = raza="gigante"; break;
        case 4: raza1 = raza="kender"; break;
        case 5..6: raza1 = (sexo == GENDER_MALE ? "humano" : "humana"); raza="humano"; break;
    }

    /* Minimo nivel 2, maximo nivel 11:
                          bebe......<4
                          pequeño..<6
                          normal....<8
                          viejo.....<7
                          anciano...<5
                          Si es guerrero/a se le anyade 3 al total
    */
    nivel=2;
    switch(edad)
    { // De 0 a 4
        case BEBE: nivel += d2() - 1;break;
        case PEQUENYO: nivel  += d3(); break;
        case MEDIANA: nivel += d6() - 1;break;
        case VIEJO: nivel += d4() - 1; break;
        case ANCIANO: nivel += d3() - 1; break;
    }

    if(guerrero) nivel += 3;

    tmp=(sexo == GENDER_MALE ? 1:0) + (guerrero ? 2 : 0) + (edad < 2 ? 0 : 3);
    if(edad > PEQUENYO && tmp >= d8())
    // se convierten en borrachos :)
    {
        borracho=1;
        AddId(tmp2 = (sexo == GENDER_FEMALE ?"borracha" : "borracho"));
        AddId(tmp2=raza1+ " " + tmp2);
    }

    nombre+=raza1;
    AddId(({nombre, raza1}));

    if(borracho)
    {
        nombre+=(sexo==2?" borracha":" borracho");
        SetAlcohol(40 + d10(6));
        AddId(nombre);
    }
    nombre=art+nombre;
    SetStandard(nombre, raza, guerrero ? ([GC_LUCHADOR:nivel]) : nivel, sexo);
    SetLong("Se trata de "+nombre+".\n");
    SetWhimpy(QueryMaxHP()/4); // Que huya facilmente

    switch(edad)
    {
        case BEBE: cobre = d6() + 4; break;
        case PEQUENYO: cobre = d4() + 4; plata=d2(); break;
        case MEDIANA: plata= d3() + 2; oro = d2(); break;
        case VIEJO: plata = d3()+1; oro=d2() + 1;         break;
        case ANCIANO: oro = d3() + 1; break;
    }


    if(borracho) // Si estas borracho tienes la mitad del dinero
    {
        cobre /= 2; plata /= 2; oro /= 2;
    }
    AddItem("/obj/money",REFRESH_REMOVE,
            (["Money":(["cobre":cobre,"plata":plata,"oro":oro])]));

    if (edad < MEDIANA)
    {
        InitChats(3,({ CAP(NNAME(TO)) + " llora desconsoladamente... Buuaahhhhhh!\n"}));
    }

    if (raza == "orco" && d3() >= 2 && edad > PEQUENYO)
    {
        AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
    }

    if (guerrero && QuerySize() == P_SIZE_MEDIUM && !borracho)
    {
        if (edad > PEQUENYO && edad < ANCIANO)
        {
            AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
            AddItem(PROT("casco_hierro"),REFRESH_REMOVE,SF(wearme));
        }
        else AddItem(ARMA("espada_madera"),REFRESH_REMOVE,SF(wieldme));
    }
    else if (guerrero && QuerySize() == P_SIZE_LARGE && !borracho)
    {
        if (edad > PEQUENYO && edad < ANCIANO)
        {
            AddItem(ARMA("maza_hierro"),REFRESH_REMOVE,SF(wieldme));
        }
    }

    if (QuerySize() == P_SIZE_MEDIUM && d4() < 3 && !guerrero)
    {
        AddItem(PROT("c_camisa"),REFRESH_REMOVE,SF(wearme));
    }

    if (edad > PEQUENYO && !guerrero && d4() > 3 && QuerySize() == P_SIZE_MEDIUM)
    {
        if (d3() >2) AddItem(ARMA("daga"),REFRESH_REMOVE,SF(wieldme));
        else AddItem(ARMA("cuchillo"),REFRESH_REMOVE,SF(wieldme));
    }

    if (QuerySize() == P_SIZE_SMALL && edad < MEDIANA)
    {
        AddItem(PROT("s_camisa"),REFRESH_REMOVE,SF(wearme));
    }
    if (guerrero)
    {
        AddItem(ARMA("palo"),REFRESH_REMOVE,SF(wieldme));
    }
    if (edad == ANCIANO && !guerrero) AddItem(ARMA("palo"),REFRESH_REMOVE,SF(wieldme));
    SetEdad(edad);
    SetBorracho(borracho);
}





public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras)
// Si le atacan busca a los guardias para que le defiendan.
{
    int i;
    filter(all_inventory(environment()),(:$1->QueryGuardian() ? $1->Kill(TP ||PO) : 0:));

    return ::DoDamage(dmg,type,gentle,xtras);
}
