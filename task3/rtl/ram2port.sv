module ram2port #(
    parameter ADDRESS_WIDTH = 9,
    parameter DATA_WIDTH = 8
)(
    input logic clk,
    input logic wr_en,
    input logic rd_en,
    input logic [ADDRESS_WIDTH-1:0]     wr_addr,
    input logic [ADDRESS_WIDTH-1:0]     rd_addr,
    input logic [DATA_WIDTH-1:0]        din,
    output logic [DATA_WIDTH-1:0]       dout
);

logic [DATA_WIDTH-1:0] ramarray  [2**ADDRESS_WIDTH-1:0];

always_ff @ (posedge clk)
    begin
        if(wr_en == 1'b1) 
            ramarray[wr_addr] <= din;
        if(rd_en == 1'b1)
            dout <= ramarray[rd_addr];
    end


endmodule
