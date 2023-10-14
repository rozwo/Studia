import java.util.Arrays;
public class MergeSort<T extends Comparable<T>> extends Thread
{
    private static T[] t;
    private static int N;
    public MergeSort(T[] tab)
    {
        N = tab.length;
        t = tab;
    }

    public void run()
    {
        
        // T[] tLeft = Arrays.copyOf(t, leftLength);
        // T[] tRight = Arrays.copyOfRange(t, leftLength, leftLength + rightLength);
        // var mergeLeft = new MergeSort<T>(tLeft);
        // var mergeRight = new MergeSort<T>(tRight);
        // mergeRight.start();
        // mergeLeft.start();
        // mergeRight.join();
        // mergeLeft.join();
    }

    private void merge(T[] t1, T[] t2)
    {
        int i=p;
        int j=sr+1;
        int x=p;
        while (i<=sr && j<=k)
        {
            if (pom[i]<pom[j])
            {
                t[x++]=pom[i++];
            }
            else
            {
                t[x++]=pom[j++];
            }
        }
        while (i<=sr)
        {
            t[x++]=pom[i++];
        }
    }
    // public void mergesort(int p, int k)
    // {
    //     if (p<k)
    //     {
    //         int sr=(p+k)/2;
    //         mergesort(p, sr);
    //         mergesort(sr+1, k);
    //         merge(p, sr, k);
    //     }
    // }
}
