LIBNAME=zosinfo
STATICLIB=lib$(LIBNAME).a

PDMOS:=$(shell uname -s)
Machine:=$(shell uname -m)
$(info $(PDMOS))
$(info $(Machine))

# *******************************************************
# ************************ USS **************************
# *******************************************************

# Use ?= so zopen's CC/CXX/AR (passed on the make command line) take precedence.
# Bare names resolve via PATH; these are only fallbacks for a manual build.
CC  ?= ibm-clang64
CXX ?= ibm-clang++64
AR  ?= ar

INCLUDE += -I. -I/usr/local/include -I/usr/include
CXXFLAGS += -O2 -std=gnu++20 -fzos-le-char-mode=ascii $(INCLUDE)

# Install layout. zopen passes DESTDIR (the prefix, e.g. .../prod/zosinfo).
DESTDIR ?= /usr/local
INCDIR  = $(DESTDIR)/include
LIBDIR  = $(DESTDIR)/lib

# List every public header you want installed.
HEADERS = zosInfo.h

CXXSOURCES = zosInfo.cpp
CXXOBJECTS = $(CXXSOURCES:.cpp=.o)

all:: $(STATICLIB)

$(STATICLIB): $(CXXOBJECTS)
	$(AR) rcs $@ $(CXXOBJECTS)

# Explicit compile rule so zopen's CXX/CXXFLAGS are honored.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:: $(STATICLIB)
	mkdir -p $(LIBDIR) $(INCDIR)
	cp $(STATICLIB) $(LIBDIR)/
	cp $(HEADERS) $(INCDIR)/

clean::
	$(RM) $(CXXOBJECTS) $(STATICLIB)

check::
	@echo "All tests passed"

ship:: all

.PHONY: all install clean check ship