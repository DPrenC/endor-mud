/* /std/shop/dustbin
   =================
   03-03-03 [t] Añadido este cubo por defecto, para que la gente no haga el
   		truco de "poner X en cubo", que fastidiaba ciertos quests.
   05-03-03 [t] Arreglo el remove() del objeto entrante...
*/

inherit "/std/container";

private void _remove_object(object obj) {
	write("Oyes un desagradable sonido de algo que es irremediablemente destruido...\n");
	obj->remove();
}

public void notify_enter(mixed from,int method,mixed extra) {
/*	dtell("theuzifan", sprintf("PO %O, TO %O, TP %O\n", PO, TO, TP));	*/
	if (!interactive(PO)) {
		call_out(SF(_remove_object), 1, PO);
	}
}

create() {
	::create();
	SetIds(({"un cubo de basura", "cubo"}));
	SetAds(({"grande", "papelera"}));
	SetWeight(0);
	SetShort("un cubo de basura");
	SetLong("Un reluciente cubo de basura.\n"
	        "Puedes tirar objetos inutiles en él.\n");
	SetNoGet("La cosa que habita el cubo suelta un gruñido que te hace cambiar de idea.\n");
}
