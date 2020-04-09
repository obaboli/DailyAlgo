CXX = g++
CXXFLAGS = -g
OUTPUT_DIR = ../target/

objects = ll llt
all: $(objects)


$(objects): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(OUTPUT_DIR)$@

