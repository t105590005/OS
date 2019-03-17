import java.net.*;
import java.io.*;
import java.util.Random;
public class server
{
	public static void main(String[] args) {
		String[] strArray = {
			"I am alone",
			"Nice to meet you",
			"How are you",
			"This is an apple",
			"How old are you"}; 
		try {
			ServerSocket sock = new ServerSocket(6013);
			while (true) {
				Socket client = sock.accept();
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				Random r=new Random();
        			int randomNumber=r.nextInt(strArray.length);
				pout.println(strArray[randomNumber]);
				client.close();
			}
		}
		catch (IOException ioe) {
			System.err.println(ioe);
		}
	}
}