# Makefile
.PHONY: clean

clean:
	@echo "Cleaning all a.out, *.out, *.o, core..."
	find . -type f \( -name "a.out" -o -name "*.out" -o -name "*.o" -o -name "core" \) -delete
