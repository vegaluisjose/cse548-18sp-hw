module adder
  (input         clk
  ,input  [31:0] a
  ,input  [31:0] b
  ,output [31:0] y);

  // pipeline stage 0
  logic [31:0] ar, br;
  always_ff @(posedge clk) begin
    ar <= a;
    br <= b;
  end

  // pipeline stage 1
  logic [31:0] yr;
  always_ff @(posedge clk)
    yr <= ar + br;

  assign y = yr;

endmodule
