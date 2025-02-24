import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

    }

    static void welcomeMessage() {
        System.out.println("***********************************************************");
        System.out.println("WELCOME TO THE BANK PORTAL");
        System.out.println("New Customer? Type 'n' to create a new Account.");
        //System.out.println("Already a Customer? Type 'a' to login.");
        System.out.println("***********************************************************");
        System.out.println("Option: ");
    }

    static void userInterface() {
        System.out.println("***********************************************************");
        System.out.println("Choose the desired option:");
        System.out.println("Type 's' to view your current balance.");
        System.out.println("Type 'd' to deposit founds.");
        System.out.println("Type 'w' to withdraw founds.");
        System.out.println("Type 'i' to invest founds.");
        System.out.println("Type 't' to move time forward.");
        //System.out.println("Type 'l' to log out.");
        System.out.println("Type 'e' to exit.");
        System.out.println("***********************************************************");
        System.out.println("Option: ");
    }
}