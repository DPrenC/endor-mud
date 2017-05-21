/*****************************************************************************************
 ARCHIVO:       robledal39_santuario.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:   - Menhires con huecos: 1, 3, 5, 7 y 9
                - Menhires con runas: 2, 4, 6, 8 y 10

*****************************************************************************************/


#include "./path.h"
//#include QUEST_RUNAS("runas_quest.h")
inherit BASE_ISLA;



public string mirar_uno();
public string mirar_tres();
public string mirar_cinco();
public string mirar_siete();
public string mirar_nueve();
public string mirar_menir();
public string mirar_hueco();


create()
{

    if(::create()) return 1;
    SetIntShort("un mítico Santuario Druida");

    SetIntLong("Unos enormes menhires circundan un pequeño claro entre la masa arbórea, "
        "quebrando la homogeneidad que cubre toda la isla. Su aspecto despejado, "
        "libre de vegetación espesa, irradia un aura nítida y vibrante. En el centro "
        "de la circunferencia, configurada por la decena de bloques graníticos, se haya "
        "un amplio altar a modo de terraza. Hacia el sur observas una pequeña choza de "
        "piedra.\n");

    AddDetail(({"altar", "terraza"}), "Este lugar es realmente un punto de poder y de "
        "mágia. Es el vacío que oficia de centro, de corazón íntimo de la floresta. "
        "Corazón que se convierte en fuente, lugar simbólico desde donde mana lo "
        "vivo.\n");
    AddDetail(({"choza", "choza de piedra"}), "Es muy tosca, está hecha de "
        "piedra y tiene poca altura, el tejado es de paja en el cual puedes ver una "
        "chimenea de pizarra por la que sale humo.\n");
    AddDetail(({"menhir", "menir", "menires", "menhires", "bloques",
                "bloques graníticos"}), SF(mirar_menir));
    AddDetail(({"hueco", "huecos"}), SF(mirar_hueco));
    AddDetail(({"runa", "runas"}), "Cada una tiene grabado el símbolo del dios al que "
       "pertenecen. Puedes mirar cada menhir para observar sus runas con más "
        "detalle.\n");

    AddDetail(({"menhir 1", "menir 1", "bloque 1", "menhir uno", "menir uno",
                "bloque uno"}), SF(mirar_uno));

    AddDetail(({"menhir 2", "menir 2", "bloque 2", "menhir dos", "menir dos",
                "bloque dos"}), "Tiene la runa de Donn, dios de los muertos.\n");

    AddDetail(({"menhir 3", "menir 3", "bloque 3", "menhir tres", "menir tres",
                "bloque tres"}), SF(mirar_tres));

    AddDetail(({"menhir 4", "menir 4", "bloque 4", "menhir cuatro", "menir cuatro",
                "bloque cuatro"}), "Tiene la runa de Agnus, dios del amor y la "
                "juventud.\n");

    AddDetail(({"menhir 5", "menir 5", "bloque 5", "menhir cinco", "menir cinco",
                "bloque cinco"}), SF(mirar_cinco));

    AddDetail(({"menhir 6", "menir 6", "bloque 6", "menhir seis", "menir seis",
                "bloque seis"}), "Tiene la runa de Arianrhod, diosa de la luna y de la "
                "noche.\n");

    AddDetail(({"menhir 7", "menir 7", "bloque 7", "menhir siete", "menir siete",
                "bloque siete"}), SF(mirar_siete));

    AddDetail(({"menhir 8", "menir 8", "bloque 8", "menhir ocho", "menir ocho",
                "bloque ocho"}), "Tiene la runa de Tentatis, dios protector del "
                "pueblo.\n");

    AddDetail(({"menhir 9", "menir 9", "bloque 9", "menhir nueve", "menir nueve",
                "bloque nueve"}), SF(mirar_nueve));

    AddDetail(({"menhir 10", "menir 10", "bloque 10", "menhir diez", "menir diez",
                "bloque diez"}), "Tiene la runa de Lugh, dios de la luz.\n");
     
/*
         1.- Menhir de Cernunos (Dios de los animales)
         2.- Menhir de Donn (Dios de los muertos)
         3.- Menhir de Morgana (Diosa de la guerra)
         4.- Menhir de Agnus (Dios del amor y la juventud)
         5.- Menhir de Beli(Dios del mar)
         6.- Menhir de Arianrhod (Diosa de la luna y de la noche)
         7.- Menhir de Belisama (Diosa del fuego)
         8.- Menhir de Tentatis(Dios del pueblo)
         9.- Menhir de Balor (Dios de las tinieblas)
        10.- Menhir de Lugh (Dios de la luz)
*/
    SetIntSmell("Huele a leña quemada.\n");
    SetIndoors(0);
    AddExit("norte", "./robledal41_jardin");
    AddExit("sur", "./choza");
    AddDoor("sur", "la puerta de una choza",
    "Es una vieja puerta de madera oscura de mediano tamaño.\n",
    ({"puerta", "puerta de la choza", "puerta sur", "puerta del sur", "puerta vieja"}));
}

public string mirar_uno()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//        return "Tiene la runa de Cernunos, dios de los animales.\n";
    return "Es el menhir dedicado al dios Cernunnos. En el hueco, aparece un ciervo en "
           "miniatura.\n";
}

public string mirar_tres()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//        return "Tiene la runa de Morgana, diosa de la guerra.\n";
    return "Es el menhir dedicado a la  diosa Morgana. En el agujero puedes observar la "
           "silueta de un hacha y un yelmo.\n";
}

public string mirar_cinco()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//  return "Tiene la runa de Beli, dios de las aguas.\n";
    return "Es el menhir dedicado al dios Beli. En el hueco puedes observar la forma de "
           "una gota de agua.\n";
}

public string mirar_siete()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//        return "Tiene la runa de belisama, diosa del fuego.\n";
    return "Es el menhir dedicado a la diosa Belisama. Comienzanas de la "
           "hendidura.\n";
}

public string mirar_nueve()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//        return "Tiene la runa de Balor, dios de las tinieblas.\n";
    return "Es el menhir dedicado al dios Balor. Ves como las tinieblas se van "
           "apoderando de lo que antes era el hueco.\n";
}

public string mirar_menir()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//        return "Son diez rocas que desprenden un tenue resplandor azulado. En el centro, "
//               "en relieve, llevan marcada una runa característica.\n";
    return "Son diez rocas, cinco de las cuales tienen en el centro un hueco del tamaño "
           "de una zarpa de oso. Las otras cinco desprenden un tenue resplandor azulado "
           "y en el centro, en relieve, llevan marcada una runa característica.\n";
}

public string mirar_hueco()
{
//    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
//        return "Donde había huecos ahora están perfectamente colocadas las runas que le "
//               "entregaste a Cathrann.\n";

    return "Te fijas en uno de los huecos y observas que tiene forma pentagonal y no es "
           "especialmente profundo. Están practicados en rocas alternas.\n";
}


