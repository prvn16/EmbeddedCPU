function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["Controller.c:58c21"]=1;
    this.traceFlag["Controller.c:58c49"]=1;
    this.traceFlag["Controller.c:58c57"]=1;
    this.traceFlag["Controller.c:59c42"]=1;
    this.traceFlag["Controller.c:59c50"]=1;
    this.traceFlag["Controller.c:77c20"]=1;
    this.traceFlag["Controller.c:77c30"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["Controller.c:44"]=1;
    this.lineTraceFlag["Controller.c:47"]=1;
    this.lineTraceFlag["Controller.c:58"]=1;
    this.lineTraceFlag["Controller.c:59"]=1;
    this.lineTraceFlag["Controller.c:64"]=1;
    this.lineTraceFlag["Controller.c:67"]=1;
    this.lineTraceFlag["Controller.c:70"]=1;
    this.lineTraceFlag["Controller.c:77"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
