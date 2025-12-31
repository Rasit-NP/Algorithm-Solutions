import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        System.out.println(n*(n+1)/2);
        System.out.println(n*n*(n+1)*(n+1)/4);
        System.out.println(n*n*(n+1)*(n+1)/4);
    }
}