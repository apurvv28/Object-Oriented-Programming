#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

// User Class
class User {
public:
    string name, phone, gender, password;
    
    User() {}
    User(string n, string p, string g, string pass) 
        : name(n), phone(p), gender(g), password(pass) {}
    
    string toFileString() {
        return name + "|" + phone + "|" + gender + "|" + password;
    }
    
    static User fromFileString(string line) {
        stringstream ss(line);
        string n, p, g, pass;
        getline(ss, n, '|');
        getline(ss, p, '|');
        getline(ss, g, '|');
        getline(ss, pass, '|');
        return User(n, p, g, pass);
    }
};

// Ride Class
class Ride {
public:
    string rideId, userPhone, userName, source, destination;
    double totalFare;
    int passengers;
    string dateTime, status;
    
    Ride() {}
    Ride(string id, string uPhone, string uName, string src, string dest, 
         double fare, int pass, string dt)
        : rideId(id), userPhone(uPhone), userName(uName), source(src), 
          destination(dest), totalFare(fare), passengers(pass), 
          dateTime(dt), status("ACTIVE") {}
    
    double getFarePerPerson() {
        return totalFare / passengers;
    }
    
    string toFileString() {
        return rideId + "|" + userPhone + "|" + userName + "|" + source + "|" + 
               destination + "|" + to_string(totalFare) + "|" + 
               to_string(passengers) + "|" + dateTime + "|" + status;
    }
    
    static Ride fromFileString(string line) {
        stringstream ss(line);
        Ride r;
        string fare, pass;
        getline(ss, r.rideId, '|');
        getline(ss, r.userPhone, '|');
        getline(ss, r.userName, '|');
        getline(ss, r.source, '|');
        getline(ss, r.destination, '|');
        getline(ss, fare, '|');
        getline(ss, pass, '|');
        getline(ss, r.dateTime, '|');
        getline(ss, r.status, '|');
        r.totalFare = stod(fare);
        r.passengers = stoi(pass);
        return r;
    }
};

// File Manager Class
class FileManager {
public:
    static void saveUser(User u) {
        ofstream file("users.txt", ios::app);
        file << u.toFileString() << endl;
        file.close();
    }
    
    static vector<User> loadUsers() {
        vector<User> users;
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            if (!line.empty())
                users.push_back(User::fromFileString(line));
        }
        file.close();
        return users;
    }
    
    static void saveRide(Ride r) {
        ofstream file("rides.txt", ios::app);
        file << r.toFileString() << endl;
        file.close();
    }
    
    static vector<Ride> loadRides() {
        vector<Ride> rides;
        ifstream file("rides.txt");
        string line;
        while (getline(file, line)) {
            if (!line.empty())
                rides.push_back(Ride::fromFileString(line));
        }
        file.close();
        return rides;
    }
    
    static void updateRides(vector<Ride> rides) {
        ofstream file("rides.txt");
        for (auto& r : rides) {
            file << r.toFileString() << endl;
        }
        file.close();
    }
};

// System Class
class CabConnectSystem {
private:
    vector<User> users;
    vector<Ride> rides;
    User currentUser;
    bool isLoggedIn = false;
    int rideCounter = 1000;
    
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
    
    // Calculate fair share based on number of passengers
    double calculateFairShare(double totalFare, int passengers) {
        return totalFare / passengers;
    }
    
public:
    CabConnectSystem() {
        users = FileManager::loadUsers();
        rides = FileManager::loadRides();
        rideCounter = 1000 + rides.size();
    }
    
    void displayHeader() {
        cout << "\n";
        cout << "========================================\n";
        cout << "     CABCONNECT - RIDE SHARING SYSTEM   \n";
        cout << "========================================\n\n";
    }
    
    void registerUser() {
        cout << "\n--- USER REGISTRATION ---\n";
        User newUser;
        
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, newUser.name);
        
        cout << "Enter Phone Number: ";
        cin >> newUser.phone;
        
        // Check if phone already exists
        for (auto& u : users) {
            if (u.phone == newUser.phone) {
                cout << ">> Phone number already registered!\n";
                return;
            }
        }
        
        cout << "Enter Gender (Male/Female/Other): ";
        cin >> newUser.gender;
        
        cout << "Enter Password: ";
        cin >> newUser.password;
        
        users.push_back(newUser);
        FileManager::saveUser(newUser);
        
