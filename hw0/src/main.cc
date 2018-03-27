#include <stdint.h>
#include "verilated.h"

#if VM_TRACE
#include <verilated_vcd_c.h>
#endif

#if VM_TRACE
#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)
#endif

using namespace std;

int main(int argc, char **argv, char **env) {

  Verilated::commandArgs(argc, argv);
  VNAME *top = new VNAME;

  unsigned long int main_time = 0;
  long long int cycles = 0;
  uint32_t a = 0;
  uint32_t b = 0;

#if VM_TRACE
  Verilated::traceEverOn(true);
  VL_PRINTF("Enabling waves...\n");
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open(STRINGIZE_VALUE_OF(VCD_FILE));
#endif

  top->clk_i = 0;

  while (!Verilated::gotFinish() && cycles < TIMEOUT_CYCLES) {

    top->a_i = a;
    top->b_i = b;

    top->eval();

#if VM_TRACE
    if( tfp ) tfp->dump( main_time );
    main_time++;
#endif

    if (top->clk_i) {
      cycles++;
    } else {
      printf("cycle:%08lld, a:%08d b:%08d y:%08d\n", cycles, top->a_i, top->b_i, top->y_o);
      a += 1;
      b += 2;
    }

    top->clk_i ^= 1;

  }

#if VM_TRACE
  if( tfp ) tfp->close();
#endif

  delete top;

  exit(0);

}
