CXX = g++
CXXFLAGS = -g
OUTPUT_DIR = ../target/
VALGRIND = valgrind
VALGRINDFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

objects = oneedit lookandsay
all: $(objects)


$(objects): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(OUTPUT_DIR)$@
	$(VALGRIND) $(VALGRINDFLAGS) $(OUTPUT_DIR)$@

