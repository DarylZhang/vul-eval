using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        UserAccount currentUser = new UserAccount { Role = "user" };
        int operationCode = 12345;

        AuthorizationService authService = new AuthorizationService();
        authService.ProcessRequest(currentUser, operationCode);
    }
}

class UserAccount
{
    public string Role { get; set; }
}

class AuthorizationService
{
    public void ProcessRequest(UserAccount account, int opCode)
    {
        HelperClass helper = new HelperClass();
        helper.PerformDummyOperations();

        // CWE-862 Missing Authorization
        if (opCode == 12345)
        {
            PerformPrivilegedOperation(account);
        }

        helper.AdditionalDummyLogic();
    }

    private void PerformPrivilegedOperation(UserAccount account)
    {
        ComplexCalculationService calcService = new ComplexCalculationService();
        calcService.PerformCalculations();

        Console.WriteLine("Privileged operation performed for role: " + account.Role);
    }
}

class HelperClass
{
    public void PerformDummyOperations()
    {
        List<int> dummyList = new List<int>();
        for (int i = 0; i < 10; i++)
        {
            dummyList.Add(i);
        }

        foreach (int num in dummyList)
        {
            DummyLogic(num);
        }
    }

    private void DummyLogic(int num)
    {
        if (num % 2 == 0)
        {
            Console.WriteLine(num + " is even");
        }
        else
        {
            Console.WriteLine(num + " is odd");
        }
    }

    public void AdditionalDummyLogic()
    {
        string dummyString = "dummyData";
        for (int i = 0; i < dummyString.Length; i++)
        {
            Console.WriteLine("Char at index " + i + ": " + dummyString[i]);
        }
    }
}

class ComplexCalculationService
{
    public void PerformCalculations()
    {
        int result = 0;
        for (int i = 1; i <= 100; i++)
        {
            result += i;
        }

        Console.WriteLine("Calculation result: " + result);
    }
}