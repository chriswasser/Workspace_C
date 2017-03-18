# compiler settings
CC = gcc
CFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion -O3
CXX = g++
CXXFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion
LDFLAGS = -lm
# add -g  for debugging

# collect all c and c++ files
CEXAMPLES = $(shell find . -name '*.c' -print -type f)
CXXEXAMPLES = $(shell find . -name '*.cpp' -print -type f)

CTARGETS = $(CEXAMPLES:.c=.out)
CXXTARGETS = $(CXXEXAMPLES:.cpp=.out)

# build them all
all: $(CTARGETS) $(CXXTARGETS)

%.out: %.c
	$(CC) $(CFLAGS) -std=c99 $< $(LDFLAGS) -o $@

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -pthread -std=c++14 $< $(LDFLAGS) -o $@

# clean *.out files
.PHONY: clean
clean:
	rm -f *.out
