import java.net.*;
import java.util.Scanner;

public class UDPClient {
    public static void main(String[] args) {
        try {
            DatagramSocket clientSocket = new DatagramSocket();
            InetAddress serverAddress = InetAddress.getByName("localhost");
            int serverPort = 3000;

            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.print("You: ");
                String message = scanner.nextLine();
                byte[] sendData = message.getBytes();

                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, serverPort);
                clientSocket.send(sendPacket);

                if (message.equalsIgnoreCase("bye")) {
                    System.out.println("Closing client...");
                    break;
                }
            }
            clientSocket.close();
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
