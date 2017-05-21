/***
comando atisbar
creado por Orome  16/10/2014
no consigo arreglar para que se puedan escribir cosas como atisbar hacia el norte o atisbar
en dirección norte, solo acepta el comando atisbar más la dirección a secas.
*****/
#include <skills.h>
#include <colours.h>

public int main(string str)
{
     string direccion,fichero,intshort;
 mapping salidas;
 object destino,aqui;
int atisbar=0;
int bonus_gremio=0;
 if (!TP||!str||!(aqui = environment(TP)))
   return notify_fail("¿Hacia qué dirección quieres atisbar?\n"),0;
 if (sscanf(str,"en direccion %s",direccion)!=1 && sscanf(str,"direccion %s",direccion)!=1 &&
     sscanf(str,"en dirección %s",direccion)!=1 && sscanf(str,"dirección %s",direccion)!=1)
    direccion = str;

 salidas = (["ar":"arriba",
             "ab":"abajo",
             "n":"norte",
             "ne":"noreste",
             "e":"este",
             "se":"sureste",
             "s":"sur",
             "so":"suroeste",
             "o":"oeste",
             "no":"noroeste"]);
  str = lower_case(str);
  if (member(salidas,str))
    str = salidas[str];

  if ( !TP->HasSkill(HAB_ATISBAR))
    return notify_fail("\n Nunca has aprendido a atisbar con disimulo.\n"),0;
  if (!member(salidas = aqui->QueryPlainExits()||([]),str))
    return notify_fail("No puedes atisbar nada en esa dirección.\n"),0;
  if (!stringp(fichero = salidas[str]))
    return notify_fail("No puedes apreciar nada en esa dirección.\n"),0;
  if (TP->CantSee())
    return notify_fail("No puedes ver nada.\n"),0;
  if (TP->QueryCombatDelay())
    return notify_fail(TP->QueryCombatDelayMsg()),0;
  if (!destino=load_object(fichero))
    return notify_fail("No consigues ver nada en esa dirección.\n"),0;
  if (str=="norte" || str=="sur" || str=="este" || str=="oeste" ||
      str=="noreste" || str=="noroeste" || str=="sureste" || str=="suroeste")
  {
    write("Echas un vistazo hacia el "+str+"...");
    say(capitalize(TP->QueryRealName())+" atisba hacia el "+str+".\n");
  }
  else
  {
    write("Echas un vistazo hacia el "+str+"...");
    say(capitalize(TP->QueryRealName())+" echa un vistazo hacia el "+str+".\n");
  }
  switch (TP->QueryGuild()){
    case "guerrero": bonus_gremio = BONUS_GUERREROS_ATISBAR; break;
        case "aventurero": bonus_gremio = BONUS_AVENTUREROS_ATISBAR; break;
                            default: bonus_gremio=0; break;
            }
  atisbar = TP->UseSkill(HAB_ATISBAR, bonus_gremio);
  intshort=destino->QueryIntShort()+".\n"+TC_NORMAL;

  switch(atisbar){
    case -10..20:
write(("\n"+intshort) ||"Deberás intentarlo de nuevo para ver algo útil.\n");
break;
        case 21..45:
write(("\n"+intshort+destino->QueryIntLong())
||"Deberás intentarlo de nuevo para ver algo útil.\n");
break;
            case 46..70:
                write(("\n"+intshort+destino->QueryIntLong()+destino->Content())
                ||"Deberás intentarlo de nuevo para ver algo útil.\n");
                break;
            case 71..300:
  write(("\n"+destino->GetIntDesc()) || "Deberás intentarlo de nuevo para ver algo útil.\n");
  break;
  default:
    write(" pero debido a tu falta de entrenamiento no ves nada útil.\n");
            }

  //TP->Set("Apuntardesde",environment(TP));
  //TP->Set("Apuntardonde",destino);
  TP->SetCombatDelay(1," intentas atisbar sigilosamente.\n");
  return 1;
}

