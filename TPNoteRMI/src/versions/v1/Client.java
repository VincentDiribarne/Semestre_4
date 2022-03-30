package versions.v1;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

import enumeration.Action;
import versions.Player;
import versions.PlayerDispenserImp;
import versions.Score;

public class Client {
	public static void main(String[] args) throws RemoteException, InterruptedException, MalformedURLException, NotBoundException {
		Scanner  kb     = new Scanner(System.in);
		String   line;		
		Player   player = null;	// objet
		String   name;			// nom du joueur
		String   opponentName;  // nom de l'opposant
		int      id;			// id du joueur
		Score    r ;				// r√©sultat
		String url;
		
		
	try {
		
		url = "rmi://localhost:1900/player";
		player = (Player)Naming.lookup(url);
		
		System.out.println("Nom?");
		line = kb.nextLine();
		id = player.hello(line);
		System.out.println(player.getOpponentName(0) + " vs "+player.getOpponentName(1));
		while(true) {
			
			System.out.println("Action?");
			line = kb.nextLine();
			r = player.play(id, Action.fromString(line));
			//player.wait();  
		}
//---------		


	
	/*	System.out.println("RÈference PLayer obtenue : "+ url);
		
		player = new PlayerImp(new PlayerDispenserImp());
		System.out.println("Nom?");
		line = kb.nextLine();
		id = player.hello(line);
		
		System.out.println(player.getOpponentName(0) + " vs "+player.getOpponentName(1));
		while(true) {
			
			System.out.println("Action?");
			line = kb.nextLine();
			player.play(id, Action.fromString(line));
			//player.wait();  
		}*/
	}
	catch (Exception e) {
		System.out.println("Erreur" + e.getMessage());
	}
		
		

		
		
        
	}
}
