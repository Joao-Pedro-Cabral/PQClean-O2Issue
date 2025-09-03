
CXX ?= riscv64-unknown-linux-musl-gcc
CXXFLAGS := -g -static -Wall -Wextra
OBJDUMP ?= riscv64-unknown-linux-musl-objdump
GEM5 := $(GEM5_PATH)/build/RISCV/gem5.opt

.PHONY: run_O0 run_O2

run_O0:
	$(CXX) $(CXXFLAGS) -O0 -I../common -I../crypto_sign/falcon-512/clean ../common/*.c ../crypto_sign/falcon-512/clean/*.c bug.c -o bug
	$(OBJDUMP) -D bug > bug.disasm
	$(GEM5) gem5_core.py bug

run_O2:
	$(CXX) $(CXXFLAGS) -O2 -I../common -I../crypto_sign/falcon-512/clean ../common/*.c ../crypto_sign/falcon-512/clean/*.c bug.c -o bug
	$(OBJDUMP) -D bug > bug.disasm
	$(GEM5) gem5_core.py bug
