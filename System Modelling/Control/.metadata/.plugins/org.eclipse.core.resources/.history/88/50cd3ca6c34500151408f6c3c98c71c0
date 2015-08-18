package arc.msoe.hmi;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import arc.msoe.hmi.comms.InputThread;

/**
 * Creates the main GUI and serves as the bridge between user input and the Xbee controller
 * Provides updates on the current state of the robot
 * 
 * 3/15/2015
 * @author beaverl
 *
 */
public class MainGUI extends JFrame{
	
	float commandWeight = 0.001f;
	float cmd = 0;
	
	//Frame Constants
	private static final long serialVersionUID = 1L;
	int height = 600;
	int width = 800;
	String heading = "A.R.C. Robot HMI";
	
	//helper classes
	RTComms comms; //IO with the Xbee unit
	InputThread input;  //parses user input
	Thread inputThread;
	
	//boolean values
	boolean validController; //is the controller connected?
	boolean commsConnected;  //have the comms connected?
	boolean faultInComs;  //have the comms faulted?
	
	//GUI elements
	//images
	ImageIcon ARCLogo; //ARC Logo
	JLabel ARCLogoLabel;
	JLabel title; //program title
	JLabel subtitle; //program subtitle
	
	//buttons
	JButton exit;  //button used to close the program
	JButton connect;  //starts the comms
	
	//comms indicators
	ImageIcon commsOn;  //comms active
	ImageIcon commsFault;  //comms fault
	ImageIcon commsConnecting; //comms connecting
	ImageIcon commsOff; //comms inactive
	JLabel commsOnLabel;
	JLabel commsOffLabel;
	JLabel commsFaultLabel;
	JLabel commsConnectLabel;
	
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
	JLabel robotLabel;
	//controller indicators
	ImageIcon controllerOn;  //controller active
	ImageIcon controllerFault;  //controller fault
	ImageIcon controllerOff; //controller inactive
	JLabel controlOnLabel;
	JLabel controlOffLabel;
	JLabel controlFaultLabel;
	//misc JLabels
	JLabel controllerRef; //current controller command
	JLabel commsText;
	JLabel inputText;
	
	JLabel status;
	
