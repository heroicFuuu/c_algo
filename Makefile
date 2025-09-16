# Makefile
.PHONY: clean format

clean:
	@echo "Cleaning all a.out, *.out, *.o, core..."
	find . -type f \( -name "a.out" -o -name "*.out" -o -name "*.o" -o -name "core" \) -delete

format:
	@echo "Formatting all source files"
	find . -regex '.*\.\(c\|cpp|h|\)' -exec clang-Formatting -i {} +