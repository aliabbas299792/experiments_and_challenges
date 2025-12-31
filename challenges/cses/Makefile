CXX := clang++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Icommon
COMMON_SRCS := $(wildcard common/*.cpp)
COMMON_OBJS := $(COMMON_SRCS:.cpp=.o)

PROBLEM_DIRS := $(wildcard [0-9][0-9][0-9]_*)
ALL_TARGETS := $(addsuffix /.build,$(PROBLEM_DIRS))

all: $(ALL_TARGETS)

%/.build: %/main.cpp $(COMMON_OBJS)
	@name=$$(basename $* | cut -d_ -f2-); \
	$(CXX) $(CXXFLAGS) $^ -o $*/$$name.bin; \
	echo "Built $*/$$name.bin"

common/%.o: common/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f common/*.o
	rm -f [0-9][0-9][0-9]_*/*.bin

new:
	@NUM=$(word 2,$(MAKECMDGOALS)); \
	NAME=$(word 3,$(MAKECMDGOALS)); \
	if [ -z "$$NUM" ] || [ -z "$$NAME" ]; then \
		echo "Usage: make new <num> <name>"; exit 1; \
	fi; \
	PADDED=$$(printf "%03d" $$NUM); \
	DIR=$${PADDED}_$$NAME; \
	mkdir -p $$DIR; \
	if [ ! -f $$DIR/main.cpp ]; then \
		echo '#include "common.h"\n\nint main() {\n    std::cout << "Hello world!" << std::endl;\n}' > $$DIR/main.cpp; \
	fi; \
	$(MAKE) $$DIR/.build

run:
	@NUM=$(word 2,$(MAKECMDGOALS)); \
	if [ -z "$$NUM" ]; then echo "Usage: make run <number> [args]"; exit 1; fi; \
	PADDED=$$(printf "%03d" $$NUM); \
	DIR=$$(ls -d $${PADDED}_* 2>/dev/null); \
	if [ -z "$$DIR" ]; then echo "Error: No directory for $$PADDED"; exit 1; fi; \
	ARGS="$(wordlist 3,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))"; \
	$(MAKE) $$DIR/.build; \
	NAME=$$(basename $$DIR | cut -d_ -f2-); \
	echo "Running..."; \
	./$$DIR/$$NAME.bin $$ARGS

lldb:
	@NUM=$(word 2,$(MAKECMDGOALS)); \
	if [ -z "$$NUM" ]; then echo "Usage: make lldb <number>"; exit 1; fi; \
	PADDED=$$(printf "%03d" $$NUM); \
	DIR=$$(ls -d $${PADDED}_* 2>/dev/null); \
	if [ -z "$$DIR" ]; then echo "Error: No directory for $$PADDED"; exit 1; fi; \
	$(MAKE) $$DIR/.build; \
	NAME=$$(basename $$DIR | cut -d_ -f2-); \
	echo "Starting lldb..."; \
	lldb ./$$DIR/$$NAME.bin

list:
	@echo "ID   | Problem Name"
	@echo "-----|-------------------------------"
	@for dir in $(PROBLEM_DIRS); do \
		id=$${dir%%_*}; \
		name=$${dir#*_}; \
		printf "%-4s | %s\n" "$$id" "$${name//_/ }"; \
	done | sort -n

%:
	@:

.PHONY: all clean new run lldb list
