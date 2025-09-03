
CXX := riscv64-unknown-linux-musl-gcc
CXXFLAGS := -g -static -Wall -Wextra
OBJDUMP := riscv64-unknown-linux-musl-objdump
GEM5 := $(GEM5_PATH)/build/RISCV/gem5.opt

.PHONY: run_O0 run_O2

run_O0:
	$(CXX) $(CXXFLAGS) -O0 bug.c -o bug
	$(OBJDUMP) -D bug > bugO0.disasm
	$(GEM5) gem5_core.py bug

run_O2:
	$(CXX) $(CXXFLAGS) -O2 bug.c -o bug
	$(OBJDUMP) -D bug > bugO2.disasm
	$(GEM5) gem5_core.py bug
