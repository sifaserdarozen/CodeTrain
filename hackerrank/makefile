#makefile of training

#directories to discard
DISCARD_DIRS= CorrelationAndRegressionLines/.

#get all subdirectories
ALL_SUBDIRS= $(wildcard */.)

SUBDIRS= $(filter-out $(DISCARD_DIRS), $(ALL_SUBDIRS))

TARGETS= link compile clean

SUBDIRS_X_TARGETS= $(foreach t,$(TARGETS), $(addsuffix $t,$(SUBDIRS)))

.PHONY : $(TARGETS) $(SUBDIR_TARGETS)

# static pattern rule to distribute target to subdirs
$(TARGETS) : % : $(addsuffix %,$(SUBDIRS))
	@echo 'Performing "$*" target'
	@echo $(SUBDIR_TARGETS)

$(SUBDIRS_X_TARGETS) : 
	$(MAKE) -C $(@D) $(@F:.%=%) 
