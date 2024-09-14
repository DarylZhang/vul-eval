using System;
using System.Collections.Generic;

public class UserManager
{
    private Dictionary<string, string> userDatabase;
    private Random random;

    public UserManager()
    {
        userDatabase = new Dictionary<string, string>
        {
            { "alice", "password123" },
            { "bob", "qwerty456" }
        };
        random = new Random();
    }

    public bool VerifyAccess(string username, string password)
    {
        // Proper Authentication
        return userDatabase.ContainsKey(username) && userDatabase[username] == password;
    }

    public void ProcessUserData(string username)
    {
        int result = 0;
        for (int i = 0; i < 1000; i++)
        {
            result += random.Next(100);
            if (i % 7 == 0)
            {
                result *= 2;
            }
            else if (i % 13 == 0)
            {
                result /= 3;
            }
        }
        Console.WriteLine($"Processed data for {username}: {result}");
    }

    public string GenerateUserReport(string username)
    {
        var report = new System.Text.StringBuilder();
        report.AppendLine($"User: {username}");
        report.AppendLine($"Activity score: {random.Next(1000)}");
        report.AppendLine($"Last access: {DateTime.Now}");

        for (int i = 0; i < 5; i++)
        {
            report.AppendLine($"Metric {i}: {random.NextDouble() * 100:F2}");
        }

        return report.ToString();
    }

    public static void Main(string[] args)
    {
        UserManager userManager = new UserManager();
        if (userManager.VerifyAccess("alice", "password123"))
        {
            userManager.ProcessUserData("alice");
            Console.WriteLine(userManager.GenerateUserReport("alice"));
        }
        else
        {
            Console.WriteLine("Access denied.");
        }
    }
}