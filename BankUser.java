import java.util.Random;

public class BankUser {
    private String ID;
    private String userName;
    private double balance;
    private double wallet;
    private int timeSpent;

    public BankUser(String userName) {
        Random rand = new Random();
        this.ID = Integer.toString(rand.nextInt(1000,9999));
        this.userName = userName;
        this.balance = rand.nextDouble(1000,10000);
        this.wallet = 0;
        this.timeSpent = 0;
    }

    public String getID() {
        return ID;
    }

    public String getUserName() {
        return userName;
    }

    public void takeMoney(double m) {
        if (m > balance || balance <= 0) {
            System.out.println("Insufficient founds. The import could not be withdrew.");
        } else {
            balance -= m;
            wallet += m;
        }
    }

    public void addMoney(double m) {
        if (m > wallet) {
            System.out.println("Insufficient founds. The import could not be deposited.");
        }
        else {
            balance += m;
            wallet -= m;
        }
    }

    public void status() {
        System.out.println("Available balance: " + balance + "€");
        System.out.println("Available wallet: " + wallet + "€");
        System.out.println("Time spent: " + timeSpent);
    }

    void monthBonus() {
        wallet += 100;
        System.out.println("\nA month has passed, 100€ have been deposited in your wallet.");
    }

    void investment(double amount, char period, char risk) {
        Random rand = new Random();
        if (amount > balance || balance <= 0) {
            System.out.println("Insufficient founds");
            return;
        }
        balance -= amount;
        int _period = 0;
        if (period == 's') {
            _period = 30;
        } else if (period == 'm') {
            _period = 180;
        } else if (period == 'l') {
            _period = 360;
        } else {
            System.out.println("Invalid period.");
            return;
        }
        double _risk = 0;
        if (risk == 'l') {
            _risk = amount + amount * 2;
        } else if (risk == 'm') {
            _risk = amount + amount * 5;
        } else if (risk == 'h') {
            _risk = amount + amount * 10;
        } else {
            System.out.println("Invalid risk.");
            return;
        }
        double _amount = amount;
        timeSpent += _period;
        for (int i = 1; i <= _period; i++) {
            _amount = rand.nextInt(1000000) % _risk;
            if (rand.nextInt(1000000) % 2 != 0) {
                _amount *= -1;
            }
            if (i % 30 == 0) {
                this.monthBonus();
            }
        }
        if (risk == 'l' && (_amount < 0.7 * amount)) {
            _amount = 0.7 * amount;
        } else if (risk == 'm' && (_amount < 0.4 * amount)) {
            _amount = 0.4 * amount;
        }
        System.out.print("Initial amount invested: ");
        System.out.print(amount);
        System.out.println("€");
        System.out.print("Final amount: ");
        System.out.print(_amount);
        System.out.println("€");
        if (_amount > amount) {
            System.out.print("Earned amount: ");
            System.out.print(_amount - amount);
            System.out.println("€");
        } else if (_amount < amount) {
            System.out.print("Lost amount: ");
            System.out.print(amount - _amount);
            System.out.println("€");
        } else {
            System.out.println("No amount earned");
        }
        balance += _amount;
    }
}