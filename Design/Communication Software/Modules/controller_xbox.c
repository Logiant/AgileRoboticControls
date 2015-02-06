/*----------------------------------------------------------------------------
(C) Copyright A.R.C. 2014
Use or copying of all or any part of the document, except as
permitted by the License Agreement is prohibited.

Filename: controller_xbox.c

Purpose:  Function's primary responsibility is to capture input from an xbox
	controller for use in MATLAB simulink.

History:
Date		Name		Reason for change
30 Sep 14	paddockt	Original
30 Sep 14   mccartinq   Normalized thumb sticks (microsoft recommendation)
1 Oct 14    paddockt    All Outputs linked to buttons and zeroed norm. XYs
----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME controller_xbox /* Defines and Includes */
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include "Windows.h"
#include "XInput.h"

#define INPUT_DEADZONE  7849

static void mdlInitializeSizes(SimStruct *S)
{
	ssSetNumSFcnParams(S, 0);
	if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
		return; /* Parameter mismatch reported by the Simulink engine*/
	}

	if (!ssSetNumInputPorts(S, 1)) return;
	ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
	ssSetInputPortDirectFeedThrough(S, 0, 1);

	if (!ssSetNumOutputPorts(S, 20)) return;
	ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortWidth(S, 3, 1);
    ssSetOutputPortWidth(S, 4, 1);
    ssSetOutputPortWidth(S, 5, 1);
    ssSetOutputPortWidth(S, 6, 1);
    ssSetOutputPortWidth(S, 7, 1);
    ssSetOutputPortWidth(S, 8, 1);
    ssSetOutputPortWidth(S, 9, 1);
    ssSetOutputPortWidth(S, 10, 1);
    ssSetOutputPortWidth(S, 11, 1);
    ssSetOutputPortWidth(S, 12, 1);
    ssSetOutputPortWidth(S, 13, 1);
    ssSetOutputPortWidth(S, 14, 1);
    ssSetOutputPortWidth(S, 15, 1);
    ssSetOutputPortWidth(S, 16, 1);
    ssSetOutputPortWidth(S, 17, 1);
    ssSetOutputPortWidth(S, 18, 1);
    ssSetOutputPortWidth(S, 19, 1);
    
	ssSetNumSampleTimes(S, 1);

	/* Take care when specifying exception free code - see sfuntmpl.doc */
	ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}
static void mdlInitializeSampleTimes(SimStruct *S)
{
	ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
	ssSetOffsetTime(S, 0, 0.0);
}
static void mdlOutputs(SimStruct *S, int_T tid)
{
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(0, &state);//Supports only one controller
	if (dwResult == ERROR_SUCCESS){
		//Controller Connected
        float LX = state.Gamepad.sThumbLX;
        float LY = state.Gamepad.sThumbLY;
        float magnitude_L = (float) sqrt(LX*LX + LY*LY);//determine how far the controller is pushed
        //determine the direction the controller is pushed
        float normalizedLX = LX / magnitude_L;
        float normalizedLY = LY / magnitude_L;
        float normalizedMagnitude_L = 0;
        if (magnitude_L > INPUT_DEADZONE)//check if the controller is outside a circular dead zone
        {
            if (magnitude_L > 32767) magnitude_L = 32767;//clip the magnitude at its expected maximum value
            magnitude_L -= INPUT_DEADZONE;//adjust magnitude relative to the end of the dead zone
            //optionally normalize the magnitude with respect to its expected range
            //giving a magnitude value of 0.0 to 1.0
            normalizedMagnitude_L = magnitude_L / (32767 - INPUT_DEADZONE);
        }
        else //if the controller is in the dead zone zero out the magnitude
        {
            magnitude_L = 0.0;
            normalizedMagnitude_L = 0.0;
            normalizedLX = 0.0;
            normalizedLY = 0.0;
        }
        //repeat for right thumb stick
        float RX = state.Gamepad.sThumbRX;
        float RY = state.Gamepad.sThumbRY;
        float magnitude_R = (float) sqrt(RX*RX + RY*RY);//determine how far the controller is pushed
        //determine the direction the controller is pushed
        float normalizedRX = RX / magnitude_R;
        float normalizedRY = RY / magnitude_R;
        float normalizedMagnitude_R = 0;
        if (magnitude_R > INPUT_DEADZONE)//check if the controller is outside a circular dead zone
        {
            if (magnitude_R > 32767) magnitude_R = 32767;//clip the magnitude at its expected maximum value
            //adjust magnitude relative to the end of the dead zone
            magnitude_R -= INPUT_DEADZONE;
            //optionally normalize the magnitude with respect to its expected range
            //giving a magnitude value of 0.0 to 1.0
            normalizedMagnitude_R = magnitude_R / (32767 - INPUT_DEADZONE);
        }
        else //if the controller is in the dead zone zero out the magnitude
        {
            magnitude_R = 0.0;
            normalizedMagnitude_R = 0.0;
            normalizedRX = 0.0;
            normalizedRY = 0.0;
        }
        //Set output ports to the value of each button
        WORD buttons = state.Gamepad.wButtons;
        *ssGetOutputPortRealSignal(S,0)=buttons&XINPUT_GAMEPAD_DPAD_UP;
        *ssGetOutputPortRealSignal(S,1)=buttons&XINPUT_GAMEPAD_DPAD_DOWN;
        *ssGetOutputPortRealSignal(S,2)=buttons&XINPUT_GAMEPAD_DPAD_LEFT;
        *ssGetOutputPortRealSignal(S,3)=buttons&XINPUT_GAMEPAD_DPAD_RIGHT;
        *ssGetOutputPortRealSignal(S,4)=buttons&XINPUT_GAMEPAD_START;
        *ssGetOutputPortRealSignal(S,5)=buttons&XINPUT_GAMEPAD_BACK;
        *ssGetOutputPortRealSignal(S,6)=buttons&XINPUT_GAMEPAD_LEFT_THUMB;
        *ssGetOutputPortRealSignal(S,7)=buttons&XINPUT_GAMEPAD_RIGHT_THUMB;
        *ssGetOutputPortRealSignal(S,8)=buttons&XINPUT_GAMEPAD_LEFT_SHOULDER;
        *ssGetOutputPortRealSignal(S,9)=buttons&XINPUT_GAMEPAD_RIGHT_SHOULDER;
        *ssGetOutputPortRealSignal(S,10)=buttons&XINPUT_GAMEPAD_A;
        *ssGetOutputPortRealSignal(S,11)=buttons&XINPUT_GAMEPAD_B;
        *ssGetOutputPortRealSignal(S,12)=buttons&XINPUT_GAMEPAD_X;
        *ssGetOutputPortRealSignal(S,13)=buttons&XINPUT_GAMEPAD_Y;
        *ssGetOutputPortRealSignal(S,14)=state.Gamepad.bLeftTrigger;
        *ssGetOutputPortRealSignal(S,15)=state.Gamepad.bRightTrigger;
        *ssGetOutputPortRealSignal(S,16)=normalizedLX;
        *ssGetOutputPortRealSignal(S,17)=normalizedLY;
        *ssGetOutputPortRealSignal(S,18)=normalizedRX;
        *ssGetOutputPortRealSignal(S,19)=normalizedRY;
	}
	else{
		//Controller Disconnected
        *ssGetOutputPortRealSignal(S,0)=-1;
	}
}
static void mdlTerminate(SimStruct *S){}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c" /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif