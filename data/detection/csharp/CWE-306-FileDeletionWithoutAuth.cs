using System;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        string filepath = "/tmp/testfile.txt";
        string userRole = "user";

        ExecuteCriticalFunction(filepath, userRole);

        DummyMethod();
    }

    static void ExecuteCriticalFunction(string path, string role)
    {
        if (role == "admin")
        {
            ProcessAdminTasks(path);
        }

        PerformAdditionalTask();

        //CWE-306
        DeleteFile(path);
    }

    static void DeleteFile(string filePath)
    {
        if (File.Exists(filePath))
        {
            File.Delete(filePath);
        }
    }

    static void DummyMethod()
    {
        for (int i = 0; i < 10; i++)
        {
            PerformDummyOperations(i);
        }
    }

    static void ProcessAdminTasks(string path)
    {
        Console.WriteLine("Performing admin-specific tasks on " + path);
    }

    static void PerformAdditionalTask()
    {
        Console.WriteLine("Performing additional operations");
    }

    static void PerformDummyOperations(int i)
    {
        Console.WriteLine("Dummy operation: " + i);
    }
}