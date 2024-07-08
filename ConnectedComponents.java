import java.util.*;
import java.io.*;

class Graph {

    void dfs(ArrayList<ArrayList<Integer>> graph, int node, ArrayList<Boolean> visited, ArrayList<Integer> component) {
        visited.set(node, true);
        component.add(node);
        for (int neighbour : graph.get(node)) {
            if (visited.get(neighbour) != true) {
                dfs(graph, neighbour, visited, component);
            }
        }
    }

    ArrayList<ArrayList<Integer>> findConnectedComponents(ArrayList<ArrayList<Integer>> graph) {
        int n = graph.size();
        ArrayList<Boolean> visited = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            visited.add(false);
        }
        ArrayList<ArrayList<Integer>> connectedComponents = new ArrayList<>();
        for (int i = 0; i < graph.size(); i++) {
            if (visited.get(i) != true) {
                ArrayList<Integer> component = new ArrayList<>();
                dfs(graph, i, visited, component);
                connectedComponents.add(component);
            }
        }

        return connectedComponents;
    }
}

public class ConnectedComponents {
    public static void main(String[] args) {
        // System.out.println("Hello World!!!");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        Graph obj = new Graph();

        ArrayList<ArrayList<Integer>> connectedComponents = obj.findConnectedComponents(graph);
        int count = 1;
        for (ArrayList<Integer> component : connectedComponents) {
            System.out.print(count++ + ": ");
            for (int node : component) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }
}