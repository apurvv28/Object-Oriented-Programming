import java.net.InetAddress;
import java.net.UnknownHostException;
import java.io.IOException;

public class instance {
    public static void main(String[] args) {
        try {
            InetAddress address = InetAddress.getByName("google.com");

            System.out.println("Host Name: " + address.getHostName());
            System.out.println("IP Address: " + address.getHostAddress());
            System.out.println("Is Multicast Address? " + address.isMulticastAddress());

            InetAddress localHost = InetAddress.getLocalHost();
            System.out.println("\nLocalhost Info:");
            System.out.println("Host Name: " + localHost.getHostName());
            System.out.println("IP Address: " + localHost.getHostAddress());

        } catch (UnknownHostException e) {
            System.out.println("Unknown Host Exception: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IO Exception: " + e.getMessage());
        }
    }
}
