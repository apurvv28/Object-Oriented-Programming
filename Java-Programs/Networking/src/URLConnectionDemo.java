import java.net.URL;
import java.net.URLConnection;
import java.io.IOException;
import java.util.Date;

public class URLConnectionDemo {
    public static void main(String[] args) {
        try {
            URL url = new URL("https://www.google.com");

            URLConnection c = url.openConnection();

            System.out.println("Content Type: " + c.getContentType());
            System.out.println("Content Length: " + c.getContentLength());
            System.out.println("Date: " + new Date(c.getDate()));
            System.out.println("Expiration: " + new Date(c.getExpiration()));
            System.out.println("Last Modified: " + new Date(c.getLastModified()));

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}