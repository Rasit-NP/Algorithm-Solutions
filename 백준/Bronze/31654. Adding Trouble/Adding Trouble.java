import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int a, b, c;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        if (c == a+b){
            System.out.println("correct!");
        }
        else {
            System.out.println("wrong!");
        }
    }
}