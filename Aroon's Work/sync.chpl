var sync$: sync int;
begin {
	var foo = sync$;
	writeln("Task unblocked");
}

writeln("Task blocked");
sync$ = 1;
