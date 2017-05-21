/*
** Guildmaster del Gremio de Guerreros Kha-annu

** Autor: Nemesis@Simauria, Ago'99

** Update:
** Fusilado por Gorthem Dic'00

** [n] 21-May-01 Interceptado el Die() pa que el que lo mate se lleve un
**               bonito "regalo"...
** [n] 27-Feb-03 Quitada el hacha. No tiene sentido que sea la misma que la
**               que le da el gremio a los jans.
*/

#include "../../wguild.h"
#include <skills.h>
#include <messages.h>
#include <combat.h>
#include <guild.h>


inherit NPC;


create()
{
  ::create();
 SetStandard("Thualin","enano",([GC_GUERRERO:100]),GENDER_MALE);
  SetShort("veterano Thualin, el guildmaster");
  SetLong(
    "Thualin es grande para ser un enano, y aunque los años han pasado,\n"
    "todavía conserva la fuerza y el vigor de cien enanos. Su rostro es cansado\n"
"y viejo, de alguien que ha soportado mil pesares, pero el brillo de sus\n"
    "ojos te indica que lucharía con la animosidad de cualquier enano mucho\n"
    "más joven.\n");
  AddId(({"guildmaster","master","veterano","Thualin","enano","thualin"}));
  SetAds(({"viejo","veterano","malvado","amigable"}));
  SetGender(GENDER_MALE);
  AddSkill(HAB_ROBAR, 100);
  SetAlign(-100);
  AddResistance(DT_FIRE, 100);
  AddItem("./hacha2m",REFRESH_REMOVE,SF(wieldme));
}



public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    object who = TP;

   if (!who || who == TO) return 0;

    tell_object(who, "...\nThualin te coge del cuello y te levanta en el aire. "
                     "Con voz profunda dice: '¿De verdad quieres hacer eso?' "
                     "Te das cuenta de que realmente no deseas hacerlo y él "
                     "te deja en el suelo.\n");
    tell_room(environment(), ({ MSG_SEE,
                                "...\nThualin coge a " + NNAME(who) + " por "
                                "el cuello y le levanta en el aire. Con voz "
                                "profunda le dice: '¿De verdad quieres hacer "
                                "eso?' "+ NNAME(who) + " se pone azul y Thualin "
                                "le suelta.\n",
                                MSG_HEAR,"Escuchas unos ruidos guturales, como "
                                "de alguien ahogándose. Al poco, escuchas como "
                                "Thualin le dice algo a algguien. Tras esto, los "
                                "ruidos cesan.\n"}), ({ who }));

    who->StopHunting(TO);
    TO->StopHunting(who);
    return 0;
}
