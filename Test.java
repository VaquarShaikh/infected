import java.util.*;
import java.io.*;

class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public Node<Integer> takeInput() throws IOException {
        Node<Integer> head = null;
        Node<Integer> tail = null;

        String[] data = br.readLine().trim().split(" ");

        for (int i = 0; i < data.length; i++) {
            Node<Integer> newNode = new Node<Integer>(Integer.parseInt(data[i]));
        }

        return head;
    }
}

public class Test {
    public static void main(String[] args) {

    }
}