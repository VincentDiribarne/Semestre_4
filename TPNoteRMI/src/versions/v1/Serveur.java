package versions.v1;


import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

import versions.PlayerDispenserImp;

public class Serveur {

    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1900);
            PlayerImp p1 = new PlayerImp(new PlayerDispenserImp());
            Naming.rebind("rmi://localhost:1900/player", p1);
        } catch (Exception e) {
            System.out.println("Server exception " + e);
            e.printStackTrace();
        }
    }
}
