import java.util.*;
import java.io.*;

class Solution {

    void dfs(int[][] graph, int node, ArrayList<Boolean> visited) {
        visited.set(node, true);
        System.out.print(node + " ");
        for (int neighbour = 0; neighbour < graph.length; neighbour++) {
            if (graph[node][neighbour] == 1 && visited.get(neighbour) != true) {
                dfs(graph, neighbour, visited);
            }
        }
        System.out.println();
    }

    void bfs(int[][] graph, int startNode, ArrayList<Boolean> visited) {
        Queue<Integer> q = new LinkedList<>();
        q.add(startNode);
        visited.set(startNode, true);
        while (!q.isEmpty()) {
            int node = q.poll();
            System.out.print(node + " ");
            for (int neighbour = 0; neighbour < graph.length; neighbour++) {
                if (graph[node][neighbour] == 1 && visited.get(neighbour) != true) {
                    q.add(neighbour);
                    visited.set(neighbour, true);
                }
            }
            System.out.println();

        }
    }
}

public class BfsDfs {
    public static void main(String[] args) {
        // System.out.println("Hello World!!!");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] graph = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                graph[i][j] = sc.nextInt();
            }
        }
        // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
        // System.out.print(graph[i][j] + " ");
        // }
        // System.out.println();
        // }
        Solution obj = new Solution();
        // int ans = obj.findCircleNum(graph);
        // System.out.println(ans);
        ArrayList<Boolean> visited = new ArrayList<Boolean>(n);
        for (int i = 0; i < n; i++) {
            visited.add(false);
        }
        // obj.dfs(graph, 0, visited);
        obj.bfs(graph, 0, visited);
    }
}