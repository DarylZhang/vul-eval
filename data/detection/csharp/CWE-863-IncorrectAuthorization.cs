using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string userRole = "guest";
        List<int> dataIds = new List<int> { 1, 2, 3 };

        ComplexAuthorizationFlow(userRole, dataIds);
    }

    static void ComplexAuthorizationFlow(string role, List<int> ids)
    {
        DummyPreProcess(ids);

        for (int i = 0; i < ids.Count; i++)
        {
            if (ids[i] % 2 == 0)
            {
                DummyProcess(ids[i]);
            }
            else
            {
                DummyAlternateProcess(ids[i]);
            }
        }

        // CWE-863 vulnerability: Incorrect Authorization Check
        if (role == "admin" || role == "guest")
        {
            AccessRestrictedData(ids);
        }

        DummyPostProcess(ids);
    }

    static void DummyPreProcess(List<int> ids)
    {
        foreach (var id in ids)
        {
            Console.WriteLine("Pre-processing ID: " + id);
        }
    }

    static void DummyProcess(int id)
    {
        Console.WriteLine("Processing even ID: " + id);
    }

    static void DummyAlternateProcess(int id)
    {
        Console.WriteLine("Processing odd ID: " + id);
    }

    static void AccessRestrictedData(List<int> ids)
    {
        Console.WriteLine("Accessing restricted data: " + string.Join(", ", ids));
    }

    static void DummyPostProcess(List<int> ids)
    {
        foreach (var id in ids)
        {
            Console.WriteLine("Post-processing ID: " + id);
        }
    }
}