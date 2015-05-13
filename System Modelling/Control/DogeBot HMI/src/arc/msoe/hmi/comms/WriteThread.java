package arc.msoe.hmi.comms;

import java.io.IOException;
import java.io.OutputStream;

import arc.msoe.hmi.RTComms;

/**
 * A thread that writes data from RTComms to the Xbee controller
 * 
 * 2/12/2015
 * @author beaverl
 *
 */
public class WriteThread extends Thread {

	RTComms comms;
	OutputStream stream;
	volatile boolean running = false;
	
	public WriteThread(RTComms comms, OutputStream stream) {
		this.comms = comms;
		this.stream = stream;
	}
	
	@Override
	public void run() {
		running = true;
		while (running) {
			//write message
			try {
				stream.write(comms.getCommand());
	//			System.out.println("writing " + comms.getCommand());
				stream.flush();
				Thread.sleep(20);
			} catch (Exception e) {
				e.printStackTrace();
			}
			//wait
		}
	}
	
	public void close() {
		running = false;
		try {
			stream.write(0);
			stream.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
