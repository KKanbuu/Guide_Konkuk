
"use strict";

let CfgGNSS_Block = require('./CfgGNSS_Block.js');
let EsfSTATUS = require('./EsfSTATUS.js');
let RxmALM = require('./RxmALM.js');
let CfgPRT = require('./CfgPRT.js');
let MonHW6 = require('./MonHW6.js');
let RxmRAWX_Meas = require('./RxmRAWX_Meas.js');
let CfgNAVX5 = require('./CfgNAVX5.js');
let NavDGPS = require('./NavDGPS.js');
let NavPOSECEF = require('./NavPOSECEF.js');
let NavSVINFO_SV = require('./NavSVINFO_SV.js');
let NavPVT7 = require('./NavPVT7.js');
let CfgUSB = require('./CfgUSB.js');
let EsfINS = require('./EsfINS.js');
let CfgCFG = require('./CfgCFG.js');
let CfgGNSS = require('./CfgGNSS.js');
let AidEPH = require('./AidEPH.js');
let UpdSOS = require('./UpdSOS.js');
let AidHUI = require('./AidHUI.js');
let CfgRST = require('./CfgRST.js');
let NavVELECEF = require('./NavVELECEF.js');
let RxmRAWX = require('./RxmRAWX.js');
let CfgHNR = require('./CfgHNR.js');
let CfgNAV5 = require('./CfgNAV5.js');
let MonVER = require('./MonVER.js');
let NavSVINFO = require('./NavSVINFO.js');
let CfgNMEA = require('./CfgNMEA.js');
let NavVELNED = require('./NavVELNED.js');
let NavSTATUS = require('./NavSTATUS.js');
let NavATT = require('./NavATT.js');
let NavSAT = require('./NavSAT.js');
let NavSBAS = require('./NavSBAS.js');
let MonGNSS = require('./MonGNSS.js');
let EsfRAW_Block = require('./EsfRAW_Block.js');
let RxmSFRB = require('./RxmSFRB.js');
let Ack = require('./Ack.js');
let MonHW = require('./MonHW.js');
let RxmSVSI = require('./RxmSVSI.js');
let CfgNMEA7 = require('./CfgNMEA7.js');
let MonVER_Extension = require('./MonVER_Extension.js');
let CfgANT = require('./CfgANT.js');
let CfgMSG = require('./CfgMSG.js');
let CfgINF = require('./CfgINF.js');
let EsfMEAS = require('./EsfMEAS.js');
let CfgRATE = require('./CfgRATE.js');
let AidALM = require('./AidALM.js');
let UpdSOS_Ack = require('./UpdSOS_Ack.js');
let HnrPVT = require('./HnrPVT.js');
let CfgSBAS = require('./CfgSBAS.js');
let EsfSTATUS_Sens = require('./EsfSTATUS_Sens.js');
let NavSAT_SV = require('./NavSAT_SV.js');
let CfgDAT = require('./CfgDAT.js');
let NavTIMEUTC = require('./NavTIMEUTC.js');
let RxmSFRBX = require('./RxmSFRBX.js');
let NavPOSLLH = require('./NavPOSLLH.js');
let RxmEPH = require('./RxmEPH.js');
let CfgTMODE3 = require('./CfgTMODE3.js');
let NavRELPOSNED = require('./NavRELPOSNED.js');
let NavTIMEGPS = require('./NavTIMEGPS.js');
let NavSVIN = require('./NavSVIN.js');
let RxmRAW = require('./RxmRAW.js');
let NavDOP = require('./NavDOP.js');
let NavSOL = require('./NavSOL.js');
let RxmSVSI_SV = require('./RxmSVSI_SV.js');
let TimTM2 = require('./TimTM2.js');
let EsfRAW = require('./EsfRAW.js');
let NavSBAS_SV = require('./NavSBAS_SV.js');
let NavPVT = require('./NavPVT.js');
let RxmRAW_SV = require('./RxmRAW_SV.js');
let CfgNMEA6 = require('./CfgNMEA6.js');
let NavCLOCK = require('./NavCLOCK.js');
let CfgDGNSS = require('./CfgDGNSS.js');
let Inf = require('./Inf.js');
let CfgINF_Block = require('./CfgINF_Block.js');
let MgaGAL = require('./MgaGAL.js');
let RxmRTCM = require('./RxmRTCM.js');
let NavDGPS_SV = require('./NavDGPS_SV.js');

