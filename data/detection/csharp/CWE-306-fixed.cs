using System;
using System.Collections.Generic;

namespace SecurityDemo
{
    public class UserManager
    {
        private Dictionary<string, UserProfile> userProfiles;
        private Dictionary<string, string> userTokens;

        public UserManager()
        {
            userProfiles = new Dictionary<string, UserProfile>();
            userTokens = new Dictionary<string, string>();
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

        public string Login(string username, string password)
        {
            // In a real scenario, you would verify the password here
            if (userProfiles.ContainsKey(username))
            {
                string token = GenerateToken();
                userTokens[username] = token;
                return token;
            }
            return null;
        }

        public void UpdateUserProfile(string username, string newEmail, string token)
        {
            if (AuthenticateUser(username, token))
            {
                userProfiles[username].Email = newEmail;
                Console.WriteLine($"Email updated for user {username}.");

                PerformComplexCalculations();
            }
            else
            {
                Console.WriteLine("Authentication failed. Unable to update profile.");
            }
        }

        private bool AuthenticateUser(string username, string token)
        {
            return userTokens.ContainsKey(username) && userTokens[username] == token;
        }

        private string GenerateToken()
        {
            return Guid.NewGuid().ToString();
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
            string token = manager.Login("alice", "password");
            if (token != null)
            {
                manager.UpdateUserProfile("alice", "newalice@example.com", token);
            }
        }
    }
}