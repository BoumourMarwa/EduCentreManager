# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Source files directory
SRCDIR = src

# Object files directory
OBJDIR = obj

# Source files
SRCS = $(SRCDIR)/Etudiant5eme.cpp $(SRCDIR)/Etudiant6eme.cpp $(SRCDIR)/EtudiantBac.cpp \
       $(SRCDIR)/Etudiant.cpp $(SRCDIR)/Enseignant.cpp $(SRCDIR)/GestionnaireCentre.cpp $(SRCDIR)/Groupe.cpp \
       $(SRCDIR)/Matiere.cpp $(SRCDIR)/Personne.cpp $(SRCDIR)/Seance.cpp

# Object files
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Output binary name
TARGET = mon_programme

# Make all rule
all: $(TARGET)

# Rule to link object files and generate the executable
$(TARGET): $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile .cpp files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directory for object files if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean rule
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Run rule
run:
	./$(TARGET)
