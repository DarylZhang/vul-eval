using System;
using System.Collections.Generic;

public class DummyProcessor
{
    public void ProcessData(string data)
    {
        Console.WriteLine("Processing: " + data);
    }
}

public class UserManager
{
    private Dictionary<string, string> userDatabase;
    private Dictionary<string, string> userRoles;

    public UserManager()
    {
        userDatabase = new Dictionary<string, string>
        {
            { "alice", "password123" },
            { "bob", "qwerty456" }
        };

        userRoles = new Dictionary<string, string>
        {
            { "alice", "admin" },
            { "bob", "user" }
        };
    }

    public bool AuthenticateUser(string username, string password)
    {
        return userDatabase.ContainsKey(username) && userDatabase[username] == password;
    }

    public void AccessRestrictedFunction(string username)
    {
        // CWE-862: Missing Authorization Check
        Console.WriteLine($"User {username} accessed the restricted function.");
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        UserManager userManager = new UserManager();
        if (userManager.AuthenticateUser("bob", "qwerty456"))
        {
            userManager.AccessRestrictedFunction("bob");
        }
        else
        {
            Console.WriteLine("Authentication failed.");
        }
    }
}