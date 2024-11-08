import java.util.MissingResourceException;
public class Add extends Expression
{
    Expression left;
    Expression right;
    public Add(Expression l, Expression r)
    {
        left = l;
        right = r;
    }
    public int evaluate(String[] variables, int[] values) throws MissingResourceException
    {
        return left.evaluate(variables, values) + right.evaluate(variables, values);
    }
    public String toString()
    {
        return "(" + left.toString() + " + " + right.toString() + ")";
    }
}
