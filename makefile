#########################################
# Directory where to put the object files
OBJDIR = .

#########################################
# Directory where to locate source files
SRCDIR = .

#########################################
# Compiler
CC=g++

######################
# All the object files 
OBJFILES = $(OBJDIR)/main.o $(OBJDIR)/Map.o $(OBJDIR)/Case.o $(OBJDIR)/Ressource.o $(OBJDIR)/Player.o $(OBJDIR)/Piece.o $(OBJDIR)/Settlement.o Road.o

###############
# All the flagss
DEBUGFLAGS = -O5 -g -DDEBUG -m64 -L /lib64 `pkg-config gtkmm-3.0 --cflags`	
STFLAGS    = -DLCB -DLENGTHTYPE=Uint -pthread -std=c++0x `pkg-config gtkmm-3.0 --libs`

jeu: $(OBJFILES)
	$(CC) $^ $(STFLAGS) -o $(SRCDIR)/$@

# How to make the object files:
$(OBJDIR)/%.o: $(OBJDIR)/%.cpp
	$(CC) $(DEBUGFLAGS) -c $? -o $@

# Cleaning target (only works with fileutils):
clean:
	/bin/rm -f $(OBJDIR)/*.o jeu main.o
 
