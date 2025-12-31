CXX := clang++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Icommon
COMMON_SRCS := $(wildcard common/*.cpp)
COMMON_OBJS := $(COMMON_SRCS:.cpp=.o)

PROBLEM_DIRS := $(filter-out common,$(subst /,,$(dir $(wildcard */))))
BINARIES := $(foreach d,$(PROBLEM_DIRS),$(patsubst %.cpp,$(d)/%.bin,$(notdir $(wildcard $(d)/*.cpp))))

all: $(BINARIES)

$(BINARIES): %.bin: %.cpp $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

common/%.o: common/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f common/*.o $(PROBLEM_DIRS:%=%/*.o) $(BINARIES)

.PHONY: all clean
