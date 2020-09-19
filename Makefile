# Name of the project
PROJECT_NAME = snake&ladder

# Output directory
BUILD = build

# All source code files
SRC = project_main.c\
src/snake&ladder.c\

# All test source files
TEST_SRC = src/snake&ladder.c\
test/test_snake&ladder.c

TEST_OUTPUT = $(BUILD)/Test_$(snake&ladder).out

# All include folders with header files
INC	= -Iinc

PROJECT_OUTPUT = $(BUILD)/$(snake&ladder).out

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(snake&ladder):all

# Run the target even if the matching name exists
.PHONY: run clean test  doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out

# Call `make run` to run the application
run:$(snake&ladder)
	./$(PROJECT_OUTPUT).out

# Document the code using Doxygen
doc:
	make -C ./documentation

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) -lcunit
	./$(TEST_OUTPUT)

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

# Create new build folder if not present
$(BUILD):
	mkdir build
