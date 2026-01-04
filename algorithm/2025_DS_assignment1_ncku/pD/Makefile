SDIR := src
ODIR := out
TDIR := samples-pD

CC := gcc
CFLAGS := -std=c11 -Wall

TARGET := $(ODIR)/pD.out
TEST_INPUTS := $(wildcard $(TDIR)/*.in)
CASES := $(patsubst $(TDIR)/%.in,%,$(TEST_INPUTS))

all: check $(TARGET)

# 編譯 .c -> .o
$(ODIR)/pD.o: $(SDIR)/pD.c
	$(CC) $(CFLAGS) -c -o $@ $^

# 連結
$(TARGET): $(ODIR)/pD.o
	$(CC) $(CFLAGS) -o $@ $^


# 建 output/ 資料夾
check:
	mkdir -p $(ODIR)

# 跑測資
test: $(TARGET)
	@echo "=== Running tests ==="
	@for c in $(CASES); do \
	  input="$(TDIR)/$${c}.in"; \
	  expect="$(TDIR)/$${c}.ans"; \
	  output="$(ODIR)/$${c}.txt"; \
	  echo "Case $${c}:"; \
	  $(TARGET) < "$$input" > "$$output"; \
	  if diff --strip-trailing-cr "$$output" "$$expect" >/dev/null; then \
	    echo "  [PASS] $${c}"; \
	  else \
	    echo "  [FAIL] $${c}"; \
	    diff "$$output" "$$expect" || true; \
	  fi; \
	done

# 清理
clean:
	rm -f $(ODIR)/*.o $(TARGET) $(ODIR)/*.txt

.PHONY: all check clean test
