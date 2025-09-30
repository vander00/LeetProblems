# Compiler and flags
CXX = clang++   # Use clang++ instead of g++
CXXFLAGS = -std=c++17  # Compiler flags (adjust as needed)

# Find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)
# Generate a list of binary names from the source files (strip the extension)
BINS = $(SRCS:.cpp=)

# Default target: Compile all source files into their respective binaries
all: $(BINS)

# Rule to compile each .cpp file into its corresponding binary
$(BINS): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^

# Clean up generated binaries
clean:
	rm -f $(BINS)

.PHONY: all clean
