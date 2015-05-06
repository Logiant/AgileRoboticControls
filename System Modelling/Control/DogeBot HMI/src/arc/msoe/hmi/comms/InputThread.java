package arc.msoe.hmi.comms;

import arc.msoe.hmi.RTComms;

/**
 * Takes input from the user controller and provides the requested action to MainGUI
 * 
 * 3/15/2015
 * @author beaverl
 *
 */
public class InputThread extends Thread {
	
	RTComms comms; //IO with the Xbee unit

	boolean connected;
	volatile boolean running;

	public InputThread() {
		//check for a controller
		connected = true; //controller found
		running = true;
	}

	public void run() {
		while (running) { //while the thread is running
			if (connected) { //if a controller is connected
				//System.out.println("reading input...");
				//System.out.println("collecting data...");
				try {
					Thread.sleep(500);
					comms = new RTComms();
					comms.dllTest();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			} else { //look for controller
				
			}
		}
	}
	
	public void close() {
		running = false;
	}
}