module.exports = {
  CfgGNSS_Block: CfgGNSS_Block,
  EsfSTATUS: EsfSTATUS,
  RxmALM: RxmALM,
  CfgPRT: CfgPRT,
  MonHW6: MonHW6,
  RxmRAWX_Meas: RxmRAWX_Meas,
  CfgNAVX5: CfgNAVX5,
  NavDGPS: NavDGPS,
  NavPOSECEF: NavPOSECEF,
  NavSVINFO_SV: NavSVINFO_SV,
  NavPVT7: NavPVT7,
  CfgUSB: CfgUSB,
  EsfINS: EsfINS,
  CfgCFG: CfgCFG,
  CfgGNSS: CfgGNSS,
  AidEPH: AidEPH,
  UpdSOS: UpdSOS,
  AidHUI: AidHUI,
  CfgRST: CfgRST,
  NavVELECEF: NavVELECEF,
  RxmRAWX: RxmRAWX,
  CfgHNR: CfgHNR,
  CfgNAV5: CfgNAV5,
  MonVER: MonVER,
  NavSVINFO: NavSVINFO,
  CfgNMEA: CfgNMEA,
  NavVELNED: NavVELNED,
  NavSTATUS: NavSTATUS,
  NavATT: NavATT,
  NavSAT: NavSAT,
  NavSBAS: NavSBAS,
  MonGNSS: MonGNSS,
  EsfRAW_Block: EsfRAW_Block,
  RxmSFRB: RxmSFRB,
  Ack: Ack,
  MonHW: MonHW,
  RxmSVSI: RxmSVSI,
  CfgNMEA7: CfgNMEA7,
  MonVER_Extension: MonVER_Extension,
  CfgANT: CfgANT,
  CfgMSG: CfgMSG,
  CfgINF: CfgINF,
  EsfMEAS: EsfMEAS,
  CfgRATE: CfgRATE,
  AidALM: AidALM,
  UpdSOS_Ack: UpdSOS_Ack,
  HnrPVT: HnrPVT,
  CfgSBAS: CfgSBAS,
  EsfSTATUS_Sens: EsfSTATUS_Sens,
  NavSAT_SV: NavSAT_SV,
  CfgDAT: CfgDAT,
  NavTIMEUTC: NavTIMEUTC,
  RxmSFRBX: RxmSFRBX,
  NavPOSLLH: NavPOSLLH,
  RxmEPH: RxmEPH,
  CfgTMODE3: CfgTMODE3,
  NavRELPOSNED: NavRELPOSNED,
  NavTIMEGPS: NavTIMEGPS,
  NavSVIN: NavSVIN,
  RxmRAW: RxmRAW,
  NavDOP: NavDOP,
  NavSOL: NavSOL,
  RxmSVSI_SV: RxmSVSI_SV,
  TimTM2: TimTM2,
  EsfRAW: EsfRAW,
  NavSBAS_SV: NavSBAS_SV,
  NavPVT: NavPVT,
  RxmRAW_SV: RxmRAW_SV,
  CfgNMEA6: CfgNMEA6,
  NavCLOCK: NavCLOCK,
  CfgDGNSS: CfgDGNSS,
  Inf: Inf,
  CfgINF_Block: CfgINF_Block,
  MgaGAL: MgaGAL,
  RxmRTCM: RxmRTCM,
  NavDGPS_SV: NavDGPS_SV,
};
