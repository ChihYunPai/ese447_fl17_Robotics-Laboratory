  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (model2_P)
    ;%
      section.nData     = 45;
      section.data(45)  = dumData; %prealloc
      
	  ;% model2_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% model2_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% model2_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% model2_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% model2_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% model2_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% model2_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% model2_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% model2_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% model2_P.HILInitialize_POInitial
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% model2_P.HILInitialize_POFinal
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% model2_P.HILInitialize_POWatchdog
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% model2_P.Toradius_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% model2_P.TransferFcn1_A
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% model2_P.TransferFcn1_C
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% model2_P.Toradius1_Gain
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 18;
	
	  ;% model2_P.Constant_Value
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 19;
	
	  ;% model2_P.TransferFcn_A
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 20;
	
	  ;% model2_P.TransferFcn_C
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 21;
	
	  ;% model2_P.q1_Value
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 22;
	
	  ;% model2_P.q1dot_Value
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 23;
	
	  ;% model2_P.q3_Value
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 24;
	
	  ;% model2_P.q2dot1_Value
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 25;
	
	  ;% model2_P.degreetoradius_Gain
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 26;
	
	  ;% model2_P.interval_1indegree_Value
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 27;
	
	  ;% model2_P.interval_2indegree_Value
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 28;
	
	  ;% model2_P.Memory_X0
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 29;
	
	  ;% model2_P.SineWave_Amp
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 30;
	
	  ;% model2_P.SineWave_Bias
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 31;
	
	  ;% model2_P.SineWave_Freq
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 32;
	
	  ;% model2_P.SineWave_Phase
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 33;
	
	  ;% model2_P.Constant_Value_d
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 34;
	
	  ;% model2_P.Constant1_Value
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 35;
	
	  ;% model2_P.Saturation_UpperSat
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 36;
	
	  ;% model2_P.Saturation_LowerSat
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 37;
	
	  ;% model2_P.voltage2_Value
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 38;
	
	  ;% model2_P.Saturation1_UpperSat
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 39;
	
	  ;% model2_P.Saturation1_LowerSat
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 40;
	
	  ;% model2_P.Gain_Gain
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 41;
	
	  ;% model2_P.voltage2_Value_p
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 42;
	
	  ;% model2_P.Saturation_UpperSat_p
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 43;
	
	  ;% model2_P.Saturation_LowerSat_k
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% model2_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 52;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% model2_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 2;
	
	  ;% model2_P.HILInitialize_EIChannels
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 4;
	
	  ;% model2_P.HILInitialize_EIQuadrature
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 6;
	
	  ;% model2_P.HILReadEncoder_Channels
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 7;
	
	  ;% model2_P.HILReadEncoder1_Channels
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 8;
	
	  ;% model2_P.HILWriteAnalog_Channels
	  section.data(7).logicalSrcIdx = 59;
	  section.data(7).dtTransOffset = 9;
	
	  ;% model2_P.HILWriteAnalog1_Channels
	  section.data(8).logicalSrcIdx = 60;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% model2_P.q2Switch_CurrentSetting
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_P.q2dotSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% model2_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 65;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 66;
	  section.data(4).dtTransOffset = 3;
	
	  ;% model2_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 67;
	  section.data(5).dtTransOffset = 4;
	
	  ;% model2_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 68;
	  section.data(6).dtTransOffset = 5;
	
	  ;% model2_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 69;
	  section.data(7).dtTransOffset = 6;
	
	  ;% model2_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 70;
	  section.data(8).dtTransOffset = 7;
	
	  ;% model2_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 71;
	  section.data(9).dtTransOffset = 8;
	
	  ;% model2_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 72;
	  section.data(10).dtTransOffset = 9;
	
	  ;% model2_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 73;
	  section.data(11).dtTransOffset = 10;
	
	  ;% model2_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 74;
	  section.data(12).dtTransOffset = 11;
	
	  ;% model2_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 75;
	  section.data(13).dtTransOffset = 12;
	
	  ;% model2_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 76;
	  section.data(14).dtTransOffset = 13;
	
	  ;% model2_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 77;
	  section.data(15).dtTransOffset = 14;
	
	  ;% model2_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 78;
	  section.data(16).dtTransOffset = 15;
	
	  ;% model2_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 79;
	  section.data(17).dtTransOffset = 16;
	
	  ;% model2_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 80;
	  section.data(18).dtTransOffset = 17;
	
	  ;% model2_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 81;
	  section.data(19).dtTransOffset = 18;
	
	  ;% model2_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 82;
	  section.data(20).dtTransOffset = 19;
	
	  ;% model2_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 83;
	  section.data(21).dtTransOffset = 20;
	
	  ;% model2_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 84;
	  section.data(22).dtTransOffset = 21;
	
	  ;% model2_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 85;
	  section.data(23).dtTransOffset = 22;
	
	  ;% model2_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 86;
	  section.data(24).dtTransOffset = 23;
	
	  ;% model2_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 87;
	  section.data(25).dtTransOffset = 24;
	
	  ;% model2_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 88;
	  section.data(26).dtTransOffset = 25;
	
	  ;% model2_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 89;
	  section.data(27).dtTransOffset = 26;
	
	  ;% model2_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 90;
	  section.data(28).dtTransOffset = 27;
	
	  ;% model2_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 91;
	  section.data(29).dtTransOffset = 28;
	
	  ;% model2_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 92;
	  section.data(30).dtTransOffset = 29;
	
	  ;% model2_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 93;
	  section.data(31).dtTransOffset = 30;
	
	  ;% model2_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 94;
	  section.data(32).dtTransOffset = 31;
	
	  ;% model2_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 95;
	  section.data(33).dtTransOffset = 32;
	
	  ;% model2_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 96;
	  section.data(34).dtTransOffset = 33;
	
	  ;% model2_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 97;
	  section.data(35).dtTransOffset = 34;
	
	  ;% model2_P.HILReadEncoder_Active
	  section.data(36).logicalSrcIdx = 98;
	  section.data(36).dtTransOffset = 35;
	
	  ;% model2_P.HILReadEncoder1_Active
	  section.data(37).logicalSrcIdx = 99;
	  section.data(37).dtTransOffset = 36;
	
	  ;% model2_P.HILWriteAnalog_Active
	  section.data(38).logicalSrcIdx = 100;
	  section.data(38).dtTransOffset = 37;
	
	  ;% model2_P.HILWriteAnalog1_Active
	  section.data(39).logicalSrcIdx = 101;
	  section.data(39).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (model2_B)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% model2_B.Toradius
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_B.Toradius1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_B.degreetoradius
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% model2_B.Integrator
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% model2_B.Memory
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% model2_B.Saturation
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% model2_B.Saturation1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% model2_B.Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% model2_B.Saturation_p
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% model2_B.Xdot
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% model2_B.q2
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 21;
	
	  ;% model2_B.q2dot
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% model2_B.q1_out
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% model2_B.q1dot_out
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% model2_B.q2_out
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% model2_B.q2dot_out
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% model2_B.control
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (model2_DWork)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% model2_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% model2_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% model2_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% model2_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% model2_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% model2_DWork.Memory_PreviousInput
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% model2_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% model2_DWork.Derivative1_RWORK.TimeStampA
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_DWork.Derivative_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% model2_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_DWork.HILReadEncoder1_PWORK
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_DWork.X_collect_2_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_DWork.HILWriteAnalog_PWORK
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% model2_DWork.HILWriteAnalog1_PWORK
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% model2_DWork.V_collect_2_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% model2_DWork.V_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
	  ;% model2_DWork.X_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% model2_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_DWork.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_DWork.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 3;
	
	  ;% model2_DWork.HILReadEncoder_Buffer
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 5;
	
	  ;% model2_DWork.HILReadEncoder1_Buffer
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 6;
	
	  ;% model2_DWork.sfEvent
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 7;
	
	  ;% model2_DWork.sfEvent_m
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 8;
	
	  ;% model2_DWork.sfEvent_p
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 9;
	
	  ;% model2_DWork.sfEvent_g
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 10;
	
	  ;% model2_DWork.sfEvent_l
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% model2_DWork.Integrator_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% model2_DWork.is_active_c3_model2
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_DWork.is_active_c4_model2
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_DWork.is_active_c1_model2
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_DWork.is_active_c5_model2
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
	  ;% model2_DWork.is_active_c2_model2
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% model2_DWork.isStable
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model2_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model2_DWork.isStable_c
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 2;
	
	  ;% model2_DWork.doneDoubleBufferReInit_l
	  section.data(4).logicalSrcIdx = 37;
	  section.data(4).dtTransOffset = 3;
	
	  ;% model2_DWork.isStable_e
	  section.data(5).logicalSrcIdx = 38;
	  section.data(5).dtTransOffset = 4;
	
	  ;% model2_DWork.doneDoubleBufferReInit_lo
	  section.data(6).logicalSrcIdx = 39;
	  section.data(6).dtTransOffset = 5;
	
	  ;% model2_DWork.isStable_o
	  section.data(7).logicalSrcIdx = 40;
	  section.data(7).dtTransOffset = 6;
	
	  ;% model2_DWork.doneDoubleBufferReInit_e
	  section.data(8).logicalSrcIdx = 41;
	  section.data(8).dtTransOffset = 7;
	
	  ;% model2_DWork.isStable_b
	  section.data(9).logicalSrcIdx = 42;
	  section.data(9).dtTransOffset = 8;
	
	  ;% model2_DWork.doneDoubleBufferReInit_h
	  section.data(10).logicalSrcIdx = 43;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2721495671;
  targMap.checksum1 = 1513336412;
  targMap.checksum2 = 1442817285;
  targMap.checksum3 = 1617711543;

