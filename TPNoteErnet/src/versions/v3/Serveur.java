package versions.v3;

import versions.PlayerDispenserImp;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class Serveur {

    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1901);
            PlayerDispenserImp dispenser = new PlayerDispenserImp();
            Naming.rebind("rmi://localhost:1901/dispenser", dispenser);
            while(true){
                dispenser.waitForNewUrl();
            }
        } catch (Exception e) {
            System.out.println("Server exception " + e);
            e.printStackTrace();
        }
    }
}
