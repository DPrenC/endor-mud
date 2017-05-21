/*
  arma_rnd.c
  (c) Nemesis@Simauria

  Arma aleatoria para uso del almacén JAN del gremio de Guerreros.
  NOTA: NO USAR EN NINGUN OTRO SITIO!!
  NOTA 2: NO USAR. TODAVÍA ESTÁ EN STAGE DE PROTOTIPO
*/

#include <combat.h>
#include <mud.h>
#include <properties.h>

inherit "/std/weapon";

crear_objeto(str) {
int f,t;
 f=random(16);
 switch(f) {
  case 0: {
   TO->SetStandard(WT_ESPADA, 12, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una brillante claymore");
   TO->SetLong(
"Es una enorme espada con una larga y pesada hoja recta de la que sobresalen\n"
"dos hojas más cortas.\n");
   TO->AddId(({"espada","claymore"}));
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_ESPADA, 7, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una espada ancha");
   TO->SetLong("Es una poderosa espada ancha.\n");
   TO->AddId(({"espada","espada ancha"}));
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un martillo de guerra");
   TO->SetLong(
   "Es un martillo de guerra de buena calidad. Parece ligero y equilibrado.\n");
   TO->SetGender(GENERO_MASCULINO);
   TO->AddId(({"martillo","martillo de guerra"}));
   return 1;
  }

  case 3: {
   TO->SetStandard(WT_HACHA, 6, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un masa-kiri");
   TO->SetLong(
   "Un hacha de hoja estrecha con un largo pincho al final del mango.\n");
   TO->AddId(({"hacha","masa-kiri"}));
   TO->SetGender(GENERO_MASCULINO);
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_MAZA, 6, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una maza de pinchos");
   TO->SetLong("Es una maza metálica cubierta de afilados pinchos.\n");
   TO->AddId(({"maza","maza de pinchos"}));
   TO->SetDamageType(DT_SLASH);
   return 1;
  }
 case 5: {
   TO->SetStandard(WT_MANGUAL, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un mangual");
   TO->SetLong(
   "Un ligero mangual compuesto por tres cadenas unidas a un mango de madera.\n");
   TO->AddId(({"mangual"}));
   return 1;
  }
 case 6: {
   TO->SetStandard(WT_HACHA, 11, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un zaghnal");
   TO->SetLong(
   "Es una poderosa hacha con dos pesadas hojas curvas en forma de cuchillo.\n");
   TO->AddId(({"zaghnal","hacha"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 7: {
   TO->SetStandard(WT_MANGUAL, 10, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un mangual pesado");
   TO->SetLong(
   "Está compuesto de una pesada bola unida mediante una cadena a un mango\n"
   "de madera.\n");
   TO->AddId(({"mangual","mangual pesado"}));
   return 1;
  }
 case 8: {
   TO->SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_NINGUNO);
   TO->SetShort("un plombee");
   TO->SetLong("Una pesada maza lastrada con plomo.\n");
   TO->AddId(({"plombee","mazo"}));
   TO->SetMaterial("plomo");
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 9: {
   TO->SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un yatagán");
   TO->SetLong("Una espada curva con la hoja muy afilada.\n");
   TO->AddId(({"yatagán","espada","yatagan"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 10: {
   TO->SetStandard(WT_CUCHILLO, 3, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un kriss");
   TO->SetLong(
   "Un cuchillo de hoja larga y curvada imitando una serpiente marina.\n");
   TO->AddId(({"kriss","cuchillo"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 11: {
   TO->SetStandard(WT_LANZA, 4, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un arpón");
   TO->SetLong(
   "Un temible arpón de punta dentada. Te preguntas cómo habrá llegado aquí...\n");
   TO->AddId(({"arpón","lanza","arpon"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }

 case 12: {
   TO->SetStandard(WT_VARA, 3, P_SIZE_GENERIC, M_MADERA);
   TO->SetShort("una vara larga");
   TO->SetLong("Una vara de madera útil para pegar.\n");
   TO->AddId(({"vara","vara larga"}));
   return 1;
  }
// Esta se va, pero no se por que lo voy a sustituir...
 case 13: {
   TO->SetStandard(WT_MANOPLA, 4, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un garfio");
   TO->SetLong("Parece un gancho de carnicero, pero se engancha a la mano.\n"
                          "Sin duda fue útil para algún pirata, aunque ahora está algo oxidado.\n");
   TO->AddId(({"garfio","gancho", "garfio pirata"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
// Esto está claro que. Lo que no sé es cómo...
  case 14: {
   TO->SetStandard(WT_ESGRIMA, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un lujoso florete");
   TO->SetLong("Es un florete de hoja larga y punta afilada. La hoja brilla con un reflejo\n"
                         "azulado y la guarda está guarnecida de piedras preciosas.\n");
   TO->AddId(({"florete","lujoso florete"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
// Esta también se va a ir, pero me pasa lo mismo...
   case 15: {
   TO->SetStandard(WT_ALABARDA, 8, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una alabarda de guardia");
   TO->SetLong("Es una alabarda como las que usan los guardias. Tiene "
                          "punta de lanza y una\nhoja parecida a la de un hacha "
                          "en uno de los laterales del asta.\n");
   TO->AddId(({"alabarda","alabarda de guardia"}));
   return 1;
  }

 }
}


create() {
::create();
crear_objeto();
AddId(({"arma"}));
SetLong(QueryLong()+"Tiene grabado un extraño símbolo.\n");
AddSubDetail(({"símbolo","simbolo","extraño símbolo","extranyo símbolo",
                "extraño simbolo","extranyo simbolo"}),
                "Parece el emblema del gremio del Gremio de Guerreros.\n");
// No se puede vender, que para eso es de gratis...
Set(P_NOSELL,1);
SetResetQuality(90);
}
