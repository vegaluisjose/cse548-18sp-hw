# SystemVerilog hello world

The goal of this homework is to test if you have setup your environment correctly. You will be simulating an adder with registered input and output.

## Environment setup

If you have not setup the Docker image please read [this](https://github.com/vegaluisjose/cse548-hw/tree/master/setup)

## Run simulation

Run `make`

## Simulation output

There are two ways of debugging hardware designs: using standard output or waveforms. This homework is configured to generate both.

* Standard output is done by the following [printf](https://github.com/vegaluisjose/cse548-hw/blob/master/hw0/src/main.cc#L50)
* The waveform file (vcd) is created after running `make` and it is located at `./out/adder.vcd`
