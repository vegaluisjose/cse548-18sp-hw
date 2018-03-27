module adder
  (input         clk_i
  ,input  [31:0] a_i
  ,input  [31:0] b_i
  ,output [31:0] y_o);

  // pipeline stage 0
  logic [31:0] ar, br;
  always_ff @(posedge clk_i) begin
    ar <= a_i;
    br <= b_i;
  end

  // pipeline stage 1
  logic [31:0] yr;
  always_ff @(posedge clk_i)
    yr <= ar + br;

  assign y_o = yr;

endmodule
