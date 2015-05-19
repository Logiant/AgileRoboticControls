package test;

import java.util.Enumeration;

import gnu.io.*;
import java.awt.Color;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.TooManyListenersException;



public class SerialWriteTest {
	/* Constants */
	private String portName = "";

	//this is the object that contains the opened port
	private CommPortIdentifier selectedPortIdentifier = null;
	private SerialPort serialPort = null;

	//input and output streams for sending and receiving data
	private InputStream input = null;
	private OutputStream output = null;

	//the timeout value for connecting with the port
	final static int TIMEOUT = 2000;

	int pauseMS = 20; //ms
	
	long startTime;

	float runTime = 30; //seconds
	int roundoff = 255; //max value to write
	
	public SerialWriteTest() {

		searchForPorts();
		boolean c = connect();
		float dt = 0;
		if (c) {
			startTime = System.nanoTime();
			long time = startTime;
			while ((dt = (System.nanoTime() - startTime)/1000000000f) < runTime) {
				time = System.nanoTime();
				sendMsg((int)(dt*100) % roundoff);
				slow(time);
			}
			sendMsg(0);
			disconnect();
		}
	}

	boolean connect() {
		CommPort commPort = null;
		boolean connected = false;
		try {
			commPort = selectedPortIdentifier.open("Xbee", TIMEOUT);
			serialPort = (SerialPort) commPort;
			input = serialPort.getInputStream();
			output = serialPort.getOutputStream();
			System.out.println("Connected to " + serialPort.getName());
			connected = true;
		} catch (PortInUseException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return connected;
	}

	void disconnect() {
		serialPort.close();
		System.out.println("disconnected");
	}

	void slow(long startTime) {
		long time = System.nanoTime() ;
		while ((time - startTime) / 1000000f < pauseMS){
			 // wait
			time = System.nanoTime();
		}
	}
	
	void sendMsg(int msg) {
		try {
			output.write(msg);
			output.flush();
			System.out.println(msg + " written");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	void searchForPorts() {
		Enumeration ports = CommPortIdentifier.getPortIdentifiers();
		while(ports.hasMoreElements()) {
			CommPortIdentifier currentPort = (CommPortIdentifier)ports.nextElement();
			if (currentPort.getPortType() == CommPortIdentifier.PORT_SERIAL) {
				if (!currentPort.getName().equals("COM1") && !currentPort.isCurrentlyOwned()) {
					portName = currentPort.getName();
					System.out.println("Using " + portName + " for xBee serial protocol");
					selectedPortIdentifier = currentPort;
				} else if (currentPort.isCurrentlyOwned()) {
					System.out.println(currentPort.getName() + " is owned");
				} else {
					System.out.println("Not using " + currentPort.getName());
				}
			}
		}
	}





	public static void main(String[] args) {
		new SerialWriteTest();
	}



}