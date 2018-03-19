#include <stdint.h>
#include "verilated.h"

using namespace std;

int main(int argc, char **argv, char **env) {

    Verilated::commandArgs(argc, argv);
    VNAME *top = new VNAME;

    long long int cycles = 0;
    uint32_t a = 0;
    uint32_t b = 0;

    while (!Verilated::gotFinish() && cycles < TIMEOUT_CYCLES) {

      a += 1;
      b += 2;

      if (top->clk) {
        printf("cycle:%08lld, a:%08d b:%08d y:%08d\n", cycles, top->a, top->b, top->y);
        cycles++;
      }

      top->a = a;
      top->b = b;
      top->clk ^= 1;
      top->eval();

    }

    delete top;

    exit(0);
}
