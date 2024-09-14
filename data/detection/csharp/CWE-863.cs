using System;
using System.Collections.Generic;

public class DataManager
{
    private Dictionary<string, UserProfile> userProfiles;
    private Random random;

    public DataManager()
    {
        userProfiles = new Dictionary<string, UserProfile>();
        random = new Random();
        InitializeUsers();
    }

    private void InitializeUsers()
    {
        userProfiles.Add("alice", new UserProfile("alice", "regular"));
        userProfiles.Add("bob", new UserProfile("bob", "admin"));
    }

    public void PerformComplexOperation(string username, string operation)
    {
        if (userProfiles.TryGetValue(username, out UserProfile user))
        {
            // CWE-863 Vulnerability: No proper authorization check
            ExecuteOperation(operation);
        }
        else
        {
            Console.WriteLine("User not found");
        }
    }

    private void ExecuteOperation(string operation)
    {
        Console.WriteLine($"Executing operation: {operation}");

        for (int i = 0; i < 1000; i++)
        {
            double result = Math.Pow(i, 2) + Math.Sqrt(i);
            if (result % 2 == 0)
            {
                Console.WriteLine($"Even result: {result}");
            }
        }

        int[] numbers = new int[100];
        for (int i = 0; i < numbers.Length; i++)
        {
            numbers[i] = random.Next(1, 1000);
        }
        Array.Sort(numbers);
        Console.WriteLine($"Median number: {numbers[numbers.Length / 2]}");
    }

    public void DisplayUserInfo(string username)
    {
        if (userProfiles.TryGetValue(username, out UserProfile user))
        {
            Console.WriteLine($"Username: {user.Username}");
            Console.WriteLine($"Role: {user.Role}");
        }
        else
        {
            Console.WriteLine("User not found");
        }
    }

    private class UserProfile
    {
        public string Username { get; }
        public string Role { get; }

        public UserProfile(string username, string role)
        {
            Username = username;
            Role = role;
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        var manager = new DataManager();
        manager.PerformComplexOperation("alice", "delete_all_data");
        manager.DisplayUserInfo("alice");
    }
}