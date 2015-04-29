package test;

import com.sun.jna.Library;
import com.sun.jna.Native;
 
/** Simple example of Windows native library declaration and usage. */
public class HelloJNA{
   public interface Kernel32 extends Library {
       // FREQUENCY is expressed in hertz and ranges from 37 to 32767
       // DURATION is expressed in milliseconds
       public boolean Beep(int FREQUENCY, int DURATION);
       public void Sleep(int DURATION);
   }
   public static void main(String[] args) {
	String path = System.getProperty("user.dir") + "\\res\\";

    Kernel32 lib = (Kernel32) Native.loadLibrary(path + "kernel.dll", 
           Kernel32.class);
    lib.Beep(698, 500);
    lib.Sleep(500);
    lib.Beep(698, 500);
   }
}