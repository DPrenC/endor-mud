
inherit THING;

m()
{
  write("EEE\n");
  return 1;
}

create()
{
  ::create();
  SetShort("una cerilla");
  SetLong("Una cerilla");
  SetWeight(1);
  SetValue(5);
  SetIds(({"cerilla","cerillas"}));
}

init()
{
  ::init();
  add_action("m", "miral");
}