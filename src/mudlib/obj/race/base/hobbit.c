/*nueva raza hobbit para endor*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <bandos.h>

inherit "/obj/raceobj";

create_blueprint(){
::create_blueprint();

SetAlign(30);
SetBando(P_BANDO_LUZ);

SetMaxFood(75);
SetMaxDrink(75);
SetMaxAlcohol(50);
SetSize(P_SIZE_SMALL);
SetWeight(40000);
AddHand("pequeña mano derecha", 0, WEAPON_CLASS_OF_HANDS);
AddHand("pequeña mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
SetStatBonus(P_CON, 3);
SetStatBonus(P_INT, 0);
SetStatBonus(P_DEX, 3);
SetStatBonus(P_STR,     -4);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,15);
SetResistance(MT_POISON,5);
SetResistance(MT_PSYCHO,15);
SetResistance(DT_WATER,-5);
SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
SetUVision(2 * MAX_SUNBRIGHT);
    SetLong("Descripción temporal.\n");
    /*
switch(player->QueryGender()){
    case 1: SetLong("hobbit masculino.\n"); break;
        case 2: SetLong("Hobbit femenino.\n"); break;
        }
*/
SetRaceDescription(
"Los Hobbits son una raza perteneciente al tronco de los Hombres, aunque desde un "
"principio fueron un pueblo aparte y hasta bien entrada la Tercera Edad no aparecen en "
"las crónicas  y pasaron desapercibidos para todos.\n"
"En esta época abandonaron sus tierras en el Alto Anduin y emigraron a Eriador, donde "
"tras un tiempo de vagabundeo acabaron estableciéndose en las tierras de Bree, donde "
"aún conviven con los hombres y más tarde en la Comarca.\n"
"Los Hobbits son más bajos y ligeros que los enanos, en general rollizos, de caras "
"redondas, bonachonas y risueñas  y espesos cabellos castaños, habitualmente rizados.\n"
"Tienen dedos largos, hábiles y rápidos tanto en las  manos como en sus belludos  "
"pies, los cuales están revestidos por una plantilla de dura piel natural que les "
"permite caminar descalzos con excepcional sigilo y ligereza.\n"
"Son una raza sencilla, que vive de la agricultura y la ganadería, amantes de la buena "
"mesa y de una vida acomodada, aunque bajo esta apariencia simple esconden la facultad "
"de soportar privaciones, heridas  y desastres mucho mejor que razas aparentemente más "
"resistentes.\n"
"Habitualmente eluden el combate, pero si se ven acorralados despiertan en ellos una "
"valentía y una gran combatividad irreductible que sorprende a quienes no los conocen.\n"
"Son un pueblo  rústico, aunque excelentes agricultores, ganaderos, cocineros y sus "
"artesanías aunque sencillas son funcionales.\n"
"Su extremado buen oído, capacidad para desaparecer o no ser vistos si así no lo desean "
"junto con su gran habilidad para avanzar en casi total silencio y su gran habilidad "
"con las armas de proyectiles los hacen excelentes cazadores, exploradores y rastreadores.\n");

}
