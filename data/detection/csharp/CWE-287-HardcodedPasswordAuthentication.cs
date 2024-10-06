using System;

class AuthSystem
{
    public static void Main(string[] args)
    {
        string userInputPassword = GetPasswordFromUser();
        int dummyValue = 123;
        ProcessAuthentication(userInputPassword, dummyValue);
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

    static void ProcessAuthentication(string password, int value)
    {
        DummyMethod1();
        DummyMethod2(value);
        DummyMethod3(value, password);

        //CWE-287
        if (password == "hardcodedPassword123")
        {
            GrantAccess();
        }
        else
        {
            DenyAccess();
        }

        DummyMethod4(password);
    }

    static void DummyMethod1() { }
    static void DummyMethod2(int val) { }
    static void DummyMethod3(int val, string pass) { }
    static void DummyMethod4(string pass) { }
    static void GrantAccess() { Console.WriteLine("Access Granted"); }
    static void DenyAccess() { Console.WriteLine("Access Denied"); }
}