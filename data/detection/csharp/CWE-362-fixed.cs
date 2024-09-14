using System;
using System.Collections.Generic;
using System.Threading;

public class DummyProcessor
{
    public void ProcessData(int data)
    {
        Console.WriteLine("Processing: " + data);
    }
}

public class SharedResource
{
    private List<int> data = new List<int>();
    private readonly object lockObject = new object();

    public void AddData(int value)
    {
        lock (lockObject)
        {
            // Fixed: Proper synchronization
            data.Add(value);
        }
    }

    public void ProcessAllData()
    {
        DummyProcessor processor = new DummyProcessor();
        lock (lockObject)
        {
            foreach (int value in data)
            {
                processor.ProcessData(value);
            }
        }
    }
}

public class Program
{
    private static SharedResource sharedResource = new SharedResource();

    public static void Main(string[] args)
    {
        Thread thread1 = new Thread(AddData);
        Thread thread2 = new Thread(AddData);

        thread1.Start();
        thread2.Start();

        thread1.Join();
        thread2.Join();

        sharedResource.ProcessAllData();
    }

    public static void AddData()
    {
        for (int i = 0; i < 1000; i++)
        {
            sharedResource.AddData(i);
        }
    }
}