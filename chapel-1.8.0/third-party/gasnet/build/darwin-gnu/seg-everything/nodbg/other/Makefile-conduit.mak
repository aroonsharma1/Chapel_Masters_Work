# This Makefile fragment is used to build GASNet conduits 
# it is not meant to be used directly 
# other/Makefile-conduit.mak.  Generated from Makefile-conduit.mak.in by configure.

.PHONY: do-error do-make-fragment libs force clean-local        \
        do-clean-local do-install-data-local do-uninstall-local \
	do-install-data-conduit do-uninstall-conduit \
	test tests tests-seq tests-par tests-parsync tests-clean \
	tests-check do-run-testexit 

# header files to be installed
# Conduit-specific headers will overwrite any conflicts in extended-ref
headers = $(top_srcdir)/extended-ref/*.h $(srcdir)/*.h $(CONDUIT_EXTRAHEADERS)

# headers to exclude from $(headers) - please don't use wildcards
# XXX: Probably not complete and we lack an automated update machanism
private_headers = gasnet_coll_autotune.h \
                  gasnet_coll_hashtable.h \
                  gasnet_coll_scratch.h \
                  gasnet_coll_team.h \
                  gasnet_coll_trees.h \
                  gasnet_extended_refcoll.h \
                  gasnet_extended_refvis.h \
                  $(CONDUIT_PRIVATEHEADERS)

#     makefile_fragments_seq =     $(CONDUIT_NAME)-seq.mak
     makefile_fragments_par =     $(CONDUIT_NAME)-par.mak 
# makefile_fragments_parsync = $(CONDUIT_NAME)-parsync.mak
makefile_fragments = $(makefile_fragments_seq) $(makefile_fragments_par) $(makefile_fragments_parsync)


#GASNET_SEGMENT_STR="FAST"
#GASNET_SEGMENT_STR="LARGE"
GASNET_SEGMENT_STR="EVERYTHING"

include $(top_builddir)/other/Makefile-libgasnet.mak

EXTRA_DIST = $(CONDUIT_FILELIST) README

docdir = $(datadir)/doc/gasnet

# convenience aliases
seq par parsync: force
	@$(MAKE) $(CONDUIT_NAME)-$@.mak libgasnet-$(CONDUIT_NAME)-$@.a
	@for dir in $(SUBDIRS) ; do 		\
	  if test "$$dir" != "." ; then 	\
	    ( cd $$dir && $(MAKE) all ) || exit 1 ; 	\
	  fi ;					\
	 done

# test targets 

tests: force
	@echo You must specify one of tests-seq, tests-par or tests-parsync
	@exit 1

test: tests

TESTINSTANCE=$${PPID:-xxxx}
TESTLOG=`pwd`/.test-results
TESTLOG_INHERIT=0

do-begin-tests do-end-tests:
	@if test "$(TESTLOG_INHERIT)" = "0"; then \
          ( cd "$(top_builddir)" && $(MAKE) TESTINSTANCE=$(TESTINSTANCE) TESTLOG=$(TESTLOG) $@ ) || exit $$? ; \
        fi

tests-seq: force libgasnet-$(CONDUIT_NAME)-seq.a $(CONDUIT_NAME)-seq.mak $(CONDUIT_SEQ_HOOK)
	@echo "*** Building all GASNet tests in SEQ/$(GASNET_SEGMENT_STR) mode ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile tests-seq \
	  configfile="$(CONDUIT_NAME)-seq.mak" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

tests-parsync: force libgasnet-$(CONDUIT_NAME)-parsync.a $(CONDUIT_NAME)-parsync.mak $(CONDUIT_PARSYNC_HOOK)
	@echo "*** Building all GASNet tests in PARSYNC/$(GASNET_SEGMENT_STR) mode ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile tests-parsync \
	  configfile="$(CONDUIT_NAME)-parsync.mak" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

tests-par: force libgasnet-$(CONDUIT_NAME)-par.a $(CONDUIT_NAME)-par.mak $(CONDUIT_PAR_HOOK)
	@echo "*** Building all GASNet tests in PAR/$(GASNET_SEGMENT_STR) mode ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile tests-par \
	  configfile="$(CONDUIT_NAME)-par.mak" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

tests-mpi: force 
	@echo "*** Building all MPI tests ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile tests-mpi \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

tests-mpi2: force 
	@echo "*** Building all MPI2 tests ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile tests-mpi2 \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

testtools: force 
	@$(MAKE) $(CONDUIT_NAME)-$(THREAD_MODEL_LC).mak
	@echo "*** Building $@ ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile $@   \
	  configfile="$(CONDUIT_NAME)-$(THREAD_MODEL_LC).mak" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

test%: $(top_srcdir)/tests/test%.c force 
	@$(MAKE) libgasnet-$(CONDUIT_NAME)-$(THREAD_MODEL_LC).a $(CONDUIT_NAME)-$(THREAD_MODEL_LC).mak
	@echo "*** Building $@ in $(THREAD_MODEL)/$(GASNET_SEGMENT_STR) mode ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile $@   \
	  configfile="$(CONDUIT_NAME)-$(THREAD_MODEL_LC).mak" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

test%: $(top_srcdir)/tests/test%.cc force 
	@$(MAKE) libgasnet-$(CONDUIT_NAME)-$(THREAD_MODEL_LC).a $(CONDUIT_NAME)-$(THREAD_MODEL_LC).mak
	@echo "*** Building $@ in $(THREAD_MODEL)/$(GASNET_SEGMENT_STR) mode ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile $@   \
	  configfile="$(CONDUIT_NAME)-$(THREAD_MODEL_LC).mak" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

test%: $(top_srcdir)/tests/mpi/test%.c force 
	@echo "*** Building MPI test $@ ***"
	@$(MAKE) -f $(top_builddir)/tests/Makefile $@   \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

test%-seq: force 
	@$(MAKE) `basename $@ -seq` THREAD_MODEL=SEQ
test%-parsync: force 
	@$(MAKE) `basename $@ -parsync` THREAD_MODEL=PARSYNC
test%-par: force 
	@$(MAKE) `basename $@ -par` THREAD_MODEL=PAR

tests-clean: 
	@$(MAKE) -f $(top_builddir)/tests/Makefile clean \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS)

check-run-tests-deps: force
	@if test "$(SUBDIRS)" != "" ; then 	\
	   for dir in "$(SUBDIRS)" ; do 	\
	     if test "$$dir" != "."; then       \
	   	( cd "$$dir" && $(MAKE) ) || exit $$?;	\
             fi ;                               \
	   done ;				\
	 fi

run-tests do-run-testexit: check-run-tests-deps
	@$(MAKE) TESTINSTANCE=$(TESTINSTANCE) TESTLOG=$(TESTLOG) do-begin-tests
	@$(MAKE) -f $(top_builddir)/tests/Makefile $@ \
	  TESTINSTANCE=$(TESTINSTANCE) TESTLOG=$(TESTLOG) \
	  CONDUIT_NAME=$(CONDUIT_NAME) \
	  CONDUIT_RUNCMD="$(CONDUIT_RUNCMD)" \
	  CONDUIT_TESTS="$(CONDUIT_TESTS)" $(CONDUIT_TEST_MAKEARGS) ; \
	 $(MAKE) TESTINSTANCE=$(TESTINSTANCE) TESTLOG=$(TESTLOG) do-end-tests

# these are separate make commands to ensure they can be composed 
# and still get multiple run-tests invocations
run-tests-seq: tests-clean
	$(MAKE) tests-seq run-tests
run-tests-par: tests-clean
	@$(MAKE) tests-par run-tests
run-tests-parsync: tests-clean 
	@$(MAKE) tests-parsync run-tests
run-tests-mpi: tests-clean 
	@$(MAKE) tests-mpi run-tests
run-tests-mpi2: tests-clean 
	@$(MAKE) tests-mpi2 run-tests

.PRECIOUS: run-testexit
run-testexit: force
	@if test ! -x testexit ; then \
	  $(MAKE) testexit-par || exit $$? ; \
	fi
	@$(MAKE) do-run-testexit	

#tests-check:
#	@echo "checking for diagnostic export..."
#	@symbols=`/opt/local/bin/nm testgasnet 2>&1 | grep gasneti_run_diagnostics`; \
#   if test "$$symbols" ; then                                      \
#       echo "$$symbols" ;                                          \
#       echo FAILED ;                                               \
#       failed=1 ;                                                  \
#   else                                                            \
#       echo PASSED ;                                               \
#   fi ;                                                            \
#   exit $$failed

tests-check:
	@echo "diagnostic export test SKIPPED"

#     check_test_target = tests-seq
# check_test_target = tests-parsync
     check_test_target = tests-par
check: force
	@CHECK_TEST_TARGET_OVERRIDE=$(CHECK_TEST_TARGET_OVERRIDE) ; \
	$(MAKE) check-exports $${CHECK_TEST_TARGET_OVERRIDE:-$(check_test_target)} tests-check

force:

do-clean-local: tests-clean
	@echo rm -f $(makefile_fragments) $(libgasnet_objects) $(libraries) *.o core .test-results
	@rm -f $(makefile_fragments) $(libgasnet_objects) $(libraries) *.o core .test-results
	@rm -Rf .SEQ .PAR .PARSYNC


do-install-data-local: force $(headers) $(makefile_fragments)
	$(mkinstalldirs) $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit
	@list='$(headers)'; privlist='$(private_headers)'; \
         for p in $$list; do \
	  if test -f $$p; then \
	    filename=`basename $$p`; \
            for q in $$privlist; do \
              if test "$$filename" = "$$q"; then filename=something_internal.h; break; fi; \
            done; \
            if test "$$filename" = "`basename $$p _internal.h`" ; then \
	    echo " $(INSTALL_DATA) $$p $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit/$$filename"; \
	    $(INSTALL_DATA) $$p $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit/$$filename || exit $$? ; \
	    else :; fi; \
	  else :; fi; \
	done
	@list='$(makefile_fragments)'; for p in $$list; do \
	  if test -f $$p; then \
	    filename=`basename $$p`; \
	    echo "sed -e '/###NOINSTALL###/d' -e 's@###INSTALL_PREFIX###@$(prefix)@g' < $$p > $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit/$$filename"; \
	    sed -e '/###NOINSTALL###/d' -e 's@###INSTALL_PREFIX###@$(prefix)@g' < $$p > $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit/$$filename || exit $$? ; \
	  else :; fi; \
	done
	$(mkinstalldirs) $(DESTDIR)$(docdir)
	$(INSTALL_DATA) $(srcdir)/README $(DESTDIR)$(docdir)/README-$(CONDUIT_NAME)
	if test -f $(srcdir)/license.txt ; then \
	  $(INSTALL_DATA) $(srcdir)/license.txt $(DESTDIR)$(docdir)/license-$(CONDUIT_NAME).txt || exit $$? ; \
        fi
	if test "$(conduit_has_install_data_hook)" = yes; then \
	  $(MAKE) do-install-data-conduit || exit $$? ; \
	fi

do-uninstall-local:
	rm -f $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit/*.h $(DESTDIR)$(includedir)/$(CONDUIT_NAME)-conduit/*.mak
	rm -Rf $(DESTDIR)$(docdir)
	if test "$(conduit_has_uninstall_hook)" = yes; then \
	  $(MAKE) do-uninstall-conduit || exit $$? ; \
	fi

do-error: 
	@echo "ERROR: $(CONDUIT_NAME)-conduit support was not detected at configure time"
	@echo "       try re-running configure with --enable-$(CONDUIT_NAME)"
	@exit 1

$(top_builddir)/other/Makefile-conduit.mak: $(top_srcdir)/other/Makefile-conduit.mak.in
	cd $(top_builddir)/other && $(MAKE) Makefile-conduit.mak

$(top_builddir)/other/fragment-body.mak: $(top_srcdir)/other/fragment-body.mak.in
	cd $(top_builddir)/other && $(MAKE) fragment-body.mak

$(top_builddir)/other/fragment-head.mak: $(top_srcdir)/other/fragment-head.mak.in
	cd $(top_builddir)/other && $(MAKE) fragment-head.mak

$(top_builddir)/tests/Makefile: $(top_srcdir)/tests/Makefile.in
	cd $(top_builddir)/tests && $(MAKE) Makefile

Makefile: $(srcdir)/Makefile.am 			\
          $(top_builddir)/other/Makefile-conduit.mak 	\
          $(top_builddir)/other/Makefile-libgasnet.mak 	\
          $(top_builddir)/tests/Makefile
	cd $(top_builddir) && CONFIG_FILES=$(CONDUIT_NAME)-conduit/$@ CONFIG_HEADERS= ./config.status

make_fragment_deps = conduit.mak $(top_builddir)/other/fragment-head.mak $(top_builddir)/other/fragment-body.mak

$(CONDUIT_NAME)-seq.mak: $(make_fragment_deps)
	$(MAKE) do-make-fragment thread_model=seq THREAD_MODEL=SEQ

$(CONDUIT_NAME)-par.mak: $(make_fragment_deps)
	@#$(MAKE) do-pthreads-error
	$(MAKE) do-make-fragment thread_model=par THREAD_MODEL=PAR

$(CONDUIT_NAME)-parsync.mak: $(make_fragment_deps)
	@#$(MAKE) do-pthreads-error
	$(MAKE) do-make-fragment thread_model=parsync THREAD_MODEL=PARSYNC

do-make-fragment: force
	rm -f $(CONDUIT_NAME)-$(thread_model).mak
	@echo Building $(CONDUIT_NAME)-$(thread_model).mak... ;                             \
	AUTOGENMSG='WARNING: This file is automatically generated - do NOT edit directly' ; \
	cat $(top_builddir)/other/fragment-head.mak                                         \
	    conduit.mak                                                                     \
	    $(top_builddir)/other/fragment-body.mak |                                       \
	sed -e 's@#conduit_name#@$(CONDUIT_NAME)@g'                                         \
	    -e 's@#THREAD_MODEL#@$(THREAD_MODEL)@g'                                         \
	    -e 's@#thread_model#@$(thread_model)@g'                                         \
	    -e '/#INSTRUCTIONS#/d'                                                          \
	    -e "s@#AUTOGEN#@$${AUTOGENMSG}@g"                                               \
	> $(CONDUIT_NAME)-$(thread_model).mak || exit 1
