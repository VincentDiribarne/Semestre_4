package versions.v1;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import enumeration.Action;
import enumeration.Result;
import versions.Player;
import versions.PlayerDispenserImp;
import versions.Score;

//2. ImplÃ©mentation de l'interface
public class PlayerImp extends UnicastRemoteObject implements Player {
	private static final long serialVersionUID = 1L;

	private static final int MAXTURNS = 3; // nombre maximum de tours

	private int turn = 0; // compteur de tours
	private PlayerDispenserImp dispenser = null; // distributeur d'url

	private String[] name = new String[2]; // noms des 2 joueurs
	private Action[] action = new Action[2]; // actions des 2 joueurs
	private Result[] result = new Result[2]; // rÃ©sultats des 2 joueurs
	private int[] v = new int[2]; // nombre de victoires des 2 joueurs
	private int nbPlayers = 1; // nombre de joueurs identifiÃ©s

	/**
	 * @param dispenser cet objet est nÃ©cessaire pour informer le serveur de la
	 *                  nÃ©cessitÃ© de crÃ©er un nouvel objet Player
	 */
	public PlayerImp(PlayerDispenserImp dispenser) throws RemoteException {
		// A COMPLETER
		this.dispenser = dispenser;
	}

	/**
	 * identification du joueur
	 *
	 * @param name nom avec lequel le joueur s'identifie
	 * @return id avec lequel le joueur peut rÃ©aliser des actions
	 */
	public int hello(String name) throws RemoteException, InterruptedException {

		if (this.name[0] == null) {

			this.name[0] = name;
			return 0;
		} else if (this.name[1] == null) {
			this.name[1] = name;
			return 1;
		} else {
			System.out.println("Le nombre de joueur est au complet");
			System.exit(-1);
			return -1;
		}

	}

	/**
	 * action du joueur
	 *
	 * @param id     id du joueur
	 * @param action action du joueur
	 * @return rÃ©sultat de l'action
	 */
	public Score play(int id, Action action) throws InterruptedException {
		System.out.println("play");
		Result resFP = null;
		this.action[id] = action;
		this.action[1] = Action.fromInt((int) (Math.random() * 3));
		if (turn < MAXTURNS) {
			System.out.println(name[0] + "->" + this.action[0]);
			System.out.println(name[1] + "->" + this.action[1]);
			result[0]=gagner(this.action[0], this.action[1]);
			result[1]=gagner(this.action[1], this.action[0]);
			turn++;
		}
		else {
			if(v[0] == v[1]) {
				resFP = Result.NUL;
			}
			if(v[0] <= v[1]) {
				resFP = Result.PERDU;
			}
			if(v[0] >= v[1]) {
				resFP = Result.GAGNE;
			}
			System.out.println(resFP.toString());
		}
		return new Score(this.action, result[id], resFP);
	}

	/**
	 * obtention du nom du joueur opposant
	 *
	 * @param id id du joueur
	 * @return le nom du joueur opposant
	 */
	public String getOpponentName(int id) throws RemoteException, InterruptedException {
		return this.name[id];
	}

	private Result gagner(Action action1, Action action2) {

		if (action1 == action2) {

			return Result.NUL;
		}
		if (action1 == Action.CISEAUX) {
			if (action2 == Action.FEUILLE) {
				v[0] += 1;
				return Result.GAGNE;
			}
			if (action2 == Action.PIERRE)
				v[1] += 1;
			return Result.PERDU;

		}
		if (action1 == Action.FEUILLE) {
			if (action2 == Action.CISEAUX) {
				v[1] += 1;
				return Result.PERDU;
			}
			if (action2 == Action.PIERRE) {
				v[0] += 1;
				return Result.GAGNE;
			}
		}
		if (action1 == Action.PIERRE) {
			if (action2 == Action.FEUILLE) {
				v[0] += 1;
				return Result.PERDU;
			}
			if (action2 == Action.CISEAUX) {
				v[1] += 1;
				return Result.GAGNE;
			}
		}
		return null;
	}

}