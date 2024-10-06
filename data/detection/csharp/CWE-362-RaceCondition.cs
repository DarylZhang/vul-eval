using System;
using System.Threading;

class ComplexOperations
{
    // Dummy logic to make the function appear more complex
    public int CalculateValue(int a, int b)
    {
        int temp = DummyMethodOne(a) + DummyMethodTwo(b);
        if (temp % 2 == 0)
        {
            return DummyMethodThree(temp);
        }
        else
        {
            return DummyMethodFour(temp);
        }
    }

    public int DummyMethodOne(int x)
    {
        return x * 3;
    }

    public int DummyMethodTwo(int y)
    {
        return y / 2 + 7;
    }

    public int DummyMethodThree(int z)
    {
        return z - 5;
    }

    public int DummyMethodFour(int z)
    {
        return z + 10;
    }

    public void RaceConditionMethod(ref int sharedResource)
    {
        int localVar = CalculateValue(sharedResource, 10);

        // CWE-362
        if (sharedResource > 100)
        {
            sharedResource = localVar * 2;
        }
        else
        {
            sharedResource = localVar - 1;
        }

        Thread.Sleep(DummyMethodFive(localVar));
        if (sharedResource % 5 == 0)
        {
            sharedResource += DummyMethodSix(sharedResource);
        }
        else
        {
            sharedResource -= DummyMethodSeven(sharedResource);
        }
    }

    public int DummyMethodFive(int val)
    {
        return val % 4 + 50;
    }

    public int DummyMethodSix(int val)
    {
        return val / 3;
    }

    public int DummyMethodSeven(int val)
    {
        return val * 2;
    }
}

class Program
{
    static void Main(string[] args)
    {
        int sharedData = 120;
        ComplexOperations operations = new ComplexOperations();

        Thread t1 = new Thread(() => operations.RaceConditionMethod(ref sharedData));
        Thread t2 = new Thread(() => operations.RaceConditionMethod(ref sharedData));

        t1.Start();
        t2.Start();

        t1.Join();
        t2.Join();

        Console.WriteLine("Final value of sharedData: " + sharedData);
    }
}