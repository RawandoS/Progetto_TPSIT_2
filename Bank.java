import java.util.Vector;
public class Bank {
    Vector<BankUser> bankUserRecord;
    String name;

    public Bank(){name="Volkswagen";}

    public Bank(String name) {
        this.name = name;
    }

    public Bank(Vector<BankUser> bankUserRecord, String name) {
        this.bankUserRecord = bankUserRecord;
        this.name = name;
    }

    public Vector<BankUser> getBankUserRecord() {
        return bankUserRecord;
    }

    public String getName() {
        return name;
    }

    public BankUser getBankUserRecord(int index) {
        return bankUserRecord.elementAt(index);
    }

    public void addBankUser(BankUser userName) {
        bankUserRecord.add(userName);
    }
}
