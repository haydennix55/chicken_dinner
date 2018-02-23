CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/app
TESTTARGET := bin/test
DSYM := bin/*.dSYM
TEST := test/test.cpp
TESTLINK := test/test.cpp src/Blackjack.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++11 -g # -Wall
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	@mkdir -p bin
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

test: $(OBJECTS)
	 $(CC) $(CFLAGS) $(TEST) $(INC) -c -o $(BUILDDIR)/test.o
	 $(CC) $(CFLAGS) $(TESTLINK) $(INC) -o $(TESTTARGET)

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) bin/test $(DSYM)

.PHONY: clean test
