NTL_DIR = $(ROOT)/ntl
NTL_SRC = $(NTL_DIR)/src
NTL_ALL = $(NTL_SRC)/all

NTL_BUILD_TARGET = $(NTL_ALL)

NTL_CONFIG.cmd = cd $(NTL_SRC) && ./configure CXX="$(CXX)" CXXFLAGS="$(CXXFLAGS)" PREFIX="$(PREFIX)"
ifeq (Linux,$(shell uname -s))
NTL_CONFIG.cmd += NTL_THREADS=on
endif

NTL_CHECK.cmd = $(MAKE) -C $(NTL_SRC) check
NTL_CLEAN.cmd = $(MAKE) -C $(NTL_SRC) clean; $(RM) $(NTL_ALL)
