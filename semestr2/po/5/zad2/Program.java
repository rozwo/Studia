import java.util.MissingResourceException;

public class Program
{
    public static void main(String[] args) throws MissingResourceException
    {
        Expression wyr = (new Multiply(new Subst(new Variable("x"), new Const(3)), new Add(new Const(7), new Variable("y"))));

        System.out.println(wyr);
        String[] variables = {"x", "y"};
        int[] values = {-4, 5};

        System.out.println(wyr.evaluate(variables, values));
        values[0] = 3;
        System.out.println(wyr.evaluate(variables, values));
        values[0] = 8;
        values[1] = -2;
        System.out.println(wyr.evaluate(variables, values));
    }
}