# Compiling and Running `bug.c` on gem5

The Makefile allows you to compile `bug.c` and run it in **gem5**. It also generates a disassembly of the compiled binary using `objdump`.

## Dependences

Before running the Makefile, you must have a `riscv64` cross-compiler and `gem5` simulator. 

Also, it's necessary to export a environment variable called `GEM5_PATH`, which contains the root of your gem5 repository. Note that `gem5.opt` will be available at `$(GEM5_PATH)/build/RISCV/gem5.opt`.

## Variables

Before running the Makefile, you may want to customize the following variables:

* `CXX` – The C compiler to use. Default:

  ```make
  riscv64-unknown-linux-musl-gcc
  ```
* `OBJDUMP` – The objdump binary to use for generating disassembly. Default:

  ```make
  riscv64-unknown-linux-musl-objdump
  ```

You can set these to your preferred binaries by specifying them when running `make`:

```bash
make run_O0 CXX=<your_compiler> OBJDUMP=<your_objdump>
```

## Targets

* `run_O0` – Compile with optimization `-O0` and run on gem5.
* `run_O2` – Compile with optimization `-O2` and run on gem5.

Each target performs the following steps:

1. Compiles `bug.c`.
2. Generates a disassembly of the compiled binary as `bug.disasm`.
3. Runs the program on gem5 using the `gem5_core.py` script.

## Example Usage

Compile and run with `-O0` optimizations:

```bash
make run_O0
```

Compile and run with `-O2` optimizations:

```bash
make run_O2
```
