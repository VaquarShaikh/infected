import java.util.*;
import java.io.*;
import java.util.LinkedList;

class Graph {
    public void dfs(ArrayList<ArrayList<Integer>> edges, ArrayList<Boolean> visited, int startNode) {
        visited.set(startNode, true);
        System.out.print(startNode + " ");
        for (int neighbour : edges.get(startNode)) {
            if (!visited.get(neighbour)) {
                dfs(edges, visited, neighbour);
            }
        }
    }

    void bfs(ArrayList<ArrayList<Integer>> edges, int startNode) {
        ArrayList<Boolean> visited = new ArrayList<>();
        for (int i = 0; i < edges.size(); i++) {
            visited.add(false);
        }
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(startNode);
        visited.set(startNode, false);

        while (!q.isEmpty()) {
            int u = q.remove();
            System.out.print(u + " ");

            for (int neighbour : edges.get(u)) {
                if (!visited.get(neighbour)) {
                    q.add(neighbour);
                    visited.set(neighbour, true);
                }
            }
        }

    }

}

public class Bfsdfscool {
    public static void main(String[] args) {
        // System.out.println("Hello World!!!");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        ArrayList<ArrayList<Integer>> edges = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            edges.get(sc.nextInt()).add(sc.nextInt());
        }

        ArrayList<Boolean> visited = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            visited.add(false);
        }
        int startNode = 0;

        Graph gg = new Graph();

        // gg.dfs(edges, visited, startNode);
        gg.bfs(edges, startNode);
        System.out.println();
    }
}