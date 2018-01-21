function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDWork"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	size: 12};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	size: 4};
	 this.metricsArray.var["rtY"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	size: 4};
	 this.metricsArray.fcn["Controller_initialize"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Controller_step"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	stack: 12,
	stackTotal: 12};
	 this.metricsArray.fcn["Controller_terminate"] = {file: "C:\\Sumpurn\\Project\\sEmbeddedCPU\\work\\codegen\\Controller_ert_rtw\\Controller.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Controller_metrics.html">Global Memory: 24(bytes) Maximum Stack: 12(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
