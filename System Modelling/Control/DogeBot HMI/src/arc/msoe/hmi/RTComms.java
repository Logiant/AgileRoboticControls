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

		lib = (DLL) Native.loadLibrary(path + "DLLTest.dll", 
				DLL.class);
	}
	
	
	public void dllTest() {
		double sa = 0;
		double vol = 0;
	    System.out.println("The radius should be two: " + lib.GetSphereSAandVol(1, sa, vol));
	    System.out.println("Surface area = " + sa);
	    System.out.println("Volume = " + vol);

	}
	//Test interface using JNA to load a .dll file
	public interface DLL extends Library {
	       // FREQUENCY is expressed in hertz and ranges from 37 to 32767
	       // DURATION is expressed in milliseconds
	       public int GetSphereSAandVol(double radius, double sa, double vol);
	   }
}