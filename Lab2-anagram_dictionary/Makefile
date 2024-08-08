.PHONY: all check run clean

CXX = g++
CXX_FLAG = -Wall -std=c++11 -g -I ./header

CHECKCC = valgrind
CHECKCC_FLAG = --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

MEMORY_DIRECTORY = memory
OBJECT_DIRECTORY = object
OUTPUT_DIRECTORY = output
VERIFICATION_DIRECTORY = verification

SCRIPT_DIRECTORY = script
SOURCE_DIRECTORY = source
TESTCASE_DIRECTORY = testcase

SOURCE = $(wildcard $(SOURCE_DIRECTORY)/*.cpp)
OBJECT = $(patsubst $(SOURCE_DIRECTORY)/%.cpp, $(OBJECT_DIRECTORY)/%.o, $(SOURCE))
TESTCASE = $(wildcard $(TESTCASE_DIRECTORY)/*)

TARGET = Lab2
VERIFIER = $(SCRIPT_DIRECTORY)/verifier

all: $(TARGET)

$(MEMORY_DIRECTORY):
	mkdir $(MEMORY_DIRECTORY)

$(OBJECT_DIRECTORY):
	mkdir $(OBJECT_DIRECTORY)

$(OUTPUT_DIRECTORY):
	mkdir $(OUTPUT_DIRECTORY)

$(VERIFICATION_DIRECTORY):
	mkdir $(VERIFICATION_DIRECTORY)

$(TARGET): main.cpp $(OBJECT)
	$(CXX) $(CXX_FLAG) $^ -o $@

$(OBJECT_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.cpp | $(OBJECT_DIRECTORY)
	$(CXX) $(CXX_FLAG) -c $< -o $@

check: run | $(VERIFICATION_DIRECTORY)
	for testcase in $(TESTCASE); do \
		testcase_base=$$(basename "$$testcase"); \
		testcase_base=$${testcase_base%.*}; \
		./$(VERIFIER) "$$testcase" $(OUTPUT_DIRECTORY)/"$$testcase_base".out | tee $(VERIFICATION_DIRECTORY)/"$$testcase_base".log; \
	done

run: $(TARGET) | $(MEMORY_DIRECTORY) $(OUTPUT_DIRECTORY)
	for testcase in $(TESTCASE); do \
		testcase_base=$$(basename "$$testcase"); \
		testcase_base=$${testcase_base%.*}; \
		$(CHECKCC) $(CHECKCC_FLAG) --log-file=$(MEMORY_DIRECTORY)/"$$testcase_base.log" ./$(TARGET) "$$testcase" $(OUTPUT_DIRECTORY)/"$$testcase_base".out; \
	done

clean:
	rm -rf $(TARGET) $(MEMORY_DIRECTORY) $(OBJECT_DIRECTORY) $(OUTPUT_DIRECTORY) $(VERIFICATION_DIRECTORY)
