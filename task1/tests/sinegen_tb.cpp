#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "../vbuddy.cpp"

#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env){
    int symcyc = 0;
    int tick;
    
    Verilated::commandArgs(argc, argv);
    Vsinegen* top = new Vsinegen;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sinegen.vcd");

    top->clk = 1;
    top->en = 1;
    top->rst = 0;
    top->incr = 1;

    if(vbdOpen() != 1) return (-1);
    vbdHeader("Lab2: Sinewave Generator");

    for(symcyc = 0; symcyc < MAX_SIM_CYC; symcyc++){
        for(tick = 0; tick < 2; tick++){
            top->eval();
            tfp->dump(symcyc*2 + tick);
            top->tick = !top->tick;
        }
        
        vbdCycle(symcyc);
        vbdPlot(int(top->dout), 0, 255);;

        
        if(Verilated::gotFinish() || (vbdGetkey() == 'q') ) 
            exit(0);
    }
    vbdClose();
    tfp->close();
    exit(0);
}