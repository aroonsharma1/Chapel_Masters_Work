writeln('CHPL_HOME: ', CHPL_HOME);
writeln('CHPL_HOST_PLATFORM: ', CHPL_HOST_PLATFORM);
writeln('CHPL_HOST_COMPILER: ', CHPL_HOST_COMPILER);
writeln('CHPL_TARGET_PLATFORM: ', CHPL_TARGET_PLATFORM);
writeln('CHPL_TARGET_COMPILER: ', CHPL_TARGET_COMPILER);
writeln('CHPL_LOCALE_MODEL: ', CHPL_LOCALE_MODEL);
if(CHPL_LOCALE_MODEL == 'acc') then {
    writeln('  CHPL_ACC_CODEGEN: ', CHPL_ACC_CODEGEN);
}
writeln('CHPL_COMM: ', CHPL_COMM);
if CHPL_COMM != 'none' && CHPL_COMM != 'ugni' then {
  writeln('  CHPL_COMM_SUBSTRATE: ', CHPL_COMM_SUBSTRATE);
  if CHPL_COMM == 'gasnet' then
    writeln('  CHPL_GASNET_SEGMENT: ', CHPL_GASNET_SEGMENT);
}
writeln('CHPL_TASKS: ', CHPL_TASKS);
writeln('CHPL_LAUNCHER: ', CHPL_LAUNCHER);
writeln('CHPL_TIMERS: ', CHPL_TIMERS);
writeln('CHPL_MEM: ', CHPL_MEM);
writeln('CHPL_MAKE: ', CHPL_MAKE);
writeln('CHPL_ATOMICS: ', CHPL_ATOMICS);
if CHPL_COMM != 'none' then
  writeln('  CHPL_NETWORK_ATOMICS: ', CHPL_NETWORK_ATOMICS);
writeln('CHPL_GMP: ', CHPL_GMP);
writeln('CHPL_HWLOC: ', CHPL_HWLOC);
writeln('CHPL_REGEXP: ', CHPL_REGEXP);
writeln('CHPL_WIDE_POINTERS: ', CHPL_WIDE_POINTERS);
writeln('CHPL_LLVM: ', CHPL_LLVM);
writeln('CHPL_AUX_FILESYS: ', CHPL_AUX_FILESYS);
