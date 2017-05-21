inherit ROOM;

create() {
::create();
SetLocate("gremio de hechiceros");
SetIntBright(50);
SetIntShort("unas escaleras");
SetIntLong(W("Estas en las escaleras que comunican los distintos pisos"
" de la torre del gremio estan realizadas en marmol esqueisitamente tallado"
" si miras hacia arriba puedes verte reflejado en el pulido techo."
" Ves un cartel dorado colgado en una pared.\n"));
SetIndoors(1);
AddDetail(({"cartel"}),W("Es un pequeño cartel dorado, podrias leerlo, asi podiras saber lo que pone.\n"));
AddReadMsg(({"cartel"}),W(
"El cartel pone:\n"
"La habitacion del oraculo se encuentra al oeste, al suroeste la sala de los guildmasters del gremio "
" y al sur la sala de conferencias del gremio.\n"
));

AddExit("suroeste","./master");
AddExit("oeste","./oraculo");
AddExit("sur","./sala");
AddExit("abajo","./esca1");
}

 