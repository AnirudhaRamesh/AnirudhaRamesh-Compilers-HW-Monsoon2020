import java.math.BigInteger;

public class sqrsum {
  public static void main(String args[]) throws NumberFormatException {
    Long a = Long.parseLong(args[0]);
    BigInteger result = BigInteger.valueOf(0);
    for (long i = 1; i <= a; ++i) result = result.add(sqr(i));
    System.out.println("sqrsum of the numbers is: " + result.toString());
  }

  static BigInteger sqr(long b) {
    return BigInteger.valueOf(b * b);
  }
}