function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "fir_ne10"};
	this.sidHashMap["fir_ne10"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "fir_ne10:1"};
	this.sidHashMap["fir_ne10:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "fir_ne10:2"};
	this.sidHashMap["fir_ne10:2"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/Discrete FIR Filter"] = {sid: "fir_ne10:3"};
	this.sidHashMap["fir_ne10:3"] = {rtwname: "<S1>/Discrete FIR Filter"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "fir_ne10:4"};
	this.sidHashMap["fir_ne10:4"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
