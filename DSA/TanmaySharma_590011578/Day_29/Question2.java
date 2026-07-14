package DSA.TanmaySharma_590011578.Day_29;

import java.util.Scanner;

class Stack {
    char[] arr;
    int top;

    Stack(int size) {
        arr = new char[size];
        top = -1;
    }

    void push(char ch) {
        arr[++top] = ch;
    }

    char pop() {
        return arr[top--];
    }

    boolean isEmpty() {
        return top == -1;
    }
}

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = sc.nextLine();

        Stack stack = new Stack(s.length());

        for (int i = 0; i < s.length(); i++) {
            stack.push(s.charAt(i));
        }

        StringBuilder reversed = new StringBuilder();

        while (!stack.isEmpty()) {
            reversed.append(stack.pop());
        }

        System.out.println("Reversed string: " + reversed);

        sc.close();
    }
}