        cout << ">> Registration successful! Please login to continue.\n";
    }
    
    bool loginUser() {
        cout << "\n--- USER LOGIN ---\n";
        string phone, pass;
        
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Password: ";
        cin >> pass;
        
        for (auto& u : users) {
            if (u.phone == phone && u.password == pass) {
                currentUser = u;
                isLoggedIn = true;
                cout << ">> Welcome, " << currentUser.name << "!\n";
                return true;
            }
        }
        
        cout << ">> Invalid credentials!\n";
        return false;
    }
    
    void createRide() {
        if (!isLoggedIn) {
            cout << ">> Please login first!\n";
            return;
        }
        
        cout << "\n--- CREATE NEW RIDE ---\n";
        string src, dest;
        double fare;
        int pass;
        
        cout << "Enter Source: ";
        cin.ignore();
        getline(cin, src);
        
        cout << "Enter Destination: ";
        getline(cin, dest);
        
        cout << "Enter Total Fare (Rs): ";
        cin >> fare;
        
        cout << "Enter Number of Passengers needed: ";
        cin >> pass;
        
        // Get current date and time automatically
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char dt[100];
        strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M", ltm);
        string dateTime(dt);
        
        string id = "R" + to_string(++rideCounter);
        Ride newRide(id, currentUser.phone, currentUser.name, src, dest, fare, pass, dateTime);
        
        rides.push_back(newRide);
        FileManager::saveRide(newRide);
        
        cout << ">> Ride created successfully! (ID: " << id << ")\n";
        cout << ">> Date & Time: " << dateTime << "\n";
        cout << ">> Total Fare: ₹" << fare << " | Per Person: ₹" 
             << fixed << setprecision(2) << calculateFairShare(fare, pass) << "\n";
        
        // Check for matches
        findMatches(newRide);
    }
    
    void findMatches(Ride myRide) {
        vector<Ride*> matches;
        
        for (auto& r : rides) {
            if (r.rideId != myRide.rideId && 
                r.status == "ACTIVE" &&
                toLowerCase(r.source) == toLowerCase(myRide.source) &&
                toLowerCase(r.destination) == toLowerCase(myRide.destination)) {
                matches.push_back(&r);
            }
        }
        
        if (matches.empty()) {
            cout << "\n>> No matches found yet. You'll be notified when someone posts a similar ride.\n";
            return;
        }
        
        cout << "\n>> FOUND " << matches.size() << " MATCHING RIDE(S)!\n";
        cout << "==========================================\n";
        
        for (size_t i = 0; i < matches.size(); i++) {
            Ride* r = matches[i];
            cout << "\n[" << (i+1) << "] Ride ID: " << r->rideId << "\n";
            cout << "    Traveler: " << r->userName << "\n";
            cout << "    Route: " << r->source << " → " << r->destination << "\n";
            cout << "    Time: " << r->dateTime << "\n";
            cout << "    Available Seats: " << r->passengers << "\n";
            cout << "    Total Fare: ₹" << r->totalFare << "\n";
            cout << "    Fare per person: ₹" << fixed << setprecision(2) 
                 << r->getFarePerPerson() << "\n";
        }
        
        cout << "\n==========================================\n";
        cout << "Would you like to join any ride? (1-" << matches.size() << " or 0 to skip): ";
        
        int choice;
        cin >> choice;
        
        if (choice > 0 && choice <= matches.size()) {
            joinRide(matches[choice - 1]);
        }
    }
    
    void joinRide(Ride* targetRide) {
        // Find my ride in the main vector
        Ride* myRidePtr = nullptr;
        for (auto& r : rides) {
            if (r.userPhone == currentUser.phone && r.status == "ACTIVE") {
                myRidePtr = &r;
                break;
            }
        }
        
        if (!myRidePtr) {
            cout << ">> Error: Could not find your active ride!\n";
            return;
        }
        
        // Store original fare for savings calculation
        double myOriginalFare = myRidePtr->totalFare;
        
        // Update the target ride - add passenger but keep the same total fare
        // The fare gets divided among more people
        targetRide->passengers += 1; // Add one more passenger
        
        // Mark my ride as merged
        myRidePtr->status = "MERGED";
        
        // Calculate new fair share
        double newFarePerPerson = calculateFairShare(targetRide->totalFare, targetRide->passengers);
        
        FileManager::updateRides(rides);
        
        cout << "\n>> RIDE SHARED SUCCESSFULLY!\n";
        cout << "==========================================\n";
        cout << ">> SHARING DETAILS:\n";
        cout << "   Total Passengers: " << targetRide->passengers << "\n";
        cout << "   Combined Total Fare: ₹" << fixed << setprecision(2) << targetRide->totalFare << "\n";
        cout << "   >> New Fare Per Person: ₹" << newFarePerPerson << "\n";
        cout << "   >> You Save: ₹" << fixed << setprecision(2) 
             << (myOriginalFare - newFarePerPerson) << "\n";
        cout << "==========================================\n";
        
        // Update the user's name in the target ride to show all participants
        targetRide->userName += " & " + currentUser.name;
    }
    
    void viewMyRides() {
        if (!isLoggedIn) {
            cout << " Please login first!\n";
            return;
        }
        
        cout << "\n--- MY RIDES ---\n";
        bool found = false;
        
        for (auto& r : rides) {
            if (r.userPhone == currentUser.phone) {
                found = true;
                cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
                cout << "Ride ID: " << r.rideId << "\n";
                cout << "Route: " << r.source << " → " << r.destination << "\n";
                cout << "Time: " << r.dateTime << "\n";
                cout << "Status: " << r.status << "\n";
                cout << "Passengers: " << r.passengers << "\n";
                cout << "Total Fare: ₹" << r.totalFare << "\n";
                if (r.status == "ACTIVE") {
                    cout << "Your Share: ₹" << fixed << setprecision(2) << r.getFarePerPerson() << "\n";
                }
                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
            }
        }
        
        if (!found) {
            cout << "No rides found.\n";
        }
    }
    
    void viewAllActiveRides() {
        cout << "\n--- ALL ACTIVE RIDES ---\n";
        bool found = false;
        
        for (auto& r : rides) {
            if (r.status == "ACTIVE") {
                found = true;
                cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
                cout << "Ride ID: " << r.rideId << "\n";
                cout << "Posted by: " << r.userName << "\n";
                cout << "Route: " << r.source << " → " << r.destination << "\n";
                cout << "Time: " << r.dateTime << "\n";
                cout << "Available Seats: " << r.passengers << "\n";
                cout << "Total Fare: ₹" << r.totalFare << "\n";
                cout << "Fare per person: ₹" << fixed << setprecision(2) << r.getFarePerPerson() << "\n";
                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
            }
        }
        
        if (!found) {
            cout << "📭 No active rides available.\n";
        }
    }
    
    void searchRides() {
        cout << "\n--- SEARCH RIDES ---\n";
        string src, dest;
        
        cout << "Enter Source: ";
        cin.ignore();
        getline(cin, src);
        
        cout << "Enter Destination: ";
        getline(cin, dest);
        
        bool found = false;
        cout << "\nSearch Results:\n";
        
        for (auto& r : rides) {
            if (r.status == "ACTIVE" &&
                toLowerCase(r.source).find(toLowerCase(src)) != string::npos &&
                toLowerCase(r.destination).find(toLowerCase(dest)) != string::npos) {
                
                found = true;
                cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
                cout << "Ride ID: " << r.rideId << "\n";
                cout << "Posted by: " << r.userName << "\n";
                cout << "Route: " << r.source << " → " << r.destination << "\n";
                cout << "Time: " << r.dateTime << "\n";
                cout << "Available Seats: " << r.passengers << "\n";
                cout << "Total Fare: ₹" << r.totalFare << "\n";
                cout << "Fare per person: ₹" << fixed << setprecision(2) << r.getFarePerPerson() << "\n";
            }
        }
        
        if (!found) {
            cout << " No rides found for your search criteria.\n";
        }
    }
    
    void userMenu() {
        while (true) {
            cout << "\n--- USER MENU ---\n";
            cout << "1. Create New Ride\n";
            cout << "2. View All Active Rides\n";
            cout << "3. View My Rides\n";
            cout << "4. Search Rides\n";
            cout << "5. Logout\n";
            cout << "Enter choice: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1: createRide(); break;
                case 2: viewAllActiveRides(); break;
                case 3: viewMyRides(); break;
                case 4: searchRides(); break;
                case 5: 
                    isLoggedIn = false;
                    cout << "Logged out successfully!\n";
                    return;
                default: cout << " Invalid choice!\n";
            }
        }
    }
    
    void run() {
        while (true) {
            displayHeader();
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1: registerUser(); break;
                case 2: 
                    if (loginUser()) {
                        userMenu();
                    }
                    break;
                case 3:
                    cout << "\n Thank you for using CabConnect!\n";
                    return;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
};

int main() {
    CabConnectSystem system;
    system.run();
    return 0;
}