inherit "/std/container";

void
create()
{
   ::create();
   SetAds( ({"un","el"}) );
   AddId("mortero");
   SetShort("un mortero");
   SetLong("Es un mortero de madera. Sirve para machacar especias.\n");
   SetWeight(500);
   SetMaxIntWeight(1000);
   SetValue(10000);
}

int IsMortar() { return 1; }
