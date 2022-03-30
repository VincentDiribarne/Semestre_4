package versions; //TODO

import versions.v3.PlayerImp;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

//2. Implémentation de l'interface
public class PlayerDispenserImp extends UnicastRemoteObject implements PlayerDispenser {
	private static final long serialVersionUID = 1L;
	
	private String url = null; // url construite
	private int i=0;
	
	public PlayerDispenserImp() throws RemoteException, MalformedURLException {
		super();
		String url = "rmi://localhost:1901/player";
		PlayerImp p1 = new PlayerImp(this);
		Naming.rebind(url, p1);
		this.setUrl(url);
		
	}

	/**
	 * obtention de l'URL sous laquelle un objet Player est enregistré
	 * @return
	 * retourne l'url
	 */
	public String getUrl() throws RemoteException {
		return url;

    }

	/**
	 * définit la nouvelle URL pour délivrer un objet Player
	 * @param url
	 * url d'un objet Player
	 */
	public void setUrl(String url) throws RemoteException {
        this.url = url;
	}

	/**
	 * informe le serveur qu'un nouvel objet Player doit être créé et une nouvelle URL générée
	 * @throws MalformedURLException 
	 */
	synchronized public void nextUrl() throws RemoteException, MalformedURLException {
		i++;
		String url = "rmi://localhost:1901/player"+ i;
		PlayerImp p1 = new PlayerImp(this);
		Naming.rebind(url, p1);
		this.setUrl(url);
		notify();
	}

	
	/**
	 * attend de devoir générer une une nouvelle URL
	 */
	synchronized public void waitForNewUrl() throws RemoteException, InterruptedException {
        wait();
	}

}
