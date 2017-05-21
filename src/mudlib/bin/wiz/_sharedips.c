// comando sharedips. Devuelve los jugadores que están conectados desde la misma IP.

public int main(string str)
{
    object *usuarios;
    string *ips = ({}), *nombres = ({}), *coincidencias, mensaje = "";
    mixed compartidas;
    int pos, i, j, mostrar_ip, count;

    if (str && str != "ip")
    {
        return notify_fail("Sintaxis: 'sharedips', o 'sharedips ip'.\n");
    }
    if (str) mostrar_ip = 1;
    if (sizeof(usuarios = users()) == 1)
    {
        return notify_fail("No hay jugadores compartiendo IP.\n");
    }

    // reservamos memoria para la mitad de los usuarios, que es el máximo
    // número posible de parejas de clones
    compartidas = allocate(sizeof(usuarios) / 2);
    // asignamos a <ips> y <nombres> las ips y los nombres de los usuarios conectados
    foreach(object us:usuarios)
    {
        ips += ({query_ip_number(us)});
        nombres += ({CAP(us->QueryRealName())});
    }
    for (i=sizeof(nombres);i--;)
    // recorremos el array de usuarios
    {
        coincidencias = ({});
        while ((pos = member(ips,ips[i])) >= 0 && pos != i)
        // mientras que haya ips coincidentes y no sea la de la posición del
        //array en la que está i
        {
            // añadimos el nombre al array de coincidencias
            coincidencias += ({nombres[pos]});
            // borramos el elemento del array de nombres y de ips
            nombres = nombres[0..pos - 1] + nombres[pos + 1..];
            ips = ips[0..pos - 1] + ips[pos + 1..];
            i--;
        }
        if (sizeof(coincidencias))
        // si existen coincidencias, se añaden al array de clones
        {
            compartidas[j] = ({ips[i],nombres[i]}) + coincidencias;
            j++;
        }
    }
    // quitamos los elementos vacíos
    compartidas = filter(compartidas,(:$1:));

    if (!(count = sizeof(compartidas)))
    // no hay clones
    {
        return notify_fail("No hay jugadores compartiendo IP.\n");
    }

    for (i=sizeof(compartidas);i--;)
    // recorremos la lista de clones para componer el mensaje que se enviará
    // al wiz
    {
        string l1 = compartidas[i][<1][0..0]; // primera letra del último nombre
        // esto de la letra lo hago para evitar concatenaciones del tipo:
        // Kastwey y Iltwing
        mensaje += implode(compartidas[i][1..<2], ", ") +
                   (l1 == "I" ? " e " : " y ") + compartidas[i][<1] + " comparten "
                   "la misma IP" +
                   (mostrar_ip ? ": " + compartidas[i][0] + " (" +
                   "/lib/country"->resolve_ip_number(compartidas[i][0]) + ")" : "") +
                   ".\n";
    }
    if (count == 1)
    {
        mensaje += "Se ha encontrado un conjunto de IPs coincidentes.\n";
    }
    else
    {
        mensaje += "Se han encontrado " + count + " conjuntos de IPs coincidentes.\n";
    }
    write(mensaje);
    return 1;
}