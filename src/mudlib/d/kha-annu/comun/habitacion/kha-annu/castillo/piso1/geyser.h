/* Coded by Izet to Aurora MUD.
   Performed by Yandros to Grishnak Castle.
   Modificado por [i] Izet@Simauria para implementar al castillo Kha-annu.
   Ultima modificacion: 2 Oct, 1997
 */ 
init()  {
::init();
    call_out("geyser",59);
}

geyser(int x) {
x=random(3);
if (x==0)
	{
tell_room(this_object(),
"El suelo empieza a temblar y el geyser despide agua de una forma descomunal.\n\
Ahora el chorro de agua alcanza unos dieciseis metros de altura. Es algo\n\
increible.\n");
call_out("geyser",60);
	}
if (x==1)
	{
tell_room(this_object(),
"De repente el geyser despide un enorme chorro de agua que se eleva unos seis\n\
metros y la gente lo mira sonriente.\n");
call_out("geyser",60);
	} 
if (x==2)
	{
tell_room(this_object(),
"El geyser empieza a vibrar y emite un chorro de agua que alcanza los tres\n\
metros. La gente de dentro de la piscina se pone debajo para que el agua\n\
caiga sobre ellos.\n");
call_out("geyser",60);
	} 
if (x==3)
	{
tell_room(this_object(),
"El geyser vibra y emite un pequenyo chorrito de agua.\n");
call_out("geyser",60);
	}
}
