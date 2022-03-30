package versions.v2;

import enumeration.Action;
import enumeration.Result;
import versions.Player;
import versions.PlayerDispenserImp;
import versions.Score;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

//2. Implémentation de l'interface
public class PlayerImp extends UnicastRemoteObject implements Player {
    private static final long serialVersionUID = 1L;

    private static final int MAXTURNS = 3; // nombre maximum de tours

    private int turn = 1; // compteur de tours
    private PlayerDispenserImp dispenser = null; // distributeur d'url

    private String[] name = new String[2]; // noms des 2 joueurs
    private Action[] action = new Action[2]; // actions des 2 joueurs
    private Result[] result = new Result[2]; // résultats des 2 joueurs
    private int[] v = new int[2]; // nombre de victoires des 2 joueurs
    private int nbPlayers = 1; // nombre de joueurs identifiés

    /**
     * @param dispenser cet objet est nécessaire pour informer le serveur de la
     *                  nécessité de créer un nouvel objet Player
     */
    public PlayerImp(PlayerDispenserImp dispenser) throws RemoteException {
        this.dispenser = dispenser;
        this.name[0] = null;
        this.name[1] = null;
    }

    /**
     * identification du joueur
     *
     * @param name nom avec lequel le joueur s'identifie
     * @return id avec lequel le joueur peut réaliser des actions
     */
    synchronized public int hello(String name) throws RemoteException, InterruptedException {
        if (this.name[0] == null && this.name[1] == null) {
            this.name[0] = name;
            System.out.println("waiting");
            wait();
            return 0;
        } else if (this.name[1] == null) {
            this.name[1] = name;
            notify();
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
     * @return résultat de l'action
     */
    synchronized public Score play(int id, Action action) throws InterruptedException {
        if (this.action[0] != null && this.action[1] != null) {
            this.action[0] = null;
            this.action[1] = null;
            turn++;
        }

        if (this.action[0] == null && this.action[1] == null) {
            this.action[0] = action;
            wait();
        } else if (this.action[1] == null) {
            this.action[1] = action;
            notify();
        }

        System.out.println("Play !");
        Result resFP = null;
        if (turn < MAXTURNS) {
            System.out.println(name[0] + "->" + this.action[0]);
            System.out.println(name[1] + "->" + this.action[1]);
            result[0] = gagner(this.action[0], this.action[1]);
            result[1] = gagner(this.action[1], this.action[0]);
        } else {
            if (v[0] == v[1]) {
                resFP = Result.NUL;
            }
            if (v[0] <= v[1]) {
                if (id == 0) {
                    resFP = Result.PERDU;
                } else {
                    resFP = Result.GAGNE;
                }

            }
            if (v[0] >= v[1]) {
                if (id == 0) {
                    resFP = Result.GAGNE;
                } else {
                    resFP = Result.PERDU;
                }
            }
            System.out.println(resFP);
        }
        return new Score(this.action, result[id], resFP);
    }

    /**
     * obtention du nom du joueur opposant
     *
     * @param id id du joueur
     * @return le nom du joueur opposant
     */
    public String getOpponentName(int id) throws RemoteException {
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
