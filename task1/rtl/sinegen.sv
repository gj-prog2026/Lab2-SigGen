module sinegen #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    input logic    [D_WIDTH-1:0]  incr,
    input logic                 rst,
    input logic                 en,
    input logic                 clk,
    output logic   [D_WIDTH-1:0]  dout
);

    logic [A_WIDTH-1:0]   addr;

counter addrCounter(
    .count(addr),
    .incr(incr),
    .rst(rst),
    .en(en),
    .clk(clk)
);

rom myRom(
    .addr(addr),
    .clk(clk),
    .dout(dout)
);

endmodule
