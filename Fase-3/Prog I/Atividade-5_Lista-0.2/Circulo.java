public class Circulo{
    private double raio;
   
    // construtor que recebe o valor do raio como argumento
    public Circulo(double raio){
      this.raio = raio;  
    }
    public double getRaio(){
      return raio;
    }
    public void setRaio(double raio){
      this.raio = raio;
    }
     
    // área do círculo
    public double getArea(){
      double area = Math.PI * Math.pow(this.raio, 2); 
      return area;  
    }
     
    //circunferência do círculo
    public double getCircunferencia(){
      double circunferencia = (2 * Math.PI) * this.raio; 
      return circunferencia;  
    }
    public void aumentarRaio(double percentual) {
    }
  }