package versions.v2;

import enumeration.Action;
import versions.Player;
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
        Score r = null;                // résultat
        String url;


        try {
            url = "rmi://localhost:1900/player";
            player = (Player) Naming.lookup(url);

            System.out.println("Nom?");
            line = kb.nextLine();
            id = player.hello(line);
            System.out.println(player.getOpponentName(0) + " vs " + player.getOpponentName(1));
            while (r == null || r.getGameResult() == null ) {
                System.out.println("Action?");
                line = kb.nextLine();
                r = player.play(id, Action.fromString(line));
                System.out.println(r.getAction()[0]);
                System.out.println(r.getAction()[1]);
            }
            System.out.println(r.getGameResult());
        } catch (Exception e) {
            System.out.println("Erreur" + e.getMessage());
        }
    }
}
