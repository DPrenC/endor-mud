/* ENDOR-MUD'/bin/mortal/_equipo.c'
   ================================
*/

#include <wizlevels.h>
#include <combat.h>
#include <properties.h>

static object jug;
static int wiz;

string WeaponDat(object weap)
{
 string str;

 str="    ";
 str+=STR->ladjust("WC: "+weap->QueryWC(),8," ");
 str+=STR->ladjust("Manos: "+weap->QueryNumberHands(),11," ");
 str+=STR->ladjust("Daño: "+weap->QueryQuality()+"/100",16," ");
 str+=STR->ladjust("Tipo: "+weap->QueryWeaponType(),19," ");
 str+="Tamaño: ";
 switch(weap->QuerySize())
 {
  case 0: str+="genérico";break;
  case 1: str+="pequeño";break;
  case 2: str+="normal";break;
  case 3: str+="grande";break;
  case 4: str+="enorme";break;
  default:"<desconocido>";
 }
 return str;
}

string ArmourDat(object arm)
{
 string str;

 str="    ";
 str+=STR->ladjust("AC: "+arm->QueryAC(),8," ");
 str+=STR->ladjust("Daño: "+arm->QueryQuality()+"/100",16," ");
 switch(arm->QueryArmourType())
 {
    case -6: str+=STR->ladjust("Tipo: AT_TIARA",24," ");break;
    case -5: str+=STR->ladjust("Tipo: AT_PULSERA",24," ");break;
    case -4: str+=STR->ladjust("Tipo: AT_BROCHE",24," ");break;
  case -3: str+=STR->ladjust("Tipo: AT_AMULETO",24," ");break;
  case -2: str+=STR->ladjust("Tipo: AT_ANILLO",24," ");break;
  case -1: str+=STR->ladjust("Tipo: AT_SKIN",24," ");break;

  case 0: str+=STR->ladjust("Tipo: <indefinido>",24," ");break;
  case 1: str+=STR->ladjust("Tipo: AT_BOTAS",24," ");break;
  case 2: str+=STR->ladjust("Tipo: AT_TUNICA",24," ");break;
  case 3: str+=STR->ladjust("Tipo: AT_CORAZA",24," ");break;
  case 4: str+=STR->ladjust("Tipo: AT_GUANTES",24," ");break;
  case 5: str+=STR->ladjust("Tipo: AT_CASCO",24," ");break;
  case 6: str+=STR->ladjust("Tipo: AT_ESCUDO",24," ");break;
  case 7: str+=STR->ladjust("Tipo: AT_PANTALONES",24," ");break;
    case 8: str+=STR->ladjust("Tipo: AT_MANTO",24," ");break;
        case 9: str+=STR->ladjust("Tipo: AT_CAPUCHA",24," ");break;
            case 10: str+=STR->ladjust("Tipo: AT_GREBAS",24," ");break;
                case 11: str+=STR->ladjust("Tipo: AT_CINTURON",24," ");break;
                    case 12: str+=STR->ladjust("Tipo: AT_TALABARTE",24," ");break;
                        case 13: str+=STR->ladjust("Tipo: AT_BRAZALES",24," ");break;
                            case 14: str+=STR->ladjust("Tipo: AT_TABARDO",24," ");break;
                                case 15: str+=STR->ladjust("Tipo: AT_FALDA",24," ");break;
                                    case 16: str+=STR->ladjust("Tipo: AT_CAMISA",24," ");break;
  default: str+=STR->ladjust("Tipo: <desconocido>",24," ");break;
 }
 str+="Tamaño: ";
 switch(arm->QuerySize())
 {
  case 0: str+="genérico";break;
  case 1: str+="pequeño";break;
  case 2: str+="normal";break;
  case 3: str+="grande";break;
  case 4: str+="enorme";break;
  default:"<desconocido>";
 }

 return str;
}

void Info_wiz_weapons()
{
  string *result, str;
  int i, h, j;
  mixed *hands, arr;

  result = ({});
  hands = jug->QueryHands();
  arr = jug->QueryWeapons();
  if (sizeof(arr) && sizeof(arr -= ({ 0 })))
  {
    object weapon;

    for (i = 0; i < sizeof(arr); i++)
    {
      weapon = arr[i];
      if (!objectp(weapon))
        continue;
      str = weapon->Short() +" (";
      for (h = 0, j = 0; h < sizeof(hands); h++) {
        if (hands[h][HAND_WEAPON] == weapon)
        {
          str += (j++?" y ":"")+hands[h][HAND_SHORT];
        }
      }
      result += ({ str+")\n"+WeaponDat(weapon) });
    }
  }

  if(sizeof(result))
  {
   if(jug!=TP) write(capitalize(jug->QueryName())+" empuña:\n");
    else write("Empuñas:\n");
   for(i=0;i<sizeof(result);i++)
   {
    write("  "+capitalize(result[i])+"\n");
   }
  }
  else
   if(jug!=TP) write(capitalize(jug->QueryName())+" tiene las manos vacías.\n");
    else write("Tienes las manos vacías.\n");
}

void Info_weapons()
{
  string *result, str;
  int i, h, j;
  mixed *hands, arr;

  result = ({});
  hands = jug->QueryHands();
  arr = jug->QueryWeapons();
  if (sizeof(arr) && sizeof(arr -= ({ 0 })))
  {
    object weapon;

    for (i = 0; i < sizeof(arr); i++)
    {
      weapon = arr[i];
      if (!objectp(weapon))
        continue;
      str = weapon->Short() +" con tu";
      for (h = 0, j = 0; h < sizeof(hands); h++) {
        if (hands[h][HAND_WEAPON] == weapon)
        {
          str += (j++?" y tu ":" ")+hands[h][HAND_SHORT];
        }
      }
      result += ({ str });
    }
  }

  if(sizeof(result))
  {
   write("Empuñas:\n");
   for(i=0;i<sizeof(result);i++)
   {
    write("  "+capitalize(result[i])+".\n");
   }
  }
  else
   write("Tienes las manos vacías.\n");
}

void Info_wiz_armours()
{
 int i;
 mixed armours;

 armours=jug->QueryArmours();

 if(!sizeof(armours))
  if(jug!=TP) write(capitalize(jug->QueryName())+" está desnud"+(jug->QueryGender()==GENDER_FEMALE?"a":"o")+".\n");
  else write("Estás desnud"+(jug->QueryGender()==GENDER_FEMALE?"a":"o")+".\n");
 else
 {
   if(jug!=TP)
     write(capitalize(jug->QueryName())+" viste :\n");
   else
     write("Vistes :\n");
   for(i=0;i<sizeof(armours);i++)
    write("  "+capitalize(armours[i]->Short())+".\n"+ArmourDat(armours[i])+"\n");
 }
}

void Info_armours()
{
 int i;
 mixed armours;

 armours=jug->QueryArmours();

 if(!sizeof(armours))
   write("Estás desnud"+(jug->QueryGender()==GENDER_FEMALE?"a":"o")+".\n");
 else
 {
   write("Vistes:\n");
   for(i=0;i<sizeof(armours);i++)
    write("  "+capitalize(armours[i]->Short())+".\n");
 }
}

int equipo(string arg) {

 if(IS_LEARNER(TP)) wiz=1;
 else wiz=0;
 jug=0;
 if(arg && wiz)
  if (!jug = ( find_object(arg)||find_object(lower_case(arg))) )
    return notify_fail("Ese jugador no está conectado ahora.\n");
 if (!jug) jug=TP;

 if (wiz) Info_wiz_weapons();
 else Info_weapons();

 if (wiz) Info_wiz_armours();
 else Info_armours();

 return 1;
}
