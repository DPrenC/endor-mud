
inherit THING;

create()
{
  ::create();
  SetShort("un trozo de pedernal");
  SetLong("Es un trozo de pedernal, utilizado para hacer hogueras.\n");
  SetWeight(1000);
  SetValue(20);
  AddId("pedernal");
//  SetIds(({"yesca""}));
}