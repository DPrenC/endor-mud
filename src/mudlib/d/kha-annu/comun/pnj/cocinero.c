/* Creado por [I] Izet@Simauria.
   Cocinero que odia que entren en su cocina :)
   [Woo] Modificado
*/


#include "path.h"
#include <properties.h>
#include <combat.h>
#define NAME TP->QueryName()

inherit KBASE;


create() {
  ::create();
 SetStandard("Thrak","enano",6,GENDER_MALE);
  SetShort("Thrak, el cocinero");
  SetLong(
"Este es el cocinero del castillo. Es un enano bastante entrado en canas,\n"
"unos 270 o 280 anyos. Sus cabellos son de color castaño y una barba espesa\n"
"y trenzada puebla la mayor parte de su cara. Su cara demuestra un caracter\n"
"enfadado, probablemente has invadido la intimidad de su cocina.\n");
  SetAggressive(1);
  SetAlign(200);
  SetAC(3);
  SetHands( ({ ({"mano derecha",0,3}),({"mano izquierda",0,3}) }) );
  SetIds(({"enano","cocinero","el cocinero","al cocinero"}));
  SetAds(({"un","gordo"}));
  InitAChats(8,({
   "Thrak grita encolerizado: ¡¡¡JAMAS TE QUEDARAS CON MI COCINA!!!\n",
   "Thrak te corta la cara con el filo de su cuchillo.\n"
  }));
  InitChats(7,({
   "Thrak grita: ¡Que haces aqui! ¡Fuera de mi cocina!\n",
   "Thrak grita: ¡Vamos! ¡Largo! ¡¡¡Que haces ahi parado!!!\n",
   "Thrak grita: ¿¡¿No ves que estoy ocupado?!? ¡¡¡FUERA!!!\n"}));
  AddItem("/std/weapon",REFRESH_REMOVE,
            ([P_SHORT:"un enorme cuchillo de cocina",
              P_LONG:"Es un enorme cuchillo de cocina, con manchas de sangre.\n",
              P_IDS:({"cuchillo","cuchillo de cocina"}),
              P_ADS:({"un","enorme"}),
              P_WC:2,
/*
              P_WEAPON_TYPE:WT_CUCHILLO,
*/
              P_DAM_TYPE:DT_SLASH,
              P_WEIGHT:1000,
              P_VALUE:5]),SF(wieldme));
   AddItem("/std/weapon",REFRESH_REMOVE,
          ([P_SHORT:"una sarten",
            P_LONG:"Es una sarten vieja de color negro.\n",
            P_IDS:({"sarten"}),
            P_ADS:({"una","vieja","negra"}),
            P_WC:1,
            P_WEAPON_TYPE:WT_MAZA,
            P_DAM_TYPE:DT_BLUDGEON,
            P_GENDER:GENDER_FEMALE,
            P_WEIGHT:500,
             P_VALUE:2]),SF(wieldme));
   AddItem("/std/armour",REFRESH_REMOVE,
             ([P_SHORT:"un delantal sucio",
               P_LONG:"Es un simple delantal con manchas de sangre y comida.\n",
               P_IDS:({"delantal","delantal sucio"}),
               P_ADS:({"un"}),
               P_AC:0,
               P_ARMOUR_TYPE:AT_MAIL]),SF(wearme));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
    "Thrak tose.\n"
    "Thrak dice antes de morir: ¡"+NAME+", mi... cocina... NOOO!\n");
    TP->SetAttribute("asesino",(TP->QueryAttribute("asesino"))+1);
    ::Die(silent);
}
