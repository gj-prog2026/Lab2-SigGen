module sinegen #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    input logic                   clk,
    input logic                   rst,
    input logic                   en,
    input logic    [D_WIDTH-1:0]  offset,
    input logic    [D_WIDTH-1:0]  incr,
    output logic   [D_WIDTH-1:0]  dout1,
    output logic   [D_WIDTH-1:0]  dout2
);

    logic [A_WIDTH-1:0]   addr1;
    logic [A_WIDTH-1:0]   addr2;

counter addrCounter(
    .count(addr1),
    .incr(incr),
    .rst(rst),
    .en(en),
    .clk(clk)
);

assign addr2 = addr1 + offset;

rom myRom(
    .clk(clk),
    .addr1(addr1),
    .addr2(addr2),
    .dout1(dout1),
    .dout2(dout2)
);

endmodule
