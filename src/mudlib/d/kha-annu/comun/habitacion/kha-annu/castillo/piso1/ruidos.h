/* Coded by Kayra.
   Performed by Yandros to Grishnak Castle.
   Modificado por [i] Izet@Simauria para implementar al castillo Kha-annu.
   Ultima modificacion: 2 Oct, 1997
 */ 
init()  {
::init();
call_out("voces",1);
}

voces(int x) {
x=random(4);
if (x>2)
	{
tell_room(this_object(),
"Oyes algunos gritos distantes... Parecen voces que provienen de algun lugar\n\
bajo tus pies.\n");
	} 
if (x<2)
	{
tell_room(this_object(),
"Escuchas unos ruidos lejanos de algo metalico chocando contra las rocas justo\n\
debajo de ti.\n");
	}
}
