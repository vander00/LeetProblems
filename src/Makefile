# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++23 -O2 -fsanitize=address  # Compiler as written in leetcode

SRCS = $(wildcard *.cpp)
BINS = $(SRCS:.cpp=)

all: $(BINS)

$(BINS): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^

clean:
	rm -f $(BINS)

.PHONY: all clean
