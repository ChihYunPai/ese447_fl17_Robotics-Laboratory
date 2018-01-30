  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (untitled_P)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% untitled_P.Constant4_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_P.Constant3_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% untitled_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% untitled_P.HILInitialize_OOTerminate
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% untitled_P.HILInitialize_OOExit
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% untitled_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% untitled_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% untitled_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% untitled_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% untitled_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% untitled_P.HILInitialize_AOFinal
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% untitled_P.HILInitialize_AOWatchdog
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% untitled_P.HILInitialize_POFrequency
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% untitled_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% untitled_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% untitled_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% untitled_P.Gain_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% untitled_P.UD_InitialCondition
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% untitled_P.Constant_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% untitled_P.Constant_Value_l
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% untitled_P.Constant_Value_j
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% untitled_P.Constant_Value_g
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% untitled_P.Saturation_UpperSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% untitled_P.Saturation_LowerSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% untitled_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% untitled_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% untitled_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 2;
	
	  ;% untitled_P.HILInitialize_EIChannels
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 4;
	
	  ;% untitled_P.HILInitialize_EIQuadrature
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 6;
	
	  ;% untitled_P.HILReadEncoder_Channels
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 7;
	
	  ;% untitled_P.HILWriteAnalog_Channels
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% untitled_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% untitled_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 3;
	
	  ;% untitled_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 4;
	
	  ;% untitled_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 5;
	
	  ;% untitled_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 6;
	
	  ;% untitled_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 42;
	  section.data(8).dtTransOffset = 7;
	
	  ;% untitled_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 43;
	  section.data(9).dtTransOffset = 8;
	
	  ;% untitled_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 44;
	  section.data(10).dtTransOffset = 9;
	
	  ;% untitled_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 45;
	  section.data(11).dtTransOffset = 10;
	
	  ;% untitled_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 46;
	  section.data(12).dtTransOffset = 11;
	
	  ;% untitled_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 47;
	  section.data(13).dtTransOffset = 12;
	
	  ;% untitled_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 48;
	  section.data(14).dtTransOffset = 13;
	
	  ;% untitled_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 49;
	  section.data(15).dtTransOffset = 14;
	
	  ;% untitled_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 50;
	  section.data(16).dtTransOffset = 15;
	
	  ;% untitled_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 51;
	  section.data(17).dtTransOffset = 16;
	
	  ;% untitled_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 52;
	  section.data(18).dtTransOffset = 17;
	
	  ;% untitled_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 53;
	  section.data(19).dtTransOffset = 18;
	
	  ;% untitled_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 54;
	  section.data(20).dtTransOffset = 19;
	
	  ;% untitled_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 55;
	  section.data(21).dtTransOffset = 20;
	
	  ;% untitled_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 56;
	  section.data(22).dtTransOffset = 21;
	
	  ;% untitled_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 57;
	  section.data(23).dtTransOffset = 22;
	
	  ;% untitled_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 58;
	  section.data(24).dtTransOffset = 23;
	
	  ;% untitled_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 59;
	  section.data(25).dtTransOffset = 24;
	
	  ;% untitled_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 60;
	  section.data(26).dtTransOffset = 25;
	
	  ;% untitled_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 61;
	  section.data(27).dtTransOffset = 26;
	
	  ;% untitled_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 62;
	  section.data(28).dtTransOffset = 27;
	
	  ;% untitled_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 63;
	  section.data(29).dtTransOffset = 28;
	
	  ;% untitled_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 64;
	  section.data(30).dtTransOffset = 29;
	
	  ;% untitled_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 65;
	  section.data(31).dtTransOffset = 30;
	
	  ;% untitled_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 66;
	  section.data(32).dtTransOffset = 31;
	
	  ;% untitled_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 67;
	  section.data(33).dtTransOffset = 32;
	
	  ;% untitled_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 68;
	  section.data(34).dtTransOffset = 33;
	
	  ;% untitled_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 69;
	  section.data(35).dtTransOffset = 34;
	
	  ;% untitled_P.HILReadEncoder_Active
	  section.data(36).logicalSrcIdx = 70;
	  section.data(36).dtTransOffset = 35;
	
	  ;% untitled_P.HILWriteAnalog_Active
	  section.data(37).logicalSrcIdx = 71;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% untitled_P.Gain2_Gain
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% untitled_P.Gain1_Gain
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_P.Switch_Threshold
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 3;
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
    ;% Auto data (untitled_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% untitled_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_B.Diff
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% untitled_B.Compare
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_B.LogicalOperator1
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_B.Compare_c
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% untitled_B.LogicalOperator
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% untitled_B.Add
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 4;
    sectIdxOffset = 3;
    
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
    ;% Auto data (untitled_DWork)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% untitled_DWork.UD_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_DWork.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_DWork.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% untitled_DWork.HILInitialize_AOMinimums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% untitled_DWork.HILInitialize_AOMaximums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% untitled_DWork.HILInitialize_AOVoltages
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% untitled_DWork.HILInitialize_FilterFrequency
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% untitled_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% untitled_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_DWork.HILWriteAnalog_PWORK
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_DWork.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% untitled_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% untitled_DWork.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% untitled_DWork.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 3;
	
	  ;% untitled_DWork.HILReadEncoder_Buffer
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 4039783815;
  targMap.checksum1 = 1843785379;
  targMap.checksum2 = 799954715;
  targMap.checksum3 = 3351565520;
