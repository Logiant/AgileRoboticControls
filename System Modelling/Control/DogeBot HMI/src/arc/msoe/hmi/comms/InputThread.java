package arc.msoe.hmi.comms;
/**
 * Takes input from the user controller and provides the requested action to MainGUI
 * 
 * 3/12/2015
 * @author beaverl
 *
 */
public class InputThread extends Thread {

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
				System.out.println("reading input...");
				System.out.println("collecting data...");
				try {
					Thread.sleep(1000);
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
