CXX = g++
CXXFLAGS = -g
OUTPUT_DIR = ../target/

objects = sqrt
all: $(objects)


$(objects): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(OUTPUT_DIR)$@

