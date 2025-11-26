package networking;
import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5000);
            System.out.println("Connected to Server!");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

            Thread readThread = new Thread(() -> {
                try {
                    String serverMessage;
                    while ((serverMessage = in.readLine()) != null) {
                        System.out.println("Server: " + serverMessage);
                    }
                } catch (IOException e) {
                    System.out.println("Connection closed.");
                }
            });

            Thread writeThread = new Thread(() -> {
                try {
                    String message;
                    while ((message = userInput.readLine()) != null) {
                        out.println(message);
                    }
                } catch (IOException e) {
                    System.out.println("Error in sending message.");
                }
            });

            readThread.start();
            writeThread.start();

            readThread.join();
            writeThread.join();

            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
