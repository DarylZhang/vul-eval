using System;
using System.Collections.Generic;

public class SecureDataManager
{
    private Dictionary<string, UserProfile> userProfiles;
    private Random random;
    private IAuthorizationService authService;
    private ILoggingService logService;

    public SecureDataManager(IAuthorizationService authService, ILoggingService logService)
    {
        userProfiles = new Dictionary<string, UserProfile>();
        random = new Random();
        this.authService = authService;
        this.logService = logService;
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
            // Avoid CWE-863 Vulnerability: No proper authorization check
            if (authService.IsOperationAllowed(user.Role, operation))
            {
                ExecuteOperation(operation);
                logService.LogOperation(username, operation, true);
            }
            else
            {
                Console.WriteLine("Operation not allowed for this user role");
                logService.LogOperation(username, operation, false);
            }
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

public interface IAuthorizationService
{
    bool IsOperationAllowed(string role, string operation);
}

public class SimpleAuthorizationService : IAuthorizationService
{
    public bool IsOperationAllowed(string role, string operation)
    {
        if (role == "admin")
        {
            return true;
        }
        else if (role == "regular" && !operation.StartsWith("delete_"))
        {
            return true;
        }
        return false;
    }
}

public interface ILoggingService
{
    void LogOperation(string username, string operation, bool isAllowed);
}

public class ConsoleLoggingService : ILoggingService
{
    public void LogOperation(string username, string operation, bool isAllowed)
    {
        Console.WriteLine($"Log: User {username} attempted to perform {operation}. Allowed: {isAllowed}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        var authService = new SimpleAuthorizationService();
        var logService = new ConsoleLoggingService();
        var manager = new SecureDataManager(authService, logService);

        manager.PerformComplexOperation("alice", "delete_all_data");
        manager.DisplayUserInfo("alice");

        manager.PerformComplexOperation("bob", "delete_all_data");
        manager.DisplayUserInfo("bob");
    }
}