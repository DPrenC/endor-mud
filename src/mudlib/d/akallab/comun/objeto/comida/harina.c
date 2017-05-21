/*
DESCRIPCION  : un poco de harina
FICHERO      : /d/akallab/comun/objeto/comida/harina.c
MODIFICACION : 20-04-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Puajjj.. la harina no sabe a nada.\n",Pl_Name()+" se come un poco de harina.\n"}));
   SetFoodStuff(15);
   SetFoodHeal(6);
   SetShort("un poco de harina");
   SetLong("Es un poco de blanca harina de trigo.\n");
   AddId("harina");
   AddId("harina de trigo");
   AddId("comida");
   SetWeight(50);
   SetValue(20);
}
