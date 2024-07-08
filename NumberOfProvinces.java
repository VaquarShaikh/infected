import java.util.*;
import java.io.*;

class Solution {

    void dfs(int[][] graph, int node, ArrayList<Boolean> visited) {
        visited.set(node, true);
        for (int neighbour = 0; neighbour < graph.length; neighbour++) {
            if (graph[node][neighbour] == 1 && visited.get(neighbour) != true) {
                dfs(graph, neighbour, visited);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int count = 0;
        int n = isConnected.length;
        int m = isConnected[0].length;
        ArrayList<Boolean> visited = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            visited.add(false);
        }
        for (int i = 0; i < n; i++) {
            if (visited.get(i) != true) {
                dfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
}

public class NumberOfProvinces {
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
        int ans = obj.findCircleNum(graph);
        System.out.println(ans);
    }
}