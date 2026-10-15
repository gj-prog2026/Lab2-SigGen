#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "../vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i = 0;
    
    Verilated::commandArgs(argc, argv);
    Vsinegen* top = new Vsinegen;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sinegen.vcd");

    top->clk = 1;
    top->en = 0;
    top->rst = 1;
    top->incr = 1;

    if(vbdOpen() != 1) return (-1);
    vbdHeader("Lab2: Sinewave Generator");

    for(int i = 0; i < 300; i++){
        for(int clk = 0; clk < 2; clk++){
            top->eval();
            tfp->dump(i*2 + clk);
            top->clk = !top->clk;
        }

        vbdCycle(i+1);
        vbdPlot(int(top->dout), 0, 255);
        top->rst = (i < 2);
        top->en = 1;
        
        if(Verilated::gotFinish()) exit(0);
    }
    vbdClose();
    tfp->close();
    exit(0);
}