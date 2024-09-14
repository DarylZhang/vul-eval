using System;
using System.Collections.Generic;

namespace SecurityDemo
{
    public class UserManager
    {
        private Dictionary<string, UserProfile> userProfiles;

        public UserManager()
        {
            userProfiles = new Dictionary<string, UserProfile>();
        }

        public void RegisterUser(string username, string email)
        {
            if (!userProfiles.ContainsKey(username))
            {
                userProfiles[username] = new UserProfile { Username = username, Email = email };
                Console.WriteLine($"User {username} registered successfully.");
            }
            else
            {
                Console.WriteLine("Username already exists.");
            }
        }

        public void UpdateUserProfile(string username, string newEmail)
        {
            // Vulnerability: CWE-306 - Missing Authentication for Critical Function
            if (userProfiles.ContainsKey(username))
            {
                userProfiles[username].Email = newEmail;
                Console.WriteLine($"Email updated for user {username}.");

                // Dummy complex operations
                PerformComplexCalculations();
            }
            else
            {
                Console.WriteLine("User not found.");
            }
        }

        private void PerformComplexCalculations()
        {
            Random rand = new Random();
            double result = 0;
            for (int i = 0; i < 1000; i++)
            {
                result += Math.Pow(rand.NextDouble(), 2) * Math.Sin(rand.NextDouble() * Math.PI);
            }
            Console.WriteLine($"Complex calculation result: {result}");
        }
    }

    public class UserProfile
    {
        public string Username { get; set; }
        public string Email { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            UserManager manager = new UserManager();
            manager.RegisterUser("alice", "alice@example.com");
            manager.UpdateUserProfile("alice", "newalice@example.com");
        }
    }
}