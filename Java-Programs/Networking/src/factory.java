	import java.net.InetAddress;
	import java.net.UnknownHostException;

	public class factory {
	    public static void main(String[] args) {
	        try {
	            InetAddress add1 = InetAddress.getByName("google.com");
	            System.out.println("Google IP Address: " + add1.getHostAddress());

	            InetAddress[] allAddresses = InetAddress.getAllByName("google.com");
	            System.out.println("All IP addresses of Google:");
	            for (InetAddress addr : allAddresses) {
	                System.out.println(addr.getHostAddress());
	            }
	            
	            byte[] ip = {8, 8, 8, 8};
	            InetAddress add2 = InetAddress.getByAddress(ip);
	            System.out.println("Created InetAddress from byte array: " + add2.getHostAddress());

	            InetAddress localHost = InetAddress.getLocalHost();
	            System.out.println("Localhost: " + localHost.getHostName() + " - " + localHost.getHostAddress());

	        } catch (UnknownHostException e) {
	            System.out.println("Error: " + e.getMessage());
	        }
	    }
	}
