package arc.msoe.hmi;

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
	
}
