/*   licor.c
     Creado por : Nemesis
     Fecha 24-09-98
     Una botella de licor aleatoria para las bodegas del castillo...
*/

#include <properties.h>

inherit FOOD;

private string forma,tipo,tlicor;

crear_botella(str) {
int f,t;
 f=random(6);
 t=random(5);
 switch(f) {
  case 0:forma="redonda";
         break;
  case 1:forma="cuadrada";
         break;
  case 2:forma="grande";
         break;
  case 3:forma="pequenya";
         break;
  case 4:forma="de cuello largo";
         break;
  case 5:forma="de cristal";
         break;
 }
switch(t) {
 case 0..2:tipo=" botella ";
           TO->AddId(({"botella"}));
           break;
 case 3 : tipo=" petaca ";
          TO->AddId(({"petaca"}));
          break;
 case 4 : tipo =" garrafa ";
          TO->AddId(({"garrafa"}));
	  break;
 }
  return str+tipo+forma;
}


tipo_licor(string str1) {

int tv;
tv=random(8);
switch(tv) {
 case 0:tlicor="vodka";
        TO->SetFoodAlc(85);
        TO->AddId(({"vodka"}));
        break;
 case 1:tlicor="ginebra";
        TO->SetFoodAlc(65);
        TO->AddId(({"ginebra","gin"}));
        break;
 case 2:tlicor="pacharan";
        TO->SetFoodAlc(60);
        TO->AddId(({"pacharan"}));
        break;
 case 3:tlicor="licor de frutas del bosque";
        TO->SetFoodAlc(50);
        TO->AddId(({"licor de frutas del bosque"}));
        break;
 case 4:tlicor="ron";
        TO->SetFoodAlc(60);
        TO->AddId(({"ron"}));
        break;
 case 5:tlicor="whisky";
        TO->SetFoodAlc(80);
        TO->AddId(({"whisky"}));
        break;
 case 6:tlicor="anis";
        TO->SetFoodAlc(55);
        TO->AddId(({"anis"}));
        break;
 case 7:tlicor="brandy";
        TO->SetFoodAlc(55);
        TO->AddId(({"brandy"}));
        break;
 }
 return str1+tlicor;
}



create() {
::create();
SetShort(crear_botella("una"));
SetLong(tipo_licor("Contiene ")+".\n");
AddId(({"licor","PCN"}));
Set(P_NOGIVE,"No vas a dar el fruto de tu trabajo, no?\n");
Set(P_NODROP,
"Con lo que te ha costado conseguirlo, solo faltaria que lo perdieras...\n");
SetFoodKind("drink");
SetFoodSoak(5);
Set(P_GENDER, GENDER_MALE);
Set(P_NUMBER, NUMBER_PLURAL);
SetFoodMsgs(({"Te bebes la"+tipo+"de "+tlicor+" de un trago!\n"}));
SetWeight(1000);
SetValue(5);
}
