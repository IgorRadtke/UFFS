import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner E = new Scanner(System.in);
        System.out.print("Informe o raio do círculo: ");
        double raio = Double.parseDouble(E.nextLine());
        Circulo c = new Circulo(raio);

        System.out.println("Raio: " + c.getRaio());
        System.out.println("Área: " + c.getArea() + " metros quadrados");
        System.out.println("Circunferência: " + c.getCircunferencia() + " metros");
    }
}