package arc.msoe.hmi;

import gnu.io.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.LinkedList;
import java.util.List;

import arc.msoe.hmi.comms.*;

/**
 * This class is called by the MainGUI to read/write data to the robot
 * Uses ReadThread and WriteThread to communicate with the Xbee wireless communicator
 * 
 * 3/15/2015
 * @author beaverl
 *
 */
public class RTComms {

	WriteThread write;

	String portName;
	CommPortIdentifier commPortId;
	SerialPort serialPort;

	InputStream input;
	OutputStream output;

	boolean connected = false;

	final int TIMEOUT = 2000;


	private int command = 0; //command to write



	public RTComms() {
	}

	public boolean beginConnection() {
		boolean success = false;
		searchForPorts();
		if (commPortId != null) { //port found
			success = connect();
			connected = success;
			System.out.println("Connection success");
			if (input != null && output != null) {
				System.out.println("IO Created successfully");
				write = new WriteThread(this, output);
				System.out.println("Write thread created");
				write.start();
				System.out.println("Write thread running");
			} else {
				System.err.println("ERROR: COULD NOT READ SERIAL IO VALUES");
			}
		} else {
			System.err.println("ERROR: NO SERIAL DEVICE DETECTED");
		}
		return success;
	}

	public void close() {
		if (connected) {
			write.close();
			serialPort.removeEventListener();
			serialPort.close();
			try {
				input.close();
				output.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println("disconnected");
		}
	}

	public void updateCommand(int cmd) {
		command = cmd;
	}

	public int getCommand() {
		return command;
	}

	//find available ports on the system
	private void searchForPorts() {
		@SuppressWarnings("rawtypes")
		Enumeration ports = CommPortIdentifier.getPortIdentifiers(); //get all available ports
		while(ports.hasMoreElements()) { //for each available port
			CommPortIdentifier currentPort = (CommPortIdentifier)ports.nextElement();
			//make sure the found port is serial
			if (currentPort.getPortType() == CommPortIdentifier.PORT_SERIAL) {
				//COM1 is a virtual port that we do not want. We also don't want a busy port
				if (!currentPort.getName().equals("COM1") && !currentPort.isCurrentlyOwned()) {
					portName = currentPort.getName(); //get the name of this port
					System.out.println("Using " + portName + " for xBee serial communication");
					commPortId = currentPort;
					return; //get the first available port
				}
			}
		}
	}

	private boolean connect() {
		CommPort commPort = null;
		boolean connected = false;
		try {
			commPort = commPortId.open("Xbee", TIMEOUT);
			serialPort = (SerialPort) commPort;
			input = serialPort.getInputStream();
			output = serialPort.getOutputStream();
			serialPort.addEventListener(new Reader());
			serialPort.notifyOnDataAvailable(true);
			System.out.println("Connected to " + serialPort.getName());
			connected = true;
		} catch (PortInUseException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return connected;
	}

	private class Reader implements SerialPortEventListener {

		boolean begin = false;

		boolean beginFooter;

		int header = 0xad;
		int end1 = 0x01;
		int end2 = 0x10;

		List<Integer> packetData;

		@Override
		public void serialEvent(SerialPortEvent event) {
			if (event.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
				try {
					byte singleData = (byte)input.read();
					int data = singleData & 0xff;
					if (data == header && !begin) {
						begin = true;
						packetData = new LinkedList<Integer>();
					} else if (beginFooter) {
						if (data == end2) {
							begin = false;
							//send data
							System.out.println("Packet Info:");
							for (Integer I : packetData) {
								System.out.println(I);
							}
							beginFooter = false;
						}
					} else if (data == end1) {
						beginFooter = true;
					}else if (begin) {
						packetData.add(data);
					}



				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}

	}

}
