SOURCES = $(wildcard *.cpp)
EXECS = $(SOURCES:%.cpp=%)
CFLAGS = -std=c++11


all: $(EXECS)

%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<

.PHONY: all clean