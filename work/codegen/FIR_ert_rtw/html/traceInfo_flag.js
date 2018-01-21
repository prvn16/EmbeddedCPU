function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["FIR.c:96c26"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["FIR.c:44"]=1;
    this.lineTraceFlag["FIR.c:96"]=1;
    this.lineTraceFlag["FIR.c:97"]=1;
    this.lineTraceFlag["FIR.c:100"]=1;
    this.lineTraceFlag["FIR.c:101"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
