package arc.msoe.hmi;

import com.sun.jna.Library;
import com.sun.jna.Native;

import arc.msoe.hmi.comms.*;

/**
 * This class is called by the MainGUI to read/write data to the robot
 * Uses ReadThread and WriteThread to communicate with the Xbee wireless communicator
 * 
 * 3/15/2015
 * @author beaverl
 * @author paddockt
 *
 */
public class RTComms {

	ReadThread read;
	WriteThread write;
	
	DLL lib;
	
	
	public RTComms() {
		String path = System.getProperty("user.dir") + "\\res\\";

		lib = (DLL) Native.loadLibrary(path + "XboxInterface.dll", 
				DLL.class);
	}
	
	
	public void dllTest() {
	    System.out.println("Button STate: " + lib.getButtonStates(0));
	    System.out.println("" + lib.getLeftJoyStick(0));
	    System.out.println("" + lib.getRightJoyStick(0));
	    System.out.println("" + lib.getTriggerStates(0));

	}
	//Test interface using JNA to load a .dll file
	public interface DLL extends Library {
	       // FREQUENCY is expressed in hertz and ranges from 37 to 32767
	       // DURATION is expressed in milliseconds
		/**
		 * 
		 * @param controllerNumber Number of the Xbox Controller (0 - 3)
		 * @return
		 */
		public int getLeftJoyStick(int controllerNumber);
		
		/**
		 * Gets the x and y values of the right controller joy stick
		 * @param controllerNumber Number of the Xbox Controller (0 - 3)
		 * @return int - first short is the 
		 */
		public int getRightJoyStick(int controllerNumber);
		
		/**
		 * Gets all the non-analog button states from the Xbox controller
		 * @param controllerNumber Number of the Xbox Controller (0 - 3)
		 * @return int representing each button on the Xbox controller
		 * The following masks are used for each button
		 * XINPUT_GAMEPAD_DPAD_UP	0x0001
		 * XINPUT_GAMEPAD_DPAD_DOWN	0x0002
		 * XINPUT_GAMEPAD_DPAD_LEFT	0x0004
		 * XINPUT_GAMEPAD_DPAD_RIGHT	0x0008
		 * XINPUT_GAMEPAD_START	0x0010
		 * XINPUT_GAMEPAD_BACK	0x0020
		 * XINPUT_GAMEPAD_LEFT_THUMB	0x0040
		 * XINPUT_GAMEPAD_RIGHT_THUMB	0x0080
		 * XINPUT_GAMEPAD_LEFT_SHOULDER	0x0100
		 * XINPUT_GAMEPAD_RIGHT_SHOULDER	0x0200
		 * XINPUT_GAMEPAD_A	0x1000
		 * XINPUT_GAMEPAD_B	0x2000
		 * XINPUT_GAMEPAD_X	0x4000
		 * XINPUT_GAMEPAD_Y	0x8000
		 */
		public int getButtonStates(int controllerNumber);
		
		/**
		 * Returns the analog values of each trigger 
		 * @param controllerNumber Number of the Xbox Controller (0 - 3)
		 * @return A short representing the left trigger in the most significant
		 * byte and the right trigger in the least significant byte
		 */
		public short getTriggerStates(int controllerNumber);
	   }
}
