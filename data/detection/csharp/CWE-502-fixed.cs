using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections.Generic;

public class SafeDataProcessor
{
    private List<string> dataList;
    private Random random;
    private DataValidator validator;

    public SafeDataProcessor()
    {
        dataList = new List<string>();
        random = new Random();
        validator = new DataValidator();
    }

    public void LoadDataFromFile(string filePath)
    {
        using (FileStream fs = File.Open(filePath, FileMode.Open))
        {
            BinaryFormatter formatter = new BinaryFormatter();
            object obj = formatter.Deserialize(fs);
            // Avoid CWE-502 Vulnerable method: deserializes data without verification
            ProcessDeserializedData(obj);
        }
        PerformComplexOperations();
    }

    private void ProcessDeserializedData(object obj)
    {
        if (validator.IsValidData(obj))
        {
            dataList = (List<string>)obj;
        }
        else
        {
            Console.WriteLine("Invalid data detected. Using default empty list.");
            dataList = new List<string>();
        }
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
        SafeDataProcessor processor = new SafeDataProcessor();
        processor.LoadDataFromFile("data.bin");
        processor.GenerateReport();
    }

    private class DataValidator
    {
        public bool IsValidData(object obj)
        {
            if (!(obj is List<string>))
            {
                return false;
            }
            List<string> list = (List<string>)obj;
            foreach (string item in list)
            {
                if (item.Length > 100 || !System.Text.RegularExpressions.Regex.IsMatch(item, @"^[a-zA-Z0-9]+$"))
                {
                    return false;
                }
            }
            return true;
        }
    }
}