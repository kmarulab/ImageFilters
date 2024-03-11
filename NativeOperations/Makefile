# Configure compiler settings
CXX=clang++
CXXFLAGS=-gdwarf-4 -std=c++11 -Werror -D_GLIBCXX_DEBUG
# The object files for the picfilter program.
OFILES = file_ops.o image_ops.o

# This target builds your main program.
main: $(OFILES) main.o protect_test_data
	$(CXX) $(CXXFLAGS) -o $@ main.o $(OFILES)

# This target describes how to compile a .o file from a .cpp file.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# This target runs the automated tests.
tests: main 
	chmod +x testFilters.sh
	./testFilters.sh

# This target deletes the temporary files we have built.
.PHONY: clean
clean:
	rm -f $(OFILES)
	rm -f main.o
	rm -f ./main
	rm -f test_output/*

# This target is intended to prevent accidental modification of the provided
# test data files.
.PHONY: protect_test_data
protect_test_data:
	chmod -R -w ../test_data
