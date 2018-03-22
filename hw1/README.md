# hw1

## Setup and description (follow the steps)

1. Build Ariane by `make target=ariane"


[Ariane](https://github.com/pulp-platform/ariane) is a 6-stage, single issue,
in-order CPU which implements the 64-bit RISC-V instruction set. The goal of
this step is to download the RTL-implementation and generate a binary for
simulation.

2. Build riscv-tests by `make target=rvtests`
    * Run median by `make target=run_test test=benchmarks/median.riscv`
    * Run vvadd by `make target=run_test test=benchmarks/vvadd.riscv`
    * Run rv64ui-p-add by `make target=run_test test=isa/rv64ui-p-add`
    * Other compiled benchmark tests can be found in `ls ./out/rvtests/share/riscv-tests/benchmarks`
    * Other compiled isa tests can be found in `ls ./out/rvtests/share/riscv-tests/isa`

3. Build hello-world by `make target=hello`
    * Run hello-world by `make target=run_hello`
