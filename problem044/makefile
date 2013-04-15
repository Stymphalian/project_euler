CC=gcc
CFLAGS=-c -ansi -Wall
INFLAGS=-Iinclude -I..\archive
LDFLAGS=-L..\archive -ltakamina


OBJDIR:=objdir
SOURCES=main.c
OBJECTS=$(addprefix $(OBJDIR)\, $(SOURCES:.c=.o) )

EXECUTABLE=noin

#-g  allow for debug mode 
#-E  macro expanded






all: $(SOURCES) $(EXECUTABLE)

$(OBJDIR)\\%.o: %.c
	$(CC) $(CFLAGS) $(INFLAGS) $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)








# Setup objects directory
$(OBJECTS): | $(OBJDIR)
$(OBJDIR):
	mkdir $(OBJDIR)

# clean methods
clean:
	rmdir /s /q $(OBJDIR) 2> nul
