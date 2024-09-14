using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections.Generic;

public class DataProcessor
{
    private List<string> dataList;
    private Random random;

    public DataProcessor()
    {
        dataList = new List<string>();
        random = new Random();
    }

    public void LoadDataFromFile(string filePath)
    {

        using (FileStream fs = File.Open(filePath, FileMode.Open))
        {
            BinaryFormatter formatter = new BinaryFormatter();
            object obj = formatter.Deserialize(fs);
            // CWE-502 Vulnerable method: deserializes data without verification
            if (obj is List<string>)
            {
                dataList = (List<string>)obj;
            }
        }
        PerformComplexOperations();
    }

    private void PerformComplexOperations()
    {
        for (int i = 0; i < dataList.Count; i++)
        {
            string item = dataList[i];
            if (i % 3 == 0)
            {
                item = item.ToUpper();
            }
            else if (i % 3 == 1)
            {
                item = item.ToLower();
            }
            if (item.Length > 5)
            {
                item = item.Substring(0, 5);
            }
            dataList[i] = item;
        }
    }

    public void GenerateReport()
    {
        Console.WriteLine("Data Report:");
        foreach (string item in dataList)
        {
            Console.WriteLine($"{item} - Length: {item.Length}, Hash: {item.GetHashCode()}");
        }
        Console.WriteLine($"Total items: {dataList.Count}");
        Console.WriteLine($"Random number: {random.Next(1000)}");
    }

    public static void Main(string[] args)
    {
        DataProcessor processor = new DataProcessor();
        processor.LoadDataFromFile("data.bin");
        processor.GenerateReport();
    }
}