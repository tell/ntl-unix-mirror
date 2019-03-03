ROOT := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))
PREFIX = $(ROOT)/prefix

# Configurations for compilers:

CXXFLAGS = -std=c++11 -O2 -g3 -Wall -Wextra
# -fsanitize=address -fsanitize=leak -fsanitize=undefined
ifeq (Linux,$(shell uname -s))
CXXFLAGS += -pthread
endif
CC = $(CXX)
CFLAGS = $(CXXFLAGS)
