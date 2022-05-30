public class Atividade5 {
    public static void main(String[] args) {
        for (int i = 1; i < 100; i++) {
            System.out.print(i+" Java");
            for(int p = 0; p < i; p++){
                System.out.print(" atrapalha ");
            }
            System.out.println("muita gente");
        }
    }
}