import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
    }

    static void welcomeMessage()
    {
        System.out.println("\n***********************************************************\n");
        System.out.println("WELCOME TO THE BANK PORTAL\n");
        System.out.println("New Customer? Type 'n' to create a new Account.\n");

        //System.out.println("Already a Customer? Type 'a' to login.\n");
        System.out.println("***********************************************************\n");
        System.out.println("Option: ");
    }

    static void userInterface()
    {
        System.out.println("\n***********************************************************\n");
        System.out.println("Choose the desired option:\n");
        System.out.println("Type 's' to view your current balance.\n");
        System.out.println("Type 'd' to deposit founds.\n");
        System.out.println("Type 'w' to withdraw founds.\n");
        System.out.println("Type 'i' to invest founds.\n");
        System.out.println("Type 't' to move time forward.\n");
        //System.out.println("Type 'l' to log out.\n");
        System.out.println("Type 'e' to exit.\n");
        System.out.println("***********************************************************\n");
        System.out.println("Option: ");
    }

}