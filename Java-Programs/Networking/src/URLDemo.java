import java.net.URL;
import java.net.MalformedURLException;

public class URLDemo {
    public static void main(String[] args) {
        try {
            URL url = new URL("https://www.geeksforgeeks.org/java/");

            System.out.println("Protocol: " + url.getProtocol());
            System.out.println("Host: " + url.getHost());
            System.out.println("Port: " + url.getPort());
            System.out.println("Path: " + url.getPath());
            System.out.println("Query: " + url.getQuery());
            System.out.println("File: " + url.getFile());

        } catch (MalformedURLException e) {
            System.out.println("Invalid URL: " + e.getMessage());
        }
    }
}
