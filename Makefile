CC = gcc
CFLAGS = -W -Wall -std=c99 -pedantic -O2 -g0
SRC = test_replace.c rtf_replace.c
HDR = rtf_replace.h
# SDTEST_SRC = testdict.c sdict.c
# SDTEST_HDR = sdict.h
MFILE = Makefile

all: rtf_replace

rtf_replace: $(SRC) $(MFILE) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $@

# sdtest: $(SDTEST_SRC) $(MFILE) $(SDTEST_HDR) 
#         $(CC) $(CFLAGS) $(SDTEST_SRC) -o $@

clean:
	-rm -f rtf_replace *~ core result.rtf
