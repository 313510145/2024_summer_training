.PHONY: all run check clean clear

CXX = g++
CXX_FLAG = -Wall -std=c++11 -g -I ./include

INCLUDE_DIRECTORY = include
SOURCE_DIRECTORY = source
OBJECT_DIRECTORY = object
TESTCASE_DIRECTORY = testcase
OUTPUT_DIRECTORY = output
LOG_DIRECTORY = log
SCRIPT_DIRECTORY = script

SOURCE = $(wildcard $(SOURCE_DIRECTORY)/*.cpp)
OBJECT = $(patsubst $(SOURCE_DIRECTORY)/%.cpp, $(OBJECT_DIRECTORY)/%.o, $(SOURCE))
TESTCASE = $(wildcard $(TESTCASE_DIRECTORY)/*)

TARGET = Lab2
VERIFIER = $(SCRIPT_DIRECTORY)/verifier

all: $(TARGET)

$(OBJECT_DIRECTORY):
	mkdir $(OBJECT_DIRECTORY)

$(OUTPUT_DIRECTORY):
	mkdir $(OUTPUT_DIRECTORY)

$(LOG_DIRECTORY):
	mkdir $(LOG_DIRECTORY)

$(TARGET): main.cpp $(OBJECT)
	$(CXX) $(CXX_FLAG) $^ -o $@

$(OBJECT_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.cpp | $(OBJECT_DIRECTORY)
	$(CXX) $(CXX_FLAG) -c $< -o $@

run: $(TARGET) | $(OUTPUT_DIRECTORY)
	for testcase in $(TESTCASE); do \
		testcase_base=$$(basename "$$testcase"); \
		testcase_base=$${testcase_base%.*}; \
		./$(TARGET) "$$testcase" $(OUTPUT_DIRECTORY)/"$$testcase_base".out; \
	done

check: run | $(LOG_DIRECTORY)
	for testcase in $(TESTCASE); do \
		testcase_base=$$(basename "$$testcase"); \
		testcase_base=$${testcase_base%.*}; \
		./$(VERIFIER) "$$testcase" $(OUTPUT_DIRECTORY)/"$$testcase_base".out | tee $(LOG_DIRECTORY)/"$$testcase_base".log; \
	done

clear:
	rm -rf $(TARGET) $(OBJECT_DIRECTORY) $(OUTPUT_DIRECTORY) $(LOG_DIRECTORY)

clean:
	rm -rf $(TARGET) $(OBJECT_DIRECTORY)
