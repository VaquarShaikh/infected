import java.util.*;
import java.util.LinkedList;
import java.io.*;

public class BFS {

    static void bfs(ArrayList<ArrayList<Integer>> edges, int startNode) {
        ArrayList<Boolean> visited = new ArrayList<>(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            visited.add(false);
        }
        Queue<Integer> queue = new LinkedList<Integer>();

        queue.add(startNode);
        visited.set(startNode, true);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            System.out.print(u + " ");
            for (int v : edges.get(u)) {
                if (!visited.get(v)) {
                    queue.add(v);
                    visited.set(v, true);
                }
            }
        }
    }

    public static void main(String[] args) {
        // System.out.println("Hello World!!!");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<ArrayList<Integer>> edges = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.get(u).add(v);
            edges.get(v).add(u);
        }
        int startNode = 0;
        bfs(edges, startNode);
    }
}

// 5 6
// 0 1
// 0 2
// 1 3
// 1 2
// 4 3
// 4 2