	public MainGUI() {
		this.setSize(width, height); //set the size of the window
		this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE); //close the window when exit is pressed
		this.setTitle(heading); //window title
		this.setLocationRelativeTo(null); //center window
		setupComponents();
		createGUI(); //create the GUI
		this.setVisible(true); //make the window visible
		setupThreads();
	}
	
	/**
	 * loads images and creates initial GUI elements
	 * 
	 */
	private void setupComponents() {

		//declare images
		BufferedImage LEDOnImage = null;
		BufferedImage LEDOffImage = null;
		BufferedImage LEDErrorImage = null;
		BufferedImage LEDIdleImage = null;
		BufferedImage ARCLogoImage = null;
		BufferedImage DogeBotImage = null;
		//load images with IO
		try {
	    LEDOnImage = ImageIO.read(new File("res/ActiveImage.png"));
	    LEDOffImage = ImageIO.read(new File("res/OffImage.png"));
	    LEDErrorImage = ImageIO.read(new File("res/ErrorImage.png"));
	    LEDIdleImage = ImageIO.read(new File("res/IdleImage.png"));
	    ARCLogoImage = ImageIO.read(new File("res/ARCLogo.png"));
	    DogeBotImage = ImageIO.read(new File("res/DogebotImage.png"));
		} catch(IOException e) {
			System.err.println("COULD NOT LOAD ALL IMAGE ICONS");
			e.printStackTrace();
			System.exit(-1);
		}
		//initialize ImageIcons
		ARCLogo = new ImageIcon(ARCLogoImage); //ARC Logo
		robot = new ImageIcon(DogeBotImage); //robot image
		commsOn = new ImageIcon(LEDOnImage);  //comms active
		commsFault = new ImageIcon(LEDErrorImage);  //comms fault
		commsOff = new ImageIcon(LEDOffImage); //comms inactive
		commsConnecting = new ImageIcon(LEDIdleImage);
		controllerOn = new ImageIcon(LEDOnImage);  //controller active
		controllerFault = new ImageIcon(LEDErrorImage);  //controller fault
		controllerOff = new ImageIcon(LEDOffImage); //controller inactive
		//initialize JLabel Icons
		ARCLogoLabel = new JLabel(ARCLogo);
		robotLabel = new JLabel(robot);
		commsOnLabel = new JLabel(commsOn);
		commsOffLabel = new JLabel(commsOff);
		commsFaultLabel = new JLabel(commsFault);
		commsConnectLabel = new JLabel(commsConnecting);
		controlOnLabel = new JLabel(commsOn);
		controlOffLabel = new JLabel(commsOff);
		controlFaultLabel = new JLabel(commsFault);
		//initialize JLabels
		title = new JLabel("A.R.C. HMI"); //program title
		subtitle = new JLabel("Developed by Logan Beaver"); //program subtitle
		Leg1T = new JLabel("Leg 1 Thigh Extension: 0 inches");
		Leg1S = new JLabel("Leg 1 Shank Extension: 0 inches");
		Leg2T = new JLabel("Leg 2 Thigh Extension: 0 inches");
		Leg2S = new JLabel("Leg 2 Shank Extension: 0 inches");
		Leg3T = new JLabel("Leg 3 Thigh Extension: 0 inches");
		Leg3S = new JLabel("Leg 3 Shank Extension: 0 inches");
		Leg4T = new JLabel("Leg 4 Thigh Extension: 0 inches");
		Leg4S = new JLabel("Leg 4 Shank Extension: 0 inches");
		controllerRef = new JLabel("Current Controller Reference: NONE"); //current controller command
		commsText = new JLabel("Comms status: off");
		inputText = new JLabel("Input Status: off");
		status = new JLabel("Status: ");
		//initialize Buttons
		connect = new JButton("Connect");  //starts the comms
		exit = new JButton("Exit");  //button used to close the program
		connect.addActionListener(new ConnectListener());
		exit.addActionListener(new EscapeListener());
	}
	
	/**
	 * Creates the threads for comms IO and controller input
	 */
	private void setupThreads() {
		input = new InputThread(this);
		inputThread = new Thread(input);
		inputThread.start();
		comms = new RTComms();
	}
	
	/**
	 * organizes all elements for the main GUI
	 */
	private void createGUI() {
		this.setLayout(new BorderLayout());
		//creating JPanel holders
		JPanel titlePanel = new JPanel(); //contains title and logos
		JPanel bodyPanel = new JPanel();  //contains buttons and status indicators
		titlePanel.setLayout(new BorderLayout());
		bodyPanel.setLayout(new BorderLayout());
		//place the GUI elements in the Layouts in the JPanels in the JFrame
		titlePanel.add(title);
		titlePanel.add(subtitle, BorderLayout.SOUTH);
		titlePanel.add(ARCLogoLabel, BorderLayout.EAST);
		add(titlePanel, BorderLayout.NORTH);
		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new GridLayout(1,2));
		buttonPanel.add(connect);
		buttonPanel.add(exit);
		bodyPanel.add(buttonPanel, BorderLayout.NORTH);
		
		bodyPanel.add(status, BorderLayout.SOUTH);

		this.add(bodyPanel);
		
		JPanel statusPanel = new JPanel();
		statusPanel.setLayout(new FlowLayout());
		statusPanel.add(commsText);
		statusPanel.add(commsOffLabel);
		
		statusPanel.add(inputText);
		statusPanel.add(controlOffLabel);
		bodyPanel.add(statusPanel);

		
		
//		this.add(Leg1T);
//		this.add(Leg1S);
//		this.add(Leg2T);
//		this.add(Leg2S);
//		this.add(Leg3T);
//		this.add(Leg3S);
//		this.add(Leg4T);
//		this.add(Leg4S);
//		this.add(robotLabel);
		
	}
			
	public void updateState(int leftJoy, int rightJoy, int trigger, int button ) {
		int up = button&1;
		int down = ((button&2)>>1);
		int direction = up - down;
		

		cmd = direction * 128 + 128;
		
		cmd = Math.min(Math.max(0, cmd), 255); //clamp cmd to (-1, 1), (backward, forward)
		
	//	System.out.println((int)cmd);
		status.setText("Command: " + (int)cmd);
		comms.updateCommand((int)cmd);
	}
	
	public static void main(String[] args) {
		new MainGUI(); //create the GUI on startup
	}
	
	
	class EscapeListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent event) {
			//gracefully shut down
			input.close(); //stops controller input thread
			comms.close();
			// TODO disconnect comms
			//close the program
			System.exit(0);
		}
	}
	
	class ConnectListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent event) {
			// TODO Auto-generated method stub
			//send a connection request to RT Comms
			//wait for timeout
			//if the connection is accepted, the comms are not faulting
			System.out.println("connecting...");
			comms.beginConnection();
		}
	}
}
