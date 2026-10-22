// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay___024root.h"

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vdly__sigdelay__DOT__wr_addr;
    SData/*8:0*/ __Vdlyvdim0__sigdelay__DOT__myRam__DOT__ramarray__v0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__myRam__DOT__ramarray__v0;
    // Body
    __Vdly__sigdelay__DOT__wr_addr = vlSelf->sigdelay__DOT__wr_addr;
    if (vlSelf->rst) {
        __Vdly__sigdelay__DOT__wr_addr = 0U;
    } else if (vlSelf->en) {
        __Vdly__sigdelay__DOT__wr_addr = (0x1ffU & 
                                          ((IData)(1U) 
                                           + (IData)(vlSelf->sigdelay__DOT__wr_addr)));
    }
    vlSelf->delayed_signal = vlSelf->sigdelay__DOT__myRam__DOT__ramarray
        [(0x1ffU & ((IData)(vlSelf->sigdelay__DOT__wr_addr) 
                    - (IData)(vlSelf->offset)))];
    __Vdlyvval__sigdelay__DOT__myRam__DOT__ramarray__v0 
        = vlSelf->mic_signal;
    __Vdlyvdim0__sigdelay__DOT__myRam__DOT__ramarray__v0 
        = vlSelf->sigdelay__DOT__wr_addr;
    vlSelf->sigdelay__DOT__wr_addr = __Vdly__sigdelay__DOT__wr_addr;
    vlSelf->sigdelay__DOT__myRam__DOT__ramarray[__Vdlyvdim0__sigdelay__DOT__myRam__DOT__ramarray__v0] 
        = __Vdlyvval__sigdelay__DOT__myRam__DOT__ramarray__v0;
}

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsigdelay___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->offset & 0xfe00U))) {
        Verilated::overWidthError("offset");}
}
#endif  // VL_DEBUG
