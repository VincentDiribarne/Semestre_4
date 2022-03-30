package versions.v3;

import enumeration.Action;
import versions.Player;
import versions.PlayerDispenser;
import versions.Score;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws RemoteException, InterruptedException, MalformedURLException, NotBoundException {
        Scanner kb = new Scanner(System.in);
        String line;
        Player player = null;    // objet
        String name;            // nom du joueur
        String opponentName;  // nom de l'opposant
        int id;            // id du joueur
        Score r = null;                // r�sultat
        String url;
        PlayerDispenser dispenser = null;

        try {
        	dispenser = (PlayerDispenser) Naming.lookup("rmi://localhost:1901/dispenser");
            player = (Player) Naming.lookup(dispenser.getUrl());

            System.out.println("Nom?");
            line = kb.nextLine();
            id = player.hello(line);
            System.out.println(player.getOpponentName(0) + " vs " + player.getOpponentName(1));
            while (r == null || r.getGameResult() == null ) {
                System.out.println("Action?");
                line = kb.nextLine();
                r = player.play(id, Action.fromString(line));
                if (id == 0) {
                    System.out.println(r.getAction()[1]);
                    System.out.println(r.getAction()[0]);
                } else {
                    System.out.println(r.getAction()[0]);
                    System.out.println(r.getAction()[1]);
                }
                System.out.println(r.getResult());
            }
            System.out.println("Match terminé resultat -> " + r.getGameResult());
        } catch (Exception e) {
            System.out.println("Erreur" + e.getMessage());
        }
    }
}