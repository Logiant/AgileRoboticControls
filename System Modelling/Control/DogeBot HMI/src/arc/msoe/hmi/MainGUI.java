package arc.msoe.hmi;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

import arc.msoe.hmi.comms.InputThread;

/**
 * Creates the main GUI and serves as the bridge between user input and the Xbee controller
 * Provides updates on the current state of the robot
 * 
 * 3/12/2015
 * @author beaverl
 *
 */
public class MainGUI extends JFrame{
	
	//Frame Constants
	private static final long serialVersionUID = 1L;
	int height = 600;
	int width = 800;
	String heading = "A.R.C. Robot HMI";
	
	//helper classes
	RTComms comms; //IO with the Xbee unit
	InputThread input;  //parses user input
	
	//boolean values
	boolean validController; //is the controller connected?
	boolean commsConnected;  //have the comms connected?
	boolean faultInComs;  //have the comms faulted?
	
	//GUI elements
	//images
	ImageIcon ARCLogo; //ARC Logo
	JLabel title; //program title
	JLabel subtitle; //program subtitle
	
	//buttons
	JButton exit = new JButton("Exit");  //button used to close the program
	JButton connect = new JButton("Connect");  //starts the comms
	
	//comms indicators
	ImageIcon commsOn;  //comms active
	ImageIcon commsFault;  //comms fault
	ImageIcon commsOff; //comms inactive
	
	//cylinder indicators
	JLabel Leg1T;
	JLabel Leg1S;
	JLabel Leg2T;
	JLabel Leg2S;
	JLabel Leg3T;
	JLabel Leg3S;
	JLabel Leg4T;
	JLabel Leg4S;
	ImageIcon robot; //robot image
	
	//controller indicators
	ImageIcon controllerOn;  //controller active
	ImageIcon controllerFault;  //controller fault
	ImageIcon controllerOff; //controller inactive
	JLabel controllerRef; //current controller command
	
	
	public MainGUI() {
		this.setSize(width, height); //set the size of the window
		this.setDefaultCloseOperation(EXIT_ON_CLOSE); //close the window when exit is pressed
		this.setTitle(heading); //window title
		this.setLocationRelativeTo(null); //center window
		createGUI(); //create the GUI
		this.setVisible(true); //make the window visible
		

	}
	
	/**
	 * organizes all elements for the main GUI
	 */
	private void createGUI() {
		//place the GUI elements in the Layouts in the JPanels in the JFrame
	}
		
	public static void main(String[] args) {
		new MainGUI(); //create the GUI on startup
	}

	class EscapeListener {
		//listens for the escape button action
		//gracefully shut down
		//close the program
	}
	
	class ConnectListener {
		//listens for the connect button action
		//send a connection request to RT Comms
		//wait for timeout
		//if the connection is accepted, the comms are not faulting
	}
}
