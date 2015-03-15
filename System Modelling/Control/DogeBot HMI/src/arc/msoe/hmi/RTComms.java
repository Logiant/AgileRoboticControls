package arc.msoe.hmi;

import com.sun.jna.Library;
import com.sun.jna.Native;

import arc.msoe.hmi.comms.*;

/**
 * This class is called by the MainGUI to read/write data to the robot
 * Uses ReadThread and WriteThread to communicate with the Xbee wireless communicator
 * 
 * 3/12/2015
 * @author beaverl
 *
 */
public class RTComms {

	ReadThread read;
	WriteThread write;
	
	DLL lib;
	
	
	public RTComms() {
		String path = System.getProperty("user.dir") + "\\res\\";

		lib = (DLL) Native.loadLibrary(path + "kernel.dll", 
				DLL.class);
	}
	
	
	public void dllTest() {

	    lib.Beep(698, 500);

	}
	//Test interface using JNA to load a .dll file
	public interface DLL extends Library {
	       // FREQUENCY is expressed in hertz and ranges from 37 to 32767
	       // DURATION is expressed in milliseconds
	       public boolean Beep(int FREQUENCY, int DURATION);
	       public void Sleep(int DURATION);
	   }
}
