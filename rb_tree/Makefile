SDIR := src
ODIR := output
TDIR := test

CC := gcc
CFLAGS := -O3 -std=c11 -Wall

# 唯一的執行檔
TARGET := $(ODIR)/rb_tree.out

# 撈所有測資
TEST_INPUTS := $(wildcard $(TDIR)/input_*.txt)
CASES := $(patsubst $(TDIR)/input_%.txt,%,$(TEST_INPUTS))

# 預設：編譯
all: check $(TARGET)

# 編譯 .c -> .o
$(SDIR)/rb_tree.o: $(SDIR)/rb_tree.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 連結 -> rb_tree.out
$(TARGET): $(SDIR)/rb_tree.o
	$(CC) $(CFLAGS) -o $@ $^

# 建 output/ 資料夾
check:
	mkdir -p $(ODIR)

# 測試流程
test: $(TARGET)
	@echo "=== Running tests ==="
	@for c in $(CASES); do \
	  input="$(TDIR)/input_$${c}.txt"; \
	  expect="$(TDIR)/output_$${c}.txt"; \
	  output="$(ODIR)/output_$${c}.ans"; \
	  echo "Case $${c}:"; \
	  $(TARGET) < "$$input" > "$$output"; \
	  if diff -q "$$output" "$$expect" >/dev/null; then \
	    echo "  [PASS] $${c}"; \
	  else \
	    echo "  [FAIL] $${c}"; \
	    diff "$$output" "$$expect" || true; \
	  fi; \
	done

# 清理
clean:
	rm -f $(SDIR)/*.o $(TARGET) $(ODIR)/*.ans

.PHONY: all check clean test
