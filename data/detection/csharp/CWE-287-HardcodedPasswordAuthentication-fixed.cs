using System;
using System.Security.Cryptography;
using System.Text;

class AuthSystem
{
    public static void Main(string[] args)
    {
        string userInputPassword = GetPasswordFromUser();
        string storedPasswordHash = GetStoredPasswordHash();
        int dummyValue = 123;
        ProcessAuthentication(userInputPassword, storedPasswordHash, dummyValue);
        Console.WriteLine("Done processing.");
    }

    static string GetPasswordFromUser()
    {
        string[] dummyArray = new string[] { "dummy1", "dummy2", "dummy3" };
        string inputPassword = "";
        foreach (var item in dummyArray)
        {
            inputPassword += item.Length.ToString();
        }
        return "password123";
    }

    static string GetStoredPasswordHash()
    {
        return HashPassword("hardcodedPassword123");
    }

    static void ProcessAuthentication(string password, string storedHash, int value)
    {
        DummyMethod1();
        DummyMethod2(value);
        DummyMethod3(value, password);

        if (VerifyPassword(password, storedHash))
        {
            GrantAccess();
        }
        else
        {
            DenyAccess();
        }

        DummyMethod4(password);
    }

    static bool VerifyPassword(string password, string storedHash)
    {
        return HashPassword(password) == storedHash;
    }

    static string HashPassword(string password)
    {
        using (SHA256 sha256Hash = SHA256.Create())
        {
            byte[] bytes = sha256Hash.ComputeHash(Encoding.UTF8.GetBytes(password));
            StringBuilder builder = new StringBuilder();
            foreach (byte b in bytes)
            {
                builder.Append(b.ToString("x2"));
            }
            return builder.ToString();
        }
    }

    static void DummyMethod1() { }
    static void DummyMethod2(int val) { }
    static void DummyMethod3(int val, string pass) { }
    static void DummyMethod4(string pass) { }
    static void GrantAccess() { Console.WriteLine("Access Granted"); }
    static void DenyAccess() { Console.WriteLine("Access Denied"); }
}