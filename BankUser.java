public class BankUser {
    private String ID;
    private String userName;
    private double balance;
    private double wallet;
    private int timeSpent;

    public BankUser(String ID, String userName, double balance, double wallet, int timeSpent) {
        this.ID = ID;
        this.userName = userName;
        this.balance = balance;
        this.wallet = wallet;
        this.timeSpent = timeSpent;
    }

    public String getID() {
        return ID;
    }

    public String getUserName() {
        return userName;
    }

    public void takeMoney(double m){
        if (m > balance || balance <= 0)
        {
            System.out.println("Insufficient founds. The import could not be withdrew.\n");
        }else {
            balance -= m;
            wallet += m;
        }
    }

    public void addMoney(double m) {
        if (m > wallet)
        {
            System.out.println("Insufficient founds. The import could not be deposited.\n");
        }
        else
        {
            balance += m;
            wallet -= m;
        }
    }

    public void status() {
        System.out.println("\nAvailable balance: " + balance + "€\n");
        System.out.println("Available wallet: " + wallet + "€\n");
        System.out.println("Time spent: " + timeSpent + '\n');
    }

    void monthBonus()
    {
        wallet += 100;
        System.out.println("\nA month has passed, 100€ have been deposited in your wallet.\n");
    }
